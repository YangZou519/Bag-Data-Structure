#include <iostream>
#include <cstdlib>
#include "bag.h"
#include "set.h"
#include "keyed_bag.h"

using namespace std;

//check for bag.h and bag.cpp
void bag_check_minus(bag&, bag&);
void bag_check_minus_equal(bag&, bag&);

//check function, call to check the member functions and the operators in the class
void Set_check_minus_equal(set&, set&);
void Set_check_equal(set&, set&);
void Set_check_not_equal(set&, set&);
void Set_check_greater(set&, set&);
void Set_check_greater_equal(set&, set&);
void Set_check_less(set&, set&);
void Set_check_less_equal(set&, set&);

//insert some elements to the set
void Set_insert_some(set&, set&);
void Set_another_insert(set&, set&);

//clear all element in set A and set B
void Set_clear(set&, set&);


void check_minus(keyed_bag&, keyed_bag&);
void check_minus_equal(keyed_bag&, keyed_bag&);
void check_add(keyed_bag&, keyed_bag&);
void check_add_equal(keyed_bag&, keyed_bag&);

void insert_some(keyed_bag&, keyed_bag&);
void another_insert(keyed_bag&, keyed_bag&);
void different_insert(keyed_bag&, keyed_bag&);
void clear(keyed_bag&, keyed_bag&);

int main(){
    //check for bag class
    cout << "\n\n   This is for bag.h and bag.cpp\n----------------------------------\n";
    bag a,b;
    bag_check_minus(a, b);
    bag c,d;
    bag_check_minus_equal(c, d);

    set A;
    set B;
    //call function to check all class functions
    cout << "\n\n   This is for set.h and set.cpp\n----------------------------------\n";
    Set_check_minus_equal(A, B);
    Set_check_equal(A, B);
    Set_check_not_equal(A, B);
    Set_check_greater(A,B);
    Set_check_greater_equal(A, B);
    Set_check_less(A, B);
    Set_check_less_equal(A, B);

    cout << "\n\n   This is for keyed_key.h and keyed_key.cpp\n----------------------------------------------\n";
    keyed_bag C;
    keyed_bag D;
    check_minus(C, D);
    check_minus_equal(C, D);
    check_add(C, D);
    check_add_equal(C, D);

    return 0;
}
void bag_check_minus(bag& A, bag& B){
    A.insert(2);
    A.insert(1);
    A.insert(1);
    B.insert(3);
    B.insert(1);
    cout << "\n\nBag A: [2, 1, 1]\nBag B: [3, 1]\n";
    A = A - B;
    cout << "Check A = A - B: ";
    for(bag::size_type i = 0; i < A.getUsed(); i++){
        cout << A.getData()[i] << " ";
    }
    A.erase_all();
    B.erase_all();

    A.insert(3);
    A.insert(2);
    B.insert(1);
    B.insert(3);
    B.insert(4);
    cout << "\n\nBag A: [3, 2]\nBag B: [1, 3, 4]\n";
    A = A - B;
    cout << "Check A = A - B: ";
    for(bag::size_type i = 0; i < A.getUsed(); i++){
        cout << A.getData()[i] << " ";
    }
}
void bag_check_minus_equal(bag& A, bag& B){
    A.insert(2);
    A.insert(1);
    A.insert(1);
    B.insert(3);
    B.insert(1);
    cout << "\n\nBag A: [2, 1, 1]\nBag B: [3, 1]\n";
    A -= B;
    cout << "Check A -= B: ";
    for(bag::size_type i = 0; i < A.getUsed(); i++){
        cout << A.getData()[i] << " ";
    }
    A.erase_all();
    B.erase_all();

    A.insert(3);
    A.insert(2);
    B.insert(1);
    B.insert(3);
    B.insert(4);
    cout << "\n\nBag A: [3, 2]\nBag B: [1, 3, 4]\n";
    A = A - B;
    cout << "Check A -= B: ";
    for(bag::size_type i = 0; i < A.getUsed(); i++){
        cout << A.getData()[i] << " ";
    }
}


