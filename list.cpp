#include <iostream>
#include <fstream>
#include <stdlib.h>

#define SL 0
#define DL 1
#define CSL 2
#define CDL 3
#define OSL 4
#define ODL 5
#define OCSL 6
#define OCDL 7

template<class T>
class Node {

	Node<T>* next;
	Node<T>* prev;
	T* value;

public:

	Node(T* value) {



	}

	T* getVal(){

		return value;

	}

};

template<class T>
class List
{

	int type, size;
	Node<T> *head, *tail;

public:

    List(int type_): type(type_), size(0), head(0), tail(0){}
    ~List();
	
    T* add(T* value) {

		if (0 == head) {

            head = new Node<T>(value);
			head->next = head;
			if( type == DL || type == CDL || type == ODL || type == OCDL) head->prev = head;
			tail = head;
			size++;
			return head->getVal();

		} else {

            tail->next = new Node<T>(value);
			tail->next->prev = tail;
			tail = tail->next;
			tail->next = head;
			head->prev = tail;
			size++;
			return tail->getVal();

		}

    }

    T* front(){
        return head;
    }

    T* get(T value) {

		if (0 == head) {

            return 0;

		} else {

			Node<T> *buffer = head;

			do {

                if (value.equals(buffer->getVal()))
                    return buffer->getVal();

				buffer = buffer->next;

			} while (head != buffer);

			return 0;

		}

    }

	T remove(T value) {

		if (0 == head) {

			return 0;

		} else {

			Node<T> *buffer = head;
			bool found = false;

			do {

				if (value == buffer->getVal()) {

					found = true;
					break;

				}

				buffer = buffer->next;

			} while (head != buffer);

			if (! found) {

				return 0;

			} else {


				if (buffer == head and head == tail) {

					head = 0;
					tail = 0;
					buffer->next = 0;
					buffer->prev = 0;
					size--;
					return buffer->getVal();

				}

				if (buffer == head){

					head = head->next;
					head->prev = tail;
					tail->prev = head;
					buffer->next = 0;
					buffer->prev = 0;
					size--;
					return buffer->getVal();

				}

				if (buffer == tail) {

					tail = tail->prev;
					tail->next = head;
					head->prev = tail;
					buffer->next = 0;
					buffer->prev = 0;
					size--;
					return buffer->getVal();

				}

				Node<T> *temp = buffer;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				temp = 0;
				delete(temp);
				size--;
				return buffer->getVal();
			}

		}

    }

    void genGraph(std::string name, T* current = 0) {

		std::ofstream fs ("Graphs/List.dot");

        fs << "digraph List{" << std::endl;
        fs << "rankdir=\"LR\"" << std::endl;

		if(head != 0){

			Node<T> *temp = head;

			do {

				if (current == temp->getVal()){

                    fs << "\"" << temp << "\"[label=\"" << *temp->getVal() << "\" color=\"green\" style=\"radial\" fillcolor=\"green; 0.5: black\"]" << std::endl;

				} else {

                    fs << "\"" << temp << "\"[label=\"" << *temp->getVal() << "\"]" << std::endl;

				}

				if (temp != tail or CSL == type or CDL == type) {

					if (0 != temp->next and (DL == type or CDL == type))
						fs << "\"" << temp << "\"->\"" << temp->next << "\"[dir=\"both\"]" << std::endl;
					else if (0 != temp->next)
						fs << "\"" << temp << "\"->\"" << temp->next << "\"" << std::endl;

				}

				temp = temp->next;

			} while(temp != head);

		}

        fs << "}" << std::endl;
        fs.close();

        fs = std::ofstream("Graphs/genGraph.sh");
        fs << "dot Graphs/List.dot -Tjpg -o Graphs/" << name << ".jpg" << std::endl;
        fs << "xdg-open Graphs/" << name << ".jpg" << std::endl;
        fs.close();
        system("./Graphs/genGraph.sh");

    }

	void print(){

		if(head != 0){

			Node<T> *temp = head;

			do {

				std::cout<<"\nValor: "<<temp->getVal();

				if (0 != temp->prev and (DL == type or CDL == type))
					std::cout << "\n\tAnterior: " << temp->prev->getVal();

				if (0 != temp->next and (CSL == type or CDL == type or temp != tail))
					std::cout << "\n\tSiguiente: " << temp->next->getVal();

				temp = temp->next;

			} while(temp != head);

			std::cout<<std::endl;

		}

    }

};
