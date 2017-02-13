/*******************************************************************************
 * @file		main.cpp
 * @brief		This file tests a library.
 * @author	llHoYall <hoya@ixys.net>
 * @version	v0.0
 *
 * @revision history
 * 	v0.0 - 2017.02.13 - Start
 ******************************************************************************/

/* Include Header ------------------------------------------------------------*/
#include "gtest/gtest.h"

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
