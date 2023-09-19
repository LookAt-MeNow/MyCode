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
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());//要提前开辟空间
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}
int main() {
	test01();
	return 0;
}