#include<iostream>
#include<iomanip>
#include"1004.h"

using namespace std;

void a_1004()
{
	double sum = 0.0;
	for (int i = 0; i < 12; i++)
	{
		double n;
		cin >> n;
		sum += n;
	}
	cout.setf(ios::fixed);
	cout << "$" << setprecision(2) << (sum / 12);
}