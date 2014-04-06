#include "gtest/gtest.h"
#include <vector>
#include "bull_cow_game.h"


using namespace std;
using namespace demo::geek;
using std::vector;

class FakeGame : public BullCowGame
{
public:
    void set_answer(vector<int>& in)
    {
        _answer = in; 
        build_lookup_table();
    }
    void set_guess(vector<int>& in)
    {
        _guess = in; 
    }

    int bulls_count()
    {
        return _bulls_count;
    }

    int cows_count()
    {
        return _cows_count;
    }

};


class Geek_Fixture : public testing::Test
{
public:
    Geek_Fixture()
    {
    }

protected:
    virtual void SetUp   ()
    {
       
    }
    virtual void TearDown()
    {
        
    }

    FakeGame game;

};


using namespace demo::geek;

TEST_F(Geek_Fixture, 4_digits_should_be_valid)
{
    EXPECT_TRUE(game.is_valid("1234"));
}

TEST_F(Geek_Fixture, not_4_letters_should_be_invalid)
{
    EXPECT_FALSE(game.is_valid("123"));
    EXPECT_FALSE(game.is_valid("12345"));
}

TEST_F(Geek_Fixture, not_all_digits_should_be_invalid)
{
    EXPECT_FALSE(game.is_valid("123a"));
}

TEST_F(Geek_Fixture, should_have_no_duplication)
{
    EXPECT_FALSE(game.is_valid("1231"));
}


TEST_F(Geek_Fixture, should_calc_bulls)
{
    vector<int> answer(4);
    answer[0] = 1;
    answer[1] = 2;
    answer[2] = 3;
    answer[3] = 4;
    game.set_answer(answer);
    vector<int> guess(4);
    guess[0] = 1;
    guess[1] = 2;
    guess[2] = 4;
    guess[3] = 3;
    game.set_guess(guess);

    EXPECT_FALSE(game.guess_right());
    EXPECT_EQ(2, game.bulls_count());
}

TEST_F(Geek_Fixture, should_calc_cows)
{
    vector<int> answer(4);
    answer[0] = 1;
    answer[1] = 2;
    answer[2] = 3;
    answer[3] = 4;
    game.set_answer(answer);
    vector<int> guess(4);
    guess[0] = 1;
    guess[1] = 2;
    guess[2] = 4;
    guess[3] = 3;
    game.set_guess(guess);

    EXPECT_FALSE(game.guess_right());
    EXPECT_EQ(2, game.cows_count());
}

