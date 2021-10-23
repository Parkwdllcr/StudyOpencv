/********************************************************************************
** Form generated from reading UI file 'QtLearnOpencv3NbGvnz.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTLEARNOPENCV3NBGVNZ_H
#define QTLEARNOPENCV3NBGVNZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLearnOpencv3Class
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QPushButton *seclectPicturePathPBTN;
    QLineEdit *picturePathLEDT;
    QPushButton *SavePicturePBTN;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *srcImage;
    QLabel *resImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtLearnOpencv3Class)
    {
        if (QtLearnOpencv3Class->objectName().isEmpty())
            QtLearnOpencv3Class->setObjectName(QString::fromUtf8("QtLearnOpencv3Class"));
        QtLearnOpencv3Class->resize(1411, 858);
        centralWidget = new QWidget(QtLearnOpencv3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 641, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        seclectPicturePathPBTN = new QPushButton(layoutWidget);
        seclectPicturePathPBTN->setObjectName(QString::fromUtf8("seclectPicturePathPBTN"));

        formLayout->setWidget(0, QFormLayout::LabelRole, seclectPicturePathPBTN);

        picturePathLEDT = new QLineEdit(layoutWidget);
        picturePathLEDT->setObjectName(QString::fromUtf8("picturePathLEDT"));

        formLayout->setWidget(0, QFormLayout::FieldRole, picturePathLEDT);


        horizontalLayout->addLayout(formLayout);

        SavePicturePBTN = new QPushButton(layoutWidget);
        SavePicturePBTN->setObjectName(QString::fromUtf8("SavePicturePBTN"));

        horizontalLayout->addWidget(SavePicturePBTN);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(803, 150, 591, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(805, 202, 591, 481));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        srcImage = new QLabel(widget);
        srcImage->setObjectName(QString::fromUtf8("srcImage"));

        horizontalLayout_2->addWidget(srcImage);

        resImage = new QLabel(widget);
        resImage->setObjectName(QString::fromUtf8("resImage"));

        horizontalLayout_2->addWidget(resImage);

        QtLearnOpencv3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtLearnOpencv3Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1411, 26));
        QtLearnOpencv3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtLearnOpencv3Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtLearnOpencv3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtLearnOpencv3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtLearnOpencv3Class->setStatusBar(statusBar);

        retranslateUi(QtLearnOpencv3Class);

        QMetaObject::connectSlotsByName(QtLearnOpencv3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtLearnOpencv3Class)
    {
        QtLearnOpencv3Class->setWindowTitle(QCoreApplication::translate("QtLearnOpencv3Class", "QtLearnOpencv3", nullptr));
        seclectPicturePathPBTN->setText(QCoreApplication::translate("QtLearnOpencv3Class", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        SavePicturePBTN->setText(QCoreApplication::translate("QtLearnOpencv3Class", "\344\277\235\345\255\230\345\244\204\347\220\206\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("QtLearnOpencv3Class", "\345\216\237\345\233\276", nullptr));
        label_2->setText(QCoreApplication::translate("QtLearnOpencv3Class", "\345\244\204\347\220\206\345\233\276", nullptr));
        srcImage->setText(QCoreApplication::translate("QtLearnOpencv3Class", "\345\216\237\345\233\276", nullptr));
        resImage->setText(QCoreApplication::translate("QtLearnOpencv3Class", "\345\244\204\347\220\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLearnOpencv3Class: public Ui_QtLearnOpencv3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTLEARNOPENCV3NBGVNZ_H
