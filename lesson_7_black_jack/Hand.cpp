#include "Hand.h"
void Hand::add(Card* pCard)
{
    m_cards.push_back(pCard);
}

void Hand::clear()
{
    // �������� �� �������, ���������� ��� ������ � ����

    //��� ��������� �� range-based
    for(Card* card : m_cards) {
        delete card;
        card = nullptr;
    }

    m_cards.clear();
}


int Hand::getTotal() const
{
    // ���� ���� � ���� ���, ���������� �������� 0
    if (m_cards.empty())
        return 0;

    //���� ������ ����� ����� �������� 0, �� ��� ����� �������� �����:
    // ������� �������� 0
    if (m_cards[0]->getValue() == 0)
        return 0;

    // ������� ����� ����� ���� ����, ������ ��� ���� 1 ����
    int total = 0;

    //��� ��������� �� range-based
    for (Card* card : m_cards)
    {
        total += (card)->getValue();
    }

    // ����������, ������ �� ���� ���
    bool containsAce = false;

    //��� ��������� �� range-based
    for (Card* card : m_cards)
    {
        if ((card)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // ���� ���� ������ ��� � ����� �������� ���������, ��� ���� 11 �����
    if (containsAce && total <= 11)
    {
        // ��������� ������ 10 �����, ��������� �� ��� ��������
        // �� ������ ��� �� ������ ����
        total += 10;
    }

    return total;
}