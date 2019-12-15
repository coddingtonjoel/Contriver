#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fontBox_currentFontChanged(const QFont &f);

    void on_fontSizeBox_valueChanged(int arg1);

    void on_boldButton_toggled(bool checked);

    void on_italicButton_toggled(bool checked);

    void on_leftAllignButton_toggled(bool checked);

    void on_centerAllignButton_toggled(bool checked);

    void on_rightAllignButton_toggled(bool checked);

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
