#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class myPrint
{
public:
	void operator()(int a)
	{
        cout << a << " ";
	}
};
class My{
public:
    bool operator()(int t){
        return t >= 30;
    }
};

void test01()
{
	vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    cout<<"替换前"<<endl;
	for_each(v1.begin(), v1.end(), myPrint());
    cout << endl;
    cout<<"替换后"<<endl;
    //把大于等于30的数替换成11
    replace_if(v1.begin(),v1.end(),My(),11);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
}
int main() {
	test01();
	return 0;
}