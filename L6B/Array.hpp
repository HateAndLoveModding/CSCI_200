#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array final : public IList<T> {
public:
    Array();
    ~Array();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;
    void sort() override;
    void mergeSort(T*, int, int);
    void merge(T*, int, int, int);

private:
    int _size;
    T* _pArray;
};

//---------------------------------------------------------
using namespace std;

template<typename T>
Array<T>::Array() {
    // set size to zero
    _size = 0;
    // set array to be a nullptr
    _pArray = nullptr;
}

template<typename T>
Array<T>::~Array() {
    if (_pArray) {
        delete[] _pArray;
        _pArray = nullptr;  // Prevent double deletion
    }
}

template<typename T>
int Array<T>::size() const { 
    return _size;
}

template<typename T>
T Array<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if(POS>=_size || POS<0) {
        throw out_of_range("Position is greater than the size of the array.");
    }
    // return value at POS within array
    return _pArray[POS];
}

template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if(POS>=_size || POS<0) {
        throw out_of_range("Position is greater than the size of the array.");
    }
    // set VALUE at POS within array    
    _pArray[POS] = VALUE;
}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    int thePos = POS;
    // if POS is before zero, clamp to zero
    if(POS<0) {
        thePos = 0;
    }
    // if POS is after size, clamp to size
    if(POS>_size) {
        thePos = _size;
    }
    // create new array of size + 1
    T* temp = new T[_size+1];
    // copy elements 0 to POS from old array to new array
    for(int i=0; i<thePos; i++) {
        temp[i] = _pArray[i];
    }
    // set element at POS in new array to VALUE
    temp[thePos] = VALUE;
    // copy elements POS to size from old array to new array
    for(int i=thePos; i<_size; i++) {
        temp[i+1] = _pArray[i];
    }
    // delete old array
    delete[] _pArray;
    // set old array to be new array
    _pArray = temp;
    // increment size
    _size++;
}

template<typename T>
void Array<T>::remove(const int POS) {
    int thePos = POS;
    // if array is empty, throw std::out_of_range exception
    if(_size==0) {
        throw out_of_range("Size of Array is 0.");
    }
    // if POS is before zero, clamp to zero
    if(POS<=0) {
        thePos = 0;
    }
    // if POS is after size, clamp to size
    if(POS>=_size) {
        thePos = _size-1;
    }
    // create new array of size - 1
    T* temp = new T[_size-1];
    // copy elements from 0 to POS from old array to  new array
    for(int i=0; i<thePos; i++) {
        temp[i] = _pArray[i];
    }
    // copy elements from POS+1 to size from old array to new array
    for(int i=thePos+1; i<_size; i++) {
        temp[i-1] = _pArray[i];
    }
    // delete old array
    delete[] _pArray;
    // set old array to be new array
    _pArray = temp;
    // decrement size
    _size--;
}

template<typename T>
T Array<T>::min() const {
    // if array is empty, throw std::out_of_range exception
    if(_size==0) {
        throw out_of_range("Size of Array is 0.");
    }
    // find minimum value within array
    T minimum = _pArray[0];
    for(int i=1; i<_size; i++) {
        if(_pArray[i]<minimum) {
            minimum = _pArray[i];
        }
    }
    // return min value
    return minimum;
}

template<typename T>
T Array<T>::max() const {
    // if array is empty, throw std::out_of_range exception
    if(_size==0) {
        throw out_of_range("Size of Array is 0.");
    } 
    // find maximum value within array
    T maximum = _pArray[0];
    for(int i=1; i<_size; i++) {
        if(_pArray[i]>maximum) {
            maximum = _pArray[i];
        }
    }
    // return max value
    return maximum;
}

template<typename T>
int Array<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    // return index of first occurrence if found
    for(int i=0; i<_size; i++) {
        if(VALUE==_pArray[i]) {
            return i;
        }
    }
    // otherwise return -1
    return -1;
}

template<typename T>
void Array<T>::sort() {
    mergeSort(_pArray, 0, _size - 1);
}

template<typename T>
void Array<T>::mergeSort(T* data, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

template<typename T>
void Array<T>::merge(T* data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T* leftArray = new T[n1];
    T* rightArray = new T[n2];
    for (int i = 0; i < n1; ++i) leftArray[i] = data[left + i];
    for (int i = 0; i < n2; ++i) rightArray[i] = data[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            data[k] = leftArray[i];
            ++i;
        } else {
            data[k] = rightArray[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        data[k] = leftArray[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        data[k] = rightArray[j];
        ++j;
        ++k;
    }
    delete[] leftArray;
    delete[] rightArray;
}

#endif//ARRAY_H