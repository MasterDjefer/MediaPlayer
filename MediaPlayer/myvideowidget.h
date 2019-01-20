#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H
#include <QVideoWidget>
#include <QMouseEvent>
#include <QKeyEvent>

#include "widgetcontrols.h"

class MyVideoWidget : public QVideoWidget
{
    Q_OBJECT
public:
    MyVideoWidget(WidgetControls *w, QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    bool isControlsShow;
    WidgetControls *mWidgetControls;

signals:
    void showControls();
    void hideControls();
    void leftMouseClicked();
    void doubleClicked();
    void escapePressed();
    void spacePressed();
    void upPressed();
    void downPressed();
    void leftPressed();
    void rightPressed();
};

#endif // MYVIDEOWIDGET_H
