#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Card.hpp"
#include "Stack.hpp"

using namespace sf;

class Game {

    public:
        Game();
        void run();

    private:
        RenderWindow window;

        std::vector<Card> baralho;
        Stack pilhas[4];
        Stack pilhaPuladas;

        Font font;
        Text statusText;

        int topoBaralho = 51;
        Card cartaAtual;
        bool temCartaAtual = false;

        void carregarBaralho();
        void tratarEventos();
        void atualizar();
        void renderizar();
        void pularCarta();

};