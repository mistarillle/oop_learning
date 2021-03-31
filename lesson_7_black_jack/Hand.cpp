#include "Hand.h"
void Hand::add(Card* pCard)
{
    m_cards.push_back(pCard);
}

void Hand::clear()
{
    // проходит по вектору, освобождая всю память в куче

    //Тут переделал на range-based
    for(Card* card : m_cards) {
        delete card;
        card = nullptr;
    }

    m_cards.clear();
}


int Hand::getTotal() const
{
    // если карт в руке нет, возвращает значение 0
    if (m_cards.empty())
        return 0;

    //если первая карта имеет значение 0, то она лежит рубашкой вверх:
    // вернуть значение 0
    if (m_cards[0]->getValue() == 0)
        return 0;

    // находит сумму очков всех карт, каждый туз дает 1 очко
    int total = 0;

    //Тут переделал на range-based
    for (Card* card : m_cards)
    {
        total += (card)->getValue();
    }

    // определяет, держит ли рука туз
    bool containsAce = false;

    //Тут переделал на range-based
    for (Card* card : m_cards)
    {
        if ((card)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && total <= 11)
    {
        // добавляем только 10 очков, поскольку мы уже добавили
        // за каждый туз по одному очку
        total += 10;
    }

    return total;
}