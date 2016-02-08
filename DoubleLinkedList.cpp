/*
 * DoubleLinkedList.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: carolsusieo
 */
/*
#include "DoubleLinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
	// TODO Auto-generated constructor stub
}
DoubleLinkedList::~DoubleLinkedList() {
	// TODO Auto-generated destructor stub
}

void DoubleLinkedList::main(char** args) {
		  // eclipse run configuration is set up to send in parameter
	      int N  = Integer.parseInt(args[0]);

	      // add elements 1, ..., N
 	      cout << N <<> " random integers between 0 and 99";
	      DoublyLinkedList<Integer> list = new DoublyLinkedList<Integer>();
	      for (int i = 0; i < N; i++)
	          list.add(ThreadLocalRandom.current().nextInt(0, 99 + 1));

	      cout << list;
	      cout << ;

	      ListIterator<Integer> iterator = list.iterator();

	      cout << "add 1 to each element via next() and set()";
	      while (iterator.hasNext()) {
	          int x = iterator.next();
	          iterator.set(x + 1);
	      }
	      cout << list;
	      cout << "\n"

	      cout << "multiply each element by 3 via previous() and set()";
	      while (iterator.hasPrevious()) {
	          int x = iterator.previous();
	          iterator.set(x + x + x);
	      }
	      cout << list;
	      cout << "\n";


	      // remove all elements that are multiples of 4 via next() and remove()
	      cout << "remove elements that are a multiple of 4 via next() and remove()";
	      while (iterator.hasNext()) {
	          int x = iterator.next();
	          if (x % 4 == 0) iterator.remove();
	      }
	      cout << list;
	      cout << "\n";


	      // remove all even elements via previous() and remove()
	      cout << "remove elements that are even via previous() and remove()";
	      while (iterator.hasPrevious()) {
	          int x = iterator.previous();
	          if (x % 2 == 0) iterator.remove();
	      }
	      cout << list;
	      cout << "\n";


	      // add elements via next() and add()
	      cout << "add elements via next() and add()";
	      while (iterator.hasNext()) {
	          int x = iterator.next();
	          iterator.add(x + 1);
	      }
	      cout << list;
	      cout << "\n";

	      // add elements via previous() and add()
	      cout << "add elements via previous() and add()";
	      while (iterator.hasPrevious()) {
	          int x = iterator.previous();
	          iterator.add(x * 10);
	          iterator.previous();
	      }
	      cout << list;
	      cout << "\n";
	  }

}
template <class Item>
DoublyLinkedList::DoublyLinkedList() {
      pre  = new Node();
      post = new Node();
      pre.next = post;
      post.prev = pre;
 }
 // add the item to the list
template <class Item>
void DoubleLinkedList::add(Item item) {
      Node* last = post.prev;
      Node* x = new Node();
      x->item = item;
      x->next = post;
      x->prev = last;
      post->prev = x;
      last->next = x;
      N++;
  }


template <class ItItem>
DoublyLinkedList::DoublyLinkedList()
{
	N = 0;
      current      = pre.next;  // the node that is returned by next()
      lastAccessed = (Node*) 0;      // the last node to be returned by prev() or next()
                                             // reset to null upon intervening remove() or add()
      index = 0;
}

template <class ItItem>
ItItem DoublyLinkedList::next() {
          if (!hasNext()) throw new NoSuchElementException();
          lastAccessed = current;
          ItItem item = current.item;
          current = current.next;
          index++;
          return item;
      }
template <class ItItem>
      ItItem DoublyLinkedList::previous() {
          if (!hasPrevious()) throw new NoSuchElementException();
          current = current.prev;
          index--;
          lastAccessed = current;
          return current.item;
      }

      // replace the item of the element that was last accessed by next() or previous()
      // condition: no calls to remove() or add() after last call to next() or previous()
template <class ItItem>
      void DoublyLinkedList::set(Item item) {
          if (lastAccessed == null) throw new IllegalStateException();
          lastAccessed.item = item;
      }

      // remove the element that was last accessed by next() or previous()
      // condition: no calls to remove() or add() after last call to next() or previous()
template <class ItItem>
      void DoublyLinkedList::remove() {
          if (lastAccessed == null) throw new IllegalStateException();
          Node x = lastAccessed.prev;
          Node y = lastAccessed.next;
          x.next = y;
          y.prev = x;
          N--;
          if (current == lastAccessed)
              current = y;
          else
              index--;
          lastAccessed = null;
      }

      // add element to list
template <class ItItem>
      void DoublyLinkedList::add(Item item) {
          Node x = current.prev;
          Node y = new Node();
          Node z = current;
          y.item = item;
          x.next = y;
          y.next = z;
          z.prev = y;
          y.prev = x;
          N++;
          index++;
          lastAccessed = null;
      }



  public String toString() {
      StringBuilder s = new StringBuilder();
      for (Item item : this)
          s.append(item + " ");
      return s.toString();
  }
*/


  // different source
//http://code.runnable.com/UstrK4WeAwE0AAFl/templated-doubly-linked-list-with-forward-and-reverse-traversal-for-c%2B%2B


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "LList.h"
#include "menu.h"

