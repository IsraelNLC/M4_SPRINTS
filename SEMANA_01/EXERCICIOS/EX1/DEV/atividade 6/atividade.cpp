#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <windows.h>
#include <algorithm>
#include <chrono>
#include <windows.h>

using namespace std;

// Variáveis globais
vector<int> values;
int posCount = 0;
int first = false;
int larger = 0;

string posCheck(){
    if (posCount == 0){
        return "right";
    }
    if (posCount == 1){
        return "down";
    }
    if (posCount == 2){
        return "left";
    }
    if (posCount == 3){
        return "up";
    }
}

int checkLarger(){
    // checks larger value in vector
    larger = *max_element(values.begin(), values.end());
    return larger;
}

string largerDir(){
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
    if (posCount > 3){
        // print values
        cout << "Considering the box size of " << values[0] + values[2] << "x" << values[1] + values[3] << endl;
        cout << "The larger distance is " << checkLarger() << ", and it is to the " << largerDir() << " direction(s)." << endl;
        cout << "Press 1 to start driving or 0 to overwrite new values" << endl;
        int cont = 0;
        cin >> cont;
        // checks if the user typed a valid value
        while (cont != 1 && cont != 0){
            cout << "Invalid value, press 1 to start driving or 0 to overwrite new values" << endl;
            cin >> cont;
        }
        if (cont == 0){
            posCount = 0;
            larger = 0;
            values.clear();
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
    posCount += 1;
    return value;
    }
}

int largerValue = 0;
int largerPos = 0;
int readValues(){
    largerValue = *max_element(values.begin(), values.end());
    largerPos = distance(values.begin(), max_element(values.begin(), values.end()));
    return 0;
}

int vel = 1;

int drive(){
    // lowes the larger value by x and increases the opposite value by x
    values[largerPos] -= vel;
    if (largerPos == 0){
        values[2] += vel;
    }
    if (largerPos == 1){
        values[3] += vel;
    }
    if (largerPos == 2){
        values[0] += vel;
    }
    if (largerPos == 3){
        values[1] += vel;
    }
    cout << "The new distances are: " << endl;
    cout << values[0] << " " << values[1] << " " << values[2] << " " << values[3] << endl;
    return 0;
}

int simulation(){
    readValues();
    drive();
    // delay to make the program more realistic
    Sleep(1000);
    // if the user press esc the program will stop
    if (GetAsyncKeyState(VK_ESCAPE)){
        return 0;
    }
    // check if a distance is lower than 0
    if (values[0] < 0 || values[1] < 0 || values[2] < 0 || values[3] < 0){
        cout << "The car has crashed!" << endl;
        return 0;
    }
    // check if the car distance is higher than the box size
    if (values[0] > values[0] + values[2] || values[1] > values[1] + values[3]){
        cout << "The car has crashed!" << endl;
        return 0;
    }
    simulation();
}

int main(){
    // insert values into the
    int newValue = getValues();
    if(newValue == 999999){
        main();

    }
    else if(newValue == 100000){
        cout << "Insert a velocity to start driving... (between 1 and 5 recommended)" << endl;
        cin >> vel;
        // check if number
        while (!cin.good()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again: ";
        cin >> vel;
        }
        cout << "Starting driving..." << endl;
        cout << "(Press ESC to stop and return to distances input)" << endl;
        if(simulation() == 0){
            main();
        }
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