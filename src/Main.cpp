#include <iostream>
#include <string>
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
    return card.substr(1);
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

    // Falta fazer

    return true;
}