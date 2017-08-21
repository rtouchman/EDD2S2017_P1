#include <iostream>
#include <fstream>
#include <stdlib.h>

template<class T>
class SimpleNode {

	T* value;

public:

	SimpleNode<T>* next;
    SimpleNode(T* value): value(value), next(0) {}

	T* getVal(){

		return value;

	}

};

template<class T>
class SimpleList
{

    bool ordered;
    SimpleNode<T> *head, *tail, *current;

public:

	int size;

    SimpleList(bool ordered = 0): ordered(ordered), size(0), head(0), tail(0){}
    ~SimpleList();
	
    T* add(T* value) {

		if (0 == head) {

            head = new SimpleNode<T>(value);
			tail = head;
			size++;
			return head->getVal();

		} else {

			if (ordered) {

				if (*value < *head->getVal()) {

					SimpleNode<T>* inserted = new SimpleNode<T>(value);
					inserted->next = head;
					head = inserted;
					size++;
					return head->getVal();

				} else if (*value > *tail->getVal()) {

					tail->next = new SimpleNode<T>(value);
					tail = tail->next;
					size++;
					return tail->getVal();

				} else {

					SimpleNode<T>* buffer = head;

					while (0 != buffer->next){

                        if (*value <= *buffer->next->getVal()){

							break;

						}

						buffer = buffer->next;

					}

					SimpleNode<T>* inserted = new SimpleNode<T>(value);
					inserted->next = buffer->next;
					buffer->next = inserted;
					size++;
					return buffer->getVal();

				}

			} else {

				tail->next = new SimpleNode<T>(value);
				tail = tail->next;
				size++;
				return tail->getVal();

			}

		}

    }


    T* pushFront(T* value) {

    	if (ordered) add(value);
    	else {

    		SimpleNode<T>* inserted = new SimpleNode<T>(value);
    		inserted->next = head;
    		head = inserted;
    		size++;
    		return head->getVal();

    	}

    }

    T* pushBack(T* value) {

    	add(value);

    }

    T* front(){

        return head->getVal();

    }

    T* end() {

        return tail->getVal();

    }

    T* next() {

    	if (0 == current) current = head;
    	else current = current->next;

        return current == 0? 0: current->getVal();

    }

    T* get(T* value) {

        if (0 == head) {

            return 0;

        } else {

            SimpleNode<T> *buffer = head;

             while (0 != buffer) {

                if (*value == *buffer->getVal())
                    return buffer->getVal();

                buffer = buffer->next;

            }

            return 0;

        }

    }

    T* remove(T* value) {

		if (0 == head) {

            return 0;

		} else {

			if (*value == *head->getVal()) {

				T* result = head->getVal();
				head = head->next;
				size--;
				return result;

			}

			SimpleNode<T> *buffer = head;

			while (0 != buffer->next) {

                if (*value == *buffer->next->getVal()) {
                    
                	T* result = buffer->next->getVal();
                	buffer->next = buffer->next->next;
                	size--;
                    return result;
                
                }

				buffer = buffer->next;

			}

			return 0;

		}

    }

	void print(){

		if(head != 0){

			SimpleNode<T> *temp = head;

			while (temp != 0) {

				std::cout << "Valor: " << *temp->getVal() << std::endl;
				temp = temp->next;

			};

		}

    }

};
