#include <iostream>
#include <vector>

using namespace std;

class DeerInZooDivTwo
{
public:
	vector<int> getminmax(int N, int K);
};

vector<int> DeerInZooDivTwo::getminmax(int N, int K)
{
	vector<int> vecReturnValue;

	int minValue = N - K;
	if (minValue < 0) {
		minValue = 0;
	}
	vecReturnValue.push_back(minValue);

	int quotient = K / 2;
	int remainder = K % 2;
	int maxValue = N - (quotient + remainder);
	vecReturnValue.push_back(maxValue);

	return vecReturnValue;
}



