#include <iostream>
import calculate;
using namespace std;

int main()
{
	auto start = clock();
	cout << calculate1(1, 1000) << endl;
	auto end = clock();
	cout << "��һ�ַ�����ʱ��" << end - start << endl;

	start = clock();
	cout << calculate2(1, 1000) << endl;
	end = clock();
	cout << "�ڶ��ַ�����ʱ��" << end - start << endl;

	start = clock();
	cout << calculate3(1, 1000) << endl;
	end = clock();
	cout << "�����ַ�����ʱ��" << end - start << endl;

	start = clock();
	cout << calculate4(1, 1000) << endl;
	end = clock();
	cout << "�����ַ�����ʱ��" << end - start << endl;
	return 0;
}