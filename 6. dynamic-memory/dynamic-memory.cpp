// In this program, we can clearly understand the heap memory allocated for programmers.

// Run the program, you will automatically receive a address of one pointer 
// and give the size as `0` in how many temps. Now, you will receive the same address, which you received before.

// The reason is we just deleted the first pointer and second pointer also starts with that free address.


#include <iostream>
using namespace std;

int main() {
    
    int *int_ptr {nullptr};
    int_ptr = new int;
    cout<<int_ptr<<endl;
    delete int_ptr; 

    size_t size; // size_t is unsigned long int. Where-ever you need unsigned long int, just put size_t. 
    double *temp_ptr {nullptr};
    cout<<sizeof(double)<<" "<<"How many temps? ";
    cin>>size;
    temp_ptr = new double[size];
    cout<<temp_ptr<<endl;
    delete [] temp_ptr;

    return 0;
}