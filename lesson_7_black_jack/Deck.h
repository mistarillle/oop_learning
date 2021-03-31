#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    // ������� ����������� ������ �� 52 ����
    void populate();

    // ������ �����
    void shuffle();

    // ������� ���� ����� � ����
    void deal(Hand& aHand);

    //���� �������������� ����� ������
    void additionalCards(GenericPlayer& aGenericPlayer);
};




