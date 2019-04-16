// Perry Bunn
// ptb0010
// hw5_ptb0010.cpp
// Description
// Help

#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;

    struct Node *next;
    struct Node *prev;

    Node<T>() {
        &data = NULL;
        *next = NULL;
        *prev = NULL;
    }

    Node<T>(T dataIn) {
        &data = dataIn;
        *next = NULL;
        *prev = NULL;
    }

    Node<T>(T dataIn, Node *nextIn) {
        &data = dataIn;
        *next = nextIn;
        *prev = NULL;
    }
    Node<T>(T dataIn, Node *nextIn, Node *prevIn) {
        &data = dataIn;
        *next = nextIn;
        *prev = prevIn;
    }

    string toString();
    void print();
};

template<class T>
string Node<T>::toString() {
    return std::__cxx11::string();
}

template<class T>
void Node<T>::print() {
    cout << this->data;
}

template<class T>
class LinkedList {
private:
    Node<T> *head, *tail;

public:
    LinkedList<T>() {
        *head = NULL;
        *tail = NULL;
    };

    LinkedList<T>(T headIn, T tailIn) {
        *head = headIn;
        *tail = tailIn;
    }

    bool isEmpty();
    void push(T node);
    void insert(int index, T node);
    void append(T node);
    void remove(T data);
    int size();
    void toString();
};

template<class T>
bool LinkedList<T>::isEmpty() {
    return this.*head == NULL && this.*tail == NULL;
}

template<class T>
void LinkedList<T>::push(T node){
    head->prev = node;
    node.next = head;
    this->head = node;
}

template<class T>
void LinkedList<T>::insert(int index, T node){
    if (index == 0) {
        append(node);
        return;
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        if (i == index-1) {
            node.prev = current;
            node.next = current->next;
            current->next->prev = node;
            current->next = node;
            return;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::append(T node) {
    tail->next = node;
    node.prev = tail;
    this->tail = node;
}

template<class T>
void LinkedList<T>::remove(T data) {
    Node<T> *current = head;
    while (current->data != data) {
        if (current == tail) {
            return;
        }
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

template<class T>
int LinkedList<T>::size() {
    int count = 0;
    Node<T> *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

template<class T>
void LinkedList<T>::toString() {
    string print;
    Node<T> *current = head;
    while (current != NULL) {
        print += current->data + " ";
    }
    cout << print;
}


int main() {
    return 0;
}