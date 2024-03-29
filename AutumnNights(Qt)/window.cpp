#include "window.h"
#include <QVBoxLayout>
#include "canvas.h"

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle(tr("Autumn Nights"));
    setMinimumSize(800, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    canvas = new Canvas(this);
    canvas->draw();

    mainLayout->addWidget(canvas);

    setLayout(mainLayout);

    //canvas->draw();
}
