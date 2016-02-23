#include <stdio.h>
#include <string>
using namespace std;

class CWildCard{

	string wild_card_str;
	string given_str;

	int wc_char_index;
	int gv_char_index;

	bool equal;

	void compare_str();
	bool compare_char(char, char, int);

public:

	CWildCard();
	CWildCard(string, string);

};

CWildCard::CWildCard(){

	wc_char_index = 0;
	gv_char_index = 0;
}

CWildCard::CWildCard(string str1, string str2){

//	CWildCard();

	wild_card_str = str1;
	given_str = str2;

	wc_char_index = 0;
	gv_char_index = 0;

	equal = false;
	
	compare_str();
}

void CWildCard::compare_str(){

	int gap = given_str.length() - wild_card_str.length();
	bool result = compare_char(wild_card_str.at(wc_char_index), given_str.at(gv_char_index), gap);

	if (result) {

		printf("identical! \n");
	}
	else {

		printf("not identical! \n");
	}
}

bool CWildCard::compare_char(char wild_card_char, char given_char, int gap){

	////////////////////////////////////////////////////////////////////////////////////////////////
	if (gap > 0){
		
		if (wild_card_char == '*' || wild_card_char == '?' || wild_card_char == given_char){

			equal = true;
			wc_char_index++;
			gv_char_index++;
			if ((gv_char_index >= given_str.length()) || (wc_char_index >= wild_card_str.length())){ return equal; }
			compare_char(wild_card_str.at(wc_char_index), given_str.at(gv_char_index), gap);
		
		}else {
		
			equal = false;
			gv_char_index++;
			if ((gv_char_index >= given_str.length()) || (wc_char_index >= wild_card_str.length())){ return equal; }
			compare_char(wild_card_str.at(wc_char_index), given_str.at(gv_char_index), gap);
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////
	else { //gap <= 0

		if (wild_card_char == '*' || wild_card_char == '?' || wild_card_char == given_char){

			equal = true;
			wc_char_index++; gv_char_index++;
			compare_char(wild_card_str.at(wc_char_index), given_str.at(gv_char_index), gap);
		
		}else {

			equal = false;
			wc_char_index++; gv_char_index++;
			compare_char(wild_card_str.at(wc_char_index), given_str.at(gv_char_index), gap);
		}
	}
	
}

void main(){

	string wild_card1 = "he*";
	string wild_card2 = "he*p";
	string wild_card3 = "h*p";
	string wild_card4 = "*lp";
	string wild_card5 = "*la";
	string wild_card6 = "abc*de?fg?h*cd";
	string given_str1 = "help";
	string given_str2 = "heap";
	string given_str3 = "abceedexfghhhhhcd";

	CWildCard wc(wild_card4, given_str1);

}

//	wc.compare_char(&wild_card[0], &given_str1[0]);
//	wc.compare_char((char *)&wild_card, (char *)&given_str1);
//	wc.compare_char(wild_card, given_str1);

//	char arr[128] = "abc";
//	char *p = "abc";

/*
string test_str = given_str;
printf("test : %s \n", const_cast<char *>(given_str.c_str()));
printf("test : %s \n", const_cast<char *>(test_str.c_str()));
string test = const_cast<char *>(given_str.c_str());
printf("%c \n", test.at(0));

printf("[%s] ", given_str.c_str());
printf(" size : %d, ", given_str.size());
printf(" length : %d \n", given_str.length());
*/