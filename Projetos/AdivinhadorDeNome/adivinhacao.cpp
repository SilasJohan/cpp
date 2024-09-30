#include <locale.h>
#include <iostream>
#include <unistd.h>
using namespace std;


int main()
{
    setlocale(LC_ALL,"Portuguese");

    int nome;

    cout << "*******************************************" <<endl;
    cout << "* Bem-vindo ao jogo adivinhador de nomes! *" <<endl;
    cout << "*******************************************" <<endl;
   

    cout <<"Qual o seu nome?: ";
    cin >> nome;

    cout <<"Calculando, espere um pouco" <<endl; 
    sleep(5);

    cout <<"Seu nome é: Hello World";  




}



