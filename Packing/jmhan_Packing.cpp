#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct ST_PACKING
{
	std::string strPackName;
	unsigned uVolume;
	unsigned uUgency;

	ST_PACKING() : strPackName(""), uVolume(0), uUgency(0) {}

	ST_PACKING& operator=(ST_PACKING& stPacking) {
		this->strPackName = stPacking.strPackName;
		this->uUgency = stPacking.uUgency;
		this->uVolume = stPacking.uVolume;
		return *this;
	}
};

#define MAX_VALUE 256
int cacheData[MAX_VALUE][MAX_VALUE] = { 0 };

typedef std::vector<ST_PACKING> vecPacking;

class CPacking
{
	unsigned m_uMaxVolume;
	std::vector<unsigned> m_vecList;

	int computeValuePacking();
	void sortPackingByAscendingOrder(vecPacking &vecPackingInput);
	void computeMaximunValue(vecPacking &vecSortedPacking, unsigned uVecIndex, unsigned uCacheColIndex, unsigned uWeight);
	void copyPackingValueToOutput(vecPacking &vecSortedPacking, vecPacking &vecPackingOutput);
public:
	CPacking(unsigned uMaxVolume) : m_uMaxVolume(uMaxVolume) {}

	void getMixmunPacking(vecPacking &vecPackingInput, vecPacking &vecPackingOutput);
};

bool compareVec(ST_PACKING first, ST_PACKING second)
{
	return first.uUgency > second.uUgency;
}

void CPacking::sortPackingByAscendingOrder(vecPacking &vecPackingInput)
{
	// sorting..
	std::sort(vecPackingInput.begin(), vecPackingInput.end(), compareVec);
}

void CPacking::computeMaximunValue(vecPacking &vecSortedPacking, unsigned uVecIndex, unsigned uCacheColIndex, unsigned uWeight)
{
	if (vecSortedPacking.size() == uVecIndex)
		return;

	if (uWeight < m_uMaxVolume) {
		if (vecSortedPacking[uVecIndex].uVolume + uWeight <= m_uMaxVolume) {
			uWeight += vecSortedPacking[uVecIndex].uVolume;
			cacheData[uVecIndex + 1][uCacheColIndex] = cacheData[uVecIndex][uCacheColIndex] + vecSortedPacking[uVecIndex].uUgency;
			m_vecList.push_back(uVecIndex);
		}
		else {
			cacheData[uVecIndex + 1][uCacheColIndex] = cacheData[uVecIndex][uCacheColIndex];
		}
		computeMaximunValue(vecSortedPacking, uVecIndex + 1, uCacheColIndex, uWeight);
	}
	else {
		cacheData[uVecIndex + 1][uCacheColIndex] = cacheData[uVecIndex][uCacheColIndex];
		computeMaximunValue(vecSortedPacking, uVecIndex + 1, uCacheColIndex, uWeight);
	}
}

void CPacking::copyPackingValueToOutput(vecPacking &vecSortedPacking, vecPacking &vecPackingOutput)
{
	for (unsigned i = 0; i < m_vecList.size(); i++) {
		unsigned uValue = m_vecList[i];

		ST_PACKING stPacking;
		stPacking.strPackName = vecSortedPacking[uValue].strPackName;
		stPacking.uUgency = vecSortedPacking[uValue].uUgency;
		stPacking.uVolume = vecSortedPacking[uValue].uVolume;
		vecPackingOutput.push_back(stPacking);
	}
}

void CPacking::getMixmunPacking(vecPacking &vecPackingInput, vecPacking &vecPackingOutput)
{
	sortPackingByAscendingOrder(vecPackingInput);

	unsigned uVecIndex = 0, uCacheColIndex = 0, uWeight = 0;
	computeMaximunValue(vecPackingInput, uVecIndex, uCacheColIndex, uWeight);
	copyPackingValueToOutput(vecPackingInput, vecPackingOutput);
}


int main()
{
	vecPacking vevecPackingInput;
	vecPacking vecPackingOutput;

	ST_PACKING stPacking;
	stPacking.strPackName = "laptop";
	stPacking.uVolume = 4;
	stPacking.uUgency = 7;
	
	vevecPackingInput.push_back(stPacking);

	stPacking.strPackName = "camera";
	stPacking.uVolume = 2;
	stPacking.uUgency = 10;
	vevecPackingInput.push_back(stPacking);

	stPacking.strPackName = "xbox";
	stPacking.uVolume = 6;
	stPacking.uUgency = 6;
	vevecPackingInput.push_back(stPacking);

	stPacking.strPackName = "grinder";
	stPacking.uVolume = 4;
	stPacking.uUgency = 7;
	vevecPackingInput.push_back(stPacking);

	stPacking.strPackName = "dumbell";
	stPacking.uVolume = 2;
	stPacking.uUgency = 5;
	vevecPackingInput.push_back(stPacking);

	stPacking.strPackName = "encyclopeida";
	stPacking.uVolume = 10;
	stPacking.uUgency = 4;
	vevecPackingInput.push_back(stPacking);


	CPacking Packing(10);
	Packing.getMixmunPacking(vevecPackingInput, vecPackingOutput);

	for (unsigned i = 0; i < vecPackingOutput.size(); i++) {
		printf("%s", vecPackingOutput[i].strPackName.c_str());
	}

	return 0;
}