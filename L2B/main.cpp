/* CSCI 200: L2B
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Become familiar with using pointers and addresses.
 */

#include <iostream>
using namespace std;

int main() {
    int iNum = 4;
    int iNum2 = 5;
    int* pINum1 = nullptr;
    int* pINum2 = nullptr;
    pINum1 = &iNum;
    pINum2 = &iNum2;
    cout << "This is the memory address of iNum using pINum1 is: " << pINum1 << endl;
    cout << "This is the memory address of iNum using &iNum is: " << &iNum << endl;
    cout << "This is the memory address of iNum2 using pINum2 is: " << pINum2 << endl;
    cout << "This is the memory address of iNum2 using &iNum2 is: " << &iNum2 << endl;
    cout << "The value of iNum using *pINum1 is: " << *pINum1 << endl;
    cout << "The value of iNum2 using *pINum2 is: " << *pINum2 << endl;
    iNum = 6;
    cout << "The value of iNum using iNum is: " << iNum << endl;
    cout << "The value of iNum using *pINum1 is: " << *pINum1 << endl;
    *pINum1 = 7;
    cout << "The value of iNum using iNum is: " << iNum << endl;
    pINum2 = pINum1;
    cout << "The memory address of pINum2 is: " << pINum2 << endl;
    cout << "The value of iNum2 using *pINum2 is: " << *pINum2 << endl;
    *pINum2 = 8;
    cout << "The value of iNum using *pINum1 is: " << *pINum1 << endl;
    cout << "The value of iNum using *pINum2 is: " << *pINum2 << endl;
    cout << "The value of iNum using iNum is: " << iNum << endl;
    cout << "The value of iNum2 using iNum2 is: " << iNum2 << endl;
    double* pDNum = nullptr;
    //pDNum = &iNum; error: cannot convert ‘int*’ to ‘double*’ in assignment
    //pDNum = pINum1; error: cannot convert ‘int*’ to ‘double*’ in assignment
    double dNum = 14.25;
    pDNum = &dNum;
    cout << "The memory address of pDNum using pDNum is: " << pDNum << endl;
    cout << "The value of dNum using pDNum is: " << *pDNum << endl;
    *pDNum = *pINum1;
    cout << "The value of dNum using dNum is: " << dNum << endl;
    cout << "The value of dNum using pDNum is: " << *pDNum << endl;
}