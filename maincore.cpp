#include <iostream>
#include <string>
#include "dia.cpp"
//#include "persona.cpp"
//#include "lugar.cpp"
//#include "simplelist.cpp"
//#include "doublelist.cpp"

class NuevoEvento {

public:

    Evento* evento;
    Dia* dia;
    Persona* persona;

    NuevoEvento(): evento(0), dia(0), persona(0){}
    ~NuevoEvento();

};

class MainCore {

public:

    CircularDoubleList<Dia>* dias;
    DoubleList<Persona>* contactos;
    SimpleList<Lugar>* lugares;
    NuevoEvento* temp;

    MainCore() {

        dias = new CircularDoubleList<Dia>(1);
        contactos = new DoubleList<Persona>(1);
        lugares = new SimpleList<Lugar>(0);

    }

    ~MainCore();

    bool addDia(int dia, int mes, int anno) {

        temp = new NuevoEvento();
        temp->dia = dias->get(new Dia(dia, mes, anno));

        if (0 == temp->dia) {

            temp->dia = new Dia(dia, mes, anno);
            dias->add(temp->dia);

        }

        return 1;

    }

    bool addEvento(
            int inicio_horas,
            int inicio_minutos,
            std::string titulo="",
            std::string descripcion="",
            int duracion_horas=0,
            int duracion_minutos=0
            ) {

        if (0 == temp->dia) return 0;

        temp->evento = temp->dia->eventos->get(new Evento(inicio_horas, inicio_minutos));

        if (0 != temp->evento) return 0;

        temp->evento = temp->dia->eventos->add(new Evento(
                                                   inicio_horas,
                                                   inicio_minutos,
                                                   titulo,
                                                   descripcion,
                                                   std::to_string(temp->dia->dia) + "/" + std::to_string(temp->dia->mes) + "/" + std::to_string(temp->dia->anno),
                                                   duracion_horas,
                                                   duracion_minutos
                                                   ));
        return 1;

    }

    bool addParticipante(Persona* participante) {

        if (0 == temp->dia || 0 == temp->evento) return 0;

        temp->persona = temp->evento->participantes->get(participante);

        if (0 != temp->persona) return 0;

        temp->persona = temp->evento->participantes->add(participante);

        return true;

    }

    bool addUbicacion(Lugar* lugar) {

        if (0 == temp->dia || 0 == temp->evento) return 0;

        temp->evento->lugar = lugar;

        return 1;

    }

    bool addContacto(std::string alias, std::string nombre, std::string apellido, std::string email="", std::string telefono="", int edad=0) {

        Persona* added = new Persona(alias, nombre, apellido, email, telefono, edad);

        ordenar(NOMBRE);
        if (0 != contactos->get(added)) return 0;
        ordenar(APELLIDO);
        if (0 != contactos->get(added)) return 0;
        ordenar(ALIAS);
        if (0 != contactos->get(added)) return 0;

        contactos->add(added);
        return 1;

    }

    void ordenar(int tipo){

        Persona* p = contactos->next();
        DoubleList<Persona>* temp = new DoubleList<Persona>(1);
        while (0 != p) {

            p->orderBy(tipo);
            temp->add(p);
            p = contactos->next();

        }

        contactos = temp;

    }

    bool addLugar(std::string nombre, std::string direccion, double latitud, double longitud) {

        Lugar* added = new Lugar(nombre, direccion, latitud, longitud);

        if (0 != lugares->get(added)) return 0;

        lugares->add(added);
        return 1;

    }

};
