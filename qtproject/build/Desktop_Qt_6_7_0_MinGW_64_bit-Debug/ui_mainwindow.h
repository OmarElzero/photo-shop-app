/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *BlackAWhite;
    QPushButton *pushButton_2;
    QPushButton *Crop;
    QPushButton *Resize;
    QPushButton *Load;
    QPushButton *Save;
    QLabel *display_before;
    QLabel *display_after;
    QPushButton *Vertical;
    QPushButton *Horezintal;
    QLineEdit *StartPoints;
    QLineEdit *Diemnsions;
    QLabel *labeltext;
    QLabel *labeltext2;
    QPushButton *Apply;
    QPushButton *Clear;
    QPushButton *purple;
    QPushButton *inferared;
    QPushButton *Demon;
    QPushButton *rand;
    QPushButton *Grayscale;
    QPushButton *DetectEdges;
    QPushButton *Skew;
    QPushButton *DarkenALighten;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *slaydervalue;
    QPushButton *filtername;
    QPushButton *filtername_2;
    QPushButton *Blur;
    QPushButton *Apply_2;
    QPushButton *Invert;
    QPushButton *Blur_2;
    QPushButton *third;
    QPushButton *wanou;
    QPushButton *addframe;
    QPushButton *red;
    QPushButton *black;
    QPushButton *blue;
    QPushButton *green;
    QPushButton *oilpainting;
    QPushButton *oldtv;
    QPushButton *Merge;
    QLabel *omar;
    QLabel *awad;
    QLabel *amr;
    QLabel *sahla;
    QPushButton *undo;
    QPushButton *Redo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(926, 701);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        BlackAWhite = new QPushButton(centralwidget);
        BlackAWhite->setObjectName("BlackAWhite");
        BlackAWhite->setGeometry(QRect(660, 100, 121, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(790, 100, 131, 41));
        Crop = new QPushButton(centralwidget);
        Crop->setObjectName("Crop");
        Crop->setGeometry(QRect(660, 150, 121, 41));
        Resize = new QPushButton(centralwidget);
        Resize->setObjectName("Resize");
        Resize->setGeometry(QRect(790, 150, 131, 41));
        Load = new QPushButton(centralwidget);
        Load->setObjectName("Load");
        Load->setGeometry(QRect(430, 10, 111, 41));
        Save = new QPushButton(centralwidget);
        Save->setObjectName("Save");
        Save->setGeometry(QRect(570, 10, 111, 41));
        display_before = new QLabel(centralwidget);
        display_before->setObjectName("display_before");
        display_before->setGeometry(QRect(20, 210, 231, 241));
        display_after = new QLabel(centralwidget);
        display_after->setObjectName("display_after");
        display_after->setGeometry(QRect(330, 210, 231, 241));
        Vertical = new QPushButton(centralwidget);
        Vertical->setObjectName("Vertical");
        Vertical->setGeometry(QRect(50, 530, 93, 29));
        Horezintal = new QPushButton(centralwidget);
        Horezintal->setObjectName("Horezintal");
        Horezintal->setGeometry(QRect(180, 530, 93, 29));
        StartPoints = new QLineEdit(centralwidget);
        StartPoints->setObjectName("StartPoints");
        StartPoints->setGeometry(QRect(40, 500, 113, 26));
        Diemnsions = new QLineEdit(centralwidget);
        Diemnsions->setObjectName("Diemnsions");
        Diemnsions->setGeometry(QRect(170, 500, 113, 26));
        labeltext = new QLabel(centralwidget);
        labeltext->setObjectName("labeltext");
        labeltext->setGeometry(QRect(50, 470, 111, 21));
        labeltext2 = new QLabel(centralwidget);
        labeltext2->setObjectName("labeltext2");
        labeltext2->setGeometry(QRect(180, 470, 121, 21));
        Apply = new QPushButton(centralwidget);
        Apply->setObjectName("Apply");
        Apply->setGeometry(QRect(90, 540, 121, 41));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName("Clear");
        Clear->setGeometry(QRect(700, 10, 101, 41));
        purple = new QPushButton(centralwidget);
        purple->setObjectName("purple");
        purple->setGeometry(QRect(660, 200, 121, 41));
        inferared = new QPushButton(centralwidget);
        inferared->setObjectName("inferared");
        inferared->setGeometry(QRect(790, 200, 131, 41));
        Demon = new QPushButton(centralwidget);
        Demon->setObjectName("Demon");
        Demon->setGeometry(QRect(660, 250, 121, 41));
        rand = new QPushButton(centralwidget);
        rand->setObjectName("rand");
        rand->setGeometry(QRect(790, 250, 131, 41));
        Grayscale = new QPushButton(centralwidget);
        Grayscale->setObjectName("Grayscale");
        Grayscale->setGeometry(QRect(790, 300, 131, 41));
        DetectEdges = new QPushButton(centralwidget);
        DetectEdges->setObjectName("DetectEdges");
        DetectEdges->setGeometry(QRect(660, 300, 121, 41));
        Skew = new QPushButton(centralwidget);
        Skew->setObjectName("Skew");
        Skew->setGeometry(QRect(660, 350, 121, 41));
        DarkenALighten = new QPushButton(centralwidget);
        DarkenALighten->setObjectName("DarkenALighten");
        DarkenALighten->setGeometry(QRect(790, 350, 131, 41));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(360, 460, 151, 31));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 180, 91, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 179, 91, 31));
        slaydervalue = new QLabel(centralwidget);
        slaydervalue->setObjectName("slaydervalue");
        slaydervalue->setGeometry(QRect(520, 460, 63, 20));
        filtername = new QPushButton(centralwidget);
        filtername->setObjectName("filtername");
        filtername->setGeometry(QRect(340, 490, 93, 29));
        filtername_2 = new QPushButton(centralwidget);
        filtername_2->setObjectName("filtername_2");
        filtername_2->setGeometry(QRect(450, 490, 93, 29));
        Blur = new QPushButton(centralwidget);
        Blur->setObjectName("Blur");
        Blur->setGeometry(QRect(660, 400, 121, 41));
        Apply_2 = new QPushButton(centralwidget);
        Apply_2->setObjectName("Apply_2");
        Apply_2->setGeometry(QRect(390, 490, 93, 29));
        Invert = new QPushButton(centralwidget);
        Invert->setObjectName("Invert");
        Invert->setGeometry(QRect(790, 400, 131, 41));
        Blur_2 = new QPushButton(centralwidget);
        Blur_2->setObjectName("Blur_2");
        Blur_2->setGeometry(QRect(660, 450, 121, 41));
        third = new QPushButton(centralwidget);
        third->setObjectName("third");
        third->setGeometry(QRect(390, 530, 93, 29));
        wanou = new QPushButton(centralwidget);
        wanou->setObjectName("wanou");
        wanou->setGeometry(QRect(790, 450, 131, 41));
        addframe = new QPushButton(centralwidget);
        addframe->setObjectName("addframe");
        addframe->setGeometry(QRect(660, 500, 121, 41));
        red = new QPushButton(centralwidget);
        red->setObjectName("red");
        red->setGeometry(QRect(612, 610, 101, 31));
        black = new QPushButton(centralwidget);
        black->setObjectName("black");
        black->setGeometry(QRect(502, 610, 101, 31));
        blue = new QPushButton(centralwidget);
        blue->setObjectName("blue");
        blue->setGeometry(QRect(392, 610, 101, 31));
        green = new QPushButton(centralwidget);
        green->setObjectName("green");
        green->setGeometry(QRect(722, 610, 101, 31));
        oilpainting = new QPushButton(centralwidget);
        oilpainting->setObjectName("oilpainting");
        oilpainting->setGeometry(QRect(790, 500, 131, 41));
        oldtv = new QPushButton(centralwidget);
        oldtv->setObjectName("oldtv");
        oldtv->setGeometry(QRect(790, 550, 131, 41));
        Merge = new QPushButton(centralwidget);
        Merge->setObjectName("Merge");
        Merge->setGeometry(QRect(660, 550, 121, 41));
        omar = new QLabel(centralwidget);
        omar->setObjectName("omar");
        omar->setGeometry(QRect(20, 630, 111, 21));
        awad = new QLabel(centralwidget);
        awad->setObjectName("awad");
        awad->setGeometry(QRect(140, 630, 101, 21));
        amr = new QLabel(centralwidget);
        amr->setObjectName("amr");
        amr->setGeometry(QRect(250, 630, 101, 21));
        sahla = new QLabel(centralwidget);
        sahla->setObjectName("sahla");
        sahla->setGeometry(QRect(10, 0, 251, 41));
        undo = new QPushButton(centralwidget);
        undo->setObjectName("undo");
        undo->setGeometry(QRect(260, 220, 61, 31));
        Redo = new QPushButton(centralwidget);
        Redo->setObjectName("Redo");
        Redo->setGeometry(QRect(260, 290, 61, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 926, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BlackAWhite->setText(QCoreApplication::translate("MainWindow", "Black A White", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        Crop->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        Resize->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        display_before->setText(QString());
        display_after->setText(QString());
        Vertical->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        Horezintal->setText(QCoreApplication::translate("MainWindow", "Herozintal", nullptr));
        labeltext->setText(QCoreApplication::translate("MainWindow", "start points", nullptr));
        labeltext2->setText(QCoreApplication::translate("MainWindow", " Diemnsions", nullptr));
        Apply->setText(QCoreApplication::translate("MainWindow", "Apply Crop", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        purple->setText(QCoreApplication::translate("MainWindow", "purple", nullptr));
        inferared->setText(QCoreApplication::translate("MainWindow", "inferared", nullptr));
        Demon->setText(QCoreApplication::translate("MainWindow", "Demon", nullptr));
        rand->setText(QCoreApplication::translate("MainWindow", "Zompie", nullptr));
        Grayscale->setText(QCoreApplication::translate("MainWindow", "Gray Scale", nullptr));
        DetectEdges->setText(QCoreApplication::translate("MainWindow", "Detect Edges", nullptr));
        Skew->setText(QCoreApplication::translate("MainWindow", "Skew", nullptr));
        DarkenALighten->setText(QCoreApplication::translate("MainWindow", "darken_or_lighten", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Before", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "After", nullptr));
        slaydervalue->setText(QString());
        filtername->setText(QCoreApplication::translate("MainWindow", "Filter name", nullptr));
        filtername_2->setText(QCoreApplication::translate("MainWindow", "opthion", nullptr));
        Blur->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        Apply_2->setText(QCoreApplication::translate("MainWindow", "apply", nullptr));
        Invert->setText(QCoreApplication::translate("MainWindow", "Invert", nullptr));
        Blur_2->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        third->setText(QCoreApplication::translate("MainWindow", "thied", nullptr));
        wanou->setText(QCoreApplication::translate("MainWindow", "wanou", nullptr));
        addframe->setText(QCoreApplication::translate("MainWindow", "Frame", nullptr));
        red->setText(QCoreApplication::translate("MainWindow", "red", nullptr));
        black->setText(QCoreApplication::translate("MainWindow", "black", nullptr));
        blue->setText(QCoreApplication::translate("MainWindow", "blue", nullptr));
        green->setText(QCoreApplication::translate("MainWindow", "green", nullptr));
        oilpainting->setText(QCoreApplication::translate("MainWindow", "Oil Painting", nullptr));
        oldtv->setText(QCoreApplication::translate("MainWindow", "old tv", nullptr));
        Merge->setText(QCoreApplication::translate("MainWindow", "Merge", nullptr));
        omar->setText(QCoreApplication::translate("MainWindow", "OMAR BETAWY", nullptr));
        awad->setText(QCoreApplication::translate("MainWindow", "OMAR AWAD", nullptr));
        amr->setText(QCoreApplication::translate("MainWindow", "AMR KHALED", nullptr));
        sahla->setText(QCoreApplication::translate("MainWindow", "Sahla Bas Sa7la", nullptr));
        undo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        Redo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
