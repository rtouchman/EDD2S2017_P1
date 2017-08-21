#include "mainwindow.h"
#include <QApplication>
#include "maincore.cpp"

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/

    MainCore* core = new MainCore();

    core->addContacto("rt", "ricardo", "toca");
    core->addLugar("Mi casa", "direccion de mi casa", 5.23, 6.12);
    core->addDia(15,2,1995);
    core->addEvento(0,0, "Naci yo", "Fui parido", 2,30);
    core->addUbicacion(core->lugares->get(new Lugar("Mi casa")));
    core->addParticipante(core->contactos->get(new Persona("rt", "ricardo", "toca")));

    core->dias->print();
    core->lugares->print();
    core->contactos->print();
    core->dias->front()->eventos->print();

}
