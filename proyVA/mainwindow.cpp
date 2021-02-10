#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cap = new VideoCapture(0);
    winSelected = false;

    colorImage.create(240,320,CV_8UC3);
    grayImage.create(240,320,CV_8UC1);
    destColorImage.create(240,320,CV_8UC3);
    destColorImage.setTo(0);
    destGrayImage.create(240,320,CV_8UC1);
    destGrayImage.setTo(0);

    visorS = new ImgViewer(&grayImage, ui->imageFrameS);
    visorD = new ImgViewer(&destGrayImage, ui->imageFrameD);

    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
    connect(ui->captureButton,SIGNAL(clicked(bool)),this,SLOT(start_stop_capture(bool)));
    connect(ui->colorButton,SIGNAL(clicked(bool)),this,SLOT(change_color_gray(bool)));

    /********************/
    connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(loadFromFile(void)));
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(saveToFile(void)));

    /********************/

    connect(visorS,SIGNAL(mouseSelection(QPointF, int, int)),this,SLOT(selectWindow(QPointF, int, int)));
    connect(visorS,SIGNAL(mouseClick()),this,SLOT(deselectWindow()));
    timer.start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cap;
    delete visorS;
    delete visorD;
    colorImage.release();
    grayImage.release();
    destColorImage.release();
    destGrayImage.release();
}

void MainWindow::compute()
{

    //Captura de imagen
    if(ui->captureButton->isChecked() && cap->isOpened())
    {
        *cap >> colorImage;
        cv::resize(colorImage, colorImage, Size(320,240));
        cvtColor(colorImage, grayImage, COLOR_BGR2GRAY);
        cvtColor(colorImage, colorImage, COLOR_BGR2RGB);
    }


    //En este punto se debe incluir el código asociado con el procesamiento de cada captura


    //Actualización de los visores

    if(winSelected)
        visorS->drawSquare(QRect(imageWindow.x, imageWindow.y, imageWindow.width,imageWindow.height), Qt::green );

    visorS->update();
    visorD->update();

}

void MainWindow::start_stop_capture(bool start)
{
    if(start)
        ui->captureButton->setText("Stop capture");
    else
        ui->captureButton->setText("Start capture");
}

void MainWindow::change_color_gray(bool color)
{
    if(color)
    {
        ui->colorButton->setText("Gray image");
        visorS->setImage(&colorImage);
        visorD->setImage(&destColorImage);
    }
    else
    {
        ui->colorButton->setText("Color image");
        visorS->setImage(&grayImage);
        visorD->setImage(&destGrayImage);
    }
}

void MainWindow::loadFromFile(/*bool load*/){

    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
    ui->captureButton->setCheckable(false);
    start_stop_capture(false);

    QString ruta = QFileDialog::getOpenFileName(this, "Open File", "/home/irene/Escritorio/VisionArtificial","Images (*.png *.xpm *.jpg)");
    std::string rutaImagen = ruta.toStdString();
    Mat loadImg = imread(rutaImagen);

    cv::resize(loadImg, loadImg, Size(320, 240));
    cvtColor(loadImg,colorImage,COLOR_BGR2RGB);
    cvtColor(loadImg,grayImage,COLOR_BGR2GRAY);

    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
    ui->captureButton->setCheckable(true);
    start_stop_capture(true);
}

void MainWindow::saveToFile(){
    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

    QString file = QFileDialog::getSaveFileName(this, "Save file");
    std::string rutafichero= file.toStdString();

    cvtColor(destColorImage,destColorImage,COLOR_RGB2BGR);
    //cvtColor(destGrayImage,COLOR_RGB2BGR);

    imwrite(rutafichero,destColorImage);
    imwrite(rutafichero,destGrayImage);
    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
}


void MainWindow::resizeWin(){

}

void MainWindow::enlargeWin(){
    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

    Rect destRect;

    Mat winColor = colorImage(imageWindow);
    Mat winGray = grayImage(imageWindow);



    double fv = (240-imageWindow.height)/2;
    double fh = (320-imageWindow.width)/2;

    double menor;
        if(fv<fh)
            menor=fv;
        else
           menor=fh;

    cv::resize(winColor, winColor, Size(),menor,menor,INTER_LINEAR);
    cv::resize(winGray, winGray, Size(),menor,menor,INTER_LINEAR);

    copyTo(winColor,destColorImage,);


    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

}


void MainWindow::selectWindow(QPointF p, int w, int h)
{
    QPointF pEnd;
    if(w>0 && h>0)
    {
        imageWindow.x = p.x()-w/2;
        if(imageWindow.x<0)
            imageWindow.x = 0;
        imageWindow.y = p.y()-h/2;
        if(imageWindow.y<0)
            imageWindow.y = 0;
        pEnd.setX(p.x()+w/2);
        if(pEnd.x()>=320)
            pEnd.setX(319);
        pEnd.setY(p.y()+h/2);
        if(pEnd.y()>=240)
            pEnd.setY(239);
        imageWindow.width = pEnd.x()-imageWindow.x+1;
        imageWindow.height = pEnd.y()-imageWindow.y+1;

        winSelected = true;
    }
}

void MainWindow::deselectWindow()
{
    winSelected = false;
}


