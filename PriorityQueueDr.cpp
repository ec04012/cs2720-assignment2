// Test driver
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

#include "PriorityQueue.cpp"

void help() {
    std::cout << "enqueue value priority: Enqueue a value into the Queue based on priority.\n";
    std::cout << "enqueue  value        : Enqueue a value into the Queue based on priority.\n";
    std::cout << "dequeue               : Remove the item at the front of the queue\n";
    std::cout << "peek                  : Peeks at the first item without removing it\n ";
    std::cout << "clear                 : Clears the queue.\n";
    std::cout << "isempty               : Reports whether the queue is empyty\n";
    std::cout << "isfull                : Reports whether the queue is full\n";
    std::cout << "list                  : Reports the items in the queue, in the order they will be processed\n";
    std::cout << "help                  : Prints this message\n";
}
int main() {
    ofstream outFile;
    ifstream inFile;
    string command;

    outFile.open("outFile.txt");
    inFile.open("inFile.txt");
    if(!outFile) {
        std::cout << "error openning output file" << endl;
        return 1;
    }
    string item;
    int priority;
    PriorityQueue<string> queue;
    int numCommands = 0;

    help();
    while(true) {
        inFile >> command;

        try {
            if(command == "enqueue") {
                inFile >> item;
                inFile >> priority;
                queue.enqueue(item, priority);
                outFile << item << " is enqueued." << endl;
            } else if(command == "dequeue") {
                queue.dequeue(item);
                outFile << item << " was dequeued. " << endl;
            } else if(command == "peek") {
                string x = queue.peek();
                outFile << "Front item is " << x << endl;
            } else if(command == "peekPriority") {
                int x = queue.peekPriority();
                outFile << "Priority of the front item is " << x << endl;
            } else if(command == "length") {
                outFile << "Number of items in the Queue is: " << queue.length() << endl;
            } else if(command == "list") {
                queue.printQueue(outFile);
            } else if(command == "makeEmpty") {
                queue.makeEmpty();
            } else if(command == "isEmpty") {
                if(queue.isEmpty())
                    outFile << "Queue is empty\n";
                else
                    outFile << "Queue is not empty\n";
            } else if(command == "isFull") {
                if(queue.isFull())
                    outFile << "Queue is full." << endl;
                else
                    outFile << "Queue is not full." << endl;
            } else if(command == "help") {
                help();
            } else if(command == "quit") {
                outFile << "Testing completed";
                break;
            } else {
                outFile << " Invalid Command" << endl;
            }
        } catch(FullQueue) {
            outFile << "FullQueue exception thrown" << endl;
        } catch(EmptyQueue) {
            outFile << "EmptyQueue exception thrown" << endl;
        }
        numCommands++;
        cout << "Command number " << numCommands << " completed." << endl;
    }

    cout << "Testing completed." << endl;
    outFile.close();
    return 0;
}