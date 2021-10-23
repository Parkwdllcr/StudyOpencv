#include "QtLearnOpencv3.h"


QtLearnOpencv3::QtLearnOpencv3(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //connect(ui.seclectPicturePathPBTN, SIGNAL(clicked(bool)), this, SLOT(on_seclectPicturePathPBTN_clicked()));
    //connect(ui.showPicturePBTN, SIGNAL(clicked(bool)), this, SLOT(on_showPicturePBTN_clicked()));
}

void QtLearnOpencv3::openImage()
{
	QString OpenFile;
	OpenFile = QFileDialog::getOpenFileName(this, "please choose an image file", "",
		"Image File(Image File(*.jpg *.png *.bmp *.pgm)");
	ui.picturePathLEDT->setText(OpenFile);
	showImage(OpenFile, ui.srcImage);
}

void QtLearnOpencv3::showImage(QString showpicture, QLabel *QshowLabel)
{
	
	QshowLabel->clear();
	if (!showpicture.isEmpty())
	{
		QSize  lasize = QshowLabel->size();
		QImage image1 = QshowPicture.scaled(lasize, Qt::IgnoreAspectRatio);
		QshowLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
		QshowLabel->setScaledContents(true);
		if (image1.load(showpicture))
			ui.srcImage->setPixmap(QPixmap::fromImage(image1));
		else
			QMessageBox::information(this, tr("显示图片失败"), tr("显示图片失败!!"));
	}
	else
		QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
}


bool QtLearnOpencv3::saveImage(const QString& filename)
{
	QFile file(filename);
	if (!file.open(QIODevice::ReadWrite))
	{
		QMessageBox::warning(this, tr("保存文件"), tr("无法保存文件 %1:\n%2").arg(filename).arg(file.errorString()));
		return false;
	}
	QByteArray ba;
	QBuffer buffer(&ba);
	buffer.open(QIODevice::WriteOnly);
	QresPicture.save(&buffer, "JPG");
	//ui.resImage.save(&buffer, "JPG");
	file.write(ba);
	QMessageBox::information(this, tr("保存文件"), tr("文件已保存至：\n%1").arg(filename));
	return true;
	
}

void QtLearnOpencv3::on_seclectPicturePathPBTN_clicked()
{
    openImage();
}

void QtLearnOpencv3::on_showPicturePBTN_clicked()
{
	
}

void QtLearnOpencv3::on_SavePicturePBTN_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(
		this, "保存图片",
		".",
		"图片 (*.jpg *.bmp *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;所有文件(*.*)");
	if (!fileName.isEmpty())
	{
		saveImage(fileName);
	}
	else
	{
		return;
	}
}
