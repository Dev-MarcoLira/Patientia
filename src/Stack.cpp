#include "../include/Stack.hpp"

Stack::Stack(){}

bool Stack::push(const Card& card) {
    if (!isFull()) {
        cards.push_back(card);
        return true;
    }
    return false;
}

bool Stack::pop(Card& card) {
    if (!isEmpty()) {
        card = cards.back();
        cards.pop_back();
        return true;
    }
    return false;
}

bool Stack::isEmpty() const {
    return cards.empty();
}

bool Stack::isFull() const {
    return cards.size() >= LIMITE;
}

Card Stack::top() const {
    if (!isEmpty()) {
        return cards.back();
    }
    return Card(); // Return a default Card if the stack is empty
}

std::vector<Card> Stack::getCards() const {
    return cards;
}