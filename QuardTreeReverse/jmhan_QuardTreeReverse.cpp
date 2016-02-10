#include <iostream>
#include <string>

#define MAX_QUARD_SECTION 4
#define MID_QUARD_SECTION (MAX_QUARD_SECTION / 2)

class CQuardTreeReverse
{
public:
	void reverseQuardTree(std::string &refstrTree, std::string &refstrOutTree);
};

void CQuardTreeReverse::reverseQuardTree(std::string &refstrTree, std::string &refstrOutTree)
{
	unsigned dwSize = refstrTree.size();
	if (dwSize < 1) {
		return;
	}

	std::string strUpper, strLower, strTotal;
	for (unsigned i = 0, iSection = 1; i < dwSize; i++, iSection++) {
		if (refstrTree[i] == 'b' || refstrTree[i] == 'w') {
			if (iSection == MID_QUARD_SECTION || iSection == MID_QUARD_SECTION - 1) {
				strUpper += refstrTree[i];
				continue;
			}
			else {
				strLower += refstrTree[i];
			}
		}
		else if (refstrTree[i] == 'x') {
			std::string strInnerTree = refstrTree.substr(i + 1, dwSize - i);
			std::string strOutput;
			reverseQuardTree(strInnerTree, strOutput);
			if (iSection <= MID_QUARD_SECTION) {
				strUpper += "x" + strOutput;
			}
			else {
				strLower += "x" + strOutput;
			}
			i += strOutput.size();
		}

		if (iSection == MAX_QUARD_SECTION) {
			strTotal = strLower + strUpper;
			refstrOutTree = strTotal;
			return;
		}
	}

	strTotal = strLower + strUpper;
	refstrOutTree = strTotal;
}

int main()
{
	CQuardTreeReverse QuardTreeReverse;

	std::string strInput = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb";
	std::string strOutput;
	QuardTreeReverse.reverseQuardTree(strInput, strOutput);

	printf("%s\n", strOutput.c_str());

	return 0;
}