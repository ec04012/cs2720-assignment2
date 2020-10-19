#include "PriorityQueue.cpp"

template <class ItemType>
void printInfo(PriorityQueue<ItemType>& q) {
    try {
        cout << "peek         ";
        cout << q.peek() << endl;
    } catch(FullQueue) {
        cout << "FullQueue exception thrown" << endl;
    } catch(EmptyQueue) {
        cout << "EmptyQueue exception thrown" << endl;
    }
    try {
        cout << "peekPriority ";
        cout << q.peekPriority() << endl;
    } catch(FullQueue) {
        cout << "FullQueue exception thrown" << endl;
    } catch(EmptyQueue) {
        cout << "EmptyQueue exception thrown" << endl;
    }
    cout << "length       ";
    cout << q.length() << endl;
    cout << "print        ";
    q.printQueue();
    cout << "isEmpty      ";
    cout << q.isEmpty() << endl;
    cout << "isFull       ";
    cout << q.isFull() << endl;
    cout << endl;
}

template <class ItemType>
void add(PriorityQueue<ItemType>& q, ItemType item, int priority) {
    cout << "Enqueue " << item << " " << priority << endl;
    q.enqueue(item, priority);
}

int main() {
    PriorityQueue<string> q;
    printInfo(q);

    string str = "wasd";
    add(q, str, 1);
    printInfo(q);

    str = "qwerty";
    add(q, str, 3);
    printInfo(q);

    str = "tk2";
    add(q, str, 2);
    printInfo(q);

    str = "poi";
    add(q, str, 0);
    printInfo(q);

    string temp;
    cout << "dequeue" << endl;
    q.dequeue(temp);
    printInfo(q);

    cout << "dequeue" << endl;
    q.dequeue(temp);
    printInfo(q);

    str = "12345";
    cout << "Enqueue " << str << endl;
    q.enqueue(str);
    printInfo(q);

    str = "67890";
    cout << "Enqueue " << str << endl;
    q.enqueue(str);
    printInfo(q);

    str = "hohey";
    cout << "Enqueue " << str << endl;
    q.enqueue(str);
    printInfo(q);

    cout << "makeEmpty" << endl;
    q.makeEmpty();
    printInfo(q);
    return 0;
}