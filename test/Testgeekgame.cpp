
#include "gtest/gtest.h"
#include <vector>
#include "geek.h"


using namespace std;
using std::vector;


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

TEST_F(Geek_Fixture, should_prepair_answer_vector)
{
    vector<int> answer;
    prepair_answer(answer);
	EXPECT_EQ(4, answer.size());
	EXPECT_NE(answer[0], answer[1]);
	EXPECT_NE(answer[0], answer[2]);
	EXPECT_NE(answer[0], answer[3]);
}

TEST_F(Geek_Fixture, 4_digits_should_be_valid)
{
    vector<int> answer;
    EXPECT_TRUE(is_valid("1234", answer));
	EXPECT_EQ(4, answer.size());
	EXPECT_EQ(1, answer[0]);
    EXPECT_EQ(2, answer[1]);
    EXPECT_EQ(3, answer[2]);
	EXPECT_EQ(4, answer[3]);
}

TEST_F(Geek_Fixture, not_4_letters_should_be_invalid)
{
    vector<int> answer;
    EXPECT_FALSE(is_valid("123", answer));
    EXPECT_FALSE(is_valid("12345", answer));
}

TEST_F(Geek_Fixture, not_all_digits_should_be_invalid)
{
    vector<int> answer;
    EXPECT_FALSE(is_valid("123a", answer));
}

TEST_F(Geek_Fixture, should_have_duplication)
{
    vector<int> answer(4);
    answer[0] = 1;
    answer[1] = 2;
    answer[2] = 3;
    answer[3] = 1;
    EXPECT_TRUE(has_duplication(answer));
}

TEST_F(Geek_Fixture, should_not_have_duplication)
{
    vector<int> answer(4);
    answer[0] = 1;
    answer[1] = 2;
    answer[2] = 3;
    answer[3] = 4;
    EXPECT_FALSE(has_duplication(answer));
}

TEST_F(Geek_Fixture, should_calc_correct_pos)
{
    vector<int> answer(4);
    answer[0] = 1;
    answer[1] = 2;
    answer[2] = 3;
    answer[3] = 4;
    vector<int> guess(4);
    guess[0] = 1;
    guess[1] = 2;
    guess[2] = 4;
    guess[3] = 3;
    EXPECT_EQ(2, bulls_count(guess, answer));
}

TEST_F(Geek_Fixture, should_calc_correct_num)
{
    vector<int> answer(4);
    answer[0] = 1;
    answer[1] = 2;
    answer[2] = 3;
    answer[3] = 4;
    vector<int> guess(4);
    guess[0] = 1;
    guess[1] = 2;
    guess[2] = 4;
    guess[3] = 3;
    EXPECT_EQ(4, cows_count(guess, answer));
}
