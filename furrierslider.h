#ifndef FURRIERSLIDER_H
#define FURRIERSLIDER_H

#include <QWidget>

#include "ui_furrierslider.h"

class furrierSlider : public QWidget, public Ui::furrierSlider
{
    Q_OBJECT

public:
    explicit furrierSlider(QWidget *parent = 0);
};

#endif // FURRIERSLIDER_H
