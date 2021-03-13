#include <iostream>
#include <cstdint>
#include <string>

//-----------------------
// Task 1
//-----------------------

class Figure {
public:
    virtual ~Figure() {};
    virtual const double area() = 0;
};

class Circle : public Figure{

    const double mRadius = 0;

public:

    Circle(double Radius)
    : mRadius(Radius) {}

    const double area() override {return 3.14 * mRadius * mRadius;}

};

class Parallelogram : public Figure{
protected:

    const double m_a = 0;
    const double m_h_a = 0;

public:

    Parallelogram(double a = 0, double h_a = 0)
    : m_a(a), m_h_a(h_a) {}

    const double area() override {return m_a * m_h_a;}

};

class Rectangle : public Parallelogram {

    const double m_b = 0;

public:

    Rectangle(double a, double b)
    : Parallelogram(a), m_b(b) {}

    const double area() override {return m_a * m_b;}

};

class Square : public Parallelogram{

//    const double m_a = 0;

public:

    Square(double a)
    : Parallelogram(a) {}

    const double area() override {return m_a * m_a;}

};

class Rhombus: public Parallelogram{

public:

    Rhombus(double a, double h_a)
    : Parallelogram(a,h_a) {}

   const double area() override {return m_a * m_h_a;}

};

const void printFigureArea (Figure& figure_class) {

    std::cout << "The area of " << typeid(figure_class).name() << " is "
    << figure_class.area() << std::endl;

};

//-----------------------
// Task 2
//-----------------------

class Car{

protected:
    std::string m_company = "unknown";
    std::string m_model = "unknown";

public:
    Car(const std::string& company, const std::string& model)
    : m_company(company), m_model(model) {
        std::cout << "Car's company is " << m_company << std::endl <<
        "Car's model is " << m_model << std::endl << "Car's constructor is over." << std::endl;
    }
    virtual ~Car() {};
};

class PassengerCar : virtual public Car{

public:
    PassengerCar(const std::string& company, const std::string& model)
    : Car(company, model) {std::cout << "PassengerCar's constructor is over." << std::endl;}

};

class Bus : virtual public Car {

public:

    Bus(const std::string& company, const std::string& model)
    : Car(company, model) {std::cout << "Bus constructor is over." << std::endl;}

};

class Minivan : public PassengerCar, public Bus {

public:

    Minivan(const std::string& company, const std::string& model)
    : PassengerCar(company, model), Bus(company, model), Car(company, model) {
        std::cout << "Minivan's constructor is over." << std::endl;}
};

//-----------------------
// Task 3
//-----------------------

class Fraction {

    int16_t m_numerator = 1;
    int16_t m_denominator = 1;

public:

    Fraction(int16_t numerator, int16_t denominator) {
        m_numerator = numerator;
        if (denominator != 0) m_denominator = denominator;
        else std::cout << "Denominator must not be 0!";
    }

    void printFraction () {std::cout << m_numerator << "/" << m_denominator << std::endl;}

    friend void setCommonDenominator(Fraction& fr1, Fraction& fr2);

    friend Fraction operator+(Fraction& fr1, Fraction& fr2);
    friend Fraction operator-(Fraction& fr1, Fraction& fr2);
    friend Fraction operator*(Fraction& fr1, Fraction& fr2);
    friend Fraction operator/(Fraction& fr1, Fraction& fr2);

    friend Fraction operator-(Fraction& fr);

    friend bool operator==(Fraction& fr1, Fraction& fr2);
    friend bool operator!=(Fraction& fr1, Fraction& fr2);
    friend bool operator>(Fraction& fr1, Fraction& fr2);
    friend bool operator<(Fraction& fr1, Fraction& fr2);
    friend bool operator>=(Fraction& fr1, Fraction& fr2);
    friend bool operator<=(Fraction& fr1, Fraction& fr2);


};

void setCommonDenominator(Fraction& fr1, Fraction& fr2){
    if (fr1.m_denominator != fr2.m_denominator) {
        fr1.m_numerator *= fr2.m_denominator;
        fr2.m_numerator *= fr1.m_denominator;
        fr1.m_denominator *= fr2.m_denominator;
        fr2.m_denominator = fr1.m_denominator;
    }
}

Fraction operator+(Fraction& fr1, Fraction& fr2){
    setCommonDenominator(fr1,fr2);
    return Fraction(fr1.m_numerator + fr2.m_numerator, fr1.m_denominator);
}

Fraction operator-(Fraction& fr1, Fraction& fr2){
    setCommonDenominator(fr1, fr2);
    return Fraction(fr1.m_numerator - fr2.m_numerator, fr1.m_denominator);
}

Fraction operator*(Fraction& fr1, Fraction& fr2){
    return Fraction(fr1.m_numerator * fr2.m_numerator, fr1.m_denominator * fr2.m_denominator);
}

