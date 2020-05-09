//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::ElementsAre;

TEST(WeatherTest, test1) {
    WeatherMock weather1(200);
    WeatherMock weather3(404);
    
    ASSERT_NO_THROW(weather1.SetApiKey("api"));
    ASSERT_ANY_THROW(weather3.GetTemperature("c"));
    ASSERT_NO_THROW(weather1.GetDifferenceString("a", "b"));
    ASSERT_NO_THROW(weather1.GetDifferenceString("b", "a"));
}
