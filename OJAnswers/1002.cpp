#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include"1002.h"

using namespace std;

void a_1002()
{
	int n;
	map<char, char>& init_mapping();

	map<char, char>& mapping = init_mapping();
	map<string, int> result_count;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input, result;
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '-')
			{
				continue;
			}
			else
			{
				map<char, char>::iterator it = mapping.find(input[i]);
				if (it == mapping.end())
				{
					result += input[i];
				}
				else
				{
					result += mapping[input[i]];
				}
			}

			if (result.length() == 3)
			{
				result += '-';
			}
		}
		if (result_count.find(result) == result_count.end())
		{
			result_count[result] = 1;
		}
		else
		{
			result_count[result]++;
		}
	}

	int outputCount = 0;
	for (map<string, int>::iterator it = result_count.begin(); it != result_count.end(); it++)
	{
		if (it->second > 1)
		{
			cout << it->first << ' ' << it->second << endl;
			outputCount++;
		}
	}
	if (outputCount == 0)
	{
		cout << "No duplicates." << endl;
	}

}

map<char, char>& init_mapping()
{
	map<char, char>* mapping = new map < char, char > ;
	mapping->insert(pair<char, char>('A', '2'));
	mapping->insert(pair<char, char>('B', '2'));
	mapping->insert(pair<char, char>('C', '2'));
	mapping->insert(pair<char, char>('D', '3'));
	mapping->insert(pair<char, char>('E', '3'));
	mapping->insert(pair<char, char>('F', '3'));
	mapping->insert(pair<char, char>('G', '4'));
	mapping->insert(pair<char, char>('H', '4'));
	mapping->insert(pair<char, char>('I', '4'));
	mapping->insert(pair<char, char>('J', '5'));
	mapping->insert(pair<char, char>('K', '5'));
	mapping->insert(pair<char, char>('L', '5'));
	mapping->insert(pair<char, char>('M', '6'));
	mapping->insert(pair<char, char>('N', '6'));
	mapping->insert(pair<char, char>('O', '6'));
	mapping->insert(pair<char, char>('P', '7'));
	mapping->insert(pair<char, char>('R', '7'));
	mapping->insert(pair<char, char>('S', '7'));
	mapping->insert(pair<char, char>('T', '8'));
	mapping->insert(pair<char, char>('U', '8'));
	mapping->insert(pair<char, char>('V', '8'));
	mapping->insert(pair<char, char>('W', '9'));
	mapping->insert(pair<char, char>('X', '9'));
	mapping->insert(pair<char, char>('Y', '9'));
	return *mapping;
}