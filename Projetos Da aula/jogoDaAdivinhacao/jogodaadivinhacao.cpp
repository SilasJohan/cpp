#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    cout << "***************************************" << endl;
    cout << "* Bem vindos ao jogo da adivinhação!! *" << endl;
    cout << "***************************************" << endl;

    cout <<"Escolha o seu nivel de dificuldade: " << endl;
    cout <<"Fácil (F), Médio (M), ou Difícil (D) (use maiúsculo)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else{
        numero_de_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    cout <<"Número secreto: " << NUMERO_SECRETO << endl;
    

    int tentativas = 0;
    bool nao_acertou = true;
    
    double pontos = 1000.0;
    

    for(tentativas = 1;tentativas <= numero_de_tentativas;tentativas++){

        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute? " << endl;
        cin >> chute;

        cout << "O valor do seu chute é : " << chute << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;       
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        
        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }

        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }

        else
        {
            cout << "Seu chute foi menor que número secreto!" << endl;
        }

    }
    cout << "Fim de jogo!!! " << endl;

    if(nao_acertou){
        cout << "Você perdeu! Mais sorte na próxima." <<endl;
    }
    else{
         cout << "Você acertou o número secreta em " << tentativas << " tentativas" << endl;
         cout.precision(2);
         cout << fixed;
         cout << "Sua pontuação foi de " << pontos << " pontos." <<endl;
    }
}