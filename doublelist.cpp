#include <iostream>
#include <fstream>
#include <stdlib.h>

template<class T>
class DoubleNode {

	T* value;

public:

	DoubleNode<T>* prev;
	DoubleNode<T>* next;
    DoubleNode(T* value): value(value), prev(0), next(0) {}

	T* getVal(){

		return value;

	}

};

template<class T>
class DoubleList
{

    bool ordered;
    DoubleNode<T> *head, *tail, *current;

public:

	int size;

    DoubleList(bool ordered = 0): ordered(ordered), size(0), head(0), tail(0), current(0){}
    ~DoubleList();
	
    T* add(T* value) {

		if (0 == head) {

            head = new DoubleNode<T>(value);
			tail = head;
			size++;
			return head->getVal();

		} else {

			if (ordered) {

				if (*value < *head->getVal()) {

					head->prev = new DoubleNode<T>(value);
					head->prev->next = head;
					head = head->prev;
					size++;
					return head->getVal();

				} else if (*value > *tail->getVal()) {

					tail->next = new DoubleNode<T>(value);
					tail->next->prev = tail;
					tail = tail->next;
					size++;
					return tail->getVal();

				} else {

					DoubleNode<T>* buffer = head;

					while (0 != buffer){

                        if (*value <= *buffer->getVal()){

							break;

						}

						buffer = buffer->next;

					}

					DoubleNode<T>* inserted = new DoubleNode<T>(value);
					inserted->prev = buffer->prev;
					buffer->prev->next = inserted;
					buffer->prev = inserted;
					inserted->next = buffer;
					size++;
					return buffer->getVal();

				}

			} else {

				tail->next = new DoubleNode<T>(value);
				tail->next->prev = tail;
                tail = tail->next;

			}

		}

    }


    T* pushFront(T* value) {

    	if (ordered) add(value);
    	else {

    		head->prev = new DoubleNode<T>(value);
			head->prev->next = head;
			head = head->prev;
			size++;
			return head->getVal();

    	}

    }

    T* pushBack(T* value) {

    	add(value);

    }

    T* front(){

        return head;

    }

    T* end() {

    	return tail;

    }

    T* next() {

        if (0 == current) current = head;
    	else current = current->next;

        return 0 == current? 0: current->getVal();

    }

    T* get(T* value) {

        if (0 == head) {

            return 0;

        } else {

            DoubleNode<T> *buffer = head;

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
				head->prev = 0;
				size--;
				return result;

			}

			DoubleNode<T> *buffer = head;

			while (0 != buffer->next) {

                if (*value == *buffer->next->getVal()) {
                    
                	T* result = buffer->next->getVal();
                	buffer->next = buffer->next->next;
                	if (0 != buffer->next)	buffer->next->prev = buffer;
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

			DoubleNode<T> *temp = head;

			while (temp != 0) {

				std::cout << "Valor: " << *temp->getVal() << std::endl;
				if (0 != temp->prev) std::cout << "\tValor anterior: " << *temp->prev->getVal() << std::endl;
				if (0 != temp->next) std::cout << "\tValor siguiente: " << *temp->next->getVal() << std::endl;
				temp = temp->next;

			}

		}

    }

};

template<class T>
class CircularDoubleList
{

    bool ordered;
    DoubleNode<T> *head, *tail, *current;

public:

	int size;

    CircularDoubleList(bool ordered = 0): ordered(ordered), size(0), head(0), tail(0), current(0){}
    ~CircularDoubleList();
	
    T* add(T* value) {

		if (0 == head) {

            head = new DoubleNode<T>(value);
			tail = head;
			head->next = tail;
			tail->prev = head;
			size++;
			return head->getVal();

		} else {

			if (ordered) {

				if (*value < *head->getVal()) {

					head->prev = new DoubleNode<T>(value);
					head->prev->next = head;
					head = head->prev;
					head->prev = tail;
					tail->next = head;
					size++;
					return head->getVal();

				} else if (*value > *tail->getVal()) {

					tail->next = new DoubleNode<T>(value);
					tail->next->prev = tail;
					tail = tail->next;
					tail->next = head;
					head->prev = tail;
					size++;
					return tail->getVal();

				} else {

					DoubleNode<T>* buffer = head;

					do {

                        if (*value <= *buffer->getVal()){

							break;

						}

						buffer = buffer->next;

					} while (head != buffer);

					DoubleNode<T>* inserted = new DoubleNode<T>(value);
					inserted->prev = buffer->prev;
					buffer->prev->next = inserted;
					buffer->prev = inserted;
					inserted->next = buffer;
					size++;
					return buffer->getVal();

				}

			} else {

				tail->next = new DoubleNode<T>(value);
				tail->next->prev = tail;
				tail = tail->next;
				tail->next = head;
				head->prev = tail;
				size++;
				return tail->getVal();

			}

		}

    }


    T* pushFront(T* value) {

    	if (ordered || 0 == head) add(value);
    	else {

    		head->prev = new DoubleNode<T>(value);
			head->prev->next = head;
			head = head->prev;
			head->prev = tail;
			tail->next = head;
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
        else if (current == tail) current = 0;
    	else current = current->next;

        return current == 0? 0: current->getVal();

    }

    T* get(T* value) {

        if (0 == head) {

            return 0;

        } else {

            DoubleNode<T> *buffer = head;

            do {

                if (*value == *buffer->getVal())
                    return buffer->getVal();

                buffer = buffer->next;

            } while (head != buffer);

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
				head->prev = tail;
				size--;
				return result;

			}

			DoubleNode<T> *buffer = head;

			do {

                if (*value == *buffer->next->getVal()) {
                    
                	T* result = buffer->next->getVal();
                	buffer->next = buffer->next->next;
                	buffer->next->prev = buffer;
                	size--;
                    return result;
                
                }

				buffer = buffer->next;

			} while (head != buffer->next);

			return 0;

		}

    }

	void print(){

		if(head != 0){

			DoubleNode<T> *temp = head;

			do {

				std::cout << "Valor: " << *temp->getVal() << std::endl;
				if (0 != temp->prev) std::cout << "\tValor anterior: " << *temp->prev->getVal() << std::endl;
				if (0 != temp->next) std::cout << "\tValor siguiente: " << *temp->next->getVal() << std::endl;
				temp = temp->next;

			} while (head != temp);

		}

    }

};
