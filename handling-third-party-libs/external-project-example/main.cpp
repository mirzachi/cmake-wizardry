//
// Created by mirzachi on 7/30/21.
//

#include "date/date.h"

#include <iostream>

using namespace date;
using namespace std::chrono;

int main(){
    constexpr auto x1 = 2021_y/August/22;

    std::cout << x1 << std::endl;
}

