#include <iostream>
import calculate;
using namespace std;

int main()
{
	auto start = clock();
	cout << calculate1(1, 1000) << endl;
	auto end = clock();
	cout << "第一种方法耗时：" << end - start << endl;

	start = clock();
	cout << calculate2(1, 1000) << endl;
	end = clock();
	cout << "第二种方法耗时：" << end - start << endl;

	start = clock();
	cout << calculate3(1, 1000) << endl;
	end = clock();
	cout << "第三种方法耗时：" << end - start << endl;

	start = clock();
	cout << calculate4(1, 1000) << endl;
	end = clock();
	cout << "第四种方法耗时：" << end - start << endl;
	return 0;
}