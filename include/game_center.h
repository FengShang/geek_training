#ifndef GEEK_H_
#define GEEK_H_
#include <string>
#include <vector>

namespace demo
{
namespace geek
{

class GameCenter
{
public:
    enum answer_t
    {
        YES,
        NO,
        UNKNOW,
    };

    int run();

protected:
    answer_t check_answer(const std::string& input);
    bool want_to_play();
    void play_one_turn();
        
};



}
}

#endif
