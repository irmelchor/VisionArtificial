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
    segmentedImage.create(240,320,CV_8UC1);
    imgFinal.create(240,320,CV_8UC3);


    inicializarTabla();

    inicializarRed();


    visorS = new ImgViewer(&grayImage, ui->imageFrameS);
    visorD = new ImgViewer(&destGrayImage, ui->imageFrameD);


    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
    connect(ui->captureButton,SIGNAL(clicked(bool)),this,SLOT(start_stop_capture(bool)));
    connect(ui->colorButton,SIGNAL(clicked(bool)),this,SLOT(change_color_gray(bool)));
    /******************/
    connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(loadFromFile(void)));
    //connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(saveToFile(void)));
    /*****************/

    connect(visorS,SIGNAL(mouseSelection(QPointF,int,int)),this,SLOT(selectWindow(QPointF, int, int)));
    connect(visorS,SIGNAL(mouseClic(QPointF)),this,SLOT(deselectWindow(QPointF)));

    connect(ui->segmentImageButton,SIGNAL(clicked(bool)),this,SLOT(segmentar(void)));


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


    //Actualización de los visores
  //  updateHistogram(grayImage, visorHistoS);
  //  updateHistogram(destGrayImage, visorHistoD);

    if(winSelected)
    {
        visorS->drawSquare(QPointF(imageWindow.x+imageWindow.width/2, imageWindow.y+imageWindow.height/2), imageWindow.width,imageWindow.height, Qt::green );
    }
    visorS->update();
    visorD->update();
    //visorHistoS->update();
    //visorHistoD->update();

}

