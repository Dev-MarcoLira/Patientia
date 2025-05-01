#include "../include/Card.hpp"

Card::Card(const std::string& valor, const Texture* textura) : valor(valor) {

    if(!valor.empty() && textura) {
        sprite.setTexture(*textura);
        sprite.setScale(0.5f, 0.5f);
    }

    if(!valor.empty())
        naipe = valor[0]; // Assuming the first character is the suit

}

void Card::draw(RenderWindow& window, float x, float y) {
    sprite.setPosition(x, y);
    window.draw(sprite);
}