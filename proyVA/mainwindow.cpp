#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cap = new VideoCapture(0);
    winSelected = false;
    colorSelected = false;

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
    connect(ui->copyChannelsButton,SIGNAL(clicked(bool)),this,SLOT(copyChannels(void)));
    connect(ui->copyWindowButton,SIGNAL(clicked(bool)),this,SLOT(copyWindow(void)));
    connect(ui->enlargeButton,SIGNAL(clicked(bool)),this,SLOT(enlargeWin(void)));
    connect(ui->resizeButton,SIGNAL(clicked(bool)),this,SLOT(resizeWin(void)));


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
        colorSelected = true;
    }
    else
    {
        ui->colorButton->setText("Color image");
        visorS->setImage(&grayImage);
        visorD->setImage(&destGrayImage);
        colorSelected = false;
    }
}

void MainWindow::loadFromFile(){

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
    Mat saveColorImage;

    if(colorSelected){
        cvtColor(destColorImage,saveColorImage,COLOR_RGB2BGR);
        imwrite(rutafichero,saveColorImage);

    }else{
        imwrite(rutafichero,destGrayImage);
    }

    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
}

//Copia en destColorImage los canales de las casillas activas. Si no está activa, se considera 0
//imagen2=CV_RGB(1,0,0); //inicializar imagen a un color
void MainWindow::copyChannels(){

    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

    std::vector<Mat> channels;
    split(colorImage, channels);

    Mat zero = Mat::zeros(colorImage.size(), CV_8UC3);

    if(ui->rCheck->isChecked()){
    std::vector<Mat> imageDest = { channels[0], zero, zero };
    }

    if(ui->gCheck->isChecked()){
    std::vector<Mat> imageDest = { zero, channels[1], zero };
    }

    if(ui->bCheck->isChecked()){
    std::vector<Mat> imageDest = { zero, zero, channels[2] };
    }



    Mat rdst, gdst, bdst;

    //merge(, destColorImage);

    imshow("Channel", destColorImage);


    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

}

//Copia literalmente en el centro de la ventana destino sin escalar
void MainWindow::copyWindow(){

}


void MainWindow::resizeWin(){

    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

    Rect destImageWindow;

    Mat winColor = colorImage(imageWindow);
    Mat winGray = grayImage(imageWindow);

    destImageWindow.height = imageWindow.height;
    destImageWindow.width = imageWindow.width;

    Mat winDestColor = destColorImage(destImageWindow);
    Mat winDestGray = destGrayImage(destImageWindow);


    cv::resize(winColor, winDestColor, Size(320,240));
    cv::resize(winGray, winDestGray, Size(320,240));

    winDestColor.copyTo(destColorImage);
    winDestGray.copyTo(destGrayImage);


    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));


}

void MainWindow::enlargeWin(){
    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

    double fv = 240/imageWindow.height;
    double fh = 320/imageWindow.width;

    Rect destImageWindow(fv,fh,imageWindow.width,imageWindow.height);

    Mat winColor = colorImage(imageWindow);
    Mat winGray = grayImage(imageWindow);

    destImageWindow.height = imageWindow.height;
    destImageWindow.width = imageWindow.width;

    Mat winDestColor = destColorImage(destImageWindow);
    Mat winDestGray = destGrayImage(destImageWindow);

    double menor;
        if(fv<fh)
            menor=fv;
        else
           menor=fh;

    cv::resize(winColor, winDestColor, Size(),menor,menor,INTER_LINEAR);
    cv::resize(winGray, winDestGray, Size(),menor,menor,INTER_LINEAR);

    winDestColor.copyTo(destColorImage);
    winDestGray.copyTo(destGrayImage);


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


