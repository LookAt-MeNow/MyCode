/* -------------------------- */
/*
#include<iostream>
using namespace std;

class Time{
public:
    Time(int a,int b,int c):h(a),min(b),s(c){}
    void PrintTime(){
        cout<<this->h<<"点:"<<this->min<<"分:"<<this->s<<"秒 ";
    }
private:
    int h;
    int min;
    int s;
};

int main(){
    Time a(12,34,46);
    a.PrintTime();
    return 0;
}
*/
/* ---------------------------------------- */
/*  
#include<iostream>
using namespace std;

class Fraction{
friend Fraction operator+ (Fraction a ,Fraction b);
friend Fraction operator* (Fraction a ,Fraction b);
public:
    Fraction(){}
    Fraction(int n,int m){
        this->m = m;
        this->n = n;
    }
    void print(){
        cout <<"这个分数是"<<this->n<<"/"<<this->m<<endl;
    }
private:
    int m;
    int n;
};

Fraction operator+ (Fraction a,Fraction b){
    Fraction c;
    if(a.m==b.m){
        c.m = a.m;
        c.n = a.n+b.n;
    }else{
        int t;
        t = (a.m)*(b.m);
        a.n = a.n*b.m;
        b.n = b.n*a.m;
        c.m = t;
        c.n = a.n+b.n;
    }
    return c;
}

Fraction operator* (Fraction a,Fraction b){
    Fraction c;
    c.m = a.m*b.m;
    c.n = a.n*b.n;
    return c;
}
int main(){
    Fraction my1(1,3);
    Fraction my2(1,2);
    Fraction my3;
    Fraction my4;
    my3 = my1+my2;
    my3.print();
    my4 = my1*my2;
    my4.print();
    return 0;
}
*/

/* ---------------------------- */

#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    Student(){}
    Student(int num,string name,int age){
        this->num = num;
        this->name = name;
        this->age =age;
    }
    virtual void Info_(){
        
    }
protected:
    int num;
    string name;
    int age;
};

class Postgraduate:public Student{
public:
    Postgraduate(){}
    void Info_(){
        
    }
private:
    string teacher;
};

int main(){

    return 0;
}

/*B ------------------------ */


