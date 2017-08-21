//string cin cout
#include <iostream>
#include <string>

#define NOMBRE 0
#define APELLIDO 1
#define ALIAS 2

//clase para el manejo de eventos
class Persona {

public:

    std::string alias;
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string telefono;
    int edad;
    int orderedBy;

    Persona(std::string alias, std::string nombre, std::string apellido, std::string email="", std::string telefono="", int edad=0):
        alias(alias),
        nombre(nombre),
        apellido(apellido),
        email(email),
        telefono(telefono),
        edad(edad),
        orderedBy(0){}

    ~Persona();

    void orderBy(int orderedBy){

        this->orderedBy = orderedBy;

    }

    bool operator ==(const Persona &p) const{

        switch (orderedBy) {

        case NOMBRE:
            return nombre.compare(p.nombre) == 0;

        case APELLIDO:
            return apellido.compare(p.apellido) == 0;

        case ALIAS:
            return alias.compare(p.alias) == 0;

        }

	}

    bool operator <=(const Persona &p) const{

        switch (orderedBy) {

        case NOMBRE:
            return nombre.compare(p.nombre) <= 0;

        case APELLIDO:
            return apellido.compare(p.apellido) <= 0;

        case ALIAS:
            return alias.compare(p.alias) <= 0;

        }

	}

    bool operator >=(const Persona &p) const{

        switch (orderedBy) {

        case NOMBRE:
            return nombre.compare(p.nombre) >= 0;

        case APELLIDO:
            return apellido.compare(p.apellido) >= 0;

        case ALIAS:
            return alias.compare(p.alias) >= 0;

        }

	}

    bool operator <(const Persona &p) const{

        switch (orderedBy) {

        case NOMBRE:
            return nombre.compare(p.nombre) < 0;

        case APELLIDO:
            return apellido.compare(p.apellido) < 0;

        case ALIAS:
            return alias.compare(p.alias) < 0;

        }

	}

    bool operator >(const Persona &p) const{

        switch (orderedBy) {

        case NOMBRE:
            return nombre.compare(p.nombre) > 0;

        case APELLIDO:
            return apellido.compare(p.apellido) > 0;

        case ALIAS:
            return alias.compare(p.alias) > 0;

        }

	}

    friend std::ostream& operator << (std::ostream &o,const Persona &p){

        switch (p.orderedBy) {

        case NOMBRE:
            o << "Persona nombre: " << p.nombre;
            break;

        case APELLIDO:
            o << "Persona apellido: " << p.apellido;
            break;

        case ALIAS:
            o << "Persona alias: " << p.alias;
            break;

        }

	}

};
