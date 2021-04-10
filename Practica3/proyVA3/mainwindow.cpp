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

    detector = ORB::create();
    matcher = cv::BFMatcher::create(NORM_HAMMING);
    objectWins.resize(numObjetos);
    objectKP.resize(numObjetos);
    objectDesc.resize(numObjetos);
    escalas.resize(numEscalas);
    escalas[0] = 1.25;
    escalas[1] = 1.;
    escalas[2] = 0.75;
    colect2Object.resize(numObjetos);
    objectMatches.resize(numObjetos);
    for(int i = 0; i<3; i++){
        objectMatches[i].resize(numObjetos);
    }

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
 /*   connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(loadFromFile(void)));
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(saveToFile(void)));
    connect(ui->copyChannelsButton,SIGNAL(clicked(bool)),this,SLOT(copyChannels(void)));
    connect(ui->copyWindowButton,SIGNAL(clicked(bool)),this,SLOT(copyWindow(void)));
    connect(ui->enlargeButton,SIGNAL(clicked(bool)),this,SLOT(enlargeWin(void)));
    connect(ui->resizeButton,SIGNAL(clicked(bool)),this,SLOT(resizeWin(void)));
    connect(visorS,SIGNAL(mouseClick(QPointF)),this,SLOT(pixelValue(QPointF)));
    */
    connect(ui->addObject,SIGNAL(clicked()),this,SLOT(addObj()));
    connect(ui->delObject,SIGNAL(clicked()),this,SLOT(delObj()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),this,SLOT(mostrar(int)));


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
qDebug()<<"Vamos a proceder a detectar la imagen";
    detectarImagen();
    qDebug()<<"Se terminó de detectar la imagen";


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

    /*
    if(!ui->rCheck->isChecked())
        canales[0].setTo(0);

    if(!ui->gCheck->isChecked())
        canales[1].setTo(0);

    if(!ui->bCheck->isChecked())
        canales[2].setTo(0);
      */

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


void MainWindow::actualizarColeccion(){
    matcher->clear();
    int iColeccion=0;
    for(int i = 0; i<numObjetos; i++){
        if(!objectDesc[i].empty()){
            matcher->add(objectDesc[i]);
            colect2Object[iColeccion]=i;
            iColeccion++;
        }
    }
    qDebug("Actualizamos coleccion");

}

void MainWindow::mostrar(int indice){

  destGrayImage.setTo(0);

  if(!objectWins[indice].empty()){
      qDebug("Entramos porque no está vacio");
      double fv = (240-objectWins[indice].rows)/2;
      double fh = (320-objectWins[indice].cols)/2;

      Rect destImageWindow(fh,fv,objectWins[indice].cols,objectWins[indice].rows);


      objectWins[indice].copyTo(destGrayImage(destImageWindow));

  }
  else{
      qDebug("Entramos porque SI está vacio");
      destColorImage.setTo(0);
      destGrayImage.setTo(0);
  }

}

void MainWindow::addObj(){

    std::vector<KeyPoint> kp;
    Mat image;
    Mat desc;
    bool salir=false;

    grayImage(imageWindow).copyTo(objectWins[ui->comboBox->currentIndex()]);

    objectKP[ui->comboBox->currentIndex()].resize(3);
    objectDesc[ui->comboBox->currentIndex()].resize(3);
    for(int i = 0; i<numEscalas && !salir; i++){
       //redimensionar imagen
       cv::resize(objectWins[ui->comboBox->currentIndex()],image,Size(),escalas[i], escalas[i], INTER_LINEAR);
       detector->detectAndCompute(image, cv::noArray(),kp,desc, false);

       if(kp.size()>=10){
           objectKP[ui->comboBox->currentIndex()][i] = kp;
           objectDesc[ui->comboBox->currentIndex()][i] = desc;
       }
       else{
           //salir del bucle
           salir=true;
       }


    }

    //si no hay alguno de los objetos de la colección, llamamos a del, si no
    if(salir){
        qDebug("BORRAMOS!!!!!");
        objectKP[ui->comboBox->currentIndex()].clear();
        qDebug("Borramos kp");
        objectDesc[ui->comboBox->currentIndex()].clear();
        qDebug("Borramos desc");
        actualizarColeccion();
        //delObj(ui->comboBox->currentIndex());
    }
    else{
        qDebug("Hay objetos en la coleccion, estamos en addobj");
        actualizarColeccion();
        mostrar(ui->comboBox->currentIndex());
    }
    /*********************/
    winSelected = false;
}


void MainWindow::delObj(){
    qDebug("Entramos en DELOBJ");
    if(!objectKP[ui->comboBox->currentIndex()].empty()){
        objectWins[ui->comboBox->currentIndex()] = Mat();
        objectKP[ui->comboBox->currentIndex()].clear();
        qDebug("Borramos kp");
        objectDesc[ui->comboBox->currentIndex()].clear();
        qDebug("Borramos desc");
        actualizarColeccion();
        destGrayImage.setTo(0);

     }
}

