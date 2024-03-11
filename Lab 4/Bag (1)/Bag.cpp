#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    table.nr_elems = 0;
    table.capacity = 20;
    table.elements = new Pair[table.capacity];
    for(int i = 0; i < table.capacity; i++){
        table.elements[i].elem = NULL_TELEM;
        table.elements[i].freq = 0;
    }
}
// Theta(capacity)

void Bag::add(TElem elem) {
    if(0.66 * table.nr_elems == table.capacity)
        rehash();
    int index = this->hash(elem);
    if (this->table.elements[index].elem != -111111){
        this->table.elements[index].freq++;
        this->table.nr_elems++;
    }else {
        if (this->table.elements[index].elem == -111111){
            this->table.elements[index].elem = elem;
            this->table.elements[index].freq++;
        } else while(this->table.elements[index].elem != -111111) {
                for (int j = 0; j < this->table.capacity; j++) {
                    if (j== this->table.capacity){
                        this->rehash();
                    }
                    int aux = (index + j * j) % (this->table.capacity);
                    if (table.elements[aux].elem == -111111) {
                        this->table.elements[aux].elem = elem;
                        this->table.elements[aux].freq++;
                        break;
                    }else{
                        this->table.elements[aux].freq++;
                        this->table.nr_elems++;
                        break;
                    }
                }
            }
        this->table.nr_elems++;
            }
    }

// BC Theta(1)
// WC

bool Bag::remove(TElem elem) {
    for(int i = 0; i < table.capacity; i++)
        if(table.elements[i].elem == elem){
            table.elements[i].freq--;
            if(table.elements[i].freq == 0){
                table.elements[i].elem = NULL_TELEM;
                table.elements[i].freq = NULL_TELEM;
            }
            table.nr_elems--;
            return true;
        }
    return false;
}
/// WC O(capacity)


bool Bag::search(TElem elem) const {
    for(int i = 0; i < table.capacity; i++)
        if(table.elements[i].elem == elem)
            return true;
    return false;
}
/// WC O(capacity)

int Bag::nrOccurrences(TElem elem) const {
        for(int i = 0; i < table.capacity; i++){
            if(table.elements[i].elem == elem)
                return table.elements[i].freq;
        }
    return 0;
}
///O(capacity)

int Bag::size() const {
    return table.nr_elems;
}
/// O(1)

bool Bag::isEmpty() const {
    if(table.nr_elems == 0)
        return true;
    return false;
}
/// O(1)

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}
/// O(1)

Bag::~Bag() {
	delete[] table.elements;
}
/// O(1)

void Bag::rehash() {
    Pair* copy = new Pair[table.capacity];
    for(int i = 0; i < table.nr_elems; i++)
        copy[i] = table.elements[i];
    table.capacity *= 2;
    delete[] table.elements;

    table.elements = new Pair[table.capacity];
    table.nr_elems = 0;
    for(int i = 0; i < table.capacity; i++){
        table.elements[i].elem = NULL_TELEM;
        table.elements[i].freq = 0;
    }

    for(int i = 0; i < table.capacity; i++)
        if(copy[i].elem != -111111)
            this->add(copy[i].elem);

}
///O(capacity)

int Bag::hash(TElem e) {
    return e % this->table.capacity;
}

int Bag::distinctElems() const {
    int distinct = 0;
    for(int i = 0; i < table.capacity; i++)
        if(table.elements[i].elem != -111111)
            distinct++;
    return distinct;
}
/// O(1)

