#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Card.hpp"

class Stack {

    public:
        Stack();

        bool push(const Card& card);
        bool pop(Card& card);
        Card top() const;
        bool isEmpty() const;
        bool isFull() const;
        std::vector<Card> getCards() const;

    private:
        std::vector<Card> cards; // Vector to hold the cards in the stack
        const size_t LIMITE = 13;

};