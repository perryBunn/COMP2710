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
    T data1;
    T data2;
    int weight;

    struct Node<T> *next;
    struct Node<T> *prev;


    Node<T>(T data1In, T data2In, int weightIn) {
        data1 = data1In;
        data2 = data2In;
        weight = weightIn;
        next = nullptr;
        prev = nullptr;
    }

    Node<T>(T data1In, T data2In, int weightIn, Node *prevIn) {
        data1 = data1In;
        data2 = data2In;
        weight = weightIn;
        next = nullptr;
        prev = prevIn;
    }

    Node<T>(T data1In, T data2In, int weightIn, Node *nextIn, Node *prevIn) {
        data1 = data1In;
        data2 = data2In;
        weight = weightIn;
        next = nextIn;
        prev = prevIn;
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
public:
    Node<T> *head, *tail;

    LinkedList<T>() = default;;

    LinkedList<T>(Node<T> *headIn) {
        head = headIn;
        tail = headIn;
    }

    LinkedList<T>(Node<T> headIn, Node<T> tailIn) {
        head = &headIn;
        tail = &tailIn;
    }

    bool isEmpty();
    void push(Node<T> node);
    void insert(int index, Node<T> node);
    void append(Node<T> *node);
    void remove(T data);
    int size();
    void toString();
};

template<class T>
bool LinkedList<T>::isEmpty() {
    return this.*head == NULL && this.*tail == NULL;
}

template<class T>
void LinkedList<T>::push(Node<T> node){
    head->prev = node;
    node.next = head;
    this->head = node;
}

template<class T>
void LinkedList<T>::insert(int index, Node<T> node){
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
void LinkedList<T>::append(Node<T> *node) {
    this->tail->next = node;
    node->prev = this->tail;
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
    while (current != nullptr) {
        print += current->data1 + ", " + current->data2 + ", " + to_string(current->weight) + " -> ";
    }
    cout << print;
}

// Initialized the linked list for the program.
LinkedList<string> init(LinkedList<string> list) {
    Node<string> question1 = Node<string>("How long was the shortest war on record?", "38", 100);
    Node<string> question2 = Node<string>("What was the Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
    Node<string> question3 = Node<string>("What is the best-selling video game of all time? (Hint: Minecraft or Tetris)", "Tetris", 20);

    list = LinkedList<string>(&question1);
    list.append(&question2);
    list.append(&question3);
    return list;
}

// Creates new questions to be added to the linked list
void newQuestions(LinkedList<string> *list) {
    bool playerConsent = true;
    while (playerConsent) {
        string question;
        string answer;
        int weight;

        cout << "Enter a question: ";
        cin >> question;
        cout << "Enter an answer: ";
        cin >> answer;
        cout << "Enter award points: ";
        cin >> weight;

        Node<string> nodeQuest = Node<string>(question, answer, weight);
        list->append(&nodeQuest);

        cout << "Countinue? (Yes/No): ";
        string response = "";
        cin >> response;
        if (response == "no") {
            playerConsent = false;
        }
    }

}

int main() {
    LinkedList<string> triviaList;
    triviaList = init(triviaList);
    cout << "*** Welcome to Perry's trivia quize game ***\n";
    newQuestions(&triviaList);
    cout << triviaList.tail->data1;
    cout << triviaList.tail->data2;
    cout << triviaList.tail->weight;
    return 0;
}