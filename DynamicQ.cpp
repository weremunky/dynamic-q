#include <iostream>
#include <cstring>
#include <cctype>
#include "DynamicQ.h"

Line::~Line() //Destructor
{
  while(!isEmpty())
  {
    delLine(); //Deletes the content in the line
  }
}

Line::Line() //Constructor
{
  front = nullptr;
  back = nullptr;
}

void Line::addLine(string name)
{
    if (name.size() > 20) //Checks if the length is more than 20 letters
    {
        exit(EXIT_FAILURE);
    }
    
    qNode *newNode = nullptr;
    
    newNode = new qNode; //Creates a new node in stack
    newNode->custName = name;  //Stores the name into the stack node
    
    newNode->raffleTicket = (rand() % 500) + 1; //Random ticket number from 1 to 500
    newNode->next = nullptr;
    
    if(isEmpty()) //If the stack currently contains no elements
    {
        cout << "\nWelcome, " << name <<"! Your raffle number is " << newNode->raffleTicket << "!\n" << endl;
        front = newNode;
        back = newNode;
    }
    
    else //If the stack contains any elements
    {
        cout << "\nWelcome, " << name <<"! Your raffle number is " << newNode->raffleTicket << "!\n" << endl;
        back->next = newNode;
        back = newNode;
    }
}

void Line::delLine()
{
    qNode *temp = nullptr;
    
    if(isEmpty()) //If the stack is empty
    {
        cout<<"\nNeed customers in the line.\n";
    }
    
    else //Lets the next person in the stack to order
    {
        string name = front->custName;
        temp = front;
        front = front->next;
        delete temp;
        
        cout << endl << name <<", you can order now!\n";
    }
    
}

void Line::displayLine() const
{
    if (front == nullptr) //Can't displply the current customers if there is no customer in the front
    {
        cout << "\nThere are currently no customers in the line.\n\n";
    }
    
    else
    {
      int pos = 1; //Initial position of the first customer
      qNode *nodePtr = front;
      while (nodePtr != nullptr) //While loop to list all the current customers
      {
        cout << "(" << pos << ") " << "Name: " << nodePtr->custName << "  Ticket: " << nodePtr->raffleTicket << endl;
        nodePtr = nodePtr->next;
        pos++;
      }
    }
}

void Line::raffleWinner() const
{
  string winner = "none";
  
  while (winner == "none") //Does the raffle again, if there was no winner
  {
    winner = raffle(front, 500);
  }

  cout << "\nCongratulations, " << winner << "! You are a raffle winner!\n\n";
  cout << "Select one of the offered prizes: \n";
 
  int select; //User option
  
  cout << "1. A free t-shirt\n2. A free side dish\n\nOption: ";
  cin >> select;

  switch (select)
  {
    case 1:
      cout << "\nYou’re going to look great in your new tee!\n\n";
      break;
    case 2:
      cout << "\nEnjoy your free side dish!\n\n";
      break;
  }
}

bool Line::isEmpty() const
{
  bool empty;

  if(returnQ() > 0) //If the size of the queue is more than 0
  {
    empty = false;
  }
  else
  {
    empty = true;
  }
  return empty;
}

string Line::raffle(qNode* nodePtr, int max) const
{
  string winner = "none"; //Winner is set to none if there is no winner in the raffle
  
  int randPick = (rand() % max) + 1; //Random pick from 1 to maximum
  
  if (nodePtr == nullptr) 
  {
    return winner;
  }
  
  if (nodePtr->raffleTicket == randPick) //"If" loop if the raffle ticket matches with the random pick
  {
    winner = nodePtr->custName;
  } 
  
  else //If the ticket doesn't match, the recursion goes through the queue to get the winner 
  {
    winner = raffle(nodePtr->next, max);
  }
  return winner;
}

int Line::sizeLine(qNode *nodePtr) const //Size of the line 
{
  if (nodePtr != nullptr) //Recursion to get the size of the nodes
  {
    return 1 + sizeLine(nodePtr->next); //Adds 1 to the size of the nodes until it reaches the end
  }
  
  else
  {
    return 0;
  }
}

int Line::returnQ() const
{
  int size = sizeLine(front); //Sets the size of the line to a size integer
  return size;
}










