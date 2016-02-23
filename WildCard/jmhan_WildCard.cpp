#include <iostream>
#include <string>
#include <vector>

const char arraySPLetter[2] = { '?', '*' };

class CWildCard
{
	typedef std::vector<std::string> VecOrigin;
	VecOrigin	m_vecOrigin;
	int m_iOriginIndex;
	int m_iInputStrIndex;
	bool m_bSpecial;
	bool m_bSuccess;

	void ParseWildString(std::string& refWildString);
	void DivideAndCheckString(std::string& refstrValue);
public:
	CWildCard() : m_iOriginIndex(0), m_iInputStrIndex(0), m_bSpecial(false) {};
	~CWildCard() {}

	int CompareStrings(std::string& refWildString, std::vector<std::string>& refvecstrInput);
	bool getSuccess() { return m_bSuccess; }
};

void CWildCard::ParseWildString(std::string& refWildString)
{
	unsigned uFirstPos = 0;
	for (unsigned i = 0; i < refWildString.size(); i++) {
		for (unsigned j = 0; j < 2; j++) {
			if (refWildString[i] != arraySPLetter[j]) {
				continue;
			}
			std::string strTemp = refWildString.substr(uFirstPos, i - uFirstPos);
			m_vecOrigin.push_back(strTemp);

			std::string strSPLetter = j == 0 ? "?" : "*";
			m_vecOrigin.push_back(strSPLetter);

			uFirstPos = i + 1;
		}
	}

	if (uFirstPos < refWildString.size()) {
		std::string strTemp = refWildString.substr(uFirstPos, refWildString.size() - uFirstPos);
		m_vecOrigin.push_back(strTemp);
	}
}

void CWildCard::DivideAndCheckString(std::string& refstrValue)
{
	if (m_iInputStrIndex == refstrValue.size()) {
		m_bSuccess = true;
		return;
	}

	if (m_iOriginIndex >= m_vecOrigin.size()) {
		m_bSuccess = false;
		return ;
	}

	std::string strValue = m_vecOrigin[m_iOriginIndex];
	int iValueSize = strValue.size();

	if (iValueSize == 1 && !strValue.compare("*")) {
		m_bSpecial = true;
		m_iOriginIndex++;
		DivideAndCheckString(refstrValue);
	}
	else if (iValueSize == 1 && !strValue.compare("?")) {
		m_iOriginIndex++;
		m_iInputStrIndex++;
		DivideAndCheckString(refstrValue);
	}
	else {
		std::string strTemp = refstrValue.substr(m_iInputStrIndex, iValueSize);
		bool bResult = strValue == strTemp ? true : false;

		if (m_bSpecial) {
			if (bResult) {
				m_bSpecial = false;
				m_iOriginIndex++;
				m_iInputStrIndex += iValueSize;
			}
			else {
				m_iInputStrIndex++;
			}
		}
		else {
			if (bResult) {
				m_iOriginIndex++;
				m_iInputStrIndex += iValueSize;
			}
			else {
				refstrValue = "";
				m_bSuccess = false;
				return ;
			}
		}
		DivideAndCheckString(refstrValue);
	}
}

int CWildCard::CompareStrings(std::string& refWildString, std::vector<std::string>& refvecstrInput)
{
	ParseWildString(refWildString);
	
	for (unsigned i = 0; i < refvecstrInput.size(); i++) {
		DivideAndCheckString(refvecstrInput[i]);
		printf("%d\n", getSuccess());
		
	}

	return 0;
}


int main()
{

	CWildCard WildCard;

	std::string strWildString = "abc*de?fg?h*cd";
	std::string strInput = "abceedexfghhhhhcd";

	/*std::string strWildString = "he?p";
	std::string strInput = "helpp";*/
	std::vector<std::string> vecstrInput;
	vecstrInput.push_back(strInput);

	WildCard.CompareStrings(strWildString, vecstrInput);

	return 0;
}