/*
 * SingleLinkedList.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: carolsusieo
 */

#include <iostream>

using namespace std;

#include <cstdlib>
#include <time.h>
#include <stdio.h>


#include "SingleLinkedList.h"


SingleLinkedList::SingleLinkedList(int num)
{
      list = new LinkList<int>();
      lsize = num;
      // add elements 1, ... lsize
	  srand(time(NULL));
      for (int i = 0; i < lsize; i++)
      {
    	  list->insertFirst((int)(rand() % (int)(100)));
      }
}

SingleLinkedList::~SingleLinkedList() {
	// TODO Auto-generated destructor stub
	delete list;
}

void SingleLinkedList::main(char** args) {
	if(list == (LinkList<int>*)0)
	{
		  list = new LinkList<int>();
		  // eclipse configuration set up to send parameter
		  lsize = atoi(args[0]);

		  cout << lsize << " random integers between 0 and 99";
		  srand(time(NULL));
		  for (int i = 1; i <= lsize; i++)
		  {
			  list->insertFirst((int)(rand() % (int)(100)));
		  }
	}
	  list->printList();

	  while(!list->isEmpty()) {
			int deleteValue = list->getFirstItem();
			list->deleteFirst();
			lsize--;
			cout << "deleted: " << deleteValue << "\n";
	  }
	  list->printList();
}

void SingleLinkedList::show(){
	list->printList();
}

template <class Item>
LinkList<Item>::LinkList() {
		first = (Node<Item>*)0;
}

template <class Item>
LinkList<Item>::~LinkList() {
	while(first != (Node<Item>*) 0)
	{
		deleteFirst();
	}
}
	//Inserts a new Link at the first of the list
template <class Item>
void LinkList<Item>::insertFirst(Item item) {
   Node<Item>* link = new Node<Item>();
	link->item = item;
	link->nextLink = first;
	first = link;
}

	//Deletes the link at the first of the list

template <class Item>
Item LinkList<Item>::getFirstItem() {
	return first->item;
}

template <class Item>
Item LinkList<Item>::getItem(int i) {

	Node<Item>* currentLink = first;
	for (int j = 0; j < i && currentLink != (Node<Item>*)0;j++)
		currentLink = currentLink->nextLink;
	if(currentLink == ((Node<Item>*) 0))
		return (Item)0;
	return currentLink->item;
}


template <class Item>
void LinkList<Item>::printList() {
	Node<Item>* currentLink = first;
	cout << "List: ";
	while(currentLink != (Node<Item>*) 0) {
		cout << currentLink->item << " ";
			currentLink = currentLink->nextLink;
	}
	cout << "\n";
}


int main(int num, char** args)
{
	SingleLinkedList go(20);
	go.main(args);
}

