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

// Function: Adds newItem to the end of the list.
// Pre: List is initialized
// Post: If (List is full) QueueOverflow exception is thrown
//       If item is already in the list DuplicateItem exception is thrown
//       else newItem is in the list at the correct position based on key value.
//         list maintains the sortedness property
template <class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem) {
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

// Function: deletes Item from the list.
// Post: If List is empty, QueueUnderflow exception is thrown.
// If item is not in the list, DeletingMissingItem exception is thrown.
//   else Item is not in the list.
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

// returns the item at the front of the queue without
// removing the item from the queue
template <class ItemType>
int PriorityQueue<ItemType>::peekPriority() {
    return 0;
}

// Function: returns the number of items in the list
// pre: List is initialized.
// post: Function value = number of elemnts in the list.
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
bool PriorityQueue<ItemType>::findItem(ItemType item, QNode<ItemType>*& predecessor) {
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
