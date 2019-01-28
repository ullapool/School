#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include  <QKeyEvent>
#include <QString>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QString guessWord = "mama";
    QVector<QString> keyStrokes;
    int getNumberOfFailures();
    void refreshWord();
    void refreshNumbersOfFailures();

};

#endif // MAINWINDOW_H