using namespace std;

int randInt() {return rand()/(RAND_MAX/100);}
float randFloat() {return (float)rand()/(float)(RAND_MAX/4);}
int randPos(int size) {if (size == 0) return 0;return rand()/(RAND_MAX/size);}
void error() {cout << "\n\t\t\t A list is empty!";}
void format() {cout << "\t\t+" << setw(70) << setfill('=') << "+" << endl;}

// Function Declarations
	template <class T> void insertFloat(T &);
	template <class T> void insertInt(T &);
	template <class T> void remove(T &);


int mainDouble()
{
	srand( time( NULL ) );

	const char * mainMenu[] =
	{
		"+=========================================+",
		"|      Doubly Linked List Structures      |",
		"+=========================================+",
		"| F/f: Create one double and one integer  |",
		"|    list, and insert 10 random values in |",
		"|    each list. The value ranges of lists |",
		"|    are 0.00 .. 4.00 and 10 .. 99.       |",
		"+-----------------------------------------+",
		"| S/s: Show two lists in both directions  |",
		"+-----------------------------------------+",
		"| A/a: Ask for a double and an integer,   |",
		"|    insert the values at random          |",
		"|    positions of the lists.              |",
		"+-----------------------------------------+",
		"| D/d: Generate a random position, and    |",
		"|    remove values at the positions of    |",
		"|    the two lists.  Show values removed  |",
		"+-----------------------------------------+",
		"| H/h/?: Show this menu.                  |",
			"+-----------------------------------------+",
			"| Q/q: Exit program.                      |",
			"+-----------------------------------------+",0
	};
	int pos=0;
	char choice = ' ';
	Menu m(mainMenu);
	LList <int> * intList = NULL;
	LList <float> * floatList = NULL;

	while ( true )
	{
	    choice = ' ';
	    cin.clear();
	    cout << endl;
		choice = m.prompt("Enter a command (Q to quit, H for help):  ");
		switch (toupper(choice))
		{
			case 'F' :
				if (floatList == NULL) floatList = new LList<float>();
				if (intList == NULL) intList = new LList<int>();

				pos = intList->size();
				for (int i=0; i<10; i++)
				{
					intList->insert(randInt(), pos);
					pos++;
				}
				pos = floatList->size();
				for (int i=0; i<10; i++)
				{
					floatList->insert(randFloat(), pos);
					pos++;
				}
				break;
			case 'S' :
					if (intList == NULL || floatList == NULL) {error(); break;}
					if (intList->size() == 0 || floatList->size() == 0) {error(); break;}

					format();
					cout << "\t\t|    Int List     | Previous ADDR   | Current ADDR   | Next ADDR      |" << endl;
					format();
					intList->show();
					intList->show(false);
					cout << endl;

					format();
					cout << "\t\t|    Float List   | Previous ADDR   | Current ADDR   | Next ADDR      |" << endl;
					format();
					floatList->show();
					floatList->show(false);

					break;

				case 'A' :
					if (intList == NULL || floatList == NULL) {error(); break;}
					insertInt(intList);
					insertFloat(floatList);
					break;

				case 'D' :
					if (intList == NULL || floatList == NULL) {error(); break;}
					if (intList->size() == 0 || floatList->size() == 0) {error(); break;}
					remove (intList);
					remove (floatList);
					break;

				case '?' : case 'H' : m.show(); break;
				case 'Q' : delete intList; delete floatList; exit(0);
				default  : cout << "\n\t\t\t Illegal selection."; break;
				}
		}
		return 0;
	}


template <class T>
void insertFloat(T & floatList)  {
	char char_tmp[10];
	cout << "\t\t\t Enter a float to be inserted:  "; cin.getline(char_tmp, 10);
	while (atof(char_tmp) < 0.00 || atof(char_tmp) > 4.00 || isalpha(char_tmp[0]))
	{
		cout << "\t\t\t Invalid input.  Enter a float to be inserted:  ";
		cin.getline(char_tmp, 10);
	}
	int pos = randPos(floatList->size());
	floatList->insert(atof(char_tmp), pos);
	cout << "\n\t\t\t Float " << atof(char_tmp) << " inserted into position " << pos;
}

template <class T>
void insertInt(T & intList)
{
	char char_tmp[10];
	cout << "\t\t\t Enter an int to be inserted:  ";
	cin.getline(char_tmp, 10);
	while (atoi(char_tmp) < 0 || atoi(char_tmp) > 99 || isalpha(char_tmp[0]))
	{
		cout << "\t\t\t Invalid input.  Enter an int to be inserted:  ";
		cin.getline(char_tmp, 10);
	}
	int pos = randPos(intList->size());
	intList->insert(atoi(char_tmp), pos);
	cout << "\n\t\t\t Int " << atoi(char_tmp) << " inserted into position " << pos;
}

template <class T>
void remove(T & list)
{
	int pos = randPos(list->size());
	cout << "\n\t\t\t Removed " << list->remove(pos) << " from position " << pos;
}



