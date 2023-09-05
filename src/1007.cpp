#include<iostream>
#include<map>
#include<vector>
#include<string>
#include"1007.h"

using namespace std;

void a_1007()
{
	int n, m;
	map<int, vector<string>> result;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string input;
		int count = 0;
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (input[j]>input[k])
				{
					count++;
				}
			}
		}
		result[count].insert(result[count].end(), input);
	}
	for (map<int, vector<string>>::iterator mit = result.begin(); mit != result.end(); mit++)
	{
		for (vector<string>::iterator vit = mit->second.begin(); vit != mit->second.end(); vit++)
		{
			cout << *vit << endl;;
		}
	}
}