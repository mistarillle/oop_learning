#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) :
    GenericPlayer(name)
{}

//Addition
bool Player::isHitting() const
{
    if (this->getTotal() == 21)
    {
        cout << m_name << ", you have 21! Good job!";
        return false;
    }

    cout << m_name << ", your score is " << this->getTotal() << ". Do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << m_name << " wins.\n";
}

void Player::lose() const
{
    cout << m_name << " loses.\n";
}

void Player::push() const
{
    cout << m_name << " pushes.\n";
}