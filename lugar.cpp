//string cin cout
#include <iostream>

//clase para el manejo de eventos
class Lugar {

public:

    std::string nombre;
    std::string direccion;
    double latitud;
    double longitud;

    Lugar(std::string nombre, std::string direccion="", double latitud=0, double longitud=0):
        nombre(nombre),
        direccion(direccion),
        latitud(latitud),
        longitud(longitud){}

    ~Lugar(){}

    bool operator ==(const Lugar &l) const{

        return latitud == l.latitud && longitud == l.longitud;

	}

    bool operator <=(const Lugar &l) const{

        //alguna comparacion para menor o igual
        return 1;

	}

    bool operator >=(const Lugar &l) const{

        //alguna comparacion para mayor o igual
        return 1;

	}

    bool operator <(const Lugar &l) const{

        //alguna comparacion para menor
        return 1;

	}

    bool operator >(const Lugar &l) const{

        //alguna comparacion para mayor
        return 1;

    }

    friend std::ostream& operator << (std::ostream &o,const Lugar &l){

        o << "Lugar: " << l.nombre << ": " << l.direccion;
    	return o;

	}

};
