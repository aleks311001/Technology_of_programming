//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
private:
    long status_code;
public:
    WeatherMock(long status_code): status_code(status_code) {}
    cpr::Response Get(const std::string&) override;
};
