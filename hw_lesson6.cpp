#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <vector>

//Task 1

//Checking that every symbol in input string is int
bool stringIsInt(const std::string& string) {
    for (int16_t i = 0; i < string.size(); i++)
        if (!(isdigit(string[i])))
            return false;
    return true;
}

int getInputNumber () {
    while (true) {
        std::string number = " ";
        std::cout << "\nEnter one int number: ";
        std::cin >> number;
        if (!(stringIsInt(number))) {
            std::cout << "\nYou have entered wrong type of data. Try again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else return std::stoi(number);
        }
    return 0;
    }

//Task 2

std::ostream &endll(std::ostream &stream) {
    stream << std::endl << std::endl;
    stream.clear();
    return stream;
}

//Task 3

//classes from previous homework

class Card {

    bool isCardClosed = true;

public:

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

    cardSuits m_cardSuit;
    cardValues m_cardValue;

    Card(cardSuits cardSuit, cardValues cardValue)
    : m_cardSuit(cardSuit), m_cardValue(cardValue) {}

    void Flip() {isCardClosed = !isCardClosed;}

    std::string GetSuit() const {
        switch (m_cardSuit) {
            case cardSuits::SPADES: return "SPADES";
            case cardSuits::HEARTS: return "HEARTS";
            case cardSuits::DIAMONDS: return "DIAMONDS";
            case cardSuits::CLUBS: return "CLUBS";
        }
    }

    int16_t GetCardValue() const{
        switch (m_cardValue) {
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

    std::string GetCardName() const {
        switch (m_cardValue) {

            case cardValues::TWO: return "TWO";
            case cardValues::THREE: return "THREE";
            case cardValues::FOUR: return "FOUR";
            case cardValues::FIVE: return "FIVE";
            case cardValues::SIX: return "SIX";
            case cardValues::SEVEN: return "SEVEN";
            case cardValues::EIGHT: return "EIGHT";
            case cardValues::NINE: return "NINE";
            case cardValues::TEN: return "TEN";
            case cardValues::JACK: return "JACK";
            case cardValues::QUEEN: return "QUEEN";
            case cardValues::KING: return "KING";
            case cardValues::ACE: return "ACE";

        }
    }

    void print() {
        if(isCardClosed) std::cout << "Card is closed" << std::endl;
        else std::cout << "Card is open" << std::endl;
    }

    friend std::ostream& operator<< (std::ostream& out, const Card& card);

};

class Hand {

protected:
    std::vector<Card*> m_cards;

public:

    void Add(Card* card) {

        m_cards.push_back(card);

    }

    void Clear (){
        std::vector<Card*>::iterator iter = m_cards.begin();
        for (iter = m_cards.begin(); iter != m_cards.end(); iter++)
        {
            delete* iter;
            *iter = 0;
        }
        m_cards.clear();
    }

    int16_t GetValue() const {
        int16_t sum = 0;
        int16_t ace_counter = 0;
        int16_t bust_or_not = 0;

        for (Card* card : m_cards) {
            if (card -> GetCardValue() == 1) {
                ++ace_counter;
                continue;}
            sum += card->GetCardValue();
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

class GenericPlayer : public Hand {

protected:
    std::string m_name = "John";

public:

    GenericPlayer(const std::string& name)
    : m_name(name) {}

    virtual bool IsHitting() const = 0;

    bool isBoosted() {
        return (GetValue() > 21);
    }

    void Bust() {

        if (isBoosted()) {
            std::cout << "Player " << m_name << "is boosted!" << std::endl;
        }

    }

    friend std::ostream& operator<< (std::ostream& out, const GenericPlayer& generic_player);
};

//New class (Task 3)

class Player : public GenericPlayer {

public:

    Player(const std::string& name)
    : GenericPlayer(name) {}

    virtual bool IsHitting() const override {
        while (true)
        {
            std::cout << "Do you want a new card? Y/y for Yes, N/n for No." << std::endl;
            char answer = ' ';
            std::cin >> answer;
            if (answer == 'y' or answer == 'Y') {return true;}
            else if (answer == 'n' or answer == 'N') {return false;}
            std::cout << "Please, insert only valid symbol as a first symbol." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void Win() const {std::cout << "Player" << m_name << "is a winner!" << std::endl;}
    void Lose() const {std::cout << "Player" << m_name << "is a loser!" << std::endl;}
    void Push() const {std::cout << "Player" << m_name << "played a draw!" << std::endl;}

};

//New class (Task 4)

class House : public GenericPlayer {

public:

    virtual bool IsHitting() const override {
        if (GetValue() < 16) {return true;}
        return false;
    }

    void FlipFirstCard() {

        m_cards[0]->Flip();

    }
};

//Task 5

std::ostream& operator<< (std::ostream& out, const Card& card) {
    if (card.isCardClosed) {out << "XX\n"; return out;}
    out << "Card suit is a " << card.GetSuit() << " and card name is: " << card.GetCardName();
    return out;
}

std::ostream& operator<< (std::ostream& out, const GenericPlayer& generic_player) {
    out << "Player name is a " << generic_player.m_name << std::endl;
    out << "He has this cards: ";
     for (Card* card : generic_player.m_cards) {
         std::cout << card->GetCardName() << " ";
     }
     out << "\n The sum of values of all his cards is: " << generic_player.GetValue();
    return out;
}

int main() {

    std::cout << "***Task 1***\n";
    int32_t number = getInputNumber();
    std::cout << "You have entered a number: " << number << std::endl;

    std::cout << "\n***Task 2***\n";
    std::cout << endll << "hello" << endll << "there" << std::endl;

    std::cout << "\n***Task 3 + 5***\n";

    Card six(Card::cardSuits::HEARTS, Card::cardValues::SIX);
    Card ace(Card::cardSuits::SPADES, Card::cardValues::ACE);
    Card two(Card::cardSuits::CLUBS, Card::cardValues::TWO);
    Player player("Ivan");
    player.Add(&six);
    player.Add(&ace);
    player.Add(&two);

    std::cout << ace << std::endl;
    ace.Flip();
    std::cout << ace << "\n\n";
    std::cout << player;

    return 0;
}
