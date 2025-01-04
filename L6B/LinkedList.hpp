/* CSCI 200: L6A
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 * Description: Learn to use arrays and linked lists
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class LinkedList final : public IList<T> {
private: 
    struct Node {
        T value;
        Node* pNext;
        Node* pPrev;
    };

    Node* _pHead;
    Node* _pTail;
    int _size;
public:
    LinkedList();
    ~LinkedList();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;
    void sort() override;
    Node* mergeSort(Node*);
    Node* merge(Node*, Node*);
    Node* getMiddle(Node*);
};

//---------------------------------------------------------

using namespace std;

template<typename T>
LinkedList<T>::LinkedList() {
    // set size to zero
    _size = 0;
    // set head to be a nullptr
    _pHead = nullptr;
    // set tail to be a nullptr
    _pTail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    // remove each node in the list
    Node* current = _pHead;
    while (current != nullptr) {
        Node* temp = current;
        current = current->pNext;
        delete temp;
    }
    _pHead = _pTail = nullptr;
    _size = 0;
}

template<typename T>
int LinkedList<T>::size() const {
    return _size;
}

template<typename T>
T LinkedList<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if(POS>=_size || POS<0) {
        throw out_of_range("Position is greater than the size of the list.");
    }
    // set current node to head
    Node* current = _pHead;
    // advance current node to POS
    for (int i = 0; i < POS; ++i) {
        current = current->pNext;
    }
    // return value of current node
    return current->value;
}

template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if(POS>=_size || POS<0) {
        throw out_of_range("Pos is greater than the size of the array or pos is negative.");
    }
    // set current node to head
    Node* current = _pHead;
    // advance current node to POS
    for (int i = 0; i < POS; ++i) {
        current = current->pNext;
    }
    // set value of current node   
    current->value = VALUE;
}

template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    int thePos = POS;
    // if POS is before zero, clamp to zero
    if(POS<0) {
        thePos = 0;
    }
    // if POS is after size, clamp to size
    if(POS>_size) {
        thePos = _size;
    }
    // create pointer to new node
    Node* pTemp = new Node;
    // set value to be VALUE
    pTemp->value = VALUE;
    // set previous pointer to nullptr
    pTemp->pPrev = nullptr;
    // set next pointer to nullptr
    pTemp->pNext = nullptr;
    // if list is currently empty
    if (_size == 0) {
        // set head and tail to new node
        _pHead = _pTail = pTemp;
    // else if position is before head
    } else if (thePos == 0) {
        // set new node next to be head
        pTemp->pNext = _pHead;
        // set head previous to be new node
        _pHead->pPrev = pTemp;
        // set head to be new node
        _pHead = pTemp;
    // else if position is after tail
    } else if (thePos == _size) {
        // set new node previous to be tail
        pTemp->pPrev = _pTail;
        // set tail next to be new node
        _pTail->pNext = pTemp;
        // set tail to be new node
        _pTail = pTemp;
    // otherwise
    } else {
        // set current node to head
        Node* current = _pHead;
        // advance current node to pos
        for (int i = 0; i < thePos; ++i) {
            current = current->pNext;
        }
        // link new node into current list
        pTemp->pPrev = current->pPrev;
        pTemp->pNext = current;
        // link current list to new node
        current->pPrev->pNext = pTemp;
        current->pPrev = pTemp;
    }
    // increment size
    _size++;
}

template<typename T>
void LinkedList<T>::remove(const int POS) {
    int thePos = POS;
    // if array is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("List is empty.");
    }
    // if POS is before zero, clamp to zero
    if(POS<0) {
        thePos = 0;
    }
    // if POS is after size, clamp to size
    if(POS>=_size) {
        thePos = _size-1;
    }
    Node* toDelete = nullptr;
    // if list has one element
    if (_size == 1) {
        // set node to delete to head
        toDelete = _pHead;
        // set head and tail to be nullptr
        _pHead = _pTail = nullptr;
    // else if deleting head
    } else if (thePos == 0) {
        // set node to delete to head
        toDelete = _pHead;
        // advance head to next
        _pHead = _pHead->pNext;
        // set head previous to nullptr
        if (_pHead) {
            _pHead->pPrev = nullptr;
        }
    // else if deleting tail
    } else if (thePos == _size - 1) {
        // set node to delete to tail
        toDelete = _pTail;
        // step tail to previous
        _pTail = _pTail->pPrev;
        // set tail next to nullptr
        if (_pTail) {
            _pTail->pNext = nullptr;
        }
    // otherwise
    } else {
        // set current node to head
        Node* current = _pHead;
        // advance current node to space before position
        for (int i = 0; i < thePos; ++i) {
            current = current->pNext;
        }
        // set node to delete to the current node's next node
        toDelete = current;
        // unlink node to delete
        current->pPrev->pNext = current->pNext;
        if (current->pNext) {
            current->pNext->pPrev = current->pPrev;
        }
    }
    // delete node
    delete toDelete;
    // decrement size
    _size--;
}


template<typename T>
T LinkedList<T>::min() const {
    // if list is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("Size of array is 0.");
    }
    // find minimum value within list
    Node* current = _pHead;
    T minimum = current->value;
    for(int i=1; i<_size; i++) {
        current = current->pNext;
        if(current->value<minimum) {
            minimum = current->value;
        }
    }
    // return min value
    return minimum;
}

template<typename T>
T LinkedList<T>::max() const {
    // if list is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("Size of array is 0.");
    }
    // find maxiumum value within list
    Node* current = _pHead;
    T maximum = current->value;
    for(int i=1; i<_size; i++) {
        current = current->pNext;
        if(current->value>maximum) {
            maximum = current->value;
        }
    }
    // return max value
    return maximum;
}

template<typename T>
int LinkedList<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    // return index of first occurrence if found
    Node* current = _pHead;
    for(int i=0; i<_size; i++) {
        if(current->value==VALUE) {
            cout << current->value << " " << VALUE << endl;
            return i;
        }
        current = current->pNext; 
    }    
    // otherwise return -1
    return -1;
}

template<typename T>
void LinkedList<T>::sort() {
    _pHead = mergeSort(_pHead);
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::mergeSort(Node* head) {
    if (!head || !head->pNext) return head;
    // Split the list into two halves
    Node* middle = getMiddle(head);
    Node* secondHalf = middle->pNext;
    middle->pNext = nullptr; // Break the list into two parts

    // Recursively sort both halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(secondHalf);

    // Merge the sorted halves
    return merge(left, right);
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::merge(Node* left, Node* right) {
    Node dummy;
    Node* tail = &dummy;

    while (left && right) {
        if (left->value <= right->value) {
            tail->pNext = left;
            left = left->pNext;
        } else {
            tail->pNext = right;
            right = right->pNext;
        }
        tail = tail->pNext;
    }

    // Attach the remaining nodes
    if (left) {
        tail->pNext = left;
    } else {
        tail->pNext = right;
    }

    return dummy.pNext;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::getMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head->pNext;

    while (fast && fast->pNext) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
    }

    return slow;
}

#endif//LINKED_LIST_H
