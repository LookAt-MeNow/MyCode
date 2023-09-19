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
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2;
    for (int i = 0; i < 10; i++) {
		v2.push_back(i+10);
	}
    cout <<"交换前"<<endl;
    cout <<"容器一: ";
	for_each(v1.begin(), v1.end(), myPrint());
    cout <<"容器二: ";
	for_each(v2.begin(), v2.end(), myPrint());
    cout <<"交换后"<<endl;
    swap(v1,v2);
    cout <<"容器一: ";
	for_each(v1.begin(), v1.end(), myPrint());
    cout <<"容器二: ";
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}
int main() {
	test01();
	return 0;
}