#include "furrierslider.h"
#include <QApplication>
#include <QWidget>
#include <Qvector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* window = new QWidget;
    window->setWindowTitle("Furrier Sliders for IHS");
    Ui::furrierSlider ui;
    ui.setupUi(window);

    //window->setLayout();
    window->show();

    return a.exec();
}
