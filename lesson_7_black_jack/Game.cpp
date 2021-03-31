#include "Game.h" //!-> include h
using namespace std;


// ����������� ����� ������ ��������� ������ �� ������ �����, ��������������
// ����� ������� - �����. ����������� ������� ������ ������ Player ��� ������� �����
Game::Game(const vector<string>& names)
{
    // ������� ������ ������� �� ������� � �������

    //��� ��������� �� range-based
    for (std::string name : names) {
        m_players.push_back(Player(name));
    }

    // ��������� ��������� ��������� �����
    m_deck.populate();
    m_deck.shuffle();
}


Game::~Game()
{}

void Game::play()
{
    const int startCardCount = 2;
    // ������� ������� �� ��� ��������� �����
    for (int i = 0; i < startCardCount; ++i)
    {     //��� ��������� �� range-based
          for (Player& player : m_players)
          {
              m_deck.deal(player);
          }

        m_deck.deal(m_house);
    }

    // ������ ������ ����� ������
    m_house.flipFirstCard();

    // ��������� ���� ���� �������
    //��� ��������� �� range-based
    for (Player& player : m_players)
    {
        cout << player << endl;
    }

    cout << m_house << endl;

    // ������� ������� �������������� �����
    //��� ��������� �� range-based
    for (Player& player : m_players)
    {
        m_deck.additionalCards(player);
    }

    // ���������� ������ ����� ������
    m_house.flipFirstCard();
    cout << endl << m_house;

    // ������� ������ �������������� �����
    m_deck.additionalCards(m_house);

    if (m_house.isBusted())
    {
        // ���, ��� ������� � ����, ���������
        //��� ��������� �� range-based
        for (Player& player : m_players)
        {
            if (!(player.isBusted()))
            {
                player.win();
            }
        }
    }
    else
    {
        // ���������� ����� ����� ���� ���������� ������� � ������ ����� ������
        //��� ��������� �� range-based
        for (Player& player : m_players)
        {
            if (!(player.isBusted()))
            {
                if (player.getTotal() > m_house.getTotal())
                {
                    player.win();
                }
                else if(player.getTotal() < m_house.getTotal())
                {
                    player.lose();
                }
                else
                {
                    player.push();
                }
            }
        }
    }

    // ������� ���� ���� �������
    //��� ��������� �� range-based
    for (Player& player : m_players)
    {
        player.clear();
    }
    m_house.clear();
}
