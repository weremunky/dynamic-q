#ifndef DYNAMICQ_H
#define DYNAMICQ_H

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Line //Line class declaration
{
private:
  struct qNode //Declares a queue node
  {
    qNode *next; //Pointer to the next element
    string custName; //Customer name string
    int raffleTicket; //Raffle ticket integer
  };

  qNode *front; //Pointer to the front of the queue
  qNode *back; //Pointer to the back of the queue

public:
    
    ~Line(); //Destructor
    Line(); //Constructor
    
    //Linked list operations
    void addLine(string);
    void delLine();
    void displayLine() const;
    void raffleWinner() const;
    bool isEmpty() const;
    string raffle(qNode *, int) const;
    int sizeLine(qNode *) const;
    int returnQ() const;
    
};

#endif