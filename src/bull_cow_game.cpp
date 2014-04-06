#include "bull_cow_game.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

namespace demo
{
namespace geek
{

BullCowGame::BullCowGame():
        ANSWER_SIZE(4),
        _answer_lookup_table(10,0),
        _bulls_count(0),
        _cows_count(0)
{
    prepair_answer();
}

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
    build_lookup_table();
}


void BullCowGame::build_lookup_table()
{
    for (size_t i = 0; i < _answer.size(); ++i)
    {
        _answer_lookup_table[_answer[i]] = 1;
    }
}

bool BullCowGame::game_over(const std::string& guess)
{
    if (!is_valid(guess))
    {
        return false;
    }

    return guess_right();
}

bool BullCowGame::is_valid(const std::string& input)
{
    if (input.length() != 4)
    {
        _status_message = "Guess must be 4 digits";
        return false;
    }

    _guess.resize(ANSWER_SIZE);
    for (int i = 0; i < ANSWER_SIZE; i++)
    {
        int current_digit = input[i] - '0';
        if (current_digit > 9 || current_digit < 1)
        {
            _status_message = "Digit must be a 4-digit number within 1 to 9.";
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
    _status_message = "Digit must be a 4-digit number without duplication.";
    return false;
}


bool BullCowGame::guess_right()
{
    _bulls_count = 0;
    _cows_count = 0;
    for (int i = 0; i < ANSWER_SIZE; i++)
    {
        if(_guess[i] == _answer[i])
        {
            _bulls_count++;
        }
        else if (_answer_lookup_table[_guess[i]] == 1)
        {
            _cows_count++;
        }
        else
        {
            // Do nothing.
        }
    }

    bool success = (_bulls_count == ANSWER_SIZE);
    
    if (success)
    {
        _status_message = "Congratulations! You have won!";
    }
    else
    {
        stringstream out;
        out << _bulls_count << "B" << _cows_count << "C";
        _status_message = out.str();
    }
    return success;
}

string BullCowGame::get_status()
{
    return _status_message;
}

}
}

