#include <gtest/gtest.h>
#include <math.h>
#include "../A/index.h"
#include "../B/lib.h"

TEST(Index, tests1){
	ASSERT_LT(abs(PI - 3.14159265), 0.00000001);
}

TEST(My_abs, tests2){
	ASSERT_EQ(abs(0), my_abs(0));
	ASSERT_EQ(abs(1), my_abs(1));
	ASSERT_EQ(abs(-1), my_abs(-1));
}
