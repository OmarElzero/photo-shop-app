#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStringList>
#include <QMainWindow>
#include<QPixmap>
#include<QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QRegularExpression>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding srand() with time
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Load_clicked();

    void hide();
    void on_BlackAWhite_clicked();

    void on_Vertical_clicked();

    void on_Horezintal_clicked();

    void on_pushButton_2_clicked();

    void on_Save_clicked();

    void on_Crop_clicked();

    void on_Apply_clicked();

    void on_Resize_clicked();

    void on_Clear_clicked();

    void on_Demon_clicked();
    void on_purple_clicked();
    void on_inferared_clicked();
    void on_rand_clicked();


    void on_Grayscale_clicked();

    void on_DetectEdges_clicked();


    void on_horizontalSlider_valueChanged(int value);

    void on_Skew_clicked();

    void on_filtername_clicked();

    void on_DarkenALighten_clicked();

    void on_filtername_2_clicked();

    void on_Blur_clicked();

    void on_Apply_2_clicked();

    void on_Invert_clicked();

    void on_Blur_2_clicked();

    void on_third_clicked();

    void on_wanou_clicked();

    void on_addframe_clicked();

    void on_blue_clicked();

    void on_black_clicked();

    void on_red_clicked();

    void on_green_clicked();

    void on_oilpainting_clicked();

    void on_oldtv_clicked();

    void on_Merge_clicked();

    void on_undo_clicked();

    void on_Redo_clicked();

private:
    Ui::MainWindow *ui;
    QString imagePath;
    QString save;

    QPixmap pix;

};
#endif // MAINWINDOW_H
