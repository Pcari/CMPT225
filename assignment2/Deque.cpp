/* 
Assignment 2
name : Ben Jae
Student #: 301048319
Course: CMPT 225
*/
/* Deque.cpp */
#include <cstring>
#include <iostream>

#include "Deque.h"

using namespace std;

Deque::Deque() {
	current_size = 0;
	left_p = NULL;
	right_p = NULL;
	cursor = NULL;

}

Deque::Deque(const Deque& dq) {
	if (dq.left_p == NULL) {
		return;
	}
	left_p = NULL;
	right_p = NULL;
	cursor = NULL;
	current_size = dq.current_size;
	node* current = dq.left_p;

	left_p = new node(current->data, NULL, NULL);
	node* tmp = left_p;

	current = current->next;
	while (current != NULL) {
		tmp->next = new node(current->data, tmp, NULL);
		if (current->prev == dq.cursor) {
			cursor = tmp;
		}
		tmp = tmp->next;
		current = current->next;
		right_p = tmp;

	}
}
//Destructor
Deque::~Deque() {
	if (left_p != NULL && right_p != NULL) {
		
		while (left_p != NULL) {
			node* tmp = left_p;
			left_p = left_p->next;
			delete tmp;				
		}
	}
}

void Deque::push_left( int item ) {
	/*
	if (left_p == NULL) {
		left_p = new node(item, NULL, NULL);
		right_p = left_p;
		cursor = left_p;
	} else { //not empty
		left_p = new node(item, NULL, left_p);
	}
	*/
	node* tmp = new node(item, NULL, NULL);
	if (left_p == NULL) {
		left_p = tmp;
		right_p = tmp;
		cursor = left_p;
	} else {
		tmp->next = left_p;
		left_p->prev = tmp;
		left_p = tmp;
	}	
	current_size++;
}

void Deque::push_right(int item) {
	/*
	if (right_p == NULL) {
		right_p = new node(item, NULL, NULL);
		left_p = right_p;
		cursor = right_p;
	} else { // not empty
		right_p = new node(item, right_p, NULL);
	}
	*/
	
	node* tmp = new node(item, NULL, NULL);
	if (right_p == NULL) {
		left_p = tmp;
		right_p = tmp;
		cursor = right_p;
	} else {
		tmp->prev = right_p;
		right_p->next = tmp;
		right_p = tmp;
	}
	current_size++;
}

    /* Removal operators */
	// removes and returns item on left end.
    int Deque::pop_left() {
    	node* old_left = left_p;
    	int tmp = old_left->data;
    	left_p = left_p->next;
    	if (cursor == old_left) {
    		cursor = old_left->next;
    	}
    	if (left_p == NULL) {
    		right_p = NULL;
    	} else {
    		left_p->prev = NULL;	
    	}
    	
    	delete old_left;
    	current_size--;
    	return tmp;
        // Pre: Deque is not empty.
    }
    // removes and returns item on right end.
    int Deque::pop_right() {
    	node* old_right = right_p;
    	int tmp = old_right->data;
    	right_p = right_p->prev;
    	if (cursor == old_right) {
    		cursor = old_right->prev;
    	}
    	if (right_p == NULL) {
    		left_p = NULL;
    	} else {
    		right_p->next = NULL;
    	}
    	delete old_right;
    	current_size--;
    	return tmp;
        // Pre: Deque is not empty.
    }

    /* Size functions */
      // Returns true iff the Deque contains no items.
    bool Deque::empty() {
    	return left_p == NULL;
    }
    // Returns the current number of items in the deque.
    int Deque::size() {
    	return current_size;
    } 

    /* Cursor movement operators
    *  These move the cursor one node to the left or right and then 
    *  return true if such a move is possible.  If the move is not 
    *  possible (i.e., the cursor is already at the extreme end
    *  or the Deque is emty), no change occurs and false is returned. 
    */
    // Move cursor left.
    bool Deque::cursor_left() { 

    	if (cursor->prev == NULL || cursor == NULL) {
    		return false;
    	} else {
    		cursor = cursor->prev;
    		return true;
    	}
    	
    }
    // Move cursor right.
    bool Deque::cursor_right() {
    	if (cursor->next == NULL || cursor == NULL) {
    		return false;
    	} else {
    		cursor = cursor->next;
    		return true;
    	}
    }

    /* Accessor functions */
    // Returns the left-most item without removing it.
    int Deque::peek_left() {
    	return left_p->data;
    }   
        // Pre: Deque is not empty.

    // Returns the right-most item without removing it.
    int Deque::peek_right() {
    	return right_p->data;
    }  
        // Pre: Deque is not empty.
    // Return value the cursor currently is at,
    int Deque::get_cursor()  {
    	return cursor->data;
    }  
        // Pre: Deque is not empty.
    void Deque::set_cursor(int i) {
    	cursor->data = i;
    } 
        // Pre: Deque is not empty.

    /* Utility functions */
    void Deque::display() { // prints a depiction of the deque contents to standard output.    

	   	node* current = left_p;
	   	cout << "[";
	   	while (current != NULL) {
	   		cout << current->data << ";";
	   		current = current->next;	
    	}
    	cout << "]" << " size=" << current_size << "," << "cursor=";
	   	if (cursor == NULL) {
	   		cout << "NULL." << endl;;
	   	} else {
	   		cout << cursor->data << "." << endl;	
	   	} 
    	

    }
    // like display, but includes node addresses and pointer values. 
    void Deque::verbose_display() {
    	/*
    	if (left_p == NULL) {
    		cout << "[] size=" << current_size << ", cursor=" << cursor << endl;
    	} else {
    		*/
    		node* current = left_p;
    		cout << "[";
    		while (current != NULL) {
    			cout << &current->data << ";";
    			current = current->next;
    		}
    		cout << "]" << " size=" << current_size << ", cursor=" << &cursor->data << endl;
    	
    }
