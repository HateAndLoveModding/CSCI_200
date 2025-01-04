/* CSCI 200: L6B
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 * Description: Implement merge sort
 */

#include <iostream>
using namespace std;

#include "Array.hpp"
#include "LinkedList.hpp"

int main() {
    LinkedList<int> list1;
    list1.insert(0, 4);
    list1.insert(1, 3);
    list1.insert(2, 8);
    list1.insert(3, 1);
    list1.insert(4, 5);
    list1.insert(5, 9);
    list1.insert(6, 7);
    list1.insert(7, 2);
    list1.insert(8, 6);

    cout << "Linked list before sorting: ";
    for (int i = 0; i < list1.size(); ++i) {
        cout << list1.get(i) << " ";
    }
    cout << endl;
    list1.sort();
    cout << "Linked list after sorting: ";
    for (int i = 0; i < list1.size(); ++i) {
        cout << list1.get(i) << " ";
    }
    cout << endl;
    list1.~LinkedList();

    LinkedList<string> list2;
    list2.insert(0, "bananna");
    list2.insert(1, "pear");
    list2.insert(2, "mango");
    list2.insert(3, "apple");
    list2.insert(4, "cherry");
    list2.insert(5, "tomato");
    list2.insert(6, "watermelon");
    list2.insert(7, "canotope");

    cout << "Linked list before sorting: ";
    for (int i = 0; i < list2.size(); ++i) {
        cout << list2.get(i) << " ";
    }
    cout << endl;
    list2.sort();
    cout << "Linked list after sorting: ";
    for (int i = 0; i < list2.size(); ++i) {
        cout << list2.get(i) << " ";
    }
    cout << endl;
    list2.~LinkedList();



    Array<int> array1;
    array1.insert(0, 4);
    array1.insert(1, 3);
    array1.insert(2, 8);
    array1.insert(3, 1);
    array1.insert(4, 5);
    array1.insert(5, 9);
    array1.insert(6, 7);
    array1.insert(7, 2);
    array1.insert(8, 6);

    cout << "Array before sorting: ";
    for (int i = 0; i < array1.size(); ++i) {
        cout << array1.get(i) << " ";
    }
    cout << endl;
    array1.sort();
    cout << "Array after sorting: ";
    for (int i = 0; i < array1.size(); ++i) {
        cout << array1.get(i) << " ";
    }
    cout << endl;
    array1.~Array();

    Array<string> array2;
    array2.insert(0, "bananna");
    array2.insert(1, "pear");
    array2.insert(2, "mango");
    array2.insert(3, "apple");
    array2.insert(4, "cherry");
    array2.insert(5, "tomato");
    array2.insert(6, "watermelon");
    array2.insert(7, "canotope");

    cout << "Array before sorting: ";
    for (int i = 0; i < array2.size(); ++i) {
        cout << array2.get(i) << " ";
    }
    cout << endl;
    array2.sort();
    cout << "Array after sorting: ";
    for (int i = 0; i < array2.size(); ++i) {
        cout << array2.get(i) << " ";
    }
    cout << endl;
    array2.~Array();

    return 0;
}