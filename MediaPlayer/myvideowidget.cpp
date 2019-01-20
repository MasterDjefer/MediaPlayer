#include "myvideowidget.h"

MyVideoWidget::MyVideoWidget(WidgetControls *w, QWidget *parent) : QVideoWidget(parent),
                            mWidgetControls(w), isControlsShow(false)
{
    this->setMouseTracking(true);
}

void MyVideoWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        emit leftMouseClicked();
    }
}

void MyVideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClicked();
}

void MyVideoWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Escape:
            emit escapePressed();
            break;
        case Qt::Key_Space:
            emit spacePressed();
            break;
        case Qt::Key_Up:
            emit upPressed();
            break;
        case Qt::Key_Down:
            emit downPressed();
            break;
        case Qt::Key_Left:
            emit leftPressed();
            break;
        case Qt::Key_Right:
            emit rightPressed();
            break;
    }
}

void MyVideoWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (this->isFullScreen())
    {
        if (event->y() >= QApplication::desktop()->screenGeometry().height() - mWidgetControls->height())
        {
            showControls();
        }
        else
        {
            hideControls();
        }
    }
}

