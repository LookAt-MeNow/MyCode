#include <iostream>
#include "test.h"
int main(){
    my::Point a(3.4,4.5);
    a.info_();
    {
        using my::add;
        std::cout << add(3,4) <<std::endl;
    }

    {
        using my::Point;
        Point i(8.9,5.6);
        i.info_();
    }

    {
        using namespace my;
        std::cout <<add_two(2,3)<<std::endl;
    }
    return 0;
}