#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>

// include sleep function
#include <chrono>
#include <windows.h>
using namespace std;

// gostaria de saber por que se eu usar int teclas = 0, ele adiciona 48 aos numeros

int getNumber() {
    int contador = 0;
    int tempo = 3;
    char tecla;
    // teclas array that will receive the pressed keys
    vector<char> teclas;
    while (contador < tempo) {
        if (_kbhit()) {
            tecla = _getch();
            // cout << tecla << " tecla" << endl;
            contador = 0;
            teclas.push_back(tecla);
            // cout << teclas.size() << " tamanho" << endl;
            cout << "registrado" << endl;
        }
        else {
            contador++;
            Sleep(1000);
        }

    }
    // show elements of teclas array
    cout << "Os dados obtidos foram: " << endl;
    for (int i = 0; i < teclas.size(); i++) {
        cout << teclas[i] << " ";
    }
    cout << "" << endl;
}

int main() {
    cout << "Insira os caracteres e aguarde um momento..." << endl;
    int seila = 0;
    while(seila == 0){
        if(kbhit()){
            getNumber();
            seila = 42069;
        }
    }
    cout << "Fim do programa, reiniciando..." << endl;
    main();
    return 0;
}