//check the -= operator
void Set_check_minus_equal(set& A, set&B){
    Set_insert_some(A, B);
    A -= B;
    cout << "Check A -= B: ";
    for(int i = 0; i < A.getUsed(); i++){
        cout << A.getData()[i] << endl;
    }
    Set_clear(A, B);

    Set_another_insert(A, B);
    A -= B;
    cout << "Check A -= B: ";
    for(int i = 0; i < A.getUsed(); i++){
        cout << A.getData()[i] << endl;
    }
    cout << endl;
    Set_clear(A, B);
}

//check the == operator
void Set_check_equal(set& A, set& B){
    Set_insert_some(A, B);
    cout << ("Check A == B: ");
    if(A == B){
        cout << "A and B have the same elements.\n";
    }
    else   
        cout << "A and B have some different elements.\n";
    
    Set_clear(A, B);

    A.insert(1);
    A.insert(2);
    A.insert(3);
    B.insert(3);
    B.insert(2);
    B.insert(1);
    cout << ("\nA: [1, 2, 3]\nB: [3, 2, 1]\n");
    cout << ("Check A == B: ");
    if(A == B){
        cout << "A and B have the same elements.\n";
    }
    else   
        cout << "A and B have some different elements.\n";

    Set_clear(A, B);
}

//check the != operator
void Set_check_not_equal(set& A, set& B){
    Set_insert_some(A, B);
    cout << ("Check A != B: ");
    if(A != B){
        cout << "A and B have some different elements.\n";
    }
    else   
        cout << "A and B have the same elements.\n";
    Set_clear(A, B);

    A.insert(1);
    A.insert(2);
    A.insert(3);
    B.insert(3);
    B.insert(2);
    B.insert(1);
    cout << ("\nA: [1, 2, 3]\nB: [3, 2, 1]\n");
    cout << ("Check A != B: ");
    if(A != B){
        cout << "A and B have some different elements.\n";
    }
    else   
        cout << "A and B have the same elements.\n";

    Set_clear(A, B);
}

//check the > operator
void Set_check_greater(set&A, set&B){
    Set_insert_some(A, B);
    cout << ("Check A > B: "); 
    if (A > B){
        cout << "B is a proper subset of A.\n";
    }
    else
        cout << "B is not a proper subset of A.\n";
    Set_clear(A, B);

    Set_another_insert(A, B);
    cout << ("Check A > B: "); 
    if (A > B){
        cout << "B is a proper subset of A.\n";
    }
    else
        cout << "B is not a proper subset of A.\n";

    Set_clear(A, B);
}

//check >= operator
void Set_check_greater_equal(set& A, set& B){
    Set_insert_some(A, B);
    cout << ("Check A >= B: ");
    if (A >= B){
        cout << "B is a subset of A.\n";
    }
    else
        cout << "B is not a subset of A.\n";
    
    Set_clear(A, B);

    Set_another_insert(A, B);
    cout << ("Check A >= B: ");
    if (A >= B){
        cout << "B is a subset of A.\n";
    }
    else
        cout << "B is not a subset of A.\n";

    Set_clear(A, B);
}

//check the < operator
void Set_check_less(set& A, set& B){
    Set_insert_some(A, B);
    cout << ("Check A < B: ");
    if (A < B){
        cout << "A is a proper subset of B.\n";
    }
    else
        cout << "A is not a proper subset of B.\n";
    Set_clear(A, B);

    Set_another_insert(A, B);
    cout << ("Check A < B: ");
    if (A < B){
        cout << "A is a proper subset of B.\n";
    }
    else
        cout << "A is not a proper subset of B.\n";
    Set_clear(A, B);
}

//check <= operator
void Set_check_less_equal(set& A, set& B){
    Set_insert_some(A, B);
    cout << ("Check A <= B: ");
    if (A <= B){
        cout << "A is a subset of B.\n";
    }
    else
        cout << "A is not a subset of B.\n";
    Set_clear(A, B);

    Set_another_insert(A, B);
    cout << ("Check A <= B: ");
    if (A <= B){
        cout << "A is a subset of B.\n";
    }
    else
        cout << "A is not a subset of B.\n";
    Set_clear(A, B);
}

