// cpp11training.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest/gtest.h>

int main(int argc, char** args)
{
	::testing::InitGoogleTest(&argc, args);
	return RUN_ALL_TESTS();
}

