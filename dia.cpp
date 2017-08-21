//string cin cout
#include <iostream>
#include<simplelist.cpp>
#include<evento.cpp>

//clase para el manejo de eventos
class Dia {

public:

    int dia;
    int mes;
    int anno;

    SimpleList<Evento>* eventos;

    Dia(int dia, int mes, int anno):
        dia(dia),
        mes(mes),
        anno(anno){

        eventos = new SimpleList<Evento>(1);

	}

    ~Dia();

    bool operator ==(const Dia &d) const{

        return dia == d.dia && mes == d.mes && anno == d.anno;

	}

    bool operator <=(const Dia &d) const{

        if (anno == d.anno)
            if(mes == d.mes)
                return dia <= d.dia;
            else
                return mes < d.mes;
        return anno < d.anno;

	}

    bool operator >=(const Dia &d) const{

        if (anno == d.anno)
            if(mes == d.mes)
                return dia >= d.dia;
            else
                return mes > d.mes;
        return anno > d.anno;

	}

    bool operator <(const Dia &d) const{

        if (anno == d.anno)
            if(mes == d.mes)
                return dia < d.dia;
            else
                return mes < d.mes;
        return anno < d.anno;

	}

    bool operator >(const Dia &d) const{

        if (anno == d.anno)
            if(mes == d.mes)
                return dia > d.dia;
            else
                return mes > d.mes;
        return anno > d.anno;

	}

    friend std::ostream& operator << (std::ostream &o,const Dia &d){

        o << "Día: " << d.dia << "/" << d.mes << "/" << d.anno;
    	return o;

	}

};
