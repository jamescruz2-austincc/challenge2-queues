/* *************************************************
*  Name: James Cruz
*  Assignment: Challenge 2: Queues
*  Purpose: Building an ADT Queue, building off of
*           learnings from Stack and Linked List
*  
************************************************* */

#include "queue.h"

Queue::Queue(bool isFIFO) {
    /* *************************************************
     * Default constructor for Queue.
     *
     * @param isFifo : is FIFO, not LIFO
     * @return na : na
     * @exception na : na
     * @note na
     * *************************************************/
    head = nullptr;
    tail = nullptr;
    count = 0;
    this.isFIFO = isFIFO;
}

Queue::~Queue() {
    /* *************************************************
     * Destructor for Queue.
     *
     * @param na : na
     * @return na : na
     * @exception na : na
     * @note na
     * *************************************************/
    clear();
}

bool Queue::pull(Data* data) {
    /* *************************************************
     * Removes the top node (tail if FIFO, head if LIFO)
     * and assigns its data to passed data ptr.
     * Returns false if fails.
     *
     * @param data : Empty Data struct to assign node data
     * @return bool : Node is successfully pulled
     * @exception na : na
     * @note Passed Data struct is assigned -1 in id
     *       and an empty string if fails.
     * *************************************************/
    bool success = false;

    if(isFIFO) {
        success = removeTail(data);
    } else {
        success = removeHead(data);
    }

    if (!success) {
        data->id = -1;
        data->information = "";
    }

    return success;
}


int Queue::peek() {
    /* *************************************************
     * Reads data from the top node (tail if FIFO, head if LIFO)
     * and returns the id of the node. Returns -1 if no
     * node is found.
     *
     * @param na : na
     * @return int : Id of the top node.
     * @exception na : na
     * @note Passed Data struct is assigned -1 in id
     *       and an empty string if fails.
     * *************************************************/
    int nodeId = -1;

    if (count > 0) {
        if (isFIFO) {
            nodeId = tail->data.id;
        } else {
            nodeId = head->data.id;
        }
    }

    return nodeId;
}

int Queue::count() {
    /* *************************************************
     * Returns the total number of nodes in the Queue.
     *
     * @param na : na
     * @return int : Number of nodes in the queue.
     * @exception na : na
     * @note na
     * *************************************************/
    return count;
}

bool Queue::exists(int id) {
    /* *************************************************
     * Searches the queue for a node containing data
     * with the passed id. Returns true if a matching node
     * is found.
     *
     * @param id : Id of the node to search for.
     * @return bool : Node containing data with passed id
     *                was found.
     * @exception na : na
     * @note na
     * *************************************************/
}

int Queue::find(int id) {
    /* *************************************************
     * Searches the queue for a node containing data
     * with the passed id. Returns the queue position of
     * the matching node.
     *
     * @param id : Id of the node to search for.
     * @return int : Queue position of the found node.
     * @exception na : na
     * @note Returns -1 if no matching node is found.
     * *************************************************/
}

bool Queue::push(int id, string* information) {
    /* *************************************************
     * Adds a new node containing the passed data to the
     * head of the queue.
     *
     * @param id : Id to pass to new node.
     * @param information : String to pass to new node.
     * @return bool : Node was successfully added.
     * @exception na : na
     * @note na
     * *************************************************/
    bool success = false;

    if (id > 0 && information != nullptr && !(*information).empty()) {
        Node* newNode = new Node();

        newNode->data.id = id;
        newNode->data.information = *information;

        if(head == nullptr) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
        }

        head = newNode;

        count++;
        success = true;
    }

    return success;
}

void Queue::clear() {
    /* *************************************************
     * Removes all nodes from the queue.
     *
     * @param na : na
     * @return na : na
     * @exception na : na
     * @note na
     * *************************************************/
}

bool Queue::removeHead(Data* data) {
    /* *************************************************
     * Removes head node in LIFO case. Assigns data to
     * passed data ptr. Returns true if successful.
     *
     * @param id : Empty Data struct to assign node data.
     * @return bool : Node was successfully removed.
     * @exception na : na
     * @note na
     * *************************************************/
    bool success = false;

    if (head != nullptr) {
        data->id = head->data.id;
        data->information = head->data.information;

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        temp = nullptr;

        count--;

        success = true;
    }
    
    return success;
}

bool Queue::removeTail(Data* data) {
    /* *************************************************
     * Removes tail node in FIFO case. Assigns data to
     * passed data ptr. Returns true if successful.
     *
     * @param id : Empty Data struct to assign node data.
     * @return bool : Node was successfully removed.
     * @exception na : na
     * @note na
     * *************************************************/
    bool success = false;

    if (tail != nullptr) {
        data->id = tail->data.id;
        data->information = tail->data.information;

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        
        delete temp;
        temp = nullptr;

        count--;

        success = true;
    }
    
    return success;
}