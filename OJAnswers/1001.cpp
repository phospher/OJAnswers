#include<iostream>
#include<iomanip>

using namespace std;

void a_1001()
{
	double s;
	int n;
	cout.setf(ios::showpoint | ios::fixed);
	while (cin >> s >> n)
	{
		double result = 1;
		for (int i = 0; i < n; i++)
		{
			result *= s;
		}
		cout << result << endl;
	}
}