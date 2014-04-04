#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include "../include/geek.h"

using namespace std;

namespace demo
{
namespace geek
{

void BullCowGame::prepair_answer()
{
    int valid_numbers [9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < ANSWER_SIZE; i++){
        int j = rand()%9;
        int temp = valid_numbers[i];
        valid_numbers[i] = valid_numbers[j];
        valid_numbers[j] = temp;
    }
    _answer.resize(ANSWER_SIZE);
    std::copy(&valid_numbers[0], &valid_numbers[0] + ANSWER_SIZE, _answer.begin());
}


bool BullCowGame::is_valid(const std::string& input)
{
    if (input.length() != 4)
    {
        cout << "Guess must be 4 digits." << endl;
        return false;
    }

    _guess.resize(ANSWER_SIZE);
    for (int i = 0; i < ANSWER_SIZE; i++)
    {
        int current_digit = input[i] - '0';
        if (current_digit > 9 || current_digit < 1)
        {
            cout << "Digit must be a 4-digit number within 1 to 9." << endl;
            return false;
        }
        _guess[i] = current_digit;
    }

    return !has_duplication();
}

bool BullCowGame::has_duplication()
{
    std::vector<int> map(10,0);
    for (size_t i = 0; i < _guess.size(); ++i)
    {
        if (map[_guess[i]] == 1)
        {
            return true;
        }
        map[_guess[i]] = 1;
    }
    cout << "Digit must be a 4-digit number without duplication." << endl;
    return false;
}

int BullCowGame::bulls_count()
{
    int bulls(0);
    for (int i = 0; i < ANSWER_SIZE; i++)
    {
        if(_guess[i] == _answer[i])
            bulls++;
    }
    return bulls;
}

bool BullCowGame::guess_right()
{
    bool success = (bulls_count() == ANSWER_SIZE);
    if (success)
    {
        cout << "Congratulations! You have won!" << endl;
    }
    return bulls_count() == ANSWER_SIZE;
}

string BullCowGame::get_status()
{
    stringstream out;
    out << bulls_count() << " bulls, " << cows_count() << " cows.";
    return out.str();
}

int BullCowGame::cows_count()
{
    std::vector<int> map(10,0);
    for (size_t i = 0; i < _answer.size(); ++i)
    {
        map[_answer[i]] = 1;
    }

    int cows(0);
    for (size_t i = 0; i < _guess.size(); i++)
    {
        if(map[_guess[i]] == 1)
        {
            cows++;
        }
    }
    return cows;
}



answer_t check_answer(const string& input)
{
    if (input == "Yes"
        || input == "yes"
        || input == "y"
        || input == "Y")
    {
        return demo::geek::YES;
    }
    else if (input == "No"
        || input == "no"
        || input == "n"
        || input == "N")
    {
        return demo::geek::NO;
    }

    return demo::geek::UNKNOW;
}


bool want_to_play(std::string& message)
{
    while (true)
    {
        string answer;
        if (!getline(cin, answer))
        {
            message =  "I can't get an answer. Exiting.";
            return false;
        }

        if (check_answer(answer) == YES)
        {
            return true; 
        }
        else if (check_answer(answer) == NO)
        {
            message = "Ok. Goodbye.";
            return false;
        }
        else
        {
            cout << "Please answer yes or no: ";
        }
    }
}


void play_the_game(BullCowGame& game)
{
    game.prepair_answer();

    string guess;
    while (cout << "Your guess? ", getline(cin, guess))
    {
        if (!game.is_valid(guess))
        {
            continue;
        }

        cout << game.get_status() << endl;

        if (game.guess_right())
        {
            break;
        }
    }
}

}
}


int geek_game()
{
    using namespace demo::geek;
    cout << "Welcome to bulls and cows!\nDo you want to play? ";
    while (true)
    {
        string error_message;
        if (!want_to_play(error_message))
        {
            cout << error_message.c_str() << endl;
            return EXIT_SUCCESS;
        }

        BullCowGame game;
        play_the_game(game);
        cout << "Another game? ";
    }
}

