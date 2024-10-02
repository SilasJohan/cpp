#include <iostream>
#include <unistd.h>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void welcomeScreen()
{
    cout << "==========================================" << endl;
    cout << "|                                        |" << endl;
    cout << "|          Welcome to the game of        |" << endl;
    cout << "|           RUSSIAN ROULETTE!            |" << endl;
    cout << "|                                        |" << endl;
    cout << "==========================================" << endl;
}

// Função para verificar se o número já foi escolhido
bool isNumberUsed(int number, vector<int> &usedNumbers)
{
    for (int i : usedNumbers)
    {
        if (i == number)
            return true;
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    welcomeScreen();
    srand(time(0));

    int imposter = rand() % 10;
    int playerChoice, machineChoice;
    char yn1;
    string nome;

    // Lista para armazenar números usados
    vector<int> usedNumbers;

    cout << "Imposter number (for debugging): " << imposter << endl;

    cout << "First of all, what is your name?: ";
    cin >> nome;

    cout << "Okay " << nome << ", are you willing to risk your life in this game? (y/n): " << endl;
    cin >> yn1;

    if (yn1 != 'y')
    {
        cout << "That's what I thought..." << endl;
        return 1;
    }

    cout << "LET'S START!!!!, like... you start, BECAUSE I WANT!" << endl;
    sleep(3);

    // PRIMEIRO ROUND
    do
    {
        cout << "Choose a number (0-9)" << endl;
        cin >> playerChoice;

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "That number has already been used, choose another, NOW!" << endl;
        }
    } while (isNumberUsed(playerChoice, usedNumbers));

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE IN THE FIRST TRY YOU ARE TERRIBLE HAHAHAHAHHA" << endl;
        sleep(2.5);
        cout << "NOW GIVE-ME WHAT IS YOURS HAHHAHA" << endl;
        sleep(2);
        cout << "Bank Account Stolen [OK]" << endl;
        sleep(2);
        cout << "Longitude and Latitude captured [OK]" << endl;
        sleep(2);
        cout << "All of your password stolen [OK]" << endl;
        sleep(2);
        cout << "The " << rand() % 10 << " times you broke the law you were sent to the police [OK]" << endl;
        sleep(2);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
        
        return 0; // Encerra o programa
    }

    // Máquina escolhe um número
    sleep(3);
    do
    {
        machineChoice = rand() % 10;
    } while (isNumberUsed(machineChoice, usedNumbers));

    usedNumbers.push_back(machineChoice); // Adiciona o número escolhido pela máquina
    cout << "MY TURN!!!! And I choose: " << machineChoice << endl;

    if (machineChoice == imposter)
    {
        cout << "w-what?" << endl;
        sleep(2);
        cout << "NO, THIS IS NOT POSSIBLE, I WIN, I ALWAYS WIN!" << endl;
        sleep(2);
        cout << "Deleting System32 in:" << endl;
        cout << "3" << endl;
        sleep(1);
        cout << "2" << endl;
        sleep(1);
        cout << "1" << endl;
        sleep(1);
        cout << "Error: Cannot delete System32. The system has detected a fatal error!" << endl; // Mensagem simulando um erro
        cout << "Exiting game..." << endl;
        return 0; // Encerra o programa
    }

    // SEGUNDO ROUND
    do
    {
        cout << "Choose a number (0-9)" << endl;
        cin >> playerChoice;

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "That number has already been used, choose another, NOW!" << endl;
        }
    } while (isNumberUsed(playerChoice, usedNumbers));

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE" << endl;
        sleep(2.5);
        cout << "NOW GIVE-ME WHAT IS YOURS HAHHAHA" << endl;
        sleep(2);
        cout << "Bank Account Stolen [OK]" << endl;
        sleep(2);
        cout << "Longitude and Latitude captured [OK]" << endl;
        sleep(2);
        cout << "All of your password stolen [OK]" << endl;
        sleep(2);
        cout << "The " << rand() % 10 << " times you broke the law you were sent to the police [OK]" << endl;
        sleep(2);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
       
        return 0; // Encerra o programa
    }

    // Máquina escolhe um número
    sleep(3);
    do
    {
        machineChoice = rand() % 10;
    } while (isNumberUsed(machineChoice, usedNumbers));

    usedNumbers.push_back(machineChoice); // Adiciona o número escolhido pela máquina
    cout << "MY TURN!!!! And I choose: " << machineChoice << endl;

    if (machineChoice == imposter)
    {
        cout << "w-what?" << endl;
        sleep(2);
        cout << "NO, THIS IS NOT POSSIBLE, I WIN, I ALWAYS WIN!" << endl;
        sleep(2);
        cout << "Deleting System32 in:" << endl;
        cout << "3" << endl;
        sleep(1);
        cout << "2" << endl;
        sleep(1);
        cout << "1" << endl;
        sleep(1);
        cout << "Error: Cannot delete System32. The system has detected a fatal error!" << endl; // Mensagem simulando um erro
        cout << "Exiting game..." << endl;
        return 0; // Encerra o programa
    }

    // TERCEIRO ROUND
    do
    {
        cout << "Choose a number (0-9)" << endl;
        cin >> playerChoice;

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "That number has already been used, choose another, NOW!" << endl;
        }
    } while (isNumberUsed(playerChoice, usedNumbers));

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE" << endl;
        sleep(2.5);
        cout << "NOW GIVE-ME WHAT IS YOURS HAHHAHA" << endl;
        sleep(2);
        cout << "Bank Account Stolen [OK]" << endl;
        sleep(2);
        cout << "Longitude and Latitude captured [OK]" << endl;
        sleep(2);
        cout << "All of your password stolen [OK]" << endl;
        sleep(2);
        cout << "The " << rand() % 10 << " times you broke the law you were sent to the police [OK]" << endl;
        sleep(2);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
        
    }
}