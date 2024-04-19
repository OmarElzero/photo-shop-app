// # File: CS112_A3_part3_S3_20230263_S16_20230260_S19_20230273.zip

/*
* Purpose: Desktop Application for image processing
*/

/* Author: Omar Mohammed Abedelmoez
*   ID: 20230263
*   filter Program : Black && White - Flip Image - Crop - Resize - Purple - inferared - Zombie -Demon
/** Author: Omar Awad Saber Hegazi
*   ID: 20230260
*    filter Program : Gray scale - Merge filter - Skew -Old tv - Darken & Lighten - Detect Edges
/** Author: Amr Khaled Mohammed El sayed
*   ID: 20230273
*   filter Program : Invert Image - Rotate Image - Blur - Frame - Oilpainting - wanuo
*   /********\/
* every on impelment his filters in here
* we all contributed in design
* mainwindow.cpp: file that has the basic work for slots
* Filters.h: a header file that contains All Filters
*version 3.0
*=============================================================================
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Image_Class.h"
#include "Filters.h"

int count = 0;
Image temp;
Image Amr;
QString undo;

int angle=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    undo="undo.jpg";
    save = "saved.jpg";
    ui->Horezintal->hide();
    ui->Vertical->hide();
    ui->Diemnsions->hide();
    ui->StartPoints->hide();
    ui->labeltext->hide();
    ui->labeltext2->hide();
    ui->Apply->hide();
    ui->horizontalSlider->hide();
    ui->slaydervalue->hide();
    ui->filtername->hide();
    ui->filtername_2->hide();
    ui->Apply_2->hide();
    ui->third->hide();
    ui->red->hide();
    ui->black->hide();
    ui->green->hide();
    ui->blue->hide();

    // Apply stylesheet
    QString styleSheet = "\
        QPushButton {\
            background-color: #800080; /* Blue */ \
            border: none; \
            color: white; \
            padding: 6px 12px; \
            text-align: center; \
            text-decoration: none; \
            display: inline-block; \
            font-size: 13px; \
            margin: 3px 1px; \
            cursor: pointer; \
            border-radius: 10px; \
    } \
        QPushButton:hover {\
            background-color: #FFF; \
            color: black; \
    } \
        QLabel {\
            color: #333; \
            font-size: 16px; \
    } \
        QLabel#sahla {  \
            box-sizing: border-box; \
            display: flex;   \
            justify-content: space-between; \
            align-items: center;                                  \
            color: #00224D; /*  text color */\
            background-color: none; /* White background color */\
            padding: 0; /* Padding around the text */\
            border-radius: 5px; /* No rounded corners */\
            font-size: 25px; /* Font size */\
            font-weight: bold; /* Bold text */\
            width: 100%;\
            height: 50px;\
            font-family: Arial, sans-serif; /* Use Arial or fallback to sans-serif */\
    }\
                \
        QLabel#label{\
                         \
        font-weight: bold; /* Bold text */\
        width: 100%;\
        height: 50px;\
        color: #00224D;             \
        padding: 0;             \
        font-size: 20px;    \
        box-sizing: border-box; \
        display: flex;   \
        justify-content: space-between; \
        align-items: center;                          \
          }\
        QLabel#label_2{\
                         \
            font-weight: bold; /* Bold text */\
            width: 100%;\
            height: 50px;\
            color: #00224D;             \
            padding: 0;             \
            font-size: 20px;    \
            box-sizing: border-box; \
            display: flex;   \
            justify-content: space-between; \
            align-items: center;                          \
    }\
        QLabel#omar{\
                         \
            font-weight: bold; /* Bold text */\
            width: 100%;\
            height: 50px;\
            color: #00224D;             \
            padding: 0;             \
            font-size: 15px;    \
            box-sizing: border-box; \
            display: flex;   \
            justify-content: space-between; \
            align-items: center;                          \
    }\
        QLabel#amr{\
                         \
            font-weight: bold; /* Bold text */\
            width: 100%;\
            height: 50px;\
            color: #00224D;             \
            padding: 0;             \
            font-size: 15px;    \
            box-sizing: border-box; \
            display: flex;   \
            justify-content: space-between; \
            align-items: center;                          \
    }\
        QLabel#awad{\
                         \
            font-weight: bold; /* Bold text */\
            width: 100%;\
            height: 50px;\
            color: #00224D;             \
            padding: 0;             \
            font-size: 15px;    \
            box-sizing: border-box; \
            display: flex;   \
            justify-content: space-between; \
            align-items: center;                          \
    }\                       \
        QLineEdit {\
            border: 4px solid #4CAF50; /* Green */ \
            border-radius: 8px; \
            padding: 4px; \
    } \
        QSlider::groove:horizontal {\
            border: 1px solid #bbb; \
            background: white; \
            height: 10px; \
            border-radius: 4px; \
    } \
        QSlider::handle:horizontal {\
            background: #4CAF50; /* Green */ \
            border: 1px solid #4CAF50; \
            width: 18px; \
            margin-top: -4px; \
            margin-bottom: -4px; \
            border-radius: 8px; \
    } \
        QLabel#display_before, QLabel#display_after {\
            border: 4px solid #00224D; /* Light Gray */ \
            border-radius: 8px; \
            background-color: #f0f0f0; /* Light Gray */ \
    }";

        // Setting background color for QMainWindow
        styleSheet += "QMainWindow { background-color: #EAD8C0; }";

        this->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::hide()
{
    ui->Horezintal->hide();
    ui->Vertical->hide();
    ui->Diemnsions->hide();
    ui->StartPoints->hide();
    ui->labeltext->hide();
    ui->labeltext2->hide();
    ui->Apply->hide();
    ui->horizontalSlider->hide();
    ui->slaydervalue->hide();
    ui->filtername->hide();
    ui->filtername_2->hide();
    ui->Apply_2->hide();
    ui->third->hide();
    ui->red->hide();
    ui->black->hide();
    ui->green->hide();
    ui->blue->hide();
}
Image savefirst(const QString& filename) {

    // Convert QString to std::string
    std::string filename_std = filename.toStdString();
    Image image(filename_std);
    image.saveImage(save.toStdString());
    image.saveImage(undo.toStdString());
    return image;
}

