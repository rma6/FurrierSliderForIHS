#include "furrierslider.h"
#include "qcustomplot.h"
#include "ui_furrierslider.h"

furrierSlider::furrierSlider(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
    sc=0;
    sign=1;

    connect(scButton, SIGNAL(clicked()), this, SLOT(toggle_scButton()));
    connect(signButton, SIGNAL(clicked()), this, SLOT(toggle_signButton()));
    connect(ampSlider, SIGNAL(valueChanged(int)), this, SLOT(furrierSliderReplot()));
    connect(ampSpinBox, SIGNAL(valueChanged(int)), this, SLOT(furrierSliderReplot()));
}

void furrierSlider::setPos(int pos)
{
    posLabel->setText(QString::number(pos));
}

void furrierSlider::setPlot(QCustomPlot *_plot)
{
    plot=_plot;
}

void furrierSlider::setSL(QList<furrierSlider *> *_sl)
{
    sl=_sl;
}

void furrierSlider::toggle_scButton()
{
    scButton->setText(sc?"sin":"cos");
    sc=1-sc;
    furrierSliderReplot();
}

void furrierSlider::toggle_signButton()
{
    signButton->setText(sign==1?"-":"+");
    sign=-sign;
    furrierSliderReplot();
}

void furrierSlider::furrierSliderReplot()
{
    int np=2000;
    QVector<double> x(np), y(np);
    #pragma omp parallel for
    for (int i=0; i<np; i++)
    {
      x[i] = i/(np/(2*M_PI));
      y[i] = furrier(x[i]);
    }

    plot->addGraph();
    plot->graph(0)->setData(x, y);

    plot->xAxis->setLabel("time");
    plot->yAxis->setLabel("amplitude");

    plot->xAxis->setRange(0, 2*M_PI);
    plot->yAxis->rescale();

    plot->replot();
}

double furrierSlider::furrier(double t)
{
    double acc=0;
    for(int i=1; i<=sl->size(); i++)
    {
        acc+=sign*(sc==1?qCos(t*i):qSin(t*i))*sl->at(i-1)->ampSpinBox->value()/10000.0;
    }
    return acc;
}
