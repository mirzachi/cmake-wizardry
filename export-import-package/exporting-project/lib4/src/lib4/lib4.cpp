//
// Created by mirzachi on 7/30/21.
//
#include "lib4/lib4.h"
#include "lib1/sublib1/sublib1.h"
#include <iostream>

namespace lib4 {
    void lib4(){
        std::cout << "lib4::lib4()" << std::endl;
        std::cout << "Calling lib1..." << std::endl;
        lib1::sublib1::lib1_sublib1();
    }
}

