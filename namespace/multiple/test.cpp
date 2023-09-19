#include "test.h"

namespace my{
    Point::Point(double a,double b):x(a),y(b){}
    
    Point::~Point(){}
    int add(int a,int b){   //写在命名空间的函数
        return a+b;
    }
    int add_two(int a,int b){
        return a+b;
    }
}