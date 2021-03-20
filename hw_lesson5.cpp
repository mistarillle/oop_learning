#include <iostream>
#include <vector>

//Task 1

template<class T>
class Pair1{

    T m_first = 0;
    T m_second = 0;

public:

    Pair1(T first, T second)
    : m_first(first), m_second(second) {};

    T first() const {return m_first;}

    T second() const {return m_second;}
};

//Task 2

template <class T, class T2>
class Pair{

    T m_first = 0;
    T2 m_second = 0;

public:

    Pair(T first, T2 second)
    : m_first(first), m_second(second) {};

    T first() const {return m_first;}

    T2 second() const {return m_second;}
};

//Task 3

template <class T>
class Pair<std::string&, T>{

    std::string& m_first;
    T m_second = 0;

public:

    Pair(std::string& first, T second)
    : m_first(first), m_second(second) {};

    std::string& first() const {return m_first;}
    T second () const {return m_second;}

};

template <class T>
class StringValuePair : public Pair<std::string&, T> {
public:

    StringValuePair(std::string first, T second)
    : Pair<std::string&, T>(first, second) {}

};

//Task 4

//classes from previous homework

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

//New class (Task 4)

class GenericPlayer : public Hand {

    std::string m_name = "unknown";

public:

    virtual bool isHitting() = 0;

    bool isBoosted() {
        return (GetValue() > 21);
    }

    void Bust() {

        if (isBoosted()) {
            std::cout << "Player " << m_name << "is boosted!" << std::endl;
        }

    }
};

int main() {

    std::cout << "***Task 1***\n";

    Pair1<int> p1(6,9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    std::cout << "\n***Task 2***\n";

    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    std::cout << "\n***Task 3***\n";

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    
    return 0;
}
