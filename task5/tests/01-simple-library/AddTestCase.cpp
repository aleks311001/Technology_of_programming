//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(test_add, test1) {
	ASSERT_EQ(Add(0, 0), 0);
    
    ASSERT_EQ(Add(0, 1), 1);
    ASSERT_EQ(Add(0, -1), -1);
    ASSERT_EQ(Add(1, 0), 1);
    ASSERT_EQ(Add(-1, 0), -1);
    
    ASSERT_EQ(Add(1, 1), 2);
    ASSERT_EQ(Add(1, -1), 0);
    ASSERT_EQ(Add(-1, 1), 0);
    ASSERT_EQ(Add(-1, -1), -2);
    
    ASSERT_EQ(Add(0, 10), 10);
    ASSERT_EQ(Add(0, -10), -10);
    ASSERT_EQ(Add(10, 0), 10);
    ASSERT_EQ(Add(-10, 0), -10);
    
    ASSERT_EQ(Add(-10, 10), 0);
    ASSERT_EQ(Add(10, -10), 0);
    ASSERT_EQ(Add(10, 10), 20);
    ASSERT_EQ(Add(-10, -10), -20);
}