Fraction operator/(Fraction& fr1, Fraction& fr2){
    return Fraction(fr1.m_numerator * fr2.m_denominator, fr1.m_denominator * fr2.m_numerator);
}

Fraction operator-(Fraction& fr){
    return Fraction(-fr.m_numerator, -fr.m_denominator);
}

bool operator==(Fraction& fr1, Fraction& fr2){
    if (fr1.m_numerator == fr2.m_numerator && fr1.m_denominator == fr2.m_denominator) {return true;}
    else {return false;}
}

bool operator!=(Fraction& fr1, Fraction& fr2){
    if (fr1 == fr2) {return false;}
    else {return true;}
}

bool operator>(Fraction& fr1, Fraction& fr2){
    setCommonDenominator(fr1, fr2);
    if (fr1.m_numerator > fr2.m_numerator) {return true;}
    else {return false;}
}

bool operator<(Fraction& fr1, Fraction& fr2){
    if (fr2 > fr1) {return true;}
    else {return false;}
}

bool operator>=(Fraction& fr1, Fraction& fr2){
    setCommonDenominator(fr1, fr2);
    if (fr1 > fr2 or fr1 == fr2) {return true;}
    else {return false;}
}

bool operator<=(Fraction& fr1, Fraction& fr2){
    if (fr2 >= fr1) {return true;}
    else {return false;}
}

//-----------------------
// Task 4
//-----------------------

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

    const int16_t GetValue(){
        std::cout << "Current card value is: ";
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

int main() {

    std::cout << "***Task 1***\n" << std::endl;
    Circle circle(5);
    Parallelogram parallelogram(7,2.5);
    Rectangle rectangle(4,8);
    Square square (3);
    Rhombus rhombus(5, 7.3);

    printFigureArea(circle);
    printFigureArea(parallelogram);
    printFigureArea(rectangle);
    printFigureArea(square);
    printFigureArea(rhombus);

    std::cout << "\n***Task 2***" << std::endl;
    Car car("Chevrolet", "Impala 1967");
    std::cout << std::endl;
    PassengerCar passengerCar("Dodge", "Viper");
    std::cout << std::endl;
    Bus bus("Regular Bus Firm", "School type");
    std::cout << std::endl;
    Minivan minivan("Dodge", "Grand Caravan");

    std::cout << "\n***Task 3***" << std::endl;
    Fraction fraction1(1,2);
    Fraction fraction2(2,3);

    Fraction fractionAddition = fraction1 + fraction2;
    std::cout << "The result of addition of fraction1 and fraction2 is: ";
    fractionAddition.printFraction();

    Fraction fractionSub = fraction1 - fraction2;
    std::cout << "The result of subtraction fraction1 and fraction2 is: ";
    fractionSub.printFraction();

    Fraction fractionMultiply = fraction1 * fraction2;
    std::cout << "The result of multiplying fraction1 and fraction2 is: ";
    fractionMultiply.printFraction();

    Fraction fractionDivision = fraction1 / fraction2;
    std::cout << "The result of division fraction1 and fraction2 is: ";
    fractionDivision.printFraction();

    Fraction fractionNegative = -fraction1;
    std::cout << "The negative view of fraction 1 is: ";
    fractionNegative.printFraction();

    std::cout << std::boolalpha;
    bool fractionsAreEqual = fraction1 == fraction2;
    std::cout << "It is " << fractionsAreEqual << " that fraction1 and fraction2 are equal" << std::endl;

    bool fractionsAreNotEqual = fraction1 != fraction2;
    std::cout << "It is " << fractionsAreNotEqual << " that fraction1 and fraction2 are not equal" << std::endl;

    bool fraction1_bigger_then_fraction2 = fraction1 > fraction2;
    std::cout << "It is " << fraction1_bigger_then_fraction2 << " that fraction1 bigger then fraction2" << std::endl;

    bool fraction2_bigger_then_fraction1 = fraction1 < fraction2;
    std::cout << "It is " << fraction2_bigger_then_fraction1 << " that fraction2 bigger then fraction1" << std::endl;

    bool fraction1_bigger_or_equal_fraction2 = fraction1 >= fraction2;
    std::cout << "It is " << fraction1_bigger_or_equal_fraction2 << " that fraction1 bigger or equal fraction2" << std::endl;

    bool fraction2_bigger_or_equal_fraction1 = fraction1 <= fraction2;
    std::cout << "It is " << fraction2_bigger_or_equal_fraction1 << " that fraction2 bigger or equal fraction1" << std::endl;

    std::cout << "\n***Task 4***" << std::endl;

    Card card;
    card.print();
    card.Flip();
    card.print();
    std::cout << card.GetValue();

    return 0;
}
