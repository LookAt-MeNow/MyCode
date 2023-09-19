#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
void myPrint(string a){
    cout <<a;   
}
void test(){
    vector<string>a;
    a.push_back("zhang");
    a.push_back("jin");
    a.push_back("wei");
    for_each(a.begin(),a.end(),myPrint);
    cout << endl;
    reverse(a.begin(),a.end());
    for_each(a.begin(),a.end(),myPrint);

}
int main(){
    test();
    return 0;
}