#include <iostream>
// add portuguese
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Não consegui fazer os caracteres em português aparecerem no console
//Tentei usar o setlocale, mas não funcionou
//Farei os próximos exercícios em inglês


using namespace std;


int main(void) {
  setlocale(LC_ALL, "Portuguese");
  int valor = 0;
  int minVal = 0;
  int maxVal = 0;
  cout << "Insira seu valor base: ";
  cin >> valor;
  cout << "Insira o valor mínimo: ";
  cin >> minVal;
  cout << "Insira o valor máximo: ";
  cin >> maxVal;
  if(minVal < maxVal){
    float perMin = 0;
    float perMax = 0;
    perMin = (minVal * 100)/valor;
    perMax = (maxVal * 100)/valor;
    cout << "Com o valor de " << valor << ", o a proporção para o mínimo é de " << perMin << "%, e para o máximo é de " << perMax << "%." << endl;
    cout << "Reiniciando o programa..." << endl;
    main();
  }
  else{
    cout << "Erro, insira um valor mínimo menor do que o valor máximo. Reiniciando o programa..." << endl;
    main();
  }
  
}