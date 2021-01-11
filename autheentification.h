#ifndef AUTHEENTIFICATION_H
#define AUTHEENTIFICATION_H

#include <QMainWindow>

namespace Ui {
class autheentification;
}

class autheentification : public QMainWindow
{
    Q_OBJECT

public:
    explicit autheentification(QWidget *parent = nullptr);
    ~autheentification();

private:
    Ui::autheentification *ui;
};

#endif // AUTHEENTIFICATION_H
