#include"1010.h"
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

struct StampType
{
	int id;
	int demon;

	bool operator< (const StampType& b) const;
};

class CustomerCalculator
{
private:
	vector<StampType>* m_bestChoice;
	const vector<StampType>* m_stampTypes;
	int m_customer;
	bool m_isTie;

	void setupNewChoice(int rest, vector<StampType> choices);
	void setNewBest(vector<StampType>* choices);
	int getDifferentTypes(const vector<StampType>* choices);
	int getCountOfStamp(const vector<StampType>* choices);
	int getMaxDemon(const vector<StampType>* choices);
public:
	CustomerCalculator(int customer, const vector<StampType>* stampTypes);
	void calBestCombination();
	bool isTie();
	vector<StampType>* getBestCombination();
	int getBestDifferentTypes();

	~CustomerCalculator();
};

vector<StampType>* inputStampType();

bool StampType::operator< (const StampType& b) const
{
	return this->id < b.id;
}

CustomerCalculator::CustomerCalculator(int customer, const vector<StampType>* stampTypes)
{
	this->m_customer = customer;
	this->m_stampTypes = stampTypes;
	this->m_bestChoice = NULL;
	this->m_isTie = false;
}

CustomerCalculator::~CustomerCalculator()
{
	delete this->m_bestChoice;
}

void CustomerCalculator::calBestCombination()
{
	vector<StampType> choices;
	this->setupNewChoice(this->m_customer, choices);
}


void CustomerCalculator::setupNewChoice(int rest, vector<StampType> choices)
{
	for (vector<StampType>::const_iterator it1 = this->m_stampTypes->begin(); it1 != this->m_stampTypes->end(); it1++)
	{
		vector<StampType> c;
		c.push_back(*it1);
		if (rest - c[0].demon == 0)
		{
			this->setNewBest(&c);
			continue;
		}
		else if (rest - c[0].demon < 0)
		{
			continue;
		}
		for (vector<StampType>::const_iterator it2 = this->m_stampTypes->begin() + it1->id; it2 != this->m_stampTypes->end(); it2++)
		{
			c.push_back(*it2);
			if (rest - c[0].demon - c[1].demon == 0)
			{
				this->setNewBest(&c);
				continue;
			}
			else if (rest - c[0].demon - c[1].demon < 0)
			{
				continue;
			}
			for (vector<StampType>::const_iterator it3 = this->m_stampTypes->begin() + it2->id; it3 != this->m_stampTypes->end(); it3++)
			{
				c.push_back(*it3);
				if (rest - c[0].demon - c[1].demon - c[2].demon == 0)
				{
					this->setNewBest(&c);
					continue;
				}
				else if (rest - c[0].demon - c[1].demon - c[2].demon < 0)
				{
					continue;
				}
				for (vector<StampType>::const_iterator it4 = this->m_stampTypes->begin() + it3->id; it4 != this->m_stampTypes->end(); it4++)
				{
					if (c.size() == 3)
					{
						c.push_back(*it4);
					}
					else
					{
						c[3] = *it4;
					}
					if (rest - c[0].demon - c[1].demon - c[2].demon - c[3].demon == 0)
					{
						this->setNewBest(&c);
					}
				}
			}
		}
	}
}

void CustomerCalculator::setNewBest(vector<StampType>* choices)
{
	if (this->m_bestChoice == NULL)
	{
		this->m_bestChoice = new vector<StampType>(*choices);
		return;
	}

	int diffTypesComp = this->getDifferentTypes(this->m_bestChoice) - this->getDifferentTypes(choices);
	if (diffTypesComp < 0)
	{
		delete	this->m_bestChoice;
		this->m_bestChoice = new vector<StampType>(*choices);
		this->m_isTie = false;
		return;
	}
	if (diffTypesComp > 0)
	{
		return;
	}

	int countOfStampComp = this->getCountOfStamp(this->m_bestChoice) - this->getCountOfStamp(choices);
	if (countOfStampComp > 0)
	{
		delete	this->m_bestChoice;
		this->m_bestChoice = new vector<StampType>(*choices);
		this->m_isTie = false;
		return;
	}
	if (countOfStampComp < 0)
	{
		return;
	}

	int maxDemonComp = this->getMaxDemon(this->m_bestChoice) - this->getMaxDemon(choices);
	if (maxDemonComp < 0)
	{
		delete	this->m_bestChoice;
		this->m_bestChoice = new vector<StampType>(*choices);
		this->m_isTie = false;
		return;
	}
	if (maxDemonComp > 0)
	{
		return;
	}

	this->m_isTie = true;
}

int CustomerCalculator::getDifferentTypes(const vector<StampType>* choices)
{
	vector<int> typeIDs;
	for (vector<StampType>::const_iterator it = choices->begin(); it != choices->end(); it++)
	{
		if (find(typeIDs.begin(), typeIDs.end(), it->id) == typeIDs.end())
		{
			typeIDs.push_back(it->id);
		}
	}
	return typeIDs.size();
}

int CustomerCalculator::getCountOfStamp(const vector<StampType>* choices)
{
	return choices->size();
}

int CustomerCalculator::getMaxDemon(const vector<StampType>* choices)
{
	int result = (*choices)[0].demon;
	for (vector<StampType>::const_iterator it = choices->begin(); it != choices->end(); it++)
	{
		if (it->demon > result)
		{
			result = it->demon;
		}
	}
	return result;
}

int CustomerCalculator::getBestDifferentTypes()
{
	return this->getDifferentTypes(this->m_bestChoice);
}

bool CustomerCalculator::isTie()
{
	return this->m_isTie;
}

vector<StampType>* CustomerCalculator::getBestCombination()
{
	if (this->m_bestChoice == NULL)
	{
		return NULL;
	}
	else
	{
		sort(this->m_bestChoice->begin(), this->m_bestChoice->end());
		return this->m_bestChoice;
	}
}

void a_1010()
{
	while (true)
	{
		vector<StampType>* stampTypes = inputStampType();
		if (stampTypes->size() == 0)
		{
			break;
		}
		int customer;
		cin >> customer;
		while (customer != 0)
		{
			CustomerCalculator cal(customer, stampTypes);
			cal.calBestCombination();
			cout << customer << " ";
			if (cal.getBestCombination() == NULL)
			{
				cout << "---- none";
			}
			else
			{
				cout << "(" << cal.getBestDifferentTypes() << "):";
				if (cal.isTie())
				{
					cout << " tie";
				}
				else
				{
					vector<StampType>* best = cal.getBestCombination();
					for (vector<StampType>::iterator it = best->begin(); it != best->end(); it++)
					{
						cout << " " << it->demon;
					}
				}
			}
			cout << endl;
			cin >> customer;
		}
		delete stampTypes;
	}
}

vector<StampType>* inputStampType()
{
	vector<StampType>* result = new vector<StampType>();
	int id = 0;
	int demon;
	while ((cin >> demon) && (demon != 0))
	{
		StampType stampType;
		stampType.id = id;
		stampType.demon = demon;
		result->push_back(stampType);
		id++;
	}
	return result;
}