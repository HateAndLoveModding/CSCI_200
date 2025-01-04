/* CSCI 200: L3B
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Implement functions for string formatting.
 */

#include <iostream>

#include "test_suite.h"

int main() {

    std::cout << "Testing your functions..." << std::endl << std::endl;
    if( run_all_tests() ) {
        std::cout << "ALL TESTS PASSED!" << std::endl;
    } else {
        std::cout << "Not all tests are passing, errors remain..." << std::endl;
    }

    return 0;
}