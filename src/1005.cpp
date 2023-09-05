#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include"1005.h"

using namespace std;

void a_1005()
{
	int turns;
	cin >> turns;
	for (int i = 1; i <= turns; i++)
	{
		double x, y;
		cin >> x >> y;
		double n = (M_PI*(pow(x, 2) + pow(y, 2)) / 100.0);

		cout << "Property " << i << ": This property will begin eroding in year " << floor(n) + 1 << "." << endl;
	}
	cout << "END OF OUTPUT.";
}