void Set_insert_some(set& A, set& B){
    A.insert(4);
    A.insert(3);
    A.insert(2);
    A.insert(1);
    B.insert(1);
    B.insert(3);
    B.insert(4);
    cout << ("\nA: [4, 3, 2, 1]\nB: [1, 3, 4]\n");
}

void Set_another_insert(set& A, set& B){
    A.insert(1);
    A.insert(2);
    A.insert(3);
    B.insert(4);
    B.insert(3);
    B.insert(2);
    B.insert(1);
    cout << ("\nA: [1, 2, 3]\nB: [4, 3, 2, 1]\n");
}

void Set_clear(set& A, set& B){
    A.erase_all();
    B.erase_all();
}


//check the '-' operator
void check_minus(keyed_bag& A, keyed_bag& B){
    insert_some(A, B);
    A = A - B;
    //print result
    cout << "for A = A - B:\n";
    for(int i = 0; i < A.getUsed(); i++){
        cout << "Number: " << A.getData()[i].first << "\nKey: " << A.getData()[i].second << endl;
    }
    clear(A, B);

    another_insert(A, B);
    A = A - B;
    cout << "for A = A - B:\n";
    for(int i = 0; i < A.getUsed(); i++){
        cout << "Number: " << A.getData()[i].first << "\nKey: " << A.getData()[i].second << endl;
    }
    clear(A, B);
}

//check the '-=' operator
void check_minus_equal(keyed_bag& A, keyed_bag& B){
    insert_some(A, B);
    A -= B;
    //print result
    cout << "for A -= B:\n";
    for(int i = 0; i < A.getUsed(); i++){
        cout << "Number: " << A.getData()[i].first << "\nKey: " << A.getData()[i].second << endl;
    }
    clear(A, B);

    another_insert(A, B);
    A -= B;
    //print result
    cout << "for A -= B:\n";
    for(int i = 0; i < A.getUsed(); i++){
        cout << "Number: " << A.getData()[i].first << "\nKey: " << A.getData()[i].second << endl;
    }
    clear(A, B);
}

//check the '+' operator
void check_add(keyed_bag& A, keyed_bag& B){
    different_insert(A, B);
    A = A + B;
    //print result
    cout << "for A = A + B:\n";
    for(int i = 0; i < A.getUsed(); i++){
        cout << "Number: " << A.getData()[i].first << "\nKey: " << A.getData()[i].second << endl;
    }
    clear(A, B);
}

//check the '+=' operator
void check_add_equal(keyed_bag& A, keyed_bag& B){
    different_insert(A, B);
    A += B;
    //print result
    cout << "for A += B:\n";
    for(int i = 0; i < A.getUsed(); i++){
        cout << "Number: " << A.getData()[i].first << "\nKey: " << A.getData()[i].second << endl;
    }
    clear(A, B);
}

//insert some elements and keys for A and B
void insert_some(keyed_bag& A, keyed_bag& B){
    A.insert(1, 4);
    A.insert(2, 3);
    A.insert(3, 2);
    A.insert(4, 1);
    B.insert(1, 4);
    B.insert(2, 3);
    B.insert(3, 2);
    cout << "\nA: [(1,4) (2,3) (3,2) (4, 1)]\nB: [(1,4) (2,3) (3,2)]\nCheck ";
}

//another insert for A and B
void another_insert(keyed_bag& A, keyed_bag& B){
    A.insert(1, 4);
    A.insert(2, 3);
    A.insert(6, 7);
    B.insert(1, 4);
    B.insert(2, 3);
    B.insert(3, 2);
    B.insert(4, 1);
    cout << "\nA: [(1,4) (2,3) (6,7)]\nB: [(1,4) (2,3) (3,2) (4,1)]\nCheck ";
}

//insert some different element for A and B
void different_insert(keyed_bag& A, keyed_bag& B){
    A.insert(1, 4);
    A.insert(2, 3);
    A.insert(3, 2);
    B.insert(1, 5);
    B.insert(2, 6);
    B.insert(3, 7);
    cout << "\nA: [(1,4) (2,3) (3,2)]\nB: [(1,5) (2,6) (3,7)]\nCheck ";
}

//erase all element in keyed_bag A and B
void clear(keyed_bag& A, keyed_bag& B){
    A.erase_all();
    B.erase_all();
}