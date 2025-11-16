/* *************************************************
*  Name: James Cruz
*  Assignment: Challenge 2: Queues
*  Purpose: Building an ADT Queue, building off of
*           learnings from Stack and Linked List
*  
************************************************* */
#include "main.h"

int main(int argc, char **argv) {
    /* **********************************
    * This function is the application driver. It uses
    * and tests the ADT Queue filled with nodes.
    *
    * @param argc : number of command line parameters
    * @param argv : a two-dimensional array containing
    *               strings of program name and parameters
    * @return (int) : application exit code
    * @exception na : na
    * @note na
    * **********************************/
    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    Data tempData;
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = - 1;
    strs[testdatasize-2] = "Bad ID";
    strs[testdatasize-1] = "";

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 1: Testing FIFO Queue" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    Queue fifoQueue(true);
    std::cout << "FIFO Queue Created: Count " << fifoQueue.count() << std::endl;

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 1a: FIFO: Testing push, peek, and count" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << "Adding ID: " << ids[i] << " Info: " << strs[i] << " ... " << (fifoQueue.push(ids[i], &strs[i]) ? "SUCCESS" : "FAILED") << std::endl;
        std::cout << "Peeking ID: " << fifoQueue.peek() << std::endl;
        std::cout << "FIFO: Count " << fifoQueue.count() << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 1b: FIFO: Testing pull and count" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << "Pulling: " << (fifoQueue.pull(&tempData) ? "SUCCESS" : "FAILED") << " ID: " << tempData.id << " Info: " << tempData.information << std::endl;
        std::cout << "FIFO: Count " << fifoQueue.count() << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 1c: FIFO: Testing push, exists, and find" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << "Adding ID: " << ids[i] << " Info: " << strs[i] << " ... " << (fifoQueue.push(ids[i], &strs[i]) ? "SUCCESS" : "FAILED") << std::endl;
        std::cout << "Node with ID " << ids[i] << " Exists? : " << (fifoQueue.exists(ids[i]) ? "TRUE" : "FALSE") << std::endl;
        std::cout << "Finding position of node with ID " << ids[i] << ": POSITION " << fifoQueue.find(ids[i]) << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 1d: FIFO: Testing clear" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "FIFO: Count " << fifoQueue.count() << std::endl;
    std::cout << "Clearing..."<< std::endl;
    fifoQueue.clear();
    std::cout << "FIFO: Count " << fifoQueue.count() << std::endl;
    std::cout << "Attemping to peek, ID: " << fifoQueue.peek() << std::endl;



    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 2: Testing LIFO Queue" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    Queue lifoQueue(false);
    std::cout << "LIFO Queue Created: Count " << lifoQueue.count() << std::endl;

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 2a: LIFO: Testing push, peek, and count" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << "Adding ID: " << ids[i] << " Info: " << strs[i] << " ... " << (lifoQueue.push(ids[i], &strs[i]) ? "SUCCESS" : "FAILED") << std::endl;
        std::cout << "Peeking ID: " << lifoQueue.peek() << std::endl;
        std::cout << "LIFO: Count " << lifoQueue.count() << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 2b: LIFO: Testing pull and count" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << "Pulling: " << (lifoQueue.pull(&tempData) ? "SUCCESS" : "FAILED") << " ID: " << tempData.id << " Info: " << tempData.information << std::endl;
        std::cout << "LIFO: Count " << lifoQueue.count() << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 2c: LIFO: Testing push, exists, and find" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < testdatasize; i++) {
        std::cout << "Adding ID: " << ids[i] << " Info: " << strs[i] << " ... " << (lifoQueue.push(ids[i], &strs[i]) ? "SUCCESS" : "FAILED") << std::endl;
        std::cout << "Node with ID " << ids[i] << " Exists? : " << (lifoQueue.exists(ids[i]) ? "TRUE" : "FALSE") << std::endl;
        std::cout << "Finding position of node with ID " << ids[i] << ": POSITION " << lifoQueue.find(ids[i]) << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 2d: LIFO: Testing clear" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "LIFO: Count " << lifoQueue.count() << std::endl;
    std::cout << "Clearing..."<< std::endl;
    lifoQueue.clear();
    std::cout << "LIFO: Count " << lifoQueue.count() << std::endl;
    std::cout << "Attemping to peek, ID: " << lifoQueue.peek() << std::endl;



    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Test 3: Randomized FIFO testing" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int testId;
    string testStr;

    for (int i = 0; i < TESTCOUNT; i++) {
        testId = rand() % MAXID + 1;
        testStr = "";
        for (int j = 0; j < TESTSTRLENGTH; j++) {
            testStr += characters[rand() % characters.length()];
        }

        switch (rand() % 7 + 1) {
            case 1:
                std::cout << "Adding ID: " << testId << " Info: " << testStr << " ... " << (fifoQueue.push(testId, &testStr) ? "SUCCESS" : "FAILED") << std::endl;
                break;
            case 2:
                std::cout << "Pulling: " << (fifoQueue.pull(&tempData) ? "SUCCESS" : "FAILED") << " ID: " << tempData.id << " Info: " << tempData.information << std::endl;
                break;
            case 3:
                std::cout << "Peeking: " << fifoQueue.peek() << std::endl;
                break;
            case 4:
                std::cout << "Current Count is: " << fifoQueue.count() << std::endl;
                break;
            case 5:
                if (rand() % 2 == 0) {
                    std::cout << "Checking if bad id (-1) exists: " << (fifoQueue.exists(-1) ? "TRUE" : "FALSE") << std::endl;
                } else {
                    testId = rand() % MAXID + 1;
                    std::cout << "Checking if id " << testId << "exists: " << (fifoQueue.exists(testId) ? "TRUE" : "FALSE") << std::endl;
                }
                break;
            case 6:
                if (rand() % 2 == 0) {
                    std::cout << "Finding position of BAD id (-1): " << fifoQueue.find(-1) << std::endl;
                } else {
                    testId = rand() % MAXID + 1;
                    std::cout << "Finding position of id " << testId << "exists: " << fifoQueue.find(testId) << std::endl;
                }
                break;
            case 7:
                std::cout << "Clearing FIFO Queue..." << std::endl;
                fifoQueue.clear();
                break;
        }
    }
}