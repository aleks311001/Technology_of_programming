//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"

cpr::Response WeatherMock::Get(const std::string& city) {
    std::string text = "{ \"list\": [ { \"main\": { \"temp\": ";
    text += std::to_string(std::hash<std::string>()(city) % 100);
    text += " } } ] }";
    
    cpr::Response response;// = {status_code, text, cpr::Header(), cpr::Url(), 0.0, cpr::Cookies()};
    response.status_code = status_code;
    response.text = text;
    return response;
}
