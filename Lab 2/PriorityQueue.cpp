
#include "PriorityQueue.h"
#include <exception>
using namespace std;


PriorityQueue::PriorityQueue(Relation r) {
    this->head = nullptr;
    this->relation = r;
}

void PriorityQueue::push(TElem e, TPriority p) {
    Node* newNode = new Node;
    newNode->current = std::make_pair(e, p);

    if (head == nullptr) {
        newNode->next = nullptr;
        head = newNode;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && relation(current->current.second, p)) {
        prev = current;
        current = current->next;
    }

    if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
}
//O(n)

//throws exception if the queue is empty
Element PriorityQueue::top() const {
    if (this->isEmpty()){
        throw exception();
    }
    return head->current;

}
//O(1)

Element PriorityQueue::pop() {
    if (this->isEmpty()){
        throw exception();
    }
    Node* removedNode = head;
    head = head->next;
    Element removedData = removedNode->current;
    delete removedNode;
    return removedData;
}
//O(1)

bool PriorityQueue::isEmpty() const {
    if (head == nullptr){
        return true;
    }
    return false;
}
//O(1)

PriorityQueue::~PriorityQueue() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
//O(n)

void PriorityQueue::merge(PriorityQueue &pq) {
    Node* second = pq.head;
    while (second != nullptr) {
        this->push(second->current.first, second->current.second);
        second = second->next;
    }
}
//O(n*m)
