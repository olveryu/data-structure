#include "ItemType.h"
#include "CircularLinkedList.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int cinNumber();

int main(const int argc, const char * argv[]){
  CircularLinkedList list;
  ItemType item;
  int input;
  string command;
  fstream fs;
  int number;

  // open file and put all the variable in the linkedList
  fs.open(argv[1],ifstream::in);
  if(fs.is_open()){
    fs >> input;
    while(!fs.eof()){
      item.initialize(input);
      list.insertItem(item);
      fs >> input;
    }
  }
  else{
    cout << "File could not be opened. " <<
      "Try again." << endl;
    return 0;
  }

  // prompt user for command
  cout << "Commands - insert (i), delete (d), length (l), print (p), quit (q)" << endl;
  cout << "enter command: ";
  cin >> command;
  while(true){
    // command quit
    if(command == "q"){
      break;
      
      //command print
    }else if(command == "p"){
      if(list.lengthIs() == 0){
	cout << "list is empty" << endl;
      }else{
	list.print();
      }
      
      // command insert
    }else if(command == "i"){
      cout << "number to insert: ";
      number = cinNumber();
      item.initialize(number);
      list.insertItem(item);
      list.print();
      
      // command delete
    }else if(command == "d"){
      cout << "number to delete: ";
      number = cinNumber();
      item.initialize(number);
      list.deleteItem(item);
      if(item.getValue() == -99999){
	cout << "item does not exit" << endl;
      }else{
	list.print();
      }

      // command length
    }else if(command == "l"){
      cout << list.lengthIs() << endl;

      // invalid command
    }else{
      cout << "Command not recognized. Try again" << endl;
    }
    cout << "enter command: ";
    cin >> command;
  }
  return EXIT_SUCCESS;
}

int cinNumber(){
  int x;
  cin >> x;
  while(cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "invalid entry." << endl << "Enter a number: ";
      cin >> x;
    }
  return x;
}
