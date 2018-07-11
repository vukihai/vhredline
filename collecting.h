#ifndef COLLECTING_H
#define COLLECTING_H

#include <QDialog>

namespace Ui {
    class Collecting;
}

class Collecting : public QDialog
{
    Q_OBJECT

public:
    explicit Collecting(QWidget *parent = 0);
    ~Collecting();
    void collect();
private:
    Ui::Collecting *ui;
};

#endif // COLLECTING_H
