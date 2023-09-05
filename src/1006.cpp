#include<iostream>
#include<algorithm>
#include"1006.h"

#define MAX 21252

using namespace std;

void a_1006()
{
	int a[3], d;
	int caseCount = 1;
	while (true)
	{
		cin >> a[0] >> a[1] >> a[2] >> d;
		if (a[0] == -1 && a[1] == -1 && a[2] == -1 && d == -1)
		{
			break;
		}

		int min = *min_element(a, a + 3);
		int i = min == 0 ? 1 : min;
		while ((i - a[0]) % 23 != 0 || (i - a[1]) % 28 != 0 || (i - a[2]) % 33 != 0)
		{
			i++;
		}

		int n = (i - d) % MAX;
		if (n <= 0)
		{
			n += MAX;
		}

		cout << "Case " << caseCount << ": the next triple peak occurs in " << n << " days." << endl;
		caseCount++;
	}
}