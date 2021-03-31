#include "Game.h" //!-> include h
using namespace std;


//  онструктор этого класса принимает ссылку на вектор строк, представл€ющих
// имена игроков - людей.  онструктор создает объект класса Player дл€ каждого имени
Game::Game(const vector<string>& names)
{
    // создает вектор игроков из вектора с именами

    //“ут переделал на range-based
    for (std::string name : names) {
        m_players.push_back(Player(name));
    }

    // запускает генератор случайных чисел
    m_deck.populate();
    m_deck.shuffle();
}


Game::~Game()
{}

void Game::play()
{
    const int startCardCount = 2;
    // раздает каждому по две стартовые карты
    for (int i = 0; i < startCardCount; ++i)
    {     //“ут переделал на range-based
          for (Player& player : m_players)
          {
              m_deck.deal(player);
          }

        m_deck.deal(m_house);
    }

    // пр€чет первую карту дилера
    m_house.flipFirstCard();

    // открывает руки всех игроков
    //“ут переделал на range-based
    for (Player& player : m_players)
    {
        cout << player << endl;
    }

    cout << m_house << endl;

    // раздает игрокам дополнительные карты
    //“ут переделал на range-based
    for (Player& player : m_players)
    {
        m_deck.additionalCards(player);
    }

    // показывает первую карту дилера
    m_house.flipFirstCard();
    cout << endl << m_house;

    // раздает дилеру дополнительные карты
    m_deck.additionalCards(m_house);

    if (m_house.isBusted())
    {
        // все, кто осталс€ в игре, побеждают
        //“ут переделал на range-based
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
        // сравнивает суммы очков всех оставшихс€ игроков с суммой очков дилера
        //“ут переделал на range-based
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

    // очищает руки всех игроков
    //“ут переделал на range-based
    for (Player& player : m_players)
    {
        player.clear();
    }
    m_house.clear();
}
