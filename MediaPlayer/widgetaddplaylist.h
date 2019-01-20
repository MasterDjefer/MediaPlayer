#ifndef WIDGETADDPLAYLIST_H
#define WIDGETADDPLAYLIST_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

class WidgetAddPlaylist : public QDialog
{
    Q_OBJECT
public:
    explicit WidgetAddPlaylist(QWidget *parent = 0);

private:
    QLabel *mLabelInfo;
    QLineEdit *mTextInput;
    QPushButton *mButtonCreate;
    QPushButton *mButtonCancel;
    QHBoxLayout *mLayoutForButtons;
    QVBoxLayout *mMainLayout;

private:
    void createItems();

signals:
    void playListCreated(QString playlistName);

private slots:
    void onButtonAddClicked();
};

#endif // WIDGETADDPLAYLIST_H
