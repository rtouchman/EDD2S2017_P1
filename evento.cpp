//string cin cout
#include <iostream>
#include "lugar.cpp"
#include "persona.cpp"
#include "doublelist.cpp"

//clase para el manejo de eventos
class Evento {

public:

	std::string titulo;
	std::string descripcion;
	std::string fecha;
	int inicio_horas;
	int inicio_minutos;
	int duracion_horas;
    int duracion_minutos;
    Lugar* lugar;
    DoubleList<Persona>* participantes;

    Evento (
            int inicio_horas,
            int inicio_minutos,
            std::string titulo="",
            std::string descripcion="",
            std::string fecha="",
            int duracion_horas=0,
            int duracion_minutos=0
    ):
		inicio_horas(inicio_horas),
        inicio_minutos(inicio_minutos),
        titulo(titulo),
        descripcion(descripcion),
        fecha(fecha),
        duracion_horas(duracion_horas),
        duracion_minutos(duracion_minutos),
        lugar(0),
        participantes(new DoubleList<Persona>(1))
    {}

    ~Evento(){
        //destruir aqui
    }

    void setLugar(Lugar* lugar){

        this->lugar = lugar;

    }

    void ordenar(int tipo){

        Persona* p = participantes->next();
        DoubleList<Persona>* temp = new DoubleList<Persona>(1);
        while (0 != p) {

            p->orderBy(tipo);
            temp->add(p);
            p = participantes->next();

        }

        participantes = temp;

    }

    void print() {

        participantes->print();

    }

	bool operator ==(const Evento &e) const{

		return inicio_horas == e.inicio_horas && inicio_minutos == e.inicio_minutos;

	}

	bool operator <=(const Evento &e) const{

		if (inicio_horas == e.inicio_horas) return inicio_minutos <= e.inicio_minutos;
		return inicio_horas < e.inicio_horas;

	}

	bool operator >=(const Evento &e) const{

		if (inicio_horas == e.inicio_horas) return inicio_minutos >= e.inicio_minutos;
		return inicio_horas > e.inicio_horas;

	}

	bool operator <(const Evento &e) const{

		if (inicio_horas == e.inicio_horas) return inicio_minutos < e.inicio_minutos;
		return inicio_horas < e.inicio_horas;

	}

	bool operator >(const Evento &e) const{

		if (inicio_horas == e.inicio_horas) return inicio_minutos > e.inicio_minutos;
		return inicio_horas > e.inicio_horas;

	}

	friend std::ostream& operator << (std::ostream &o,const Evento &e){

        o  << "Evento: " << e.titulo << " - " << e.inicio_horas << ":" << e.inicio_minutos  << " - " << e.descripcion;
    	return o;

	}

};
