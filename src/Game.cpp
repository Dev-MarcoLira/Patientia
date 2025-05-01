#include "../include/Game.hpp"
#include <algorithm>
#include <random>

using namespace std;

Game::Game() : window(sf::VideoMode(1000, 700), "Patientia") {
    font.loadFromFile("assets/fonts/ARIAL.TTF");
    statusText.setFont(font);
    statusText.setCharacterSize(22);
    statusText.setFillColor(Color::White);
    statusText.setPosition(20, 650);

    carregarBaralho();
}

void Game::carregarBaralho() {

    string valores[] = {
        "♣8","♣A","♥K","♣7","♦K","♦9","♣2","♥Q","♥J","♥A",
        "♦A","♥5","♦3","♠9","♣4","♦2","♦J","♣Q","♥9","♦Q",
        "♥6","♠A","♥3","♠3","♥7","♣K","♠10","♠4","♠Q","♦10",
        "♠5","♠J","♣9","♥4","♣J","♠2","♥10","♠7","♣10","♠6",
        "♦8","♣6","♦4","♦6","♥2","♥8","♠8","♣3","♦5","♦7",
        "♠K","♣5"
    };

    vector<string> embaralhado(begin(valores), end(valores));
    
    shuffle(embaralhado.begin(), embaralhado.end(), mt19937(random_device()()));

    for (const auto& valor : embaralhado) {
        
        sf::Texture* textura = new sf::Texture();
        string path = "assets/cards/" + valor + ".png";

        if (!textura->loadFromFile(path)) {
            delete textura;
            textura = nullptr;

            throw runtime_error("Erro ao carregar a textura: " + path);
        }
        baralho.emplace_back(valor, textura);
    }
}

void Game::run() {
    
    bool jogoIniciado = false;

    sf::Text btnIniciar("Iniciar Jogo", font, 30);
    btnIniciar.setFillColor(sf::Color::Black);
    btnIniciar.setPosition(400, 300);

    sf::RectangleShape btnBox(sf::Vector2f(200, 60));
    btnBox.setFillColor(sf::Color::Green);
    btnBox.setPosition(390, 290);

    while (window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (!jogoIniciado && event.type == sf::Event::MouseButtonPressed){

                if(btnBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    jogoIniciado = true;
                    temCartaAtual = true;
                    cartaAtual = baralho[topoBaralho--];
                }
            }

            if(jogoIniciado) tratarEventos();
        }

        window.clear(sf::Color(10, 100, 10));

        if(jogoIniciado) {
            atualizar();
            renderizar();
        }else {
            window.draw(btnBox);
            window.draw(btnIniciar);
        }

        window.display();
    }
}

void Game::tratarEventos() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        pularCarta();

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        if(temCartaAtual) pilhas[0].push(cartaAtual);

        if(topoBaralho >= 0) cartaAtual = baralho[topoBaralho--];
        else temCartaAtual = false;

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        if(temCartaAtual) pilhas[1].push(cartaAtual);

        if(topoBaralho >= 0) cartaAtual = baralho[topoBaralho--];
        else temCartaAtual = false;

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        if(temCartaAtual) pilhas[2].push(cartaAtual);

        if(topoBaralho >= 0) cartaAtual = baralho[topoBaralho--];
        else temCartaAtual = false;
    
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        if(temCartaAtual) pilhas[3].push(cartaAtual);

        if(topoBaralho >= 0) cartaAtual = baralho[topoBaralho--];
        else temCartaAtual = false;
    }
}

void Game::pularCarta() {
    pilhaPuladas.push(cartaAtual);

    if(topoBaralho >= 0) cartaAtual = baralho[topoBaralho--];
    else temCartaAtual = false;
    
}

void Game::atualizar() {
    if(!temCartaAtual && !pilhaPuladas.isEmpty()) {
        
        while(!pilhaPuladas.isEmpty()) {
            Card carta;
            pilhaPuladas.pop(carta);
            baralho[++topoBaralho] = carta;
        }

        cartaAtual = baralho[topoBaralho--];
        temCartaAtual = true;
    }

    statusText.setString("Topo do baralho: " + to_string(topoBaralho + 1) + "\n" +
                            "Cartas puladas: " + to_string(pilhaPuladas.getCards().size()) + "\n" +
                            "Pressione 1-4 para mover a carta. Espaço para pular."
    );
}

void Game::renderizar() {
    window.clear(sf::Color(10, 100, 10));

    if (temCartaAtual)
        cartaAtual.draw(window, 400, 50);
    

    // Render the four stacks
    for(int i = 0; i < 4; i++){

        float x = 100 + i * 200;
        auto cards = pilhas[i].getCards();

        for (size_t j = 0; j < cards.size(); j++) {
            cards[j].draw(window, x, 150 + j * 20);
        }
    }

    window.draw(statusText);
    window.display();
}