#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>

using namespace std;

template <class T> struct Node
{
	Node (T data) : data(data), next(NULL), prev(NULL) {}
	T data;
	Node * next;
	Node * prev;
	~Node() {if (next != NULL) delete next;}
};

template <class T> class LList {
	protected:
		int cnt;
		Node<T> *front, *rear;

	public:
		int size() const {return cnt;};
		bool empty() const {return front == rear;};

		LList() : cnt(0), front(NULL), rear(NULL) {}
		~LList() {if (front != NULL) delete front; if (rear != NULL) delete rear;}

		LList (const LList <T> & list)
		{
			cout << "Copying...";
			cnt = 0;
			front = rear = NULL;
			Node <T> * current = list->front;

			for (int i=0; i<list->cnt+1; i++)
			{
				insert (current->data, i);
				current = current->next;
			}
			cout << " Done!" << endl;
		}

        LList<T> & insert(const T & v, int pos)
        {
            pos = pos > cnt ? cnt : pos < 0 ? 0 : pos;
            Node<T> * nn = new Node<T>(v);
            Node<T> * current = front;

            for (int i=1; i<pos; i++) current = current->next;

            if (pos == 0)
            {
                front = nn;
                nn->next = current;
                if (cnt == 0) rear = nn;
                else current->prev = nn;
            }
            else
            {
                nn->next = current->next;
                nn->prev = current;
                current->next = nn;
                if (current == rear) rear = nn;
                else nn->next->prev = nn;
            }
            cnt++;
            return * this;
        }

        T remove (int pos)
        {
            assert(pos >= 0 && pos < cnt);

            Node<T> * current = front;
            for (int i=0; i<pos; i++) current = current->next;
            T v = current->data;

            if (current == front) front = current->next;
            else current->prev->next = current->next;

            if (current == rear) rear = current->prev;
            else current->next->prev = current->prev;

            cnt--;
            return v;
        }

		void show(bool dir = true) const
		{
			int i= dir? 0 : cnt-1;
			Node <T> * current = dir ? front : rear;
			while (current != NULL)
			{
				cout << "\t\t  Node[" << setw(2) << setfill ('0') << i << "]:  "
					 << left << setfill (' ') << setw(5) << fixed << setprecision(2)
					 << current->data << right << setw(2) << "| "
					 << "prev:  " << setw(8) << current->prev
					 << " | curr: " << setw(8) << current
					 << " | next: " << setw(8) << current->next << endl;

				dir ? i++ : --i;
				current = dir ? current->next : current->prev;
			}
			cout << endl;
		}
};
#endif
		