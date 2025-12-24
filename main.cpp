#include <iostream>
#include "DLL_doxygen.hpp"

using namespace pk::jpo;
using std::cout; using std::cin; using std::endl;

int main() {
    DoublyLinkedList list;

    cout << "Test push_front:\n";
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.print_forward();      // [ 30 20 10 ]
    list.print_backward();     // [ 10 20 30 ]

    cout << "\nTest push_back:\n";
    list.push_back(40);
    list.push_back(50);
    list.print_forward();      // [ 30 20 10 40 50 ]
    list.print_backward();     // [ 50 40 10 20 30 ]

    cout << "\nTest pop_front:\n";
    list.pop_front();
    list.print_forward();      // [ 20 10 40 50 ]

    cout << "\nTest pop_back:\n";
    list.pop_back();
    list.print_forward();      // [ 20 10 40 ]

    cout << "\nTest clear():\n";
    list.clear();
    list.print_forward();      // [ ]
    return 0;
}

