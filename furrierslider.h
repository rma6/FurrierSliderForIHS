#ifndef FURRIERSLIDER_H
#define FURRIERSLIDER_H

#include "qcustomplot.h"

#include "ui_furrierslider.h"

class furrierSlider : public QWidget, public Ui::furrierSlider
{
    Q_OBJECT

public:
    explicit furrierSlider(QWidget *parent = 0);
    void setPlot(QCustomPlot* _plot);
    void setPos(int pos);
    void setSL(QList<furrierSlider*>* _sl);

private:
    Ui::furrierSlider ui;

    bool sc; //0=sin, 1=cos
    int sign;
    QCustomPlot* plot;
    QList<furrierSlider*>* sl;

    double furrier(double t);

private slots:
    void toggle_scButton();
    void toggle_signButton();
    void furrierSliderReplot();

};

#endif // FURRIERSLIDER_H
