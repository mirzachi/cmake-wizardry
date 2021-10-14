#include <iostream>

#ifdef MY_FLAG
std::string msg{"MY_FLAG defined."};
#else
std::string msg{"MY_FLAG not defined."};
#endif


int main() {
    std::cout << msg << std::endl;
}
