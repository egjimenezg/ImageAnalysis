#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>

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
    void convertToRed();

  private:
    void createActions();
    void createMenuBar();
    QLabel *imageLabel;
    QScrollArea* scrollArea;
    QMenu* fileMenu;
    QImage* image;
    QPushButton *changeColor;

    /*Actions of the menu*/
    QAction *openAction;
    QAction *changeRed;

};

#endif // IMAGEWINDOW_H
