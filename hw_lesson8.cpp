#include <iostream>

//Task 1

double div(double number1, double number2) {
    if (number1 == 0 | number2 == 0) {throw "You can't use 0 here!\n";}
    return number1 / number2;
}

//Task 2

class Ex{

    int m_x = 0;

public:

    Ex(int x)
    : m_x(x) {}

    int get() {
        return m_x;
    }

};

class Bar {

    int m_y = 0;

public:

    void set(int a) {
        if (a + m_y > 100) {throw Ex(a * m_y);}
        m_y = a;
    }

};

//Task 3

class robot_exception {

    int m_x = 0;
    int m_y = 0;
    std::string m_direction = "Unknown";
    std::string m_error = "Unknown";

public:

    robot_exception (int x, int y, std::string& direction, std::string error) :
            m_x(x), m_y(y), m_direction(direction), m_error(error) {};

    void get_info() {
        std::cout << "X: " << m_x << std::endl;
        std::cout << "Y: " << m_y << std::endl;
        std::cout << "Direction: " << m_direction << std::endl;
        std::cout << "Error: " << m_error << std::endl;
    }

};

class Robot {

int m_current_x = 1;
int m_current_y = 1;

public:

    void Move(std::string direction)
    {
        if (direction == "left")
        {
            if (m_current_x == 1) {throw robot_exception(m_current_x, m_current_y, direction, "OffTheField");}
            m_current_x -= 1;
        }
        else if (direction == "right")
        {
            if (m_current_x == 10) {throw robot_exception(m_current_x, m_current_y, direction, "OffTheField");}
            m_current_x += 1;
        }
        else if (direction == "up")
        {
            if (m_current_y == 10) {throw robot_exception(m_current_x, m_current_y, direction, "OffTheField");}
            m_current_y += 1;
        }
        else if (direction == "down")
        {
            if (m_current_y == 1) {throw robot_exception(m_current_x, m_current_y, direction, "OffTheField");}
            m_current_y -= 1;
        }
        else {throw robot_exception(m_current_x, m_current_y, direction, "IllegalCommand");}

    }

};


int main() {

    std::cout << "\n***Task 1***\n\n";
    try
    {
        div(16.0, 0.0);
    }
    catch (const char* exception)
    {
        std::cout << exception;
    }

    std::cout << "\n***Task 2***\n\n";

    Bar bar;
    int n = 1;

    while (n != 0)
    {
        std::cout << "Enter some number or 0 to exit : ";
        std::cin >> n;
        try
        {
            bar.set(n);
        }
        catch (Ex& exception)
        {
            std::cout << "\nNUMBER " << exception.get() << " it's too big! OVERFLOW\n";
            n = 1;
        }
    }

    std::cout << "\n***Task 3***\n\n";

    Robot robot;
    try
    {
        robot.Move("some move");
    }
    catch(robot_exception& exception)
    {
        exception.get_info();
    }

    return 0;
}
