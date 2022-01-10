#include <iostream>
using namespace std;

int main() {
    int width {0}, height {0}; // c++11 way of initialization
    cout<<"Enter the width of the room: ";
    cin>>width;
    cout<<"Enter the height of the room: ";
    cin>>height;
    cout<<"The area of the room is "<<width * height<<" square feet"<<endl;
    return 0;
}