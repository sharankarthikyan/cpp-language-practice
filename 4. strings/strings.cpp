#include <iostream>
#include <cstring> // for C - style string function.
#include <cctype> // for Character - based function.
using namespace std;

int main() {

    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};

    // cout<<first_name; // This will display garbage value or do nothing. Only if you delete {} in first_name

    cout<<"Enter your first name: ";
    cin>>first_name;
    cout<<"Enter your last name: ";
    cin>>last_name;
    cout<<"--------------------------------"<<endl;


    cout<<"Hello, "<< first_name <<" your first name has "<< strlen(first_name) << " characters"<<endl; // strlen return size_t datatype value. size_t is unsigned int or unsigned long
    cout<<"and your last name, "<< last_name <<" has "<< strlen(last_name) << " characters"<<endl;
    
    // strcpy(full_name, first_name);
    // strcat(full_name, " ");
    // strcat(full_name, last_name);
    // cout<<"Your full name is: "<< full_name <<endl;
    

    cout<<"Enter the full name: ";
    cin.getline(full_name, 50); // This get atmost 50 chars from the user.

    string s1; //Empty
    string s2 {"Sharan"}; //  Sharan
    string s3 {s2}; // Sharan
    string s4 {"Sharan", 3}; // Sha // 3 is length of chars want to store in a string.
    string s5 {"Sharan", 0, 2}; // Sh // 0 is starting index and 2 is length of chars want to store in a string.
    string s6 (3, 'X'); // XXX


    return 0;
}