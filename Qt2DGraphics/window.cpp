#include "window.h"
#include "canvas.h"

#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle(tr("2D Painting Qt"));

    QVBoxLayout *mainLayout = new QVBoxLayout;

    Canvas *canvas = new Canvas(this);
    QLabel *label = new QLabel(tr("Drawing Example"));
    label->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(canvas);
    setLayout(mainLayout);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), canvas, SLOT(animate()));
    timer->start(50);
}

