#ifndef _BULL_COW_GAME_H_
#define _BULL_COW_GAME_H_
#include <string>
#include <vector>

namespace demo
{
namespace geek
{

class BullCowGame 
{
public:
    BullCowGame();

    bool game_over(const std::string& input);
    bool guess_right();
    std::string get_status();
    bool is_valid(const std::string& input);

protected:
    void prepair_answer();
    bool has_duplication();
    void build_lookup_table();
    const int ANSWER_SIZE;
    std::string _status_message;
    std::vector<int> _answer;
    std::vector<int> _guess;
    std::vector<int> _answer_lookup_table;
    int _bulls_count;
    int _cows_count;
};

}
}


#endif