void MainWindow::inicializarRed(){
    miRed = readNetFromCaffe("../proyVA4/fcn/fcn.prototxt","../proyVA4/fcn/fcn.caffemodel");
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

void MainWindow::inicializarTabla(){
    tablaColores.push_back({0,0,0});
    tablaColores.push_back({128,0,0});
    tablaColores.push_back({0,128,0});
    tablaColores.push_back({128,128,0});
    tablaColores.push_back({0,0,128});
    tablaColores.push_back({128,0,128});
    tablaColores.push_back({0,128,128});
    tablaColores.push_back({128,128,128});
    tablaColores.push_back({64,0,0});
    tablaColores.push_back({192,0,0});
    tablaColores.push_back({64,128,0});
    tablaColores.push_back({192,128,0});
    tablaColores.push_back({64,0,128});
    tablaColores.push_back({192,0,128});
    tablaColores.push_back({64,128,128});
    tablaColores.push_back({192,128,128});
    tablaColores.push_back({0,64,0});
    tablaColores.push_back({128,64,0});
    tablaColores.push_back({0,192,0});
    tablaColores.push_back({128,192,0});
    tablaColores.push_back({0,64,128});
}


void MainWindow::segmentar(){
    Mat imagenFormateada = blobFromImage(colorImage, 1.0, Size(), mean(colorImage), true, false, CV_32F);
    miRed.setInput(imagenFormateada);
    Mat output = miRed.forward();


    for(int f=0;f<ui->imageWidthBox->value();f++){
        //qDebug()<<"Entramos en el primer for";
        for(int c=0; c<ui->ImageHeightBox->value();c++){
            //qDebug()<<"Entramos en el segundo for";
            float catMax=0;
            int icat;
            for(int cat=0; cat<=20;cat++){ //for de la categoría
                //qDebug()<<"Entramos en el tercer for";
                int idx[4]={0,cat,f,c};
                float val = output.at<float>(idx);
                  //qDebug()<<"Antes del if"<<cat;
                if (val > catMax){
                     // qDebug()<<"Entramos en el if";
                    catMax = val;
                    icat = cat;
                }
            }

            //qDebug()<<"Hacemos at";
            segmentedImage.at<uchar>(f,c)=icat;
            //qDebug()<<"Terminamos at";
        }
    }

    //Llamar al siguiente método
    visualizacionDeLaSegmentacion();

}

void MainWindow::visualizacionDeLaSegmentacion(){
    //2 for de la imagen segmentada, para generar imagen de la pag 50. accedemos al pixel, accedemos al índice y vemos el color.
    for(int f=0; f<segmentedImage.rows;f++){
        for(int c=0; c<segmentedImage.cols; c++){
            int indice= segmentedImage.at<uchar>(f,c);
            imgFinal.at<Vec3b>(f,c)= tablaColores[indice];
        }
    }
    imgFinal.copyTo(destColorImage);
    //imgFinal.copyTo(destGrayImage);

    sumarImagenes();
}

void MainWindow::sumarImagenes(){
    Mat combinada;
    //segmentedImage -> (1-p)
    //imgFinal       -> (p)


    combinada.copyTo(destColorImage);
}



void MainWindow::loadFromFile(){


    disconnect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
    ui->captureButton->setCheckable(false);
    start_stop_capture(false);


    QString ruta = QFileDialog::getOpenFileName(this, "Open File", "/home/irene/Escritorio/VisionArtificial","Images (*.png *.xpm *.jpg *.jpeg)");
    std::string rutaImagen = ruta.toStdString();
    Mat loadImg = imread(rutaImagen);

    cv::resize(loadImg, loadImg, Size(320, 240));
    //miRed.setInput();
    //blobFromImage();
    cvtColor(loadImg,colorImage,COLOR_BGR2RGB);
    cvtColor(loadImg,grayImage,COLOR_BGR2GRAY);

    connect(&timer,SIGNAL(timeout()),this,SLOT(compute()));
    ui->captureButton->setCheckable(true);
    start_stop_capture(true);

}


void MainWindow::saveToFile(){

   /* destColorImage.setTo(0);
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
    */
}


void MainWindow::pixelTransformation(Mat src, Mat &dst){
   /* int r;
    std::vector<uchar> lut;
    lut.resize(256);

    std::vector<int> vectorS;
    vectorS.resize(4);
    std::vector<int> vectorR;
    vectorR.resize(4);

    for(int i =0; i<4;i++){
        vectorS[i] = pixelTDialog.grayTransformW->item(i,0)->text().toInt();
        vectorR[i] = pixelTDialog.grayTransformW->item(i,1)->text().toInt();
    }

    for(int i = 0; i<vectorS.size()-1;i++){
        for(int s=vectorS[i]; s<vectorS[i+1];s++){
            r = (((s-vectorS[i])*(vectorR[i+1] - vectorR[i]))/(vectorS[i+1] - vectorS[i]))+vectorR[i];
            lut[s]=r;
        }
    }

    cv::LUT(src,lut,dst);
*/
}

//Umbralización
void MainWindow::thresholding(Mat src, Mat &dst){
  //cv::threshold(src, dst, ui->thresholdSpinBox->text().toInt(),255, THRESH_BINARY);

}

void MainWindow::histogramEqualization(Mat src, Mat &dst){
    cv::equalizeHist(src,dst);
}

void MainWindow::gaussianSmoothing(Mat src, Mat &dst){
   // int w= ui->gaussWidthBox->text().toInt();
    //cv::GaussianBlur(src,dst,Size(w,w),w/5.,w/5., BORDER_DEFAULT);
}

void MainWindow::mediumFilter(Mat src, Mat &dst){
    cv::medianBlur(src,dst,3);
}

void MainWindow::linealFilter(Mat src, Mat &dst){
    /*
    Matx33f matrizKernel;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            matrizKernel(i,j)=lFilterDialog.kernelWidget->item(i,j)->text().toFloat();
        }
    }
    double addedValue = lFilterDialog.addedVBox->text().toDouble();
    cv::filter2D(src,dst,-1,matrizKernel,Point(-1,-1),addedValue,BORDER_DEFAULT);
    */
}

void MainWindow::dilatation(Mat src, Mat &dst){
    Mat auxImage;
   // cv::threshold(src, auxImage, ui->thresholdSpinBox->text().toInt(),255, THRESH_BINARY);
    //cv::dilate(auxImage,dst,Mat(),Point(-1,-1),1,BORDER_CONSTANT,morphologyDefaultBorderValue());
}

void MainWindow::erosion(Mat src, Mat &dst){
    Mat auxImage;
   // cv::threshold(src, auxImage, ui->thresholdSpinBox->text().toInt(),255, THRESH_BINARY);
    cv::erode(auxImage,dst,Mat(),Point(-1,-1),1,BORDER_CONSTANT,morphologyDefaultBorderValue());
}

void MainWindow::applySeveral(){
    /*
    destGrayImage.setTo(0);

    if(operOrderDialog.firstOperCheckBox->isChecked()){
        int metodo = operOrderDialog.operationComboBox1->currentIndex();
        Mat aux = metodoSwitch(metodo, grayImage);

        if(operOrderDialog.secondOperCheckBox->isChecked()){
            int metodo = operOrderDialog.operationComboBox2->currentIndex();
            Mat aux2 = metodoSwitch(metodo, aux);

            if(operOrderDialog.thirdOperCheckBox->isChecked()){
                int metodo = operOrderDialog.operationComboBox3->currentIndex();
                Mat aux3 = metodoSwitch(metodo, aux2);

                if(operOrderDialog.fourthOperCheckBox->isChecked()){
                    int metodo = operOrderDialog.operationComboBox4->currentIndex();
                    Mat aux4 = metodoSwitch(metodo,aux3);
                    //Copiar aux4 en destGrayImage
                    aux4.copyTo(destGrayImage);

                } else{
                    //Copiar aux3 en destGrayImage
                    aux3.copyTo(destGrayImage);
                }

            } else{
                //Copiar aux2 en destGrayImage
                aux2.copyTo(destGrayImage);
            }

        } else{
            //Copiar aux en destGrayImage
            aux.copyTo(destGrayImage);
        }

    } else{
        grayImage.copyTo(destGrayImage);
    }
*/
}


Mat MainWindow::metodoSwitch(int metodo, Mat src){
    Mat aux;
    switch (metodo) {
    case 0:
        pixelTransformation(src,aux);
        break;
    case 1:
        thresholding(src,aux);
        break;
    case 2:
        histogramEqualization(src,aux);
        break;
    case 3:
        gaussianSmoothing(src,aux);
        break;
    case 4:
        mediumFilter(src,aux);
        break;
    case 5:
        linealFilter(src,aux);
        break;
    case 6:
        dilatation(src,aux);
        break;
    case 7:
        erosion(src,aux);
        break;
    }
return aux;
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
/*
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

*/
void MainWindow::closeEvent(QCloseEvent *event)
{
  //  pixelTDialog.close();
    //lFilterDialog.close();
    //operOrderDialog.close();
    event->accept();
}
