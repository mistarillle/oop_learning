#include <iostream>
#include <cstdio>
#include <string>

class Person {

    std::string mName = "Unknown";
    int16_t mAge = 0;
    int16_t mWeight = 0;
    std::string mSex = "Unknown";

public:
    Person(std::string name, int16_t age, int16_t weight, std::string sex)
    : mName(name), mAge(age), mWeight(weight), mSex(sex) {}
    virtual ~Person() {};

    void changeName(std::string name) {mName = name;}
    void changeAge(int16_t age) {mAge = age;}
    void changeWeight(int16_t weight) {mWeight = weight;}
    void printPerson() const{
        std::cout << "Person's name: " <<  mName << std::endl;
        std::cout << "Person's age: " << mAge << std::endl;
        std::cout << "Person's weight: " << mWeight << std::endl;
        std::cout << "Person's sex: " << mSex << "\n" << "----------------\n";
    }

};

class Student : public Person {

    int16_t mStudyCourse = 1;
    inline static int16_t mCreatedStudentsCounter = 0;

public:
    Student(std::string name, int16_t age, int16_t weight, std::string sex)
    : Person(name, age, weight, sex)
    {mCreatedStudentsCounter += 1;
    std::cout << "\n" << name <<" successfully created as a student!\n"
    << "Students created so far: " << mCreatedStudentsCounter << "\n\n";}

    void changeStudyCourse(int16_t course) {mStudyCourse = course;}
    void incrementStudyCourse() {mStudyCourse += 1;}
    void printStudent() const{
        printPerson();
    }
};

class Fruit {

    std::string mName = "Unknown";
    std::string mColor = "Unknown";

public:
    Fruit(std::string name, std::string color)
    : mName(name), mColor(color) {}

    virtual ~Fruit() {}

    std::string getName() const {return mName;}
    std::string getColor() const {return mColor;}
};

class Apple : public Fruit {

public:
    Apple (std::string name, std::string color)
    : Fruit (name, "green") {}
    Apple (std::string color)
    : Fruit("Apple", color) {}
};

class Banana : public Fruit {

public:
    Banana(std::string color = "yellow")
    : Fruit("Banana", color) {}
};

class GrannySmith final : public Apple {

public:
    GrannySmith (std::string color = "green")
    : Apple ("Granny Smith apple", color) {}
};

void printFruitNameAndColor (const Fruit& fruit){
    std::cout << "My " << fruit.getName() << " is " << fruit.getColor() << ".\n";
}

int main() {

    std::cout << "\n***Task 1***\n";

    Student student1("John Doe", 23, 88, "male");
    student1.printStudent();
    Student student2("Some Dude", 20, 77, "battle chopper");
    student2.printStudent();

    std::cout << "\n***Task 2***\n\n";

    Apple a("red");
    Banana b;
    GrannySmith c;

    printFruitNameAndColor(a);
    printFruitNameAndColor(b);
    printFruitNameAndColor(c);

    return 0;
}
