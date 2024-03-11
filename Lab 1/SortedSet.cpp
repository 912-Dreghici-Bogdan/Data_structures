#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    this->length = 0;
    this->capacity = 10;
    this->relation= r;
    this->elements= new TComp[this->capacity];
}


bool SortedSet::add(TComp elem) {
    if(this->length == this->capacity){
        this->capacity = this->capacity * 2;
        TElem * newElements = new TComp[this->capacity];
        for(int i = 0; i < this->length; i++){
            newElements[i] = this->elements[i];
        }
        delete [] this->elements;
        this->elements = newElements;
    }
    int index = 0;
    while(index < this->length && this->relation(this->elements[index], elem)){
        index++;
    }

    for(int i = this->length; i > index; i--){
        this->elements[i] = this->elements[i-1];
    }
    this->elements[index] = elem;
    this->length++;
}


bool SortedSet::remove(TComp elem) {
    if (this->search(elem)==true){
        int index = 0;
        while (this->elements[index] != elem){
            index++;
        }
        for (index; index < length - 1; index++){
            this->elements[index] = this->elements[index + 1];
        }
        this->length--;
        return true;
    }
	return false;
}


bool SortedSet::search(TComp elem) const {
    for (int index = 0; index < length; index++){
        if (this->elements[index]==elem)
            return true;
    }
    return false;
}


int SortedSet::size() const {
    return this->length;
}



bool SortedSet::isEmpty() const {
	if(this->length==0)
        return true;
	return false;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    delete [] this->elements;
}


