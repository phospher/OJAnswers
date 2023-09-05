#include<iostream>
#include"1003.h"

using namespace std;

void a_1003()
{
	float c;
	while (cin >> c)
	{
		if (c == 0.0)
		{
			break;
		}
		int count = 1;
		float sum = 1.0 / 2.0;
		while (sum <= c)
		{
			count++;
			sum += 1.0 / (count + 1);
		}
		cout << count << " card(s)" << endl;
	}
}