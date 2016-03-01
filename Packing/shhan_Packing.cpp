#include <stdio.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <Windows.h>

struct baggage {

		unsigned	dwVolume;
		unsigned	dwImportance;
		bool		bCheck;
};

class CPacking{

public:
		baggage		arrBaggageList[6];
		baggage		stItem;

		unsigned	iMaxWeight;
		unsigned	iTotalPackedWeight;
		int			iInitFlagIndex;

		CPacking();
		void Init();
		int	 initMaxImportance(baggage *pArr, int iArrSize);
		void PackingItem(baggage *pBaggageList, int iArrSize, int iCurrentMax, int iInitFlagIndex);
		int	 FindMaxImportance(baggage *pArr, int iArrSize, int iCurrentMax);
};

CPacking::CPacking(){

		iMaxWeight			= 15;
		iTotalPackedWeight	= 0;

		//////////////////////////////

		stItem.dwVolume		= 4;
		stItem.dwImportance = 7;
		stItem.bCheck		= false;
		arrBaggageList[0]	= stItem;

		stItem.dwVolume		= 2;
		stItem.dwImportance = 10;
		stItem.bCheck		= false;
		arrBaggageList[1]	= stItem;

		stItem.dwVolume		= 6;
		stItem.dwImportance = 6;
		stItem.bCheck		= false;
		arrBaggageList[2]	= stItem;

		stItem.dwVolume		= 4;
		stItem.dwImportance	= 7;
		stItem.bCheck		= false;
		arrBaggageList[3]	= stItem;

		stItem.dwVolume		= 2;
		stItem.dwImportance	= 5;
		stItem.bCheck		= false;
		arrBaggageList[4]	= stItem;

		stItem.dwVolume		= 10;
		stItem.dwImportance = 4;
		stItem.bCheck		= false;
		arrBaggageList[5]	= stItem;

		//////////////////////////////

		Init();
}

void CPacking::Init(){

//	int iCurrentMaxIndex = initMaxImportance(arrBaggageList, sizeof(arrBaggageList) / sizeof(baggage));
		
	int iMaxPackedVolume = 0;
	for (int i = 0; i < sizeof(arrBaggageList) / sizeof(baggage); i++){

		int iCurrentMaxIndex = initMaxImportance(arrBaggageList, sizeof(arrBaggageList) / sizeof(baggage));

	//	printf("[%d] volume: %d, importance: %d \n", i, arrBaggageList[i].dwVolume, arrBaggageList[i].dwImportance);
		PackingItem(arrBaggageList, sizeof(arrBaggageList) / sizeof(baggage), iCurrentMaxIndex, iInitFlagIndex);
		if (iMaxPackedVolume < iTotalPackedWeight)
			iMaxPackedVolume = iTotalPackedWeight;

		//flag ÃÊ±âÈ­
		for (int i = 0; i < sizeof(arrBaggageList) / sizeof(baggage); i++){
			arrBaggageList[i].bCheck = false;
		}
		arrBaggageList[iCurrentMaxIndex].bCheck = true;
	}

	printf("max volume : %d \n", iMaxPackedVolume);
}

int CPacking::initMaxImportance(baggage *pArr, int iArrSize){

	int iMaxIndex = 0;
	unsigned iMaxImportance = pArr->dwImportance;

	for (int i = 0; i < iArrSize; i++){
		if (!(pArr + i)->bCheck && iMaxImportance <= (pArr + i)->dwImportance){
			iMaxImportance = (pArr + i)->dwImportance;
			iMaxIndex = i;
		}
	}

//	(pArr + iMaxIndex)->bCheck = true;

	return iMaxIndex;
}

void CPacking::PackingItem(baggage *pBaggageList, int iArrSize, int iCurrentMaxIndex, int iInitFlagIndex) {

	int iMaxImportanceIndex = FindMaxImportance(pBaggageList, iArrSize, iCurrentMaxIndex);
	if (iMaxImportanceIndex == -1){
		return;
	}

	int iTempWeight = (iTotalPackedWeight + (pBaggageList + iMaxImportanceIndex)->dwVolume);
	if (iTempWeight <= iMaxWeight) {
		iTotalPackedWeight = iTotalPackedWeight + (pBaggageList + iMaxImportanceIndex)->dwVolume;
	}
	PackingItem(arrBaggageList, sizeof(arrBaggageList) / sizeof(baggage), iMaxImportanceIndex, iInitFlagIndex);
}

int CPacking::FindMaxImportance(baggage *pArr, int iArrSize, int iCurrentMaxIndex) {

	int iMaxIndex = 0;
	unsigned iMaxImportance = 0;

	bool bFlagCheck = true;					//still remain?
	for (int i = 0; i < iArrSize; i++){
		if ((pArr + i)->bCheck == false){	
			bFlagCheck = false;
			break;
		}
	}

	if (bFlagCheck == true)
		return -1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < iArrSize; i++){
		if (!(pArr + i)->bCheck && iMaxImportance <= (pArr + i)->dwImportance){
			iMaxImportance = (pArr + i)->dwImportance;
			iMaxIndex = i;
		}
	}
	(pArr + iMaxIndex)->bCheck = true;

	return iMaxIndex;
}

int main(void) {

	CPacking pack;
	return 0;
}
