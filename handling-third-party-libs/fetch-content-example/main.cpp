//
// Created by mirzachi on 7/30/21.
//

#include "date/date.h"
#include "outcome/outcome-basic.hpp"

#include <iostream>

using namespace date;
using namespace std::chrono;

namespace outcome = OUTCOME_V2_NAMESPACE;
template<typename T>
using Result =  outcome::basic_result<T, int, outcome::policy::terminate>;


int main(){
    constexpr auto x1 = 2021_y/August/22;

    std::cout << x1 << std::endl;

    Result<void> result{outcome::success()};
}

