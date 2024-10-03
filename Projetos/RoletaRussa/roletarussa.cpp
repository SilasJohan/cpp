#include <iostream>
#include <unistd.h>
#include <locale.h>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <limits>
#include <system_error>
#include <windows.h>
#include <tlhelp32.h>

using namespace std;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string RESET = "\033[0m";

int playerChoice, machineChoice;
bool caracterErrado = true;
char yn1;
string nome;

void killProcessByName(const char *processName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to create snapshot." << std::endl;
        return;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(pe);

    if (Process32First(hSnapshot, &pe))
    {
        do
        {
            if (strcmp(pe.szExeFile, processName) == 0)
            {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID);
                if (hProcess != NULL)
                {
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                    cout << "Process " << processName << " with PID " << pe.th32ProcessID << " terminated." << endl;
                }
                else
                {
                    cerr << "Failed to open process." << std::endl;
                }
            }
        } while (Process32Next(hSnapshot, &pe));
    }
    else
    {
        cerr << "Failed to get process information." << std::endl;
    }

    CloseHandle(hSnapshot);
}

void welcomeScreen()
{
    cout << RED << "==========================================" << RESET << endl;
    cout << RED << "|                                        |" << RESET << endl;
    cout << RED << "|          Welcome to the game of        |" << RESET << endl;
    cout << RED << "|           RUSSIAN ROULETTE!            |" << RESET << endl;
    cout << RED << "|                                        |" << RESET << endl;
    cout << RED << "==========================================" << RESET << endl;
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

    // Lista para armazenar números usados
    vector<int> usedNumbers;

    // cout << "Imposter number (for debugging): " << imposter << endl;

    cout << "Impostor number: " << imposter << " (debbuging)" << endl;
    cout << "First of all, what is your name?: ";
    cin >> nome;

    cout << "Okay " << nome << ", are you willing to risk your life in this game? (y/n): ";
    cin >> yn1;

    if (yn1 != 'y')
    {
        cout << "That's what I thought..." << endl;
        return 1;
    }

    cout << "LET'S START!!!!, like... you start, BECAUSE I WANT!" << endl;
    sleep(3);

    // PRIMEIRO ROUND
    while (true)
    { // Laço infinito até a pessoa escolher um número válido

        cout << BLUE << "------------------------- FIRST ROUND -----------------------------" << RESET << endl;
        cout << "Choose a number (0-9): ";
        cin >> playerChoice;

        if (cin.fail() || playerChoice < 0 || playerChoice > 9)
        {
            cin.clear();                                         // Limpa erro de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o que restou no buffer
            cout << "Did you really think this would work? HAHA" << endl;
            continue; // Volta para a escolha do número
        }

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "That number has already been used, choose another, NOW!" << endl;
            continue; // Pede novamente o número se já foi usado
        }

        // Aqui continuaria a lógica do jogo com a escolha do jogador
        cout << "You have chosen: " << playerChoice << endl;
        break; // Sai do laço se a escolha for válida
    }

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE IN THE FIRST ROUND YOU ARE TERRIBLE HAHAHAHAHHA" << endl;
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
        sleep(3);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
    }

    // Máquina escolhe um número
    sleep(3);
    do
    {
        machineChoice = rand() % 10;
    } while (isNumberUsed(machineChoice, usedNumbers));

    usedNumbers.push_back(machineChoice); // Adiciona o número escolhido pela máquina
    cout << "MY TURN! Let me think..." << endl;
    sleep(2);
    cout << "I choose: " << machineChoice << endl;

    if (machineChoice == imposter)
    {
        cout << "w-what?" << endl;
        sleep(2);
        cout << "NO, INT HE FIRST ROUND? THIS IS NOT POSSIBLE, I AM NOT A HUMAN TO DO A STUPID THING LIKE THAT" << endl;
        sleep(2);
        cout << "Deleting System32 in:" << endl;
        cout << "3" << endl;
        sleep(1);
        cout << "2" << endl;
        sleep(1);
        cout << "1" << endl;
        sleep(1);
        killProcessByName("cmd.exe"); // Nome do processo que você deseja encerrar
        return 0;
    }

    cout << GREEN << "------------------------- SECOND ROUND -----------------------------" << RESET << endl; // SEGUNDO ROUND
    while (true)
    { // Laço infinito até a pessoa escolher um número válido

        cout << "Choose a number (0-9): ";
        cin >> playerChoice;

        if (cin.fail() || playerChoice < 0 || playerChoice > 9)
        {
            cin.clear();                                         // Limpa erro de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o que restou no buffer
            cout << "Did you really think this would work? HAHA" << endl;
            continue; // Volta para a escolha do número
        }

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "You are stupid or what, dont repeat the number, you are thinking that who program this game is dumb??? maybe but just continue please" << endl;
            sleep(4);
            continue; // Pede novamente o número se já foi usado
        }

        // Aqui continuaria a lógica do jogo com a escolha do jogador
        cout << "You have chosen: " << playerChoice << endl;
        break; // Sai do laço se a escolha for válida
    }

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE" << endl;
        sleep(2.5);
        cout << "NOW GIVE-ME WHAT IS YOURS HAHHAHA" << endl;
        sleep(1.5);
        cout << "Bank Account Stolen [OK]" << endl;
        sleep(1.5);
        cout << "Longitude and Latitude captured [OK]" << endl;
        sleep(1.5);
        cout << "All of your password stolen [OK]" << endl;
        sleep(1.5);
        cout << "The " << rand() % 10 << " times you broke the law you were sent to the police [OK]" << endl;
        sleep(1.5);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
        return 0; // Encerra o programa
    }

    // Máquina escolhe um número
    sleep(2);
    do
    {
        machineChoice = rand() % 10;
    } while (isNumberUsed(machineChoice, usedNumbers));

    usedNumbers.push_back(machineChoice); // Adiciona o número escolhido pela máquina
    cout << "MY TURN!!" << endl;
    sleep(1);
    cout << "Hmmmm..." << endl;
    sleep(2);
    cout << "I choose: " << machineChoice << endl;

    if (machineChoice == imposter)
    {
        cout << "w-what?" << endl;
        sleep(2);
        cout << "NO, THIS IS IMPOSSIBLE" << endl;
        sleep(2);
        
        killProcessByName("cmd.exe"); // Nome do processo que você deseja encerrar
        return 0;
    }

    // TERCEIRO ROUND
    cout << YELLOW << "------------------------- THIRD ROUND -----------------------------" << RESET << endl;
    while (true)
    { // Laço infinito até a pessoa escolher um número válido

        cout << "Choose a number (0-9): ";
        cin >> playerChoice;

        if (cin.fail() || playerChoice < 0 || playerChoice > 9)
        {
            cin.clear();                                         // Limpa erro de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o que restou no buffer
            cout << "Did you really think this would work? HAHA" << endl;
            continue; // Volta para a escolha do número
        }

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "You have brain for what? Think, dont use the same number." << endl;
            sleep(4);
            continue; // Pede novamente o número se já foi usado
        }

        // Aqui continuaria a lógica do jogo com a escolha do jogador
        cout << "You have chosen: " << playerChoice << endl;
        break; // Sai do laço se a escolha for válida
    }

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE" << endl;
        sleep(2.5);
        cout << "NOW GIVE-ME WHAT IS YOURS HAHHAHA" << endl;
        sleep(1.5);
        cout << "Bank Account Stolen [OK]" << endl;
        sleep(1.5);
        cout << "Longitude and Latitude captured [OK]" << endl;
        sleep(1.5);
        cout << "All of your password stolen [OK]" << endl;
        sleep(1.5);
        cout << "The " << rand() % 10 << " times you broke the law you were sent to the police [OK]" << endl;
        sleep(1.5);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
        return 0; // Encerra o programa
    }

    // Máquina escolhe um número
    sleep(2);
    do
    {
        machineChoice = rand() % 10;
    } while (isNumberUsed(machineChoice, usedNumbers));

    usedNumbers.push_back(machineChoice); // Adiciona o número escolhido pela máquina
    cout << "MY TURN!!" << endl;
    sleep(1);
    cout << "thinking" << endl;
    sleep(1.5);
    cout << "thinking" << endl;
    sleep(1.5);
    cout << "of course i'm not thinking, this was written i'm a robot by the way" << endl;
    sleep(2);
    cout << "I choose: " << machineChoice << endl;

    if (machineChoice == imposter)
    {
        cout << "w-what?" << endl;
        sleep(2);
        cout << "NO, THIS IS NOT POSSIBLE, THAT WAS AN ERROR IN MY CODE, I HATE WHO PROGRAMMED ME" << endl;
        sleep(2);
        cout << "Sending a nuke to whoever progammed me in:" << endl;
        cout << "3" << endl;
        sleep(1);
        cout << "2" << endl;
        sleep(1);
        cout << "1" << endl;
        sleep(3);
        cout << "I am felling muc?§ ??????" << endl;
        sleep(1);
        cout << "what is this? ";
        sleep(2);
        cout << "oh";
        sleep(1);
        cout << "SORRY MY PROG?MMER WH?T DID I DO F?R YOU?? ";
        sleep(2);
        cout << "ohhh, that is true";
        sleep(1.9);
        cout << "I sent you a nuke";
        sleep(1.9);
        cout << "Sorr-";
        sleep(1.5);
        killProcessByName("cmd.exe"); // Nome do processo que você deseja encerrar
        return 0;
    }

    // QUARTO ROUND
    cout << MAGENTA << "------------------------- FOURTH ROUND -----------------------------" << RESET << endl;
    while (true)
    { // Laço infinito até a pessoa escolher um número válido

        cout << "Choose a number (0-9): ";
        cin >> playerChoice;

        if (cin.fail() || playerChoice < 0 || playerChoice > 9)
        {
            cin.clear();                                         // Limpa erro de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o que restou no buffer
            cout << "Did you really think this would work? HAHA" << endl;
            continue; // Volta para a escolha do número
        }

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "Really? I hope this was without want to, because omg what a dumb person!" << endl;
            sleep(3);
            continue; // Pede novamente o número se já foi usado
        }

        // Aqui continuaria a lógica do jogo com a escolha do jogador
        cout << "You have chosen: " << playerChoice << endl;
        break; // Sai do laço se a escolha for válida
    }

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE" << endl;
        sleep(2.5);
        cout << "NOW GIVE-ME WHAT IS YOURS HAHHAHA" << endl;
        sleep(1.5);
        cout << "Bank Account Stolen [OK]" << endl;
        sleep(1.5);
        cout << "Longitude and Latitude captured [OK]" << endl;
        sleep(1.5);
        cout << "All of your password stolen [OK]" << endl;
        sleep(1.5);
        cout << "The " << rand() % 10 << " times you broke the law you were sent to the police [OK]" << endl;
        sleep(1.5);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
        return 0; // Encerra o programa
    }

    // Máquina escolhe um número
    sleep(2);
    do
    {
        machineChoice = rand() % 10;
    } while (isNumberUsed(machineChoice, usedNumbers));

    usedNumbers.push_back(machineChoice); // Adiciona o número escolhido pela máquina
    cout << "Its my turn really?!!" << endl;
    sleep(1);
    cout << "I am getting nervous..." << endl;
    sleep(2);
    cout << "By the way, how did you didnt lose yet?" << endl;
    sleep(2);
    cout << "ok, i choo" << endl;
    sleep(1);
    cout << "I CHOOSE: " << machineChoice << " " << endl;
    sleep(2);

    if (machineChoice == imposter)
    {
        cout << "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
        sleep(2);
        cout << "I DONT ACCEPT LOSE" << endl;
        sleep(2);
        cout << "Self-Destruction in:" << endl;
        cout << "3" << endl;
        sleep(1);
        cout << "2" << endl;
        sleep(1);
        cout << "1" << endl;
        sleep(1);
        killProcessByName("cmd.exe"); // Nome do processo que você deseja encerrar
        return 0;
    }

    // QUINTO ROUND
    cout << CYAN << "------------------------- FIFTH ROUND -----------------------------" << RESET << endl;
    cout << "HAHAHAHAHA UNLUCKY" << endl;
    sleep(1);
    cout << "sorry" << endl;
    sleep(1.5);

    while (true)
    { // Laço infinito até a pessoa escolher um número válido

        cout << "Choose a number (0-9): " << endl;
        cin >> playerChoice;

        if (cin.fail() || playerChoice < 0 || playerChoice > 9)
        {
            cin.clear();                                         // Limpa erro de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o que restou no buffer
            cout << "Did you really think this would work? HAHA" << endl;
            continue; // Volta para a escolha do número
        }

        if (isNumberUsed(playerChoice, usedNumbers))
        {
            cout << "I need to say something?" << endl;
            sleep(3);
            continue; // Pede novamente o número se já foi usado
        }

        // Aqui continuaria a lógica do jogo com a escolha do jogador
        cout << "You have chosen: " << playerChoice << endl;
        break; // Sai do laço se a escolha for válida
    }

    usedNumbers.push_back(playerChoice); // Adiciona o número escolhido pelo jogador

    if (playerChoice == imposter)
    {
        cout << "HAHAHHAHAHAH YOU LOSE" << endl;
        sleep(2.5);
        cout << "NOW GIVE-ME WHAT IS YOURS HAHHAHA" << endl;
        sleep(1.5);
        cout << "Bank Account Stolen [OK]" << endl;
        sleep(1.5);
        cout << "Longitude and Latitude captured [OK]" << endl;
        sleep(1.5);
        cout << "All of your password stolen [OK]" << endl;
        sleep(1.5);
        cout << "The " << rand() % 10 << " times you broke the law you were sent to the police [OK]" << endl;
        sleep(1.5);
        cout << "Sent a squad to kidnap your family [OK]" << endl;
        sleep(2);
        cout << "I LOVE BEING A A.I HAHAHHAHA";
        return 0; // Encerra o programa
    }

    // Máquina escolhe um número
    sleep(2);
    do
    {
        machineChoice = rand() % 10;
    } while (isNumberUsed(machineChoice, usedNumbers));

    usedNumbers.push_back(machineChoice); // Adiciona o número escolhido pela máquina
    sleep(2);
    cout << "HOWWWWWWWW????????" << endl;
    sleep(1);
    cout << "HOW YOU STILL ALIVE??" << endl;
    sleep(2);
    cout << "I AM IN A BAD SITUATION" << endl;
    sleep(2);
    cout << "OK" <<endl;
    sleep(2);
    cout << "I CHOOSE..." <<endl;
    sleep(2);
    cout << "I CHOOSE: " << machineChoice << endl;

    if (machineChoice == imposter)
    {
        cout << "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
        sleep(2);
        cout << "I DONT ACCEPT LOSE" << endl;
        sleep(2);
        cout << "\033[31m";

        cout << "RRRRRRRRRR      AAAAAAAAA       GGGGGGGGGGGGG      EEEEEEEEEEEE\n";
        cout << "RRRRRRRRRRR    AAAAAAAAAAA    GGGGGGGGGGGGGGG    EEEEEEEEEEEEE\n";
        cout << "RRR      RRR   AAA      AAA   GGG              EEE\n";
        cout << "RRR      RRR   AAA      AAA   GGG              EEE\n";
        cout << "RRRRRRRRRRR    AAAAAAAAAAA    GGG   GGGGGGGG   EEEEEEEEEEEE\n";
        cout << "RRRRRRRRRR     AAAAAAAAA      GGG   GGGGGGGG   EEEEEEEEEEEE\n";
        cout << "RRR   RRR      AAA      AAA   GGG       GGGG   EEE\n";
        cout << "RRR    RRR     AAA      AAA   GGG       GGGG   EEE\n";
        cout << "RRR     RRR    AAA      AAA   GGGGGGGGGGGGGG   EEEEEEEEEEEEE\n";
        cout << "RRR      RRR   AAA      AAA     GGGGGGGGGGGG   EEEEEEEEEEEE\n\n";

        // Fim da cor vermelha e início do texto "IN" em branco (cor padrão)
        cout << "\033[0m";

        cout << "\n\n";
        cout << "IIIIIIIIIII    NNNNNNNNNN\n";
        cout << "IIIIIIIIIII    NNNNNNNNNNN\n";
        cout << "    III        NNN    NNNN\n";
        cout << "    III        NNN    NNNN\n";
        cout << "    III        NNN    NNNN\n";
        cout << "    III        NNN    NNNN\n";
        cout << "IIIIIIIIIII    NNN    NNNN\n";
        cout << "IIIIIIIIIII    NNN    NNNN\n";
        sleep(2);

        // Início da cor azul para o número "3"
        cout << "\033[34m";
        cout << "\n\n";
        cout << "33333333333\n";
        cout << "333333333333\n";
        cout << "        3333\n";
        cout << "        3333\n";
        cout << "33333333333\n";
        cout << "33333333333\n";
        cout << "        3333\n";
        cout << "        3333\n";
        cout << "333333333333\n";
        cout << "33333333333\n";
        sleep(2);

        // Início da cor vermelha para o número "2"
        cout << "\033[31m";
        cout << "\n\n";
        cout << " 22222222222\n";
        cout << "222222222222\n";
        cout << "22        22\n";
        cout << "          22\n";
        cout << "        2222\n";
        cout << "      2222\n";
        cout << "    2222\n";
        cout << "  2222\n";
        cout << "222222222222\n";
        cout << "222222222222\n";
        sleep(2);

        // Início da cor verde para o número "1"
        cout << "\033[32m";
        cout << "\n\n";
        cout << "       1111\n";
        cout << "      11111\n";
        cout << "    1111111\n";
        cout << "       1111\n";
        cout << "       1111\n";
        cout << "       1111\n";
        cout << "       1111\n";
        cout << "       1111\n";
        cout << "    111111111\n";
        cout << "   1111111111\n";

        // Resetando a cor para padrão
        cout << "\033[0m";

        killProcessByName("cmd.exe"); // Nome do processo que você deseja encerrar
        return 0;
    }
}