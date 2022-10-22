#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <windows.h>
#include <algorithm>

using namespace std;

// vector for 4 values
vector<int> values;
int pos = 0;
int first = false;
int larger = 0;

string posCheck(){
    if (pos == 0){
        return "right";
    }
    if (pos == 1){
        return "down";
    }
    if (pos == 2){
        return "left";
    }
    if (pos == 3){
        return "up";
    }
}

int checkLarger(){
    // checks larger value in vector
    larger = *max_element(values.begin(), values.end());
    return larger;
}

string largerPos(){
    if (larger == values[0] && larger == values[1] && larger == values[2] && larger == values[3]){
        return "right, down, left and up";
    }
        if (larger == values[0] && larger == values[1] && larger == values[2]){
        return "right, down and left";
    }
    if (larger == values[0] && larger == values[1] && larger == values[3]){
        return "right, down and up";
    }
    if (larger == values[0] && larger == values[2] && larger == values[3]){
        return "right, left and up";
    }
    if (larger == values[1] && larger == values[2] && larger == values[3]){
        return "down, left and up";
    }
        if (larger == values[0] && larger == values[1]){
        return "right and down";
    }
    if (larger == values[0] && larger == values[2]){
        return "right and left";
    }
    if (larger == values[0] && larger == values[3]){
        return "right and up";
    }
    if (larger == values[1] && larger == values[2]){
        return "down and left";
    }
    if (larger == values[1] && larger == values[3]){
        return "down and up";
    }
    if (larger == values[2] && larger == values[3]){
        return "left and up";
    }
    if (larger == values[0]){
        return "right";
    }
    if (larger == values[1]){
        return "down";
    }
    if (larger == values[2]){
        return "left";
    }
    if (larger == values[3]){
        return "up";
    }
}


int getValues(){
    if (pos > 3){
        // print values
        cout << "Considering the box size of " << values[0] + values[2] << "x" << values[1] + values[3] << endl;
        cout << "The larger distance is " << checkLarger() << ", and it is to the " << largerPos() << " direction(s)." << endl;
        pos = 0;
        larger = 0;
        values.clear();
        cout << "Press 1 to continue or 0 to exit" << endl;
        int cont = 0;
        cin >> cont;
        // checks if the user typed a valid value
        while (cont != 1 && cont != 0){
            cout << "Invalid value, please type 1 to continue or 0 to exit" << endl;
            cin >> cont;
        }
        if (cont == 0){
            return 999999;
        }
        if (cont == 1){
            return 100000;
        }
    }
    else{
    cout << "Insert a new value to be stored in " << posCheck() << ": ";
    int value = 0;
    cin >> value;
    while (!cin.good()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input. Try again: ";
    cin >> value;
    }
    pos += 1;
    return value;
    }
}



int main(){
    // insert values into the
    int newValue = getValues();
    if(newValue == 100000){
        main();
    }
    else if(newValue == 999999){
        return 0;
    }
    else{
    values.push_back(newValue);
    cout << "Position: " << endl;
    for(int i = 0; i < values.size(); i++){
        cout << values[i] << " ";
    }
    cout << "" << endl;
    main();
    }
}