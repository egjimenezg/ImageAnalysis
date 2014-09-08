#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
class QPushButton;

class ImageWindow : public QMainWindow
{
    Q_OBJECT

  public:
    ImageWindow();
    ~ImageWindow();

  private slots:
    void openImage();
    void practice1();
    void practice2();
    void practice3();
    void practice4();
    void practice5();
    void convertToCian();
    void convertToMagenta();
    void converToYellow();

  private:
    void createActions();
    void createMenuBar();
    QLabel *imageLabel;
    QLabel *imageResult;
    QScrollArea* scrollArea;
    QMenu* fileMenu;
    QImage* image;
    QPushButton *practice1Button;
    QPushButton *practice2Button;
    QPushButton *practice3Button;
    QPushButton *practice4Button;
    QPushButton *practice5Button;
    QPushButton *practice6Button;
    QPushButton *cyanButton;
    QPushButton *magentaButton;
    QPushButton *yellowButton;

    /*Actions of the menu*/
    QAction *openAction;
    QAction *changeRed;

};

#endif // IMAGEWINDOW_H