void MainWindow::detectarImagen(){

   if(!matcher->empty()){
       qDebug()<< "ENTRAMOS EN EL IF DE DETECTAR IMAGEN";
        //detectAndCompute
        //imageKp son los keypoint de grayImage e imageDesc son descriptores de gray image
       qDebug()<<"Procedemos a detectAndCompute";
        detector->detectAndCompute(grayImage, cv::noArray(),imageKP,imageDesc, false);
        //DMatch tiene de atributos los que ponen en mx
        qDebug()<<"Procedemos a knnMatch";
        matches.clear();///
         matcher->knnMatch(imageDesc, matches, 3);

         for(int i = 0; i<numObjetos; i++){
             for(int j = 0; j<numEscalas; j++){
                 objectMatches[i][j].clear();
             }
         }

         //recorremos con 2 for matches
         qDebug()<<"Vamos a recorrer los 2 for matches";
         for(int i = 0; i< matches.size(); i++){
             for(int j = 0; j<matches[i].size(); j++){
                 //qDebug()<<"dentro de los dos for";
                 if(matches[i][j].distance<=40){ ///
                     //qDebug()<<"Estamos dentro de la comprobación de la distancia";
                     int ob = colect2Object[matches[i][j].imgIdx/3];
                     //qDebug()<<"Hemos conseguido el objeto";
                     int scala = matches[i][j].imgIdx%3;
                     //qDebug()<<"Hemos conseguido la escala"<<ob<<scala;

                     objectMatches[ob][scala].push_back(matches[i][j]); //insercion al final
                     //qDebug()<<"Hemos hecho push_back";
                 }
             }
         }
         //HACER AQUI point2f
     //
         std::vector<Point2f> imagePoints;
         std::vector<Point2f> objectPoints;

         std::vector<DMatch> listaFinal;

         for(int obj= 0; obj<numObjetos;obj++){
             //qDebug()<<"Entramos en el primer for. Comprobamos cual tiene más";
             int mejor=0;
             if(objectMatches[obj][0].size() > objectMatches[obj][1].size() && objectMatches[obj][0].size() > objectMatches[obj][2].size())
                 mejor = 0;
             else if(objectMatches[obj][1].size() > objectMatches[obj][2].size())
                 mejor = 1;
             else
                 mejor = 2;

             //qDebug()<<"Terminamos la comparacion";

             listaFinal = objectMatches[obj][mejor];

             if(listaFinal.size()>10) ///
             {

                 for(int i = 0; i<listaFinal.size(); i++){
                     //qDebug()<<"Entramos en el for de recorrer lista final";
                     imagePoints.push_back(imageKP[listaFinal[i].queryIdx].pt);
                     //visorS->drawSquare(QPoint(imageKP[listaFinal[i].queryIdx].pt.x, imageKP[listaFinal[i].queryIdx].pt.y), 3, 3, Qt::blue, true);
                     objectPoints.push_back(objectKP[obj][mejor][listaFinal[i].trainIdx].pt);
                     //visorD->drawSquare(QPoint(objectKP[obj][mejor][listaFinal[i].trainIdx].pt.x, objectKP[obj][mejor][listaFinal[i].trainIdx].pt.y), 3, 3, Qt::blue, true);
                 }
                 qDebug()<<"Ya estamos fuera del for de la lista final"<<listaFinal.size();
                 Mat H = findHomography(objectPoints,imagePoints, LMEDS);

                 //Comprobar si la H está vacía o no
                 qDebug()<<"Comprobamos si la H está vacía";
                 if(!H.empty()){
                     qDebug()<<"H no está vacía";
                     std::vector<Point2f> objectCorners;
                     float h = objectWins[obj].rows * escalas[mejor];  /// h es rows
                     float w = objectWins[obj].cols * escalas[mejor];  /// w es cols
                     objectCorners = {Point2f(0,0), Point2f(w-1,0), Point2f(w-1,h-1), Point2f(0, h-1)};
                     std::vector<Point2f> imageCorners;
                     qDebug()<<"Realizamos la prespective transform";
                     perspectiveTransform(objectCorners, imageCorners, H);
                     qDebug()<<"Terminamos la perspective transform";

                     //recorrer lista imageCorners para mostrar las líneas
                     QPointF punto, punto1;
                     qDebug()<<"Vamos a entrar en el último for";
                     for(int i =0; i<imageCorners.size(); i++){
                         //qDebug()<<"Dentro del último for";
                         punto.setX(imageCorners[i].x);
                         punto.setY(imageCorners[i].y);
                         punto1.setX(imageCorners[(i+1)%4].x);
                         punto1.setY(imageCorners[(i+1)%4].y);
                         QLineF linea(punto, punto1);
                         visorS->drawLine(linea, Qt::red , 5);
                     }
                      qDebug()<<"FUERA DEL ULTIMO FOR";
                 }
                 else{
                    qDebug()<<"LA H está vacía";
                 }
             }
         }
         qDebug()<<"Terminamos FOR COMPLETO";
         //
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

