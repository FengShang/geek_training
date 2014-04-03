#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "../include/geek.h"

using namespace std;

namespace demo
{
namespace geek
{

const int ANSWER_SIZE(4);

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

void prepair_answer(std::vector<int>& output)
{
    int valid_numbers [9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < ANSWER_SIZE; i++){
        int j = rand()%9;
        int temp = valid_numbers[i];
        valid_numbers[i] = valid_numbers[j];
        valid_numbers[j] = temp;
    }
    output.resize(ANSWER_SIZE);
    std::copy(&valid_numbers[0], &valid_numbers[0] + ANSWER_SIZE, output.begin());
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

bool is_valid(const std::string& input, std::vector<int>& output)
{
    if (input.length() != 4)
    {
        cout << "Guess must be 4 digits." << endl;
        return false;
    }

    output.resize(ANSWER_SIZE);
    for (int i = 0; i < ANSWER_SIZE; i++)
    {
        int current_digit = input[i] - '0';
        if (current_digit > 9 || current_digit < 1)
        {
            cout << "Digit must be a 4-digit number within 1 to 9." << endl;
            return false;
        }
        output[i] = current_digit;
    }

    return true;
}

bool has_duplication(const std::vector<int> input)
{
    std::vector<int> map(10,0);
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (map[input[i]] == 1)
        {
            return true;
        }
        map[input[i]] = 1;
    }
    return false;
}

int bulls_count(const std::vector<int> guess_number,
        const std::vector<int> answer)
{
    int bulls(0);
    for (int i = 0; i < ANSWER_SIZE; i++)
    {
        if(guess_number[i] == answer[i])
            bulls++;
    }
    return bulls;
}

int cows_count(const std::vector<int> guess_number,
        const std::vector<int> answer)
{
    std::vector<int> map(10,0);
    for (size_t i = 0; i < answer.size(); ++i)
    {
        map[answer[i]] = 1;
    }

    int cows(0);
    for (size_t i = 0; i < guess_number.size(); i++)
    {
        if(map[guess_number[i]] == 1)
        {
            cows++;
        }
    }
    return cows;
}

void guess_answer(const std::vector<int>& answer)
{
    string guess;
    while (cout << "Your guess? ", getline(cin, guess))
    {
        std::vector<int> guess_number;
        if (!is_valid(guess, guess_number))
        {
            continue;
        }

        if (has_duplication(guess_number))
        {
            cout << "Digit must be a 4-digit number without duplication." << endl;
            continue;
        }

        cout << bulls_count(guess_number, answer) << " bulls, " 
            << cows_count(guess_number, answer) << " cows." << endl;

        if (bulls_count(guess_number, answer) == ANSWER_SIZE)
        {
            cout << "Congratulations! You have won!" << endl;
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
        string message;
        if (!want_to_play(message))
        {
            cout << message.c_str() << endl;
            return EXIT_SUCCESS;
        }

        vector<int> answer;
        prepair_answer(answer);

        guess_answer(answer);

        cout << "Another game? ";
    }
}
