#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, bool> chutou;
const string PALAVRA_SECRETA = "MELANCIA";



bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){
        if (chute == letra){
            return true;
        }
    }
    return false;
}


int main () {
    
    bool nao_acertou = true;
    bool nao_enforcou = true;

    while(nao_acertou && nao_enforcou){
        for(char letra : PALAVRA_SECRETA){
            if(chutou[letra]){
                cout << letra << " ";
            }
            else{
                cout << "_ ";
            }
        }
        cout << endl;
        

        char chute;
        cin >> chute;

        chutou[chute] = true;

        if(letra_existe(chute)){       
            cout << "Você acertou! Seu chute está na palavra." << endl;
        }
        else{
            cout << "Você errou! Seu chute não esta na palavra." << endl;
        }               
    }
}