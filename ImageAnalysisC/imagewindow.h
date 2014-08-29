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
    void practice1();
    void practice2();

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
    /*Actions of the menu*/
    QAction *openAction;
    QAction *changeRed;

};

#endif // IMAGEWINDOW_H
