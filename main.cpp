#include "furrierslider.h"
#include "qcustomplot.h"
#include <QApplication>
#include <QWidget>
#include <QList>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>

double furrier(double t);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* window = new QWidget;
    window->setWindowTitle("IHS Furrier");

    QList<furrierSlider*> sl;
    QVBoxLayout* layout = new QVBoxLayout;
    QHBoxLayout* slidersLayout = new QHBoxLayout;
    layout->addLayout(slidersLayout);

    QCustomPlot* plot = new QCustomPlot;
    layout->addWidget(plot);

    for(int i=0; i<18; i++) //mudar aqui o número de sliders
    {
        furrierSlider* slider = new furrierSlider;
        slider->setPos(i+1);
        slider->setPlot(plot);
        slider->setSL(&sl);
        sl << slider;
        slidersLayout->addWidget(slider);
    }

    window->setLayout(layout);
    window->show();

    return a.exec();
}
