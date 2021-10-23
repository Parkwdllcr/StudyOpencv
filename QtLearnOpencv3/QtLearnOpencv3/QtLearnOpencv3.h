#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QBuffer>
#include <QApplication>
#include <QFileDialog>
#include "ClOpencvAndQt.h"
#include "ui_QtLearnOpencv3.h"



class QtLearnOpencv3 : public QMainWindow
{
    Q_OBJECT

public:
    QtLearnOpencv3(QWidget *parent = Q_NULLPTR);

private:
    void    openImage();
    void    showImage(QString showpicture,QLabel* QshowLabel);
    bool    saveImage(const QString &filename);

private:
    QImage      QshowPicture;
    QImage      QresPicture;

private slots:
    void on_seclectPicturePathPBTN_clicked();
    void on_showPicturePBTN_clicked();
    void on_SavePicturePBTN_clicked();
private:
    Ui::QtLearnOpencv3Class ui;
};
