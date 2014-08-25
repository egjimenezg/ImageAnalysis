#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

class ImageWindow : public QMainWindow
{
    Q_OBJECT

  public:
    ImageWindow();
    ~ImageWindow();

  private slots:
    void openImage();

  private:
    void createActions();
    void createMenuBar();
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QMenu *fileMenu;
    /*Actions of the menu*/
    QAction *openAction;

};

#endif // IMAGEWINDOW_H
