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

int continueMap(){
    cout << "Do you want to continue mapping? (0 - no, 1 - yes)" << endl;
    int confirm;
    cin >> confirm;
    while(confirm != 0 && confirm != 1){
        cout << "Invalid input. Try again: ";
        cin >> confirm;
    }
    if (confirm == 0){
        return 0;
    }
    if (confirm == 1){
        return 1;
    }
}

int main(){
    if(continueMap() == 1){
        cout << "Continuing..." << endl;
        main();
    }
    else{
        cout << "Exiting..." << endl;
        return 0;
    }
}