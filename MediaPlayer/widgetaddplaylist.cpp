#include "widgetaddplaylist.h"

WidgetAddPlaylist::WidgetAddPlaylist(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(240,120);
    createItems();
}

void WidgetAddPlaylist::createItems()
{
    mLabelInfo = new QLabel("Enter playlist name");
    mTextInput = new QLineEdit;

    mButtonCreate = new QPushButton("Create");
    mButtonCreate->setFixedSize(100, 30);
    QObject::connect(mButtonCreate, &QPushButton::clicked, this, &WidgetAddPlaylist::onButtonAddClicked);

    mButtonCancel = new QPushButton("Cancel");
    mButtonCancel->setFixedSize(100, 30);
    QObject::connect(mButtonCancel, &QPushButton::clicked, this, &WidgetAddPlaylist::close);

    mLayoutForButtons = new QHBoxLayout;
    mLayoutForButtons->addWidget(mButtonCreate);
    mLayoutForButtons->addWidget(mButtonCancel);

    mMainLayout = new QVBoxLayout;
    mMainLayout->addWidget(mLabelInfo);
    mMainLayout->addWidget(mTextInput);
    mMainLayout->addLayout(mLayoutForButtons);

    this->setLayout(mMainLayout);
}

void WidgetAddPlaylist::onButtonAddClicked()
{
    if (mTextInput->text() == "")
    {
        QMessageBox::information(this, "Playlist", "Input playlist name!");
        return;
    }

    emit playListCreated(mTextInput->text());
    mTextInput->setText("");
    this->close();
}
