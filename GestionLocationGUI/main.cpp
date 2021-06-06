#include "gestionlocation.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionLocation w;

    w.show();
    return a.exec();
}
