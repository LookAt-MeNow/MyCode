#ifndef _TEST_H
#define _TSTE_H
#include<iostream>

namespace my{     //在命名空间声明一个类

    int add(int a,int b);
    int add_two(int a,int b);
    class Point{
        public:
            Point()=default;
            Point(double a,double b);
            void info_() const {
                std::cout << "Point x="<< x <<" y="<< y << std::endl;
            }
            ~Point();
        private:
            double x{0.0};
            double y{0.0};
    };
}
#endif