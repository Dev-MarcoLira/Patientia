#include <iostream>
#include <string>
#include <windows.h>
#define MAX 13

using namespace std;

/* Baralho e mesa  */
string baralho[52] = {
    "♣8","♣A","♥K","♣7","♦K","♦9","♣2","♥Q","♥J","♥A","♦A","♥5","♦3","♠9",
    "♣4","♦2","♦J","♣Q","♥9","♦Q","♥6","♠A","♥3","♠3","♥7","♣K","♠10","♠4",
    "♠Q","♦10","♠5","♠J","♣9","♥4","♣J","♠2","♥10","♠7","♣10","♠6","♦8",
    "♣6","♦4","♦6","♥2","♥8","♠8","♣3","♦5","♦7","♠K","♣5"
};

string mesa[4][MAX];
int topo_baralho = 51;
int topo_mesa[4] = { -1, -1, -1 , -1 };

string pilha_puladas[52];
int topo_puladas = -1;

/* Funções de pilha */

bool isFull(int topo){
    return topo == MAX - 1;
}

bool isEmpty(int topo){
    return topo == -1;
}

string top(int pilha){
    if(topo_mesa[pilha] >= 0){
        return mesa[pilha][topo_mesa[pilha]];
    }

    return "";
}

char getSuit(string card){
    
    return card[0];
}

string getValue(string card){
    
    return card.substr(card.size() - (card.size() == 3 ? 2 : 1));
}

int getNumValue(string value){
    if (value == "A") return 1;
    if (value == "J") return 11;
    if (value == "Q") return 12;
    if (value == "K") return 13;

    return stoi(value);
}

// Funções do baralho de cartas puladas

void pushPulada(string card){
    pilha_puladas[++topo_puladas] = card;
}

void refreshBaralho(){
    if(topo_puladas >= 0){
        cout << "\n>> Recarregando o baralho principal com as cartas puladas...";

        while(topo_puladas >= 0){
            baralho[++topo_baralho] = pilha_puladas[topo_puladas--];
        }
    }
}

// RNF5 - função separada para exibir mesa

void showTable(){

    cout << "\n=== Estado atual da mesa ===\n";

    for (int i = 0; i < 4; i++) {
        cout << "Pilha " << i + 1 << ": ";
        if (isEmpty(topo_mesa[i])) {
            cout << "[vazia]";
        } else {
            for (int j = 0; j <= topo_mesa[i]; j++) {
                cout << mesa[i][j] << " ";
            }
        }
        cout << endl;
    }

}

// RNF4 - push para adicionar carta NA PILHA DESEJADA

bool pushCardInTheTable(string card, int pilha){

    if(pilha < 0 || pilha > 3) return false;

    if(isFull(topo_mesa[pilha])) return false;

    char suit = getSuit(card);
    string value_card = getValue(card);
    int value = getNumValue(value_card);

    if(isEmpty(topo_mesa[pilha])){

        if(value_card != "K"){
            cout << "\nErro: só é permitido iniciar a pilha com um Rei (K).\n";
            return false;
        }

        mesa[pilha][++topo_mesa[pilha]] = card;
        return true;

    }else{    
        if(value_card == "K"){

            cout << "\nErro: só é permitido um Rei (K) por pilha.\n";
            return false;                
        }
    }

    /* Restrições Opcionais:
        - mesmo naipe
        - ordem decrescente
    */

    string topo = top(pilha);
    char suit_top = getSuit(topo);
    string value_topo = getValue(topo);
    int value_n_topo = getNumValue(value_topo);

    if(suit != suit_top){
        cout << "Erro: só pode colocar cartas do mesmo naipe na pilha. \n";
        return false;
    }

   /* if(value != value_n_topo -1){
        cout << "Erro: a carta deve estar em ordem decrescente. \n";
        return false;
    }*/

    mesa[pilha][++topo_mesa[pilha]] = card;

    return true;
}

int main() {
    // faz o console imprimir UTF-8 - devido aos símbolos Unicode do baralho
    SetConsoleOutputCP(CP_UTF8);

    while(topo_baralho >= 0 || topo_puladas >= 0){

        if(topo_baralho < 0){
            refreshBaralho();
            if(topo_baralho < 0) break;
        }

        string card = baralho[topo_baralho--];

        cout << "\n==== Nova Rodada ====\n";
        cout << "Carta da rodada: [" << card << "]\n";

        cout << "Escolha uma pilha para colocar a carta (1-4) ou 0 para pular: ";

        int pilha;
        cin >> pilha;

        cout << endl;

        if(pilha == 0){

            pushPulada(card);

            cout << "Carta pulada!\n";
        }else if(pilha >= 1 && pilha <= 4){

            if(!pushCardInTheTable(card, pilha - 1)){
                cout << "A carta não pôde ser colocada. Ela será pulada.\n";
                pushPulada(card);
            }
        }else{

            cout << "Escolha inválida. A carta será pulada.\n";
            pushPulada(card);
        }

        showTable();
    }


    cout << "===== Fim do Jogo! ====\n";
    return 0;
}