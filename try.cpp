#include <iostream>

using namespace std;

class my{
    public:
        my(){
            cout<<"创建成功"<<endl;
        }
    private:
};

int main(){
    my a[3];
    return 0;
}