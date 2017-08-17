#include <iostream>
#include "doublelist.cpp"
#include "evento.cpp"

int main() {

	CircularDoubleList<Evento>* lista = new CircularDoubleList<Evento>(true);

	lista->add(new Evento(5, 25));
	lista->add(new Evento(5, 32));
	lista->add(new Evento(4, 26));
	lista->add(new Evento(5, 23));
	lista->add(new Evento(5, 59));
	lista->add(new Evento(5, 45));
	lista->add(new Evento(5, 29));
	lista->add(new Evento(6, 25));

	lista->print();
	std::cout << lista->size << std::endl;

	lista->remove(new Evento(6,25));

	lista->print();
	std::cout << lista->size << std::endl;

	return 0;

}