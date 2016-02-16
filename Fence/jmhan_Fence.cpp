#include <iostream>
#include <string>
#include <vector>

typedef std::vector<unsigned> vecArray;

class CFence
{
	unsigned m_uArea;

	int FindValueFromArray(vecArray &refvecArray);

	void calculateMaxFence(vecArray &refvecArray);
	void DivideValueByCriteria(int iCriteria, vecArray &refvecOrigin, vecArray &refvecFirstArray, vecArray &refvecSecondArray);
	
public:
	CFence() : m_uArea(0) {}

	void calculateAreaByDivision(vecArray &refvecArray);
	unsigned getMaximunArea() {
		return m_uArea;
	}
};

void CFence::calculateAreaByDivision(vecArray &refvecArray)
{
	if (refvecArray.size() < 1) {
		return;
	}
	int iCriteria = FindValueFromArray(refvecArray);

	vecArray vecFirstArray, vecSecondArray;
	DivideValueByCriteria(iCriteria, refvecArray, vecFirstArray, vecSecondArray);

	if (vecFirstArray.size() > 0) {
		calculateMaxFence(vecFirstArray);
	}
	if (vecSecondArray.size() > 0) {
		calculateMaxFence(vecSecondArray);
	}

	calculateAreaByDivision(vecFirstArray);
	calculateAreaByDivision(vecSecondArray);
}

void CFence::calculateMaxFence(vecArray &refvecArray)
{
	int iCriteria = FindValueFromArray(refvecArray);
	
	unsigned uWidth = refvecArray.size();
	unsigned uHeight = refvecArray[iCriteria];
	unsigned uArea = uWidth * uHeight;
	
	if (m_uArea < uArea) {
		m_uArea = uArea;
	}
}

int CFence::FindValueFromArray(vecArray &refvecArray)
{
	unsigned iMin = 0, iTemp, iIndex = 0;
	bool bFirst = true;
	for (unsigned i = 0; i < refvecArray.size(); i++) {
		iTemp = refvecArray[i];

		if (bFirst) {
			iMin = iTemp;
			bFirst = false;
			continue;
		}

		if (iMin < iTemp) {
			continue;
		}

		iMin = iTemp;
		iIndex = i;
	}

	return iIndex;
}

void CFence::DivideValueByCriteria(int iCriteria, vecArray &refvecOrigin, vecArray &refvecFirstArray, vecArray &refvecSecondArray)
{
	if (refvecOrigin.size() == 1) {
		return;
	}

	unsigned i = 0;
	for (i = 0; i < iCriteria; i++) {
		refvecFirstArray.push_back(refvecOrigin[i]);
	}

	for (i = iCriteria + 1; i < refvecOrigin.size(); i++) {
		refvecSecondArray.push_back(refvecOrigin[i]);
	}

	if (refvecSecondArray.size() < 1) {
		refvecSecondArray.push_back(refvecOrigin[iCriteria]);
	}
	else {
		refvecFirstArray.push_back(refvecOrigin[iCriteria]);
	}

}

/////////////////////////////// Data Parse ////////////////////////////////////
void ParseStringToVector(std::string &refstrInput, vecArray &refvecArray)
{
	int iSize = refstrInput.size();

	int iFirstIndex = 0, iSecondIndex = 0;

#define BLANK " "
	while (iFirstIndex < iSize) {
		iSecondIndex = refstrInput.find_first_of(BLANK, iFirstIndex);
		if (iSecondIndex == std::string::npos) {
			std::string strTemp;
			strTemp = refstrInput.substr(iFirstIndex, iSize - iFirstIndex);
			int iTemp = ::atoi(strTemp.c_str());
			refvecArray.push_back(static_cast<unsigned>(iTemp));

			break;
		}

		std::string strTemp;
		strTemp = refstrInput.substr(iFirstIndex, iSecondIndex - iFirstIndex);
		int iTemp = ::atoi(strTemp.c_str());
		refvecArray.push_back(static_cast<unsigned>(iTemp));

		iFirstIndex = iSecondIndex + 1;
	}
}

int main()
{

	std::string strInput = "1 8 2 2";
	vecArray vecInputArray;
	ParseStringToVector(strInput, vecInputArray);

	CFence Fence;
	Fence.calculateAreaByDivision(vecInputArray);

	printf("%d\n", Fence.getMaximunArea());

	return 0;
}