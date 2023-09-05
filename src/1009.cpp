#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include"1009.h"

using namespace std;

struct RLE
{
	int value;
	long length;
	long startIndex;

	RLE(){}

	RLE(int value, long length, long startIndex)
	{
		this->value = value;
		this->length = length;
		this->startIndex = startIndex;
	}
};

class RLEVector :public vector < RLE* >
{
public:
	RLEVector() :vector<RLE*>(){ }

	void releaseItem()
	{
		for (RLEVector::iterator it = this->begin(); it != this->end(); it++)
		{
			delete *it;
		}
	}
};

int getValueByIndex(const RLEVector* inputImage, long index);
int calOutputValue(const RLEVector* inputImage, long index, int width, long maxIndex);
RLEVector* initInputImage();
RLEVector* exchangeImage(const RLEVector* inputImage, int width);
RLEVector* calAroundOutputValue(const RLEVector* inputImage, long index, int width, long maxIndex);
bool compStartIndex(RLE* a, RLE* b);
RLEVector* aggChangePointResult(RLEVector* changePointResult, int maxIndex);

void a_1009()
{
	while (true)
	{
		int width;
		cin >> width;
		if (width == 0)
		{
			break;
		}
		RLEVector* inputImage = initInputImage();
		RLEVector* outputImage = exchangeImage(inputImage, width);
		cout << width << endl;
		for (RLEVector::iterator it = outputImage->begin(); it != outputImage->end(); it++)
		{
			cout << (*it)->value << " " << (*it)->length << endl;
		}
		cout << "0 0" << endl;

		inputImage->releaseItem();
		outputImage->releaseItem();

		delete inputImage;
		delete outputImage;
	}
	cout << "0" << endl;
}

RLEVector* initInputImage()
{
	RLE* input;
	RLEVector* rles = new RLEVector();
	input = new RLE();
	cin >> input->value >> input->length;
	while (input->length != 0 || input->length != 0)
	{
		if (rles->size() == 0)
		{
			input->startIndex = 0;
		}
		else
		{
			input->startIndex = (*(rles->end() - 1))->startIndex + (*(rles->end() - 1))->length;
		}
		rles->push_back(input);

		input = new RLE();
		cin >> input->value >> input->length;
	}
	return rles;
}

RLEVector* exchangeImage(const RLEVector* inputImage, int width)
{
	RLEVector* changePointResult = new RLEVector();
	int maxIndex = (*(inputImage->end() - 1))->startIndex + (*(inputImage->end() - 1))->length;
	for (RLEVector::const_iterator it = inputImage->begin(); it != inputImage->end(); it++)
	{
		RLEVector* aroundResult = calAroundOutputValue(inputImage, (*it)->startIndex, width, maxIndex);
		for (RLEVector::iterator it2 = aroundResult->begin(); it2 != aroundResult->end(); it2++)
		{
			changePointResult->push_back(*it2);
		}
		delete aroundResult;
	}
	RLEVector* result = aggChangePointResult(changePointResult, maxIndex);
	changePointResult->releaseItem();
	delete changePointResult;
	return result;
}

RLEVector* aggChangePointResult(RLEVector* changePointResult, int maxIndex)
{
	RLEVector* result = new RLEVector();
	sort(changePointResult->begin(), changePointResult->end(), compStartIndex);
	RLE* rle = new RLE((*changePointResult)[0]->value, 1, 0);
	int prevValue = (*changePointResult)[0]->value;
	for (RLEVector::iterator it = changePointResult->begin() + 1; it != changePointResult->end(); it++)
	{
		rle->length += (*it)->startIndex - (*(it - 1))->startIndex;
		if ((*it)->value != prevValue)
		{
			rle->length--;
			result->push_back(rle);
			rle = new RLE((*it)->value, 1, 0);
			prevValue = (*it)->value;
		}
	}

	rle->length += maxIndex - (*changePointResult)[changePointResult->size() - 1]->startIndex - 1;

	result->push_back(rle);

	return result;
}

RLEVector* calAroundOutputValue(const RLEVector* inputImage, long index, int width, long maxIndex)
{
	RLEVector* result = new RLEVector();
	if (index - width - 1 >= 0)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index - width - 1, width, maxIndex), 0, index - width - 1));
	}
	if (index + width - 1 < maxIndex)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index + width - 1, width, maxIndex), 0, index + width - 1));
	}
	if (index - 1 >= 0)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index - 1, width, maxIndex), 0, index - 1));
	}

	if (index - width + 1 >= 0)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index - width + 1, width, maxIndex), 0, index - width + 1));
	}
	if (index + width + 1 < maxIndex)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index + width + 1, width, maxIndex), 0, index + width + 1));
	}
	if (index + 1 < maxIndex)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index + 1, width, maxIndex), 0, index + 1));
	}

	if (index - width >= 0)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index - width, width, maxIndex), 0, index - width));
	}

	if (index + width < maxIndex)
	{
		result->push_back(new RLE(calOutputValue(inputImage, index + width, width, maxIndex), 0, index + width));
	}

	result->push_back(new RLE(calOutputValue(inputImage, index, width, maxIndex), 0, index));

	return result;
}

int calOutputValue(const RLEVector* inputImage, long index, int width, long maxIndex)
{
	vector<int> aroundValue;
	if (index%width > 0)
	{
		if (index - width - 1 >= 0)
		{
			aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index - width - 1)));
		}
		if (index + width - 1 < maxIndex)
		{
			aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index + width - 1)));
		}
		if (index - 1 >= 0)
		{
			aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index - 1)));
		}
	}

	if (index%width < width - 1)
	{
		if (index - width + 1 >= 0)
		{
			aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index - width + 1)));
		}
		if (index + width + 1 < maxIndex)
		{
			aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index + width + 1)));
		}
		if (index + 1 < maxIndex)
		{
			aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index + 1)));
		}
	}

	if (index - width >= 0)
	{
		aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index - width)));
	}

	if (index + width < maxIndex)
	{
		aroundValue.push_back(abs(getValueByIndex(inputImage, index) - getValueByIndex(inputImage, index + width)));
	}

	return *max_element(aroundValue.begin(), aroundValue.end());
}

int getValueByIndex(const RLEVector* inputImage, long index)
{
	RLEVector::const_iterator currentRLE = inputImage->begin();
	while (currentRLE != inputImage->end())
	{
		if (index < (*currentRLE)->startIndex || index >= (*currentRLE)->startIndex + (*currentRLE)->length)
		{
			currentRLE++;
		}
		else
		{
			return (*currentRLE)->value;
		}
	}
	return -1;
}

bool compStartIndex(RLE* a, RLE* b)
{
	return a->startIndex < b->startIndex;
}