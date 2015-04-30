#include<iostream>
#include<map>
#include<string>
#include"1008.h"

using namespace std;

int calNumberOfDaysWithHaab(int numberOfDay, string& month, int year);
map<int, string>& initTzolkinNameOfDay();
map<string, int>& initHaabMonth();

void a_1008()
{
	int n;
	cin >> n;
	cout << n << endl;
	map<int, string>& dayMapping = initTzolkinNameOfDay();
	for (int i = 0; i < n; i++)
	{
		int numberOfDay, year;
		string month;
		char point;

		cin >> numberOfDay >> point >> month >> year;
		int numberOfDays = calNumberOfDaysWithHaab(numberOfDay, month, year);
		int resultYear = numberOfDays / 260;
		int restOfDays = numberOfDays % 260;
		string& nameOfDay = dayMapping[restOfDays % 20];
		int periodNumber = restOfDays % 13 + 1;
		cout << periodNumber << " " << nameOfDay << " " << resultYear << endl;
	}
}

int calNumberOfDaysWithHaab(int numberOfDay, string& month, int year)
{
	map<string, int> monthMapping = initHaabMonth();
	return year * 365 + monthMapping[month] * 20 + numberOfDay;
}

map<string, int>& initHaabMonth()
{
	map<string, int>* result = new map < string, int > ;
	(*result)["pop"] = 0;
	(*result)["no"] = 1;
	(*result)["zip"] = 2;
	(*result)["zotz"] = 3;
	(*result)["tzec"] = 4;
	(*result)["xul"] = 5;
	(*result)["yoxkin"] = 6;
	(*result)["mol"] = 7;
	(*result)["chen"] = 8;
	(*result)["yax"] = 9;
	(*result)["zac"] = 10;
	(*result)["ceh"] = 11;
	(*result)["mac"] = 12;
	(*result)["kankin"] = 13;
	(*result)["muan"] = 14;
	(*result)["pax"] = 15;
	(*result)["koyab"] = 16;
	(*result)["cumhu"] = 17;
	(*result)["uayet"] = 18;
	return *result;
}

map<int, string>& initTzolkinNameOfDay()
{
	map<int, string>* result = new map < int, string > ;
	(*result)[0] = "imix";
	(*result)[1] = "ik";
	(*result)[2] = "akbal";
	(*result)[3] = "kan";
	(*result)[4] = "chicchan";
	(*result)[5] = "cimi";
	(*result)[6] = "manik";
	(*result)[7] = "lamat";
	(*result)[8] = "muluk";
	(*result)[9] = "ok";
	(*result)[10] = "chuen";
	(*result)[11] = "eb";
	(*result)[12] = "ben";
	(*result)[13] = "ix";
	(*result)[14] = "mem";
	(*result)[15] = "cib";
	(*result)[16] = "caban";
	(*result)[17] = "eznab";
	(*result)[18] = "canac";
	(*result)[19] = "ahau";
	return *result;
}