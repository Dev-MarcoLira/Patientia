#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;


class Card {

    public:
        Card(const std::string& valor = "", const Texture* textura = nullptr);

        void draw(RenderWindow& window, float x, float y);

        std::string valor;
        char naipe;

    private:
        Sprite sprite;

};