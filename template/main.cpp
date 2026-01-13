#include "DLL_template.hpp"
#include <string>
using std::cout; using std::cin; using std::endl;

int main() {
    pk::jpo::DoublyLinkedList<int> li;
    pk::jpo::DoublyLinkedList<double> ld;
    pk::jpo::DoublyLinkedList<std::string> ls;

    li.push_front(10);
    li.push_front(5);
    li.push_back(20);

    ld.push_back(3.14);
    ld.push_front(2.71);

    ls.push_back("ala");
    ls.push_back("ma");
    ls.push_back("kota");


    cout<<endl<<endl<<endl;
    cout <<"---------------------------------------------------- INT ---------------------------------------------\n";
    cout << "Test INT LIST:\n";
    cout << "Test push_front:\n";
    li.push_front(1);
    li.print_forward();      // [ 1 5 10 20 ]
    li.print_backward();     // [ 20 10 5 1 ]

    cout << "\nTest push_back:\n";
    li.push_back(30);
    li.print_forward();      // [ 1 5 10 20 30]
    li.print_backward();     // [ 30 20 10 5 1]

    cout << "\nTest pop_front:\n";
    li.pop_front();
    li.print_forward();      // [ 5 10 20 30 ]

    cout << "\nTest pop_back:\n";
    li.pop_back();
    li.print_forward();      // [ 5 10 20 ]

    cout << "\nTest clear():\n";
    li.clear();
    li.print_forward();      // [ ]

    cout<<"\nTest empty: \n";
    if(li.empty()){
        cout<<"empty"<<endl;
    }else {
        cout<<"not empty"<<endl;
    }

    cout<<endl<<endl<<endl;
    cout <<"---------------------------------------------------- DOUBLE ---------------------------------------------\n";
    cout << "Test DOUBLE LIST:\n";
    cout << "Test push_front:\n";
    ld.push_front(1.1);
    ld.print_forward();      // [ 1.1 3.14 2.71 ]
    ld.print_backward();     // [ 2.71 3.14 1.1 ]

    cout << "\nTest push_back:\n";
    ld.push_back(3.33);
    ld.print_forward();      // [ 1.1 3.14 2.71 3.33]
    ld.print_backward();     // [ 3.33 2.71 3.14 1.1 ]

    cout << "\nTest pop_front:\n";
    ld.pop_front();
    ld.print_forward();      // [ 3.14 2.71 3.33 ]

    cout << "\nTest pop_back:\n";
    ld.pop_back();
    ld.print_forward();      // [ 3.14 2.71 ]

    cout << "\nTest clear():\n";
    ld.clear();
    ld.print_forward();      // [ ]

    cout<<"\nTest empty: \n";
    if(ld.empty()){
        cout<<"empty"<<endl;
    }else {
        cout<<"not empty"<<endl;
    }


    cout<<endl<<endl<<endl;
    cout <<"---------------------------------------------------- STRING ---------------------------------------------\n";
    cout << "Test STRING LIST:\n";
    cout << "Test push_front:\n";
    ls.push_front("elo");
    ls.print_forward();      // [ elo ala ma kota ]
    ls.print_backward();     // [ kota ma ala elo ]

    cout << "\nTest push_back:\n";
    ls.push_back("nara");
    ls.print_forward();      // [ elo ala ma kota nara]
    ls.print_backward();     // [ nara kota ma ala elo]

    cout << "\nTest pop_front:\n";
    ls.pop_front();
    ls.print_forward();      // [ ala ma kota nara ]

    cout << "\nTest pop_back:\n";
    ls.pop_back();
    ls.print_forward();      // [ ala ma kota ]

    cout << "\nTest clear():\n";
    ls.clear();
    ls.print_forward();      // [ ]

    cout<<"\nTest empty: \n";
    if(ls.empty()){
        cout<<"empty"<<endl;
    }else {
        cout<<"not empty"<<endl;
    }

    return 0;
}
