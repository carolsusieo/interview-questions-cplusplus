/*
 * DoubleLinkedList.h
 *
 *  Created on: Feb 2, 2016
 *      Author: carolsusieo
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_


class DoubleLinkedList {
public:
	DoubleLinkedList();
	virtual ~DoubleLinkedList();
	void main(char**);

};



template <class Item>
class DoublyLinkedList implements Iterable<Item> {
	private:
		template <class ItItem>
		class DoublyLinkedListIterator implements ListIterator<ItItem> {
			private:
				Node current;
				Node lastAccessed;
				int index = 0;

			  public:
				  bool hasNext()      { return index < N; }
				  bool hasPrevious()  { return index > 0; }
				  int previousIndex()    { return index - 1; }
				  int nextIndex()        { return index;     }

				  Item next();
				  Item previous();
				  void set(Item item);
				  void remove();
				  void add(Item item);

		  }

	private:
		template <typename Items>
		struct Node {
			  Items item;
			  Node* next;
			  Node* prev;
		  }
		int N;        // number of elements on list
		Node<Item>* pre;     // sentinel before first item
		Node<Item>* post;    // sentinel after last item

	public:
		 ListIterator<Item> iterator()  { return new DoublyLinkedListIterator(); }

		DoublyLinkedList();
		~DoublyLinkedList();

		bool isEmpty()    { return N == 0; }
		int size()           { return N;      }

		void add(Item item);


		public char* toString();
}

#endif /* DOUBLELINKEDLIST_H_ */

/*
 *
  */

