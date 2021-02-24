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

    visorHistoS = new ImgViewer(260,150, (QImage *) NULL, ui->histoFrameS);
    visorHistoD = new ImgViewer(260,150, (QImage *) NULL, ui->histoFrameD);


    visorS = new ImgViewer(&grayImage, ui->imageFrameS);
    visorD = new ImgViewer(&destGrayImage, ui->imageFrameD);


    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
    connect(ui->captureButton,SIGNAL(clicked(bool)),this,SLOT(start_stop_capture(bool)));
    connect(ui->colorButton,SIGNAL(clicked(bool)),this,SLOT(change_color_gray(bool)));
    /******************/
    connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(loadFromFile(void)));
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(saveToFile(void)));
    /*****************/

    connect(visorS,SIGNAL(mouseSelection(QPointF,int,int)),this,SLOT(selectWindow(QPointF, int, int)));
    connect(visorS,SIGNAL(mouseClic(QPointF)),this,SLOT(deselectWindow(QPointF)));

    connect(ui->pixelTButton,SIGNAL(clicked()),&pixelTDialog,SLOT(show()));
    connect(pixelTDialog.okButton,SIGNAL(clicked()),&pixelTDialog,SLOT(hide()));
    connect(pixelTDialog.grayTransformW, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(controlGrayRanges(QTableWidgetItem*)));

    connect(ui->kernelButton,SIGNAL(clicked()),&lFilterDialog,SLOT(show()));
    connect(lFilterDialog.okButton,SIGNAL(clicked()),&lFilterDialog,SLOT(hide()));
    connect(lFilterDialog.kernelWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(controlKernelRanges(QTableWidgetItem*)));


    connect(ui->operOrderButton,SIGNAL(clicked()),&operOrderDialog,SLOT(show()));
    connect(operOrderDialog.okButton,SIGNAL(clicked()),&operOrderDialog,SLOT(hide()));


    timer.start(30);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete cap;
    delete visorS;
    delete visorD;
}

void MainWindow::compute()
{
    //Captura de imagen

    if(ui->captureButton->isChecked() && cap->isOpened())
    {
        *cap >> colorImage;

        cv::resize(colorImage, colorImage, Size(320, 240));
        cvtColor(colorImage, grayImage, COLOR_BGR2GRAY);
        cvtColor(colorImage, colorImage, COLOR_BGR2RGB);

    }


    //Procesamiento
    std::string str = "Transform Pixel";
    QString qstr = QString::fromStdString(str);
    if(ui->operationComboBox->currentText(qstr));

        pixelTransformation();

   // if(ui->operationComboBox->)
   //     thresholding();


    //Actualización de los visores
    updateHistogram(grayImage, visorHistoS);
    updateHistogram(destGrayImage, visorHistoD);

    if(winSelected)
    {
        visorS->drawSquare(QPointF(imageWindow.x+imageWindow.width/2, imageWindow.y+imageWindow.height/2), imageWindow.width,imageWindow.height, Qt::green );
    }
    visorS->update();
    visorD->update();
    visorHistoS->update();
    visorHistoD->update();

}

void MainWindow::updateHistogram(Mat image, ImgViewer * visor)
{
    if(image.type() != CV_8UC1) return;

    Mat histogram;
    int channels[] = {0,0};
    int histoSize = 256;
    float grange[] = {0, 256};
    const float * ranges[] = {grange};
    double minH, maxH;

    calcHist( &image, 1, channels, Mat(), histogram, 1, &histoSize, ranges, true, false );
    minMaxLoc(histogram, &minH, &maxH);

    float maxY = visor->getHeight();

    for(int i = 0; i<256; i++)
    {
        float hVal = histogram.at<float>(i);
        float minY = maxY-hVal*maxY/maxH;

        visor->drawLine(QLineF(i+2, minY, i+2, maxY), Qt::red);
    }

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
        colorSelected=true;

    }
    else
    {
        ui->colorButton->setText("Color image");
        visorS->setImage(&grayImage);
        visorD->setImage(&destGrayImage);
        colorSelected=false;

    }
}

/***************************/

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


void MainWindow::pixelTransformation(){
//s = (L-1) - r //s=c∗log(1+ r̄ )
    std::vector<char> vectorSalida[255];

}

//Umbralización
void MainWindow::thresholding(){

  threshold(grayImage, destGrayImage, 1, 128, THRESH_BINARY);

}
void MainWindow::histogramEqualization(){

}
void MainWindow::gaussianSmoothing(){

}
void MainWindow::mediumFilter(){

}
void MainWindow::linealFilter(){

}
void MainWindow::dilatation(){

}
void MainWindow::erosion(){

}


/***************************/




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
        imageWindow.width = pEnd.x()-imageWindow.x;
        imageWindow.height = pEnd.y()-imageWindow.y;

        winSelected = true;
    }
}

void MainWindow::deselectWindow(QPointF p)
{
    std::ignore = p;
    winSelected = false;
}

void MainWindow::controlKernelRanges(QTableWidgetItem* it)
{
    bool ok;
    it->text().toFloat(&ok);
    if(not ok)
        it->setText("0");
}

void MainWindow::controlGrayRanges(QTableWidgetItem* it)
{
    bool ok;
    int g = it->text().toInt(&ok);
    if(not ok or g<0)
        it->setText("0");
    if(g>255)
        it->setText("255");
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    pixelTDialog.close();
    lFilterDialog.close();
    operOrderDialog.close();
    event->accept();
}
