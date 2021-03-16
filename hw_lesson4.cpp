#include <iostream>
#include <cstdint>
#include "Arrayint.h"
#include <vector>

//-----------------------
// Task 2
//-----------------------

int16_t getUniqueElementsNumber (std::vector<int16_t>& vector) {
    int16_t counter = 0;
    for (int16_t i = 0; i < vector.size() - 1; i++)
    {
        if (vector[i] - vector[i+1]) {++counter;};
    }
    if (vector[vector.size()] - vector[vector.size() - 1] != 0) ++counter;
    return counter;
}

//-----------------------
// Task 3
//-----------------------

//class Card from previous homework

class Card {

    enum class cardSuits {
        SPADES,
        HEARTS,
        DIAMONDS,
        CLUBS
    };

    enum class cardValues {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };

    cardSuits cardSuit;
    cardValues cardValue = cardValues::ACE;

    bool isCardClosed = true;

public:

    void Flip() {isCardClosed = !isCardClosed;}

    int16_t const GetValue(){
        switch (cardValue) {
            case cardValues::TWO: return 2;
            case cardValues::THREE: return 3;
            case cardValues::FOUR: return 4;
            case cardValues::FIVE: return 5;
            case cardValues::SIX: return 6;
            case cardValues::SEVEN: return 7;
            case cardValues::EIGHT: return 8;
            case cardValues::NINE: return 9;
            case cardValues::TEN: return 10;
            case cardValues::JACK: return 10;
            case cardValues::QUEEN: return 10;
            case cardValues::KING: return 10;
            case cardValues::ACE: return 1;
        }
    }

    void print() {
        if(isCardClosed) std::cout << "Card is closed" << std::endl;
        else std::cout << "Card is open" << std::endl;
    }

};

class Hand {

    std::vector<Card*> m_cards;

public:

    void Add(Card* card) {

        m_cards.push_back(card);

    }

    void Clear (){

        m_cards.clear();
    }

    int16_t GetValue() {
        int16_t sum = 0;
        int16_t ace_counter = 0;
        int16_t bust_or_not = 0;

        for (Card* card : m_cards) {
            if (card -> GetValue() == 1)
                ++ace_counter;
                continue;
            sum += card->GetValue();
        }
        //set value of first ace - 1 or 11 by checking, will it bust player or not
        if (ace_counter){
            bust_or_not = sum + 11 + (ace_counter - 1);
            if (bust_or_not > 21) sum += ace_counter;
            else sum = bust_or_not;
        }
        return sum;
    }

};

int main() {

    std::cout <<"***Task 1***\n\n";

    ArrayInt array(7);
    array.insertBefore(9,0);
    array.insertBefore(8,1);
    array.insertBefore(10,2);
    array.insertBefore(112,3);
    array.insertBefore(2,4);
    array.insertBefore(4,5);
    array.insertBefore(1,6);
    array.resize(7);

    std::cout << "Original array:";
    array.print();
    array.pop_back();
    std::cout << "pop.back():";
    array.print();
    array.pop_front();
    std::cout << "pop.front():";
    array.print();
    std::cout << "Sorted array:";
    array.sort();
    array.print();

    std::cout <<"\n***Task 2***\n\n";

    std::vector<int16_t> vector = {2, 3, 1, 4, 3, 9, 1, 2, 2};
    std::sort(vector.begin(),vector.end());
    std::cout << "Sorted vector: [ ";
    for (int16_t i : vector) std:: cout << i << " ";
    std::cout << "]\n";
    std::cout << "The number of unique numbers in vector: " << getUniqueElementsNumber(vector);

    std::cout <<"\n\n***Task 3***\n\n";

    Card card_ace;
    Hand hand;
    hand.Add(&card_ace);
    std::cout << "The values of card in hand: " << hand.GetValue();

    return 0;
}
