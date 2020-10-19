#include "PriorityQueue.h"

// Class constructor.
template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue() {
    items = NULL;
    Length = 0;
}

// Class destructor.
template <class ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {
    makeEmpty();
}

// Function: Adds newItem into the queue based on its priority.
// A lower priority means the items is placed earlier in the queue
// towards the front.
// Post: If (queue is full) QueueOverflow exception is thrown
//       else newItem is inserted into the proper location in queue.
template <class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem, int priority) {
    // Check for full list
    if(isFull()) {
        throw QueueOverflow();
    }

    // predecessor QNode
    QNode<ItemType>* pred = NULL;

    // Attemp to insert item
    QNode<ItemType>* newQNode = new QNode<ItemType>;
    newQNode->info = newItem;
    if(pred == NULL) {
        // special case for inserting at beginning
        newQNode->next = items;
        items = newQNode;
    } else {
        // regular case, insert a new QNode in middle or at end of list
        newQNode->next = pred->next;
        pred->next = newQNode;
    }
    Length++;
}

// Function: Adds newItem to the the queue.
// This adds newItem with a priority of 0
// Post: If (queue is full) QueueOverflow exception is thrown
//       else newItem is inserted into queue.
template <class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem) {
    enqueue(newItem, 0, );
}

// Function: deletes Item from the front of the queue and returns
// it in item.
// Post: If List is empty, QueueUnderflow exception is thrown and item
//       is undefined.
//       else front item is dequeued and returned in item.
template <class ItemType>
void PriorityQueue<ItemType>::dequeue(ItemType& item) {
    // predecessor QNode
    QNode<ItemType>* pred;

    if(isEmpty()) {
        throw QueueUnderflow();
    }

    if(pred == NULL) {
        // special case for deleting first element
        QNode<ItemType>* loc = items;
        items = items->next;
        loc->next = NULL;
        delete loc;
    } else {
        // regular case, connect pred to next next
        // then delete the loc QNode
        QNode<ItemType>* loc = pred->next;
        pred->next = loc->next;
        loc->next = NULL;
        delete loc;
    }
    Length--;
}

// returns the item at the front of the queue without
// removing the item from the queue
template <class ItemType>
ItemType PriorityQueue<ItemType>::peek() {
    ItemType e;
    return e;
}

// returns the priority of the  item at the front
// of the queue without removing the item from the queue
template <class ItemType>
int PriorityQueue<ItemType>::peekPriority() {
    return 0;
}

// Function: returns the number of items in the queue
// pre: List is initialized.
// post: Function value = number of elements in the queue.
//       and queue is unchanged.
template <class ItemType>
int PriorityQueue<ItemType>::length() const {
    return Length;
}

// Function: Prints the list to a file
// pre: List is initialized
// post: List is not changed
template <class ItemType>
void PriorityQueue<ItemType>::printQueue(ofstream& stream) {
    QNode<ItemType>* temp = items;
    stream << "List Items : ";
    while(temp != NULL) {
        stream << temp->info << "->";
        temp = temp->next;
    }
    stream << "NULL" << endl;
}

// Function: Deallocates all list QNodes, and reinitializes the list to its empty state.
// Pre: List is initialized
// Post: list is empty.
template <class ItemType>
void PriorityQueue<ItemType>::makeEmpty() {
    QNode<ItemType>* tempPtr;
    while(items != NULL) {
        tempPtr = items;
        items = items->next;
        delete tempPtr;
    }
    Length = 0;
}

// Function: Determines whether the list is empty.
// Pre: List is initialized
// Post: Function value = (list is empty)
template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
    return items == NULL;
}

// Function: Determines whether the list is full.
// Pre: List is initialized
// Post: Function value = (list is full)
template <class ItemType>
bool PriorityQueue<ItemType>::isFull() const {
    // Try to allocate a new QNode, if not possible then list if full
    try {
        QNode<ItemType>* temp = new QNode<ItemType>;
        delete temp;
        return false;
    } catch(std::bad_alloc) {
        return true;
    }
}

// Function: Searches the list for item and returns a pointer to item's predecessor QNode.
// pre: list is initialized
// post: (1) If item is in the list, function value =  true
//       (2) if item is not in the list, function value is false
//       (3) predecessor contains the address of item's predecessor QNode ( i.e. QNode with largest value < item's key)
//        if no predescessor exit, predecessor is set to NULL.
template <class ItemType>
bool PriorityQueue<ItemType>::findItem(int priority, QNode<ItemType>*& predecessor) {
    predecessor = NULL;

    QNode<ItemType>* location = items;
    while(location != NULL && location->info < item) {
        predecessor = location;
        location = location->next;
    }

    if(location != NULL && location->info == item) {
        return true;
    }

    return false;
}
