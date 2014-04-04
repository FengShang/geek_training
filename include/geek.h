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

class BullCowGame 
{
public:
    BullCowGame():ANSWER_SIZE(4) {}
    void prepair_answer();
    bool is_valid(const std::string& input);
    int cows_count();
    int bulls_count();
    bool guess_right();
    std::string get_status();

protected:
    bool has_duplication();
    const int ANSWER_SIZE;
    std::vector<int> _answer;
    std::vector<int> _guess;
};

}
}

#endif
