/*
*
* Ian Angel
*
* 
*
* May 2023
*
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include "DynamicQ.h"
using namespace std;

void menu(); //Function that outputs the header and lists the options to the user

void lineName(Line &); //Function that obtains the customer's name

void lineOrder(Line &); //Function that lets the next customer in the queue to order

void lineCount(Line &); //Function that counts the number of customers in the line

void lineWinner(Line &); //Function that chooses the random winner in the raffle

void lineCustomer(Line &); //Function that shows the customers in order with their ticket numbers

void exitProgram(); //Function to exit the program

int main()
{
    Line queue;
    int option;
    
    while (option != 6)
    {
        menu();
        cin >> option; //User option input
        
	    switch(option) //Switch statement to create a menu loop
        {
            case 1:
                lineName(queue);
                break;
            case 2:
                lineOrder(queue);
                break;
            case 3:
                lineCount(queue);
                break;
            case 4:
                lineWinner(queue);
                break;
            case 5:
                lineCustomer(queue);
                break;
            case 6:
                exitProgram();
                break;
                
        }
        
    }
    
}
    

void menu()
{
  cout << "\nWelcome to Point Loma Seafoods!\n\n" << "1. Add a Name\n" << "2. Place an Order\n" << "3. Count names in line\n" << "4. Draw Raffle Winner\n"<< "5. Display the Line\n" << "6. Exit\n";

  cout << "\nChoose an option: ";
}

void lineName(Line &queue)
{
  string name;
  cout << "Enter your name: ";
  cin >> name;
  
  if(name.size() > 20) //Checks if the name length is more than 20 letters
  {
    cout << "\n\nError\n" << "The name must be less than 20 letters\n" << "Name: ";
    cin >> name; //If it is more than 20 characters, the user will have to put their name again considering the given terms
  }
  
  queue.addLine(name); //Adds the customer to the line
}

void lineOrder(Line &queue)
{
    queue.delLine(); //Lets the next customer in line to order
}

void lineCount(Line &queue)
{
  if (queue.returnQ() == 1) //Displays the single customer, if there is only 1
  {
    cout << "\nThere is " << queue.returnQ() << " person in line.\n\n";
  }
    
  else //Displays all the current customers if there are more (or 0) than 1
  {
    cout<<"\nThere are "<< queue.returnQ() << " people in line.\n\n";
  }
  
}

void lineWinner(Line &queue)
{
  if(queue.returnQ() == 0) //If there are no current customers present
  {
    cout<<"\n\nThere are currently no people participating in the raffle.\n";
  }
  
  else //If there are, it chooses the random winner
  {
    queue.raffleWinner();
  }
}

void lineCustomer(Line &queue) //Displays the current customers with their number in line, name, and a raffle ticket 
{
  cout << "\nLine: \n";
  queue.displayLine();
}

void exitProgram() //Function to exit the program
{
  cout << "\nThank you for coming to Point Loma Seafoods!\n";

  exit (0);
}


