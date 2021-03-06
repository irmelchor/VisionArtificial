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
    connect(visorS,SIGNAL(mouseClick(QPointF)),this,SLOT(pixelValue(QPointF)));

    /********************/

    connect(visorS,SIGNAL(mouseSelection(QPointF, int, int)),this,SLOT(selectWindow(QPointF, int, int)));
    connect(visorS,SIGNAL(mouseClick(QPointF)),this,SLOT(deselectWindow(QPointF)));
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

    destColorImage.setTo(0);
    destGrayImage.setTo(0);

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


void MainWindow::copyChannels(){

    destColorImage.setTo(0);
    destGrayImage.setTo(0);

    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));



    std::vector<Mat> canales;
    split(colorImage, canales);

    if(!ui->rCheck->isChecked())
        canales[0].setTo(0);

    if(!ui->gCheck->isChecked())
        canales[1].setTo(0);

    if(!ui->bCheck->isChecked())
        canales[2].setTo(0);

    merge(canales, destColorImage);

   // imshow("Channel", destColorImage);

    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
}


void MainWindow::copyWindow(){
    destColorImage.setTo(0);
    destGrayImage.setTo(0);

    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

    double fv = (240-imageWindow.height)/2;
    double fh = (320-imageWindow.width)/2;

    Rect destImageWindow(fh,fv,imageWindow.width,imageWindow.height);

    Mat winColor = colorImage(imageWindow);
    Mat winGray = grayImage(imageWindow);

    Mat winDestColor = destColorImage(destImageWindow);
    Mat winDestGray = destGrayImage(destImageWindow);

    winColor.copyTo(winDestColor);
    winGray.copyTo(winDestGray);

    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
}


void MainWindow::resizeWin(){
    destColorImage.setTo(0);
    destGrayImage.setTo(0);

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

    destColorImage.setTo(0);
    destGrayImage.setTo(0);

    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));

    double fh = 240./imageWindow.height;
    double fv = 320./imageWindow.width;

    double menor;
    if(fh<fv){
        menor=fh;
    }else{
        menor=fv;
    }

    int W = rint(imageWindow.width*menor);
    int H = rint(imageWindow.height*menor);

    double y = (240-H)/2;
    double x = (320-W)/2;

    Rect destImageWindow(x,y,W,H);

    Mat winColor = colorImage(imageWindow);
    Mat winGray = grayImage(imageWindow);

    Mat winDestColor = destColorImage(destImageWindow);
    Mat winDestGray = destGrayImage(destImageWindow);


    cv::resize(winColor, winColor, Size(),menor,menor,INTER_LINEAR);
    cv::resize(winGray, winGray, Size(),menor,menor,INTER_LINEAR);

    winColor.copyTo(winDestColor);
    winGray.copyTo(winDestGray);

    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
}


void MainWindow::pixelValue(QPointF p){
//mat -> colorImage
//       grayImage
//img.at<char (si es de grises) o vector de 3 posiciones si es RGB>
   //tooltip
    //    colorImage.at<Vec3b>(f,c);
    //grayImage.at<uchar>(f,c); //unsigned char

   Point posicion(p.x(),p.y());
   QPoint qposicion(p.x(),p.y());

   QPoint suma = qposicion+this->pos()+ui->imageFrameS->pos();

   Vec3b vcolor = colorImage.at<Vec3b>(posicion);
   uchar vgris = grayImage.at<uchar>(posicion);


   if(colorSelected){
   QString colorConcatenado = "R= "+QString::number(vcolor[0])+" G= "+QString::number(vcolor[1])+ " B= "+QString::number(vcolor[2]);
   QToolTip::showText(suma, colorConcatenado);

   }else{
   QString gris = "Gray= "+QString::number(vgris);
   QToolTip::showText(suma, gris);
   }

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

void MainWindow::deselectWindow(QPointF p)
{
    std::ignore = p;
    winSelected = false;
}


