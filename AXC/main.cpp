/* CSCI 200: AXC
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 * Description: Implement a Binary Tree
 */

#include <iostream>
#include <iomanip>
#include "BinarySearchTree.hpp"
using namespace std;

int main() {
    BinarySearchTree<int> tree;

    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(9);
    tree.insert(3);

    // tree.insert(5);
    // tree.insert(1);
    // tree.insert(9);
    // tree.insert(7);
    // tree.insert(6);
    // tree.insert(3);
    // tree.insert(2);

    // tree.insert(5);
    // tree.insert(2);
    // tree.insert(1);
    // tree.insert(7);
    // tree.insert(9);
    // tree.insert(6);
    // tree.insert(3);

    std::cout << left << setw(15) << "In Order: ";
    tree.printInOrder();

    std::cout << left << setw(15) << "Pre Order: ";
    tree.printPreOrder();

    std::cout << left << setw(15) << "Post Order: ";
    tree.printPostOrder();

    cout << left << setw(15) << "Breadth Order: ";
    tree.printBreadthOrder();

    cout << left << setw(15) << "Depth Order: ";
    tree.printDepthOrder();

    cout << "By Levels:" << endl;
    tree.printByLevels();

    cout << "Height: " << tree.height() << endl;;

    return 0;
}