void MainWindow::on_Load_clicked()
{
    imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap pix(imagePath);
    int w = ui->display_before->width();
    int h = ui->display_before->height();
    ui->display_before->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    savefirst(imagePath);
}


void MainWindow::on_BlackAWhite_clicked()
{
    hide();
    // Call Black_White with imagePath
    Image holder(save.toStdString());
    temp = holder;
    Black_White(save);
    QPixmap pix(save);
    int w = ui->display_after->width();
    int h = ui->display_after->height();
    ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_Vertical_clicked()
{
    Image holder(save.toStdString());
    temp = holder;
    flip_V(save.toStdString());
    QPixmap pix(save);
    int w = ui->display_after->width();
    int h = ui->display_after->height();
    ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_Horezintal_clicked()
{
    Image holder(save.toStdString());
    temp = holder;
    flip_H(save.toStdString());
    QPixmap pix(save);
    int w = ui->display_after->width();
    int h = ui->display_after->height();
    ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    ui->Horezintal->show();
    ui->Vertical->show();
}


void MainWindow::on_Save_clicked() {
    if (ui->Apply_2->text() == "do") {
        Image toresize(save.toStdString());
        QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));
        if (!filePath.isEmpty()) {
            toresize.saveImage(filePath.toStdString());
            QMessageBox::information(this, "Success", "Image saved successfully!");
        } else {
            QMessageBox::warning(this, "Error", "Invalid file path!");
        }
    } else {
        QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));
        QPixmap savePix = ui->display_after->grab();
        Image toresize(save.toStdString());
        if (!filePath.isEmpty()) {
            if (!savePix.isNull()) {
                if (toresize.saveImage(filePath.toStdString())) {
                    QMessageBox::information(this, "Success", "Image saved successfully!");
                } else {
                    QMessageBox::warning(this, "Error", "Failed to save image!");
                }
            } else {
                QMessageBox::warning(this, "Error", "No image to save!");
            }
        } else {
            QMessageBox::warning(this, "Error", "Invalid file path!");
        }
    }
}




void MainWindow::on_Crop_clicked()
{
    hide();
    ui->Apply->setText("Apply Crop");
    ui->labeltext2->setText("Diemnsions(w,h)");
    ui->labeltext->setText("Start Points(x,y)");
    ui->Diemnsions->show();
    ui->StartPoints->show();
    ui->labeltext->show();
    ui->labeltext2->show();
    ui->Apply->show();

    // Get start points from input field
   }


   void MainWindow::on_Apply_clicked()
   {
       if(ui->Apply->text()=="Apply Crop")
       {
           QString startPoint = ui->StartPoints->text();
           QRegularExpression rx("^[0-9]+ [0-9]+$"); // Regular expression to match only numeric values

           if (rx.match(startPoint).hasMatch()) {
               QStringList startPointList = startPoint.split(" ", Qt::SkipEmptyParts);

               if (startPointList.size() == 2) {
                   // Extracting X and Y values
                   int startX = startPointList[0].toInt();
                   int startY = startPointList[1].toInt();

                   // Get dimensions from input field
                   QString dimensions = ui->Diemnsions->text();

                   if (rx.match(dimensions).hasMatch()) {
                       QStringList dimensionsList = dimensions.split(" ", Qt::SkipEmptyParts);

                       if (dimensionsList.size() == 2) {
                           // Extracting width and height values
                           int width = dimensionsList[0].toInt();
                           int height = dimensionsList[1].toInt();

                           imge.loadNewImage(save.toStdString());

                           // Check if the crop region exceeds the image dimensions
                           if (startX + width <= imge.width && startY + height <= imge.height)
                           {
                               // Apply the "Crop" filter using the provided parameters
                               Image holder(save.toStdString());
                               temp = holder;
                               Crop(save.toStdString(), width, height, startX, startY);
                           } else {
                               QMessageBox::critical(this, "Error", "Crop region exceeds image dimensions.");
                               return;
                           }
                       } else {
                           QMessageBox::critical(this, "Error", "Invalid input format for dimensions. Expected format: 'width height'");
                           return;
                       }
                   } else {
                       QMessageBox::critical(this, "Error", "Invalid input for dimensions. Dimensions must be numeric.");
                       return;
                   }
               } else {
                   QMessageBox::critical(this, "Error", "Invalid input format for start points. Expected format: 'x y'");
                   return;
               }
           } else {
               QMessageBox::critical(this, "Error", "Invalid input for start points. Start points must be numeric.");
               return;
           }

           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
       }


       if(ui->Apply->text()=="Apply Resize")
       {
           bool widthOk, heightOk;
           int width = ui->StartPoints->text().toInt(&widthOk);
           int height = ui->Diemnsions->text().toInt(&heightOk);

           if (widthOk && heightOk) {
               // Proceed with resizing
               Image holder(save.toStdString());
               temp = holder;
               Resize(save.toStdString(), width, height);
               QPixmap pix(save);
               int w = ui->display_after->width();
               int h = ui->display_after->height();
               ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
               QMessageBox::information(this, "Title", "Save The photo to see changes in details");
           } else {
               QMessageBox::critical(this, "Error", "Invalid input. Width and height must be numeric.");
           }
       }

       if(ui->Apply->text()=="Apply Oil")
       {
           bool radiusOk, levelOk;
           int radius = ui->StartPoints->text().toInt(&radiusOk);
           int level = ui->Diemnsions->text().toInt(&levelOk);

           if (radiusOk && levelOk) {
               // Proceed with oil painting
               Image holder(save.toStdString());
               temp = holder;
               OilPaintingEffect(save.toStdString(), radius, level);
               QPixmap pix(save);
               int w = ui->display_after->width();
               int h = ui->display_after->height();
               ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           } else {
               QMessageBox::critical(this, "Error", "Invalid input. Radius and level must be numeric.");
           }
       }



   void MainWindow::on_Resize_clicked()
   {
       hide();
       ui->Apply->setText("Apply Resize");
       ui->labeltext2->setText("heigh");
       ui->labeltext->setText("width");
       ui->Diemnsions->show();
       ui->StartPoints->show();
       ui->labeltext->show();
       ui->labeltext2->show();
       ui->Apply->show();
       ui->Apply_2->setText("do");


   }


   void MainWindow::on_Clear_clicked()
   {
       hide();
       ui->display_after->clear();
       savefirst(imagePath);

   }


   void MainWindow::on_purple_clicked()
   {
       hide();
       Image holder(save.toStdString());
       temp = holder;
       purple(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

   }


   void MainWindow::on_inferared_clicked()
   {
       hide();
       Image holder(save.toStdString());
       temp = holder;
       inferared(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
   }


   void MainWindow::on_Demon_clicked()
   {
       hide();
       Image holder(save.toStdString());
       temp = holder;
       Demon(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
   }


   void MainWindow::on_rand_clicked()
   {
       hide();
       Image holder(save.toStdString());
       temp = holder;
       rand(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
   }





   void MainWindow::on_Grayscale_clicked()
   {
       hide();
       Image holder(save.toStdString());
       temp = holder;
       gray_scale(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
   }


   void MainWindow::on_DetectEdges_clicked()
   {
       hide();
       Image holder(save.toStdString());
       temp = holder;
      detect_image_edges(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
   }





   void MainWindow::on_horizontalSlider_valueChanged(int value)
   {
       ui->slaydervalue->setText(QString::number(value));
        angle = QString::number(value).toInt();

       qDebug() << "Filter name: " << ui->filtername->text();


   }



   void MainWindow::on_Skew_clicked()
   {
       hide();
       ui->horizontalSlider->show();
       ui->Apply_2->setText("Skew");
       ui->Apply_2->show();
       ui->slaydervalue->show();


   }


   void MainWindow::on_filtername_clicked()
   {
    //for managing frame
       ui->Apply_2->setText("1");
       if (ui->filtername->text()=="Lighten")
       {
           Image holder(save.toStdString());
           temp = holder;
           darken_or_lighten(save.toStdString(),2,angle);
               QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
       }
       if(ui->filtername->text()=="90")
       {
           Image img1(save.toStdString());
           Image holder(save.toStdString());
           temp = holder;
           rotateImage90(img1);
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
       }

       if (ui->filtername->text()=="Normal")
       {
           ui->red->show();
           ui->black->show();
           ui->green->show();
           ui->blue->show();
       }

   }


   void MainWindow::on_DarkenALighten_clicked()
   {
       hide();
       ui->filtername->setText("Lighten");
       ui->filtername_2->setText("Darken");
       ui->horizontalSlider->show();
       ui->slaydervalue->show();
       ui->filtername->show();
       ui->filtername_2->show();

   }


   void MainWindow::on_filtername_2_clicked()
   {
       // managing frame
       ui->Apply_2->setText("2");
       if(ui->filtername_2->text()=="Darken")
       {
           Image holder(save.toStdString());
           temp = holder;
           darken_or_lighten(save.toStdString(),1,angle);
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

       }

       if(ui->filtername_2->text()=="180")
       {
           Image img1(save.toStdString());
           Image holder(save.toStdString());
           temp = holder;
           rotateImage180(img1);
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
       }
       if (ui->filtername_2->text()=="Fancy")
       {
           ui->red->show();
           ui->black->show();
           ui->green->show();
           ui->blue->show();
       }

   }


   void MainWindow::on_Blur_clicked()
   {
       hide();
       ui->horizontalSlider->show();
       ui->slaydervalue->show();
       ui->Apply_2->setText("Blur");
       ui->Apply_2->show();


   }


   void MainWindow::on_Apply_2_clicked()
   {
       if(ui->Apply_2->text()=="Skew")
       {
           Image holder(save.toStdString());
           temp = holder;
           skewing_filter(save.toStdString(), angle);
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
       }
       if(ui->Apply_2->text()=="Blur")
       {
           Image holder(save.toStdString());
           temp = holder;
           Blur(save.toStdString(), angle);
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
       }
   }


   void MainWindow::on_Invert_clicked()
   {
       Image holder(save.toStdString());
       temp = holder;
       invertColors(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

   }


   void MainWindow::on_Blur_2_clicked()
   {
       hide();
       ui->third->setText("270");
       ui->filtername->setText("90");
       ui->filtername_2->setText("180");
       ui->third->show();
       ui->filtername->show();
       ui->filtername_2->show();

   }


   void MainWindow::on_third_clicked()
   {
       Image holder(save.toStdString());
       temp = holder;
       Image img1(save.toStdString());
       rotateImage270(img1);
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

   }


   void MainWindow::on_wanou_clicked()
   {
       hide();
       Image holder(save.toStdString());
       temp = holder;
       Filter_13(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

   }


   void MainWindow::on_addframe_clicked()
   {
       hide();
       ui->filtername->setText("Normal");
        ui->filtername_2->setText("Fancy");
       ui->filtername->show();
       ui->filtername_2->show();

   }


   void MainWindow::on_blue_clicked()
   {

       if (ui->Apply_2->text()=="2")
       {
           Image holder(save.toStdString());
           temp = holder;
           addFancyFrame(save.toStdString(),20,"blue","White");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply_2->setText("3");
       }

       if (ui->Apply_2->text()=="1")
       {
           Image holder(save.toStdString());
           temp = holder;
           addNormalFrame(save.toStdString(),20,"blue");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply_2->setText("3");
       }
   }


   void MainWindow::on_black_clicked()
   {
       if (ui->Apply_2->text()=="2")
       {
           Image holder(save.toStdString());
           temp = holder;
           addFancyFrame(save.toStdString(),20,"black","White");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply->setText("3");
       }

       if (ui->Apply_2->text()=="1")
       {
           Image holder(save.toStdString());
           temp = holder;
           addNormalFrame(save.toStdString(),20,"black");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply_2->setText("3");
       }

   }


   void MainWindow::on_red_clicked()
   {
       if (ui->Apply_2->text()=="2")
       {
           Image holder(save.toStdString());
           temp = holder;
           addFancyFrame(save.toStdString(),20,"red","White");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply_2->setText("3");
       }

       if (ui->Apply_2->text()=="1")
       {
           Image holder(save.toStdString());
           temp = holder;
           addNormalFrame(save.toStdString(),20,"red");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply_2->setText("3");
       }
   }


   void MainWindow::on_green_clicked()
   {
       if (ui->Apply_2->text()=="2")
       {
           Image holder(save.toStdString());
           temp = holder;
           addFancyFrame(save.toStdString(),20,"green","White");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply_2->setText("3");
       }

       if (ui->Apply_2->text()=="1")
       {
           Image holder(save.toStdString());
           temp = holder;
           addNormalFrame(save.toStdString(),20,"green");
           QPixmap pix(save);
           int w = ui->display_after->width();
           int h = ui->display_after->height();
           ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
           ui->Apply_2->setText("3");
       }
   }


   void MainWindow::on_oilpainting_clicked()
   {
       hide();
       ui->Apply->setText("Apply Oil");
       ui->labeltext->setText("level");
       ui->labeltext2->setText("radious");
       ui->StartPoints->show();
       ui->Diemnsions->show();
       ui->Apply->show();
       ui->labeltext->show();
       ui->labeltext2->show();

   }


   void MainWindow::on_oldtv_clicked()
   {
       Image holder(save.toStdString());
       temp = holder;
       old_tv_filter(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

   }


   void MainWindow::on_Merge_clicked()
   {
       QString nametomerge = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));
       Image holder(save.toStdString());
       temp = holder;
       merging_images_filter(save.toStdString(),nametomerge.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));


   }



   void MainWindow::on_undo_clicked()
   {
       temp.saveImage("undo.jpg");
       Image holder(save.toStdString());
       Amr = holder;
       temp.saveImage(save.toStdString());
       QPixmap pix("undo.jpg");
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
   }


   void MainWindow::on_Redo_clicked()
   {
       save="saved.jpg";
       Amr.saveImage(save.toStdString());
       QPixmap pix(save);
       int w = ui->display_after->width();
       int h = ui->display_after->height();
       ui->display_after->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
   }

