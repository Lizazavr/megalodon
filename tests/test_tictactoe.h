#ifndef TEST_TICTACTOE_H
#define TEST_TICTACTOE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "myfunc.hpp"

extern "C" {
#include "myfunc.hpp"
}

TEST(x_win, row)
{
    std::string output_text = "The first player won the game!!!";

    testing::internal::CaptureStdout();

    int select[]={1,4,3,7,2};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(x_win, column)
{
    std::string output_text = "The first player won the game!!!";

    testing::internal::CaptureStdout();

    int select[]={2,4,5,1,8};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(x_win, diagonal)
{
    std::string output_text = "The first player won the game!!!";

    testing::internal::CaptureStdout();

    int select[] = {3,2,5,6,7};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(o_win, row)
{
    std::string output_text = "The second player won the game!!!";

    testing::internal::CaptureStdout();

    int select[]= {4,1,9,3,7,8,5,2};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(o_win, column)
{
    std::string output_text = "The second player won the game!!!";

    testing::internal::CaptureStdout();

    int select[]={2,5,1,3,8,9,7,6};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(o_win, diagonal)
{
    std::string output_text = "The second player won the game!!!";

    testing::internal::CaptureStdout();

    int select[]={2,1,6,5,8,9};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(draw, draw)
{
    std::string output_text = "Draw!!!";

    testing::internal::CaptureStdout();

    int select[]={5,7,9,1,4,6,8,2,3};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(minus, out_pos)
{
    std::string output_text = "Impossible move";

    testing::internal::CaptureStdout();

    int select[]={10};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(minus, game_is_not_finished)
{
    std::string output_text = "It is impossible to identify the winner";

    testing::internal::CaptureStdout();

    int select[]={7,6,5};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif
