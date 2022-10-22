#include <iostream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <windows.h>
#include <algorithm> 

using namespace std;

// global variable
vector<int> values;

int getValues(){
    cout << "Insert a new value to be stored: ";
    int value = 0;
    cin >> value;
    while (!cin.good()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input. Try again: ";
    cin >> value;
    }  
    return value;
}

int main(){
    // insert values into the
    values.push_back(getValues());
    cout << "* Stored values so far: " << endl;
    for(int i = 0; i < values.size(); i++){
        cout << values[i] << " ";
    }
    cout << "" << endl;
    main();
}