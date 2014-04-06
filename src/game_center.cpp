#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include "game_center.h"
#include "bull_cow_game.h"



namespace demo {
namespace geek {

using std::string;
using std::cin;
using std::cout;
using std::endl;

GameCenter::answer_t GameCenter::check_answer(const string& input)
{
    if (input == "Yes"
        || input == "yes"
        || input == "y"
        || input == "Y")
    {
        return YES;
    }
    else if (input == "No"
        || input == "no"
        || input == "n"
        || input == "N")
    {
        return NO;
    }

    return UNKNOW;
}


bool GameCenter::want_to_play()
{
    while (true)
    {
        string answer;
        if (!getline(cin, answer))
        {
            cout << "I can't get an answer. Exiting." << endl;
            return false;
        }

        if (check_answer(answer) == YES)
        {
            return true; 
        }
        else if (check_answer(answer) == NO)
        {
            cout << "Ok. Goodbye." << endl;
            return false;
        }
        else
        {
            cout << "Please answer yes or no: ";
        }
    }
}


void GameCenter::play_one_turn()
{
    BullCowGame game;

    string guess;
    while (cout << "Your guess? ", getline(cin, guess))
    {
        bool finish = game.game_over(guess);
        cout << game.get_status() << endl;

        if (finish)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

int GameCenter::run()
{
    cout << "Welcome to bulls and cows!\nDo you want to play? ";
    while (true)
    {
        if (!want_to_play())
        {
            return EXIT_SUCCESS;
        }

        play_one_turn();
        cout << "Another game? ";
    }
}

}
}



