#include "Map.h"
#include "MapIterator.h"

Map::Map() {
    this->capacity = 10;
    this->length = 0;
    this->head = -1;
    this->firstEmpty = 0;
    this->nodes = new Node[this->capacity];
    for (int i = 0; i < this->capacity - 1; i++)
        this->nodes[i].next = i + 1;
    this->nodes[this->capacity - 1].next = -1;
}//O(n)

Map::~Map() {
    delete[] this->nodes;
}//O(1)

TValue Map::add(TKey c, TValue v) {
    int low = head;
    int high = -1;
    while (low != -1)
    {
        if (this->nodes[low].info.first == c)
        {
            TValue oldValue = this->nodes[low].info.second;
            this->nodes[low].info.second = v;
            return oldValue;
        }
        high = low;
        low = this->nodes[low].next;
    }
    int pos = this->allocate();
    this->nodes[pos].info = std::make_pair(c, v);
    this->nodes[pos].next = -1;
    if (high == -1)
    {
        // add to the beginning of the list
        this->nodes[pos].next = this->head;
        this->head = pos;
    }
    else if (low == -1)
    {
        // add to the end of the list
        this->nodes[high].next = pos;
    }
    this->length++;
    return NULL_TVALUE;
}//O(n)

TValue Map::search(TKey c) const{
    int pos = head;
    while (pos != -1 && this->nodes[pos].info.first != c)
        pos = this->nodes[pos].next;
    if (pos != -1) {
        return this->nodes[pos].info.second;
    } else {
        return NULL_TVALUE;
    }
}//O(n)

TValue Map::remove(TKey c){
    int low = head;
    int high = -1;
    while (low != -1 && this->nodes[low].info.first != c)
    {
        high = low;
        low = this->nodes[low].next;
    }
    if (low != -1)
    {
        TValue oldValue = this->nodes[low].info.second;
        if (high == -1)
        {
            this->head = this->nodes[low].next;
        }
        else
        {
            this->nodes[high].next = this->nodes[low].next;
        }
        this->free(low);
        this->length--;
        return oldValue;
    }
    return NULL_TVALUE;
}//O(n)


int Map::size() const {
	return this->length;
}//O(1)

bool Map::isEmpty() const{
    if(this->length == 0)
        return true;
    return false;
}//O(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
}//O(1)

void Map::free(int pos) {
    this->nodes[pos].next = this->firstEmpty;
    this->firstEmpty = pos;
}//O(1)

int Map::allocate() {
    if (this->firstEmpty == -1)
        this->resize();
    int pos = this->firstEmpty;
    this->firstEmpty = this->nodes[this->firstEmpty].next;
    return pos;
}//O(1)

void Map::resize() {
    this->capacity *= 2;
    Node *newNodes = new Node[this->capacity];
    for (int i = 0; i < this->capacity / 2; i++)
        newNodes[i] = this->nodes[i];
    for (int i = this->capacity / 2; i < this->capacity - 1; i++)
        newNodes[i].next = i + 1;
    newNodes[this->capacity - 1].next = -1;
    this->firstEmpty = this->capacity / 2;
    delete[] this->nodes;
    this->nodes = newNodes;
}//O(n)

vector <TValue> Map::valueBag() const {
    TElem e;
    vector<TValue> values;
    MapIterator id = this->iterator();
    id.first();
    while (id.valid()) {
        e = id.getCurrent();
        values.push_back(e.second);
        id.next();
    }
    return values;
}//O(n)





