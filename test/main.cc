
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#ifdef _DEBUG
#pragma comment(lib, "gtestd.lib")
#else
#pragma comment(lib, "gtest.lib")
#endif


int main(int argc, char* argv[])
{
    ::testing::GTEST_FLAG(output) = "xml:geek.xml";
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

