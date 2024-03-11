#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    this->current = 0;
}


void SortedSetIterator::first() {
    this->current = 0;
}


void SortedSetIterator::next() {
    if (this->current >= this->multime.length){
        throw exception();
    }
    else {
        this->current++;
    }
}


TElem SortedSetIterator::getCurrent()
{
    if (this->current >= this->multime.length){
        throw exception();
    }
    else {
        return this->multime.elements[this->current];
    }
	return NULL_TELEM;
}

bool SortedSetIterator::valid() const {
	if (this->current < this->multime.length){
        return true;
    }
	return false;
}

