#include <gtest/gtest.h>
#include "program.hpp"

TEST(program, init)
{
	FTR::Program prog(10, 6);

	EXPECT_EQ(prog.getFrequency(), 10);

	EXPECT_THROW(FTR::Program prog1(0, 6), std::exception);

	EXPECT_EQ(prog.getState(), FTR::State::pause);
}

TEST(program, fibonacci)
{
	EXPECT_TRUE(FTR::Program::IsFibonacci(0));
	EXPECT_TRUE(FTR::Program::IsFibonacci(1));
	EXPECT_TRUE(FTR::Program::IsFibonacci(2));
	EXPECT_TRUE(FTR::Program::IsFibonacci(3));
	EXPECT_TRUE(FTR::Program::IsFibonacci(5));
	EXPECT_TRUE(FTR::Program::IsFibonacci(8));
	EXPECT_TRUE(FTR::Program::IsFibonacci(13));
	EXPECT_TRUE(FTR::Program::IsFibonacci(21));

	EXPECT_FALSE(FTR::Program::IsFibonacci(4));
	EXPECT_FALSE(FTR::Program::IsFibonacci(6));
	EXPECT_FALSE(FTR::Program::IsFibonacci(14));
}



