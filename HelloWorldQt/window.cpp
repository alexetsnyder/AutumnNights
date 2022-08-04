#include "window.h"

#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(200, 160);
    m_counter = 0;

    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 40, 180, 30);

    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 80, 180, 30);

    connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);
    m_button->setCheckable(true);

    //connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));

    connect(this, SIGNAL(counterReached()), QApplication::instance(), SLOT(quit()));
}

void Window::slotButtonClicked(bool checked)
{
    if (checked)
    {
        m_button->setText("Checkded");
    }
    else
    {
        m_button->setText("Hello World!");
    }

    if (++m_counter == 10)
    {
        emit counterReached();
    }
}

