//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"
#include <Functions.h>

struct A {
 bool a;
 A(bool b): a(b) {}
 ~A() {
     IsLeap(1);
 }
};

TEST(test_leap, test1) {
    try {
        bool b = IsLeap(-1);
        FAIL();
    } catch (std::invalid_argument& exc) {
        ASSERT_STREQ(exc.what(), "Year must be greater than 0");
    }
    
    try {
        bool b = IsLeap(1);
        ASSERT_FALSE(b);
    } catch (std::invalid_argument& exc) {
        ASSERT_EQ(strcmp(exc.what(), "Year must be greater than 0"), 0);
    }
    
    try {
        bool b = IsLeap(0);
        FAIL();
    } catch (...) {
        SUCCEED();
    }
    
    A a = IsLeap(1);
    ASSERT_THROW(IsLeap(-1), std::invalid_argument);
    ASSERT_NO_THROW(IsLeap(1));
    ASSERT_ANY_THROW(IsLeap(-1));
    
    ASSERT_FALSE(IsLeap(1));
    ASSERT_TRUE(IsLeap(400));
    ASSERT_FALSE(IsLeap(300));
    ASSERT_TRUE(IsLeap(8));
}
