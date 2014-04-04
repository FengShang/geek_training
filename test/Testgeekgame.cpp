
#include "gtest/gtest.h"
#include <vector>
#include "geek.h"


using namespace std;
using namespace demo::geek;
using std::vector;

class FakeGame : public BullCowGame
{
public:
    void set_answer(vector<int>& in)
    {
       _answer = in; 
    }
    void set_guess(vector<int>& in)
    {
       _guess = in; 
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

TEST_F(Geek_Fixture, should_pass_if_input_yes)
{
    demo::geek::answer_t answer;
    answer = check_answer("yes");
	EXPECT_EQ(demo::geek::YES, answer);
    answer = check_answer("Yes");
	EXPECT_EQ(demo::geek::YES, answer);
    answer = check_answer("y");
	EXPECT_EQ(demo::geek::YES, answer);
    answer = check_answer("Y");
	EXPECT_EQ(demo::geek::YES, answer);
}

TEST_F(Geek_Fixture, should_fail_if_input_no)
{
    demo::geek::answer_t answer;
    answer = check_answer("no");
	EXPECT_EQ(demo::geek::NO, answer);
    answer = check_answer("No");
	EXPECT_EQ(demo::geek::NO, answer);
    answer = check_answer("N");
	EXPECT_EQ(demo::geek::NO, answer);
    answer = check_answer("n");
	EXPECT_EQ(demo::geek::NO, answer);
}

TEST_F(Geek_Fixture, should_be_unknow_if_input_other)
{
    demo::geek::answer_t answer;
    answer = check_answer("other");
	EXPECT_EQ(demo::geek::UNKNOW, answer);
}


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


TEST_F(Geek_Fixture, should_calc_correct_pos)
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
    EXPECT_EQ(2, game.bulls_count());
}

TEST_F(Geek_Fixture, should_calc_correct_num)
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
    EXPECT_EQ(4, game.cows_count());
}

