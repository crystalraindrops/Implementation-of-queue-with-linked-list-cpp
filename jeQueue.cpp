/*
 Linear Queue (Linked List) in C++
 @author: PARK JI EUN
 @date: 2016.12.19
 */

#include <iostream>

using namespace std;

template <typename T>
class Queue;

/** Linked List Node **/
template <typename T>
class Node {
    friend class Queue<T>;
public:
    Node():link(0) {}; // init link = 0
    Node(const T&);
private:
    T data;
    Node* link;
};

template <typename T>
Node<T>::Node(const T& _data) {
    data = _data;
    link = 0;
}

/** Linear Queue implemented with Linked List **/
template <typename T>
class Queue {
    friend ostream& operator<<(ostream& os, Queue queue) {
        Node<T>* current = queue.head;
        while (current->link != queue.head) {
            current = current->link;
            os << current->data << " ";
        }
        os << endl;
        return os;
    };
public:
    Queue();
    void Enqueue(const T&); // Push data to the queue
    void Dequeue(); // Remove data from the queue
    T& Front(); // Get First data of the queue
    T& Rear(); // Get Last data of the queue
    bool IsEmpty(); // Check if the queue is Empty or not
private:
    Node<T>* head; // head node
};

template <typename T>
Queue<T>::Queue() {
    head->link = head;
}

template <typename T>
bool Queue<T>::IsEmpty() {
    bool isEmpty = false;
    // if head points themself, that's empty!
    if (head->link == head) {
        isEmpty = true;
        cout << "\tQueue is Empty." << endl;
    }
    return isEmpty;
}

template <typename T>
void Queue<T>::Enqueue(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (IsEmpty()) {
        head->link = newNode;
    } else {
        // Find the Last node
        Node<T>* current = head;
        while (current->link != head) {
            current = current->link;
        }
        current->link = newNode;
    }
    newNode->link = head;
}

template <typename T>
void Queue<T>::Dequeue() {
    if (!IsEmpty()) {
        // now, headnode points 2nd node
        Node<T>* firstNode = head->link;
        head->link = firstNode->link;
        delete firstNode;
    }
}

template <typename T>
T& Queue<T>::Front() {
    T data = NULL;
    if (!IsEmpty()) {
        // return data of first element
        data = head->link->data;
    }
    return data;
}

template <typename T>
T& Queue<T>::Rear() {
    T data = NULL;
    if (!IsEmpty()) {
        // Find the Last node
        Node<T>* current = head;
        while (current->link != head) {
            current = current->link;
        }
        data = current->data;
    }
    return data;
}

int main(void)
{
    Queue<char> queue;
    int select = 0;
    char data;
    
    while (true) {
        cout << "\n- Select Command -" << endl;
        cout << "1:Enqueue, 2:Dequeue, 3:Front, 4:Rear, 5:Display, 0: Quit\n\t>> ";
        cin >> select;
        switch (select) {
            case 1:
                cout << "\tEnter Data to Enqueue >> ";
                cin >> data;
                queue.Enqueue(data);
                cout << queue;
                break;
            case 2:
                queue.Dequeue();
                cout << queue;
                break;
            case 3:
                cout << "\tFront >> " << queue.Front() << endl;
                break;
            case 4:
                cout << "\tRear >> " << queue.Rear() << endl;
                break;
            case 5:
                cout << queue;
                break;
            case 0:
                cout << "BYE!" << endl;
                exit(0);
            default:
                cout << "WRONG INPUT" << endl;
                cout << "Re-Enter" << endl;
                break;
        }
    }
    system("pause");
    return 0;
}