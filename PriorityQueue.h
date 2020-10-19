#ifndef PriorityQueue_H
#define PriorityQueue_H
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
class QueueOverflow {};

class QueueUnderflow {};

template <class ItemType>
struct QNode {
    ItemType info;
    int priority;
    QNode<ItemType>* next;
};

template <class ItemType>
class PriorityQueue {
   public:
    // Class constructor.
    PriorityQueue();

    ~PriorityQueue();
    // Class destructor.

    void enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.

    void dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it
    // in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.

    ItemType peek();
    // returns the item at the front of the queue without
    // removing the item from the queue

    int peekPriority();
    // returns the item at the front of the queue without
    // removing the item from the queue

    int length() const;
    // Function: returns the number of items in the queue

    void printQueue(ofstream&);
    // displays QueueItems

    void makeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.

    bool isEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)

    bool isFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

   private:
    QNode<ItemType>* items;
    int Length;
    bool findItem(ItemType item, QNode<ItemType>*& predecessor);
};
#endif