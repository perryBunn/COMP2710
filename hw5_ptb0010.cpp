// Perry Bunn
// ptb0010
// hw5_ptb0010.cpp
// Description
// Help

#include <iostream>

using namespace std;

class String : public string {
public:
    String toLower();
};

String String::toLower() {
    String compiled;
    locale loc;
    for (auto s : *this) {
        compiled += tolower(s, loc);
    }
    return compiled;
}

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

    T getData1();
    T getData2();
    int getWeight();
};

template<class T>
T Node<T>::getData1() {
    return this->data1;
}

template<class T>
T Node<T>::getData2() {
    return this->data2;
}

template<class T>
int Node<T>::getWeight() {
    return this->weight;
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
    if (this->size() == 0) {
        this->head = node;
        return;
    }
    if (this->size() == 1) {
        this->tail = node;
        this->head->next = node;
        return;
    }
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

// Initialized the linked list for the program.
void init(LinkedList<string> *list) {

    Node<string> *question1 = new Node<string>("How long was the shortest war on record?", "38", 100);
    Node<string> *question2 = new Node<string>("What was the Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
    Node<string> *question3 = new Node<string>("What is the best-selling video game of all time? (Hint: Minecraft or Tetris)", "Tetris", 20);

    list->append(question1);
    list->append(question2);
    list->append(question3);
}

// Creates new questions to be added to the linked list
void newQuestions(LinkedList<string> listIn) {
    LinkedList<string> *list = &listIn;
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

        Node<string> *nodeQuest = new Node<string>(question, answer, weight);
        list->append(nodeQuest);

        cout << "Continue? (Yes/No): ";
        String response;
        cin >> response;
        response = response.toLower();
        (response == "yes") ? (true):(playerConsent = false);
    }
}

// Iterates through the linked list checking if the correct responses have been made
void askQuestions(LinkedList<string> listIn) {
    LinkedList<string> *list = &listIn;
    bool playerConsent = true;
    Node<string> *current = list->head;
    while (playerConsent) {
        String qResponse;
        int points = 0;
        cout << "Question: " + current->data1 +"\n";
        cout << "Answer: ";
        cin >> qResponse;
        if (qResponse == current->data2) {
            cout << "Your answer is correct. You recieve " + to_string(current->weight) + " points.\n";
            points += current->weight;
            cout << "Your Total points: " + to_string(points) +"\n";
        } else {
            cout << "Your answer is wrong. The correct answer is: " + current->data2 +"\n";
            cout << "Your Total points: " + to_string(points) +"\n";
        }

        if (current->next == nullptr) {
            playerConsent = false;
            return;
        }
        current = current->next;
    }
}

int main() {
    LinkedList<string> triviaList = LinkedList<string>();
    init(&triviaList);
    cout << "*** Welcome to Perry's trivia quiz game ***\n";
    newQuestions(triviaList);
//    cout << triviaList.head->getData1() + "\n";
//    cout << triviaList.head->getData2() + "\n";
//    cout << to_string(triviaList.head->getWeight()) + "\n";
//    cout << triviaList.tail->getData1() + "\n";
//    cout << triviaList.tail->getData2() + "\n";
//    cout << to_string(triviaList.tail->getWeight()) + "\n";
    askQuestions(triviaList);
    cout << "*** Thank you for playing the trivia quiz game. Goodbye!";
    return 0;
}