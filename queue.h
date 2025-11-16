/* *************************************************
*  Name: James Cruz
*  Assignment: Challenge 2: Queues
*  Purpose: Building an ADT Queue, building off of
*           learnings from Stack and Linked List
*  
************************************************* */

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
};

struct Node {
    Data data;
    Node* next;
    Node* prev;
};

class Queue {
    public:
        /**********************
        Constructor/Destructor
        ***********************/
        Queue(bool = true);
        ~Queue();

        /**********************
        Getters/Accessors
        ***********************/
        bool pull(Data*);
        int peek();
        int count();
        bool exists(int);
        int find(int);

        /**********************
        Setters/Mutators
        ***********************/
        bool push(int, string*);
        void clear();
        

    private:
        /**********************
        Methods
        ***********************/
        bool removeHead(Data*);
        bool removeTail(Data*);

        /**********************
        Attributes
        ***********************/
        Node* head;
        Node* tail;
        int count_;
        bool isFIFO;
};

#endif //QUEUE_H