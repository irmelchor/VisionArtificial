#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <imgviewer.h>

#include <QFileDialog>
#include <QPixmap>
#include <QToolTip>
#include <QPoint>
#include <QString>


using namespace cv;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer timer;

    VideoCapture *cap;
    ImgViewer *visorS, *visorD;
    Mat colorImage, grayImage;
    Mat destColorImage, destGrayImage;
    bool winSelected;
    Rect imageWindow;
    bool colorSelected;

    const int numObjetos = 3;
    const int numEscalas = 3;
    typedef std::vector<KeyPoint> kplist;
    Ptr<ORB> detector;
    Ptr<BFMatcher> matcher;
    std::vector<std::vector<kplist>> objectKP;
    std::vector<std::vector<Mat>> objectDesc;
    std::vector<Mat> objectWins;
    std::vector<int> colect2Object;
    std::vector<float> escalas;


public slots:
    void compute();
    void start_stop_capture(bool start);
    void change_color_gray(bool color);
    /********************/

    void loadFromFile(/*bool load*/);
    void saveToFile();
    void copyChannels();
    void copyWindow();
    void resizeWin();
    void enlargeWin();
    void pixelValue(QPointF p);

    void actualizarColeccion();
    void addObj();
    void delObj(int indice);
    void mostrar(int indice);

    /********************/
    void selectWindow(QPointF p, int w, int h);
    void deselectWindow(QPointF p);

};


#endif // MAINWINDOW_H
