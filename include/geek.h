#ifndef GEEK_H_
#define GEEK_H_
#include <string>
#include <vector>

int geek_game();

namespace demo
{
namespace geek
{
    enum answer_t
    {
        YES,
        NO,
        UNKNOW,
    };

    answer_t check_answer(const std::string& input);
    void prepair_answer(std::vector<int>& output);
    bool is_valid(const std::string& input, std::vector<int>& output);
    bool has_duplication(const std::vector<int> input);
    int cows_count(const std::vector<int> guess_number,
        const std::vector<int> answer);
    int bulls_count(const std::vector<int> guess_number,
        const std::vector<int> answer);
}
}

#endif
