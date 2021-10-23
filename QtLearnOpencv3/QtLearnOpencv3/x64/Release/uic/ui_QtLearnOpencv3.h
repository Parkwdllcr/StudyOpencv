/********************************************************************************
** Form generated from reading UI file 'QtLearnOpencv3.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLEARNOPENCV3_H
#define UI_QTLEARNOPENCV3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLearnOpencv3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtLearnOpencv3Class)
    {
        if (QtLearnOpencv3Class->objectName().isEmpty())
            QtLearnOpencv3Class->setObjectName(QString::fromUtf8("QtLearnOpencv3Class"));
        QtLearnOpencv3Class->resize(600, 400);
        menuBar = new QMenuBar(QtLearnOpencv3Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtLearnOpencv3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtLearnOpencv3Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtLearnOpencv3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtLearnOpencv3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtLearnOpencv3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtLearnOpencv3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtLearnOpencv3Class->setStatusBar(statusBar);

        retranslateUi(QtLearnOpencv3Class);

        QMetaObject::connectSlotsByName(QtLearnOpencv3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtLearnOpencv3Class)
    {
        QtLearnOpencv3Class->setWindowTitle(QCoreApplication::translate("QtLearnOpencv3Class", "QtLearnOpencv3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLearnOpencv3Class: public Ui_QtLearnOpencv3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLEARNOPENCV3_H
