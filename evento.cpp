//string cin cout
#include <iostream>

//clase para el manejo de eventos
class Evento {

	std::string titulo;
	std::string descripcion;
	std::string fecha;
	int inicio_horas;
	int inicio_minutos;
	int duracion_horas;
	int duracion_minutos;
	//clase lugar pendiente de abstraer
	//lista de participantes pendiente de implementar

public:

	Evento(int inicio_horas, int inicio_minutos): 
		inicio_horas(inicio_horas),
		inicio_minutos(inicio_minutos) {

			//hacer algo en el constructor aqui

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

    	o << e.inicio_horas << ":" << e.inicio_minutos;
    	return o;

	}

};