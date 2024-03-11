#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    this->current = d.head;
}//O(1)


void MapIterator::first() {
    this->current = this->map.head;
}//O(1)


void MapIterator::next() {
    if (!this->valid())
    {
        throw exception();
    }

    this->current = this->map.nodes[this->current].next;
}//O(1)


TElem MapIterator::getCurrent(){
    if (this->valid()) {
        return this->map.nodes[this->current].info;
    } else {
        throw std::exception();
    }
}//O(1)


bool MapIterator::valid() const {
    return this->current != -1;
}//O(1)



