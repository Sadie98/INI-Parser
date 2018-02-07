#include <iostream> 
#include <fstream> 
#include <cstdio>
#include <string> 
#include <algorithm>
#include <map>
#include <cstring>
#include <locale>  
#include "IniParser.h"

using namespace std;


int main()
{
	setlocale(LC_CTYPE, "Russian");
	string a;
	//getline(cin, a);
	a = "file.txt";
	string temp;
	temp = "Получить строковое значение параметра FileName из секции DEMODS";
	//getline(cin, temp);
	char ask[100];
	strcpy(ask, temp.c_str());
	//cout << ask << "!";
	char * leks = strtok(ask, " "); 
	int num_of_word = 0;
	string typ, sec, par;
	while (leks != NULL)                         
	{
		string word = string(leks);
		word.erase(remove(word.begin(), word.end(), ' '),
			word.end());
		if (num_of_word == 1)
			typ = word;
		if (num_of_word == 4)
			par = word;
		if (num_of_word == 7)
			sec = word;
		leks = strtok(NULL, " ");
		num_of_word++;
	}
	IniParser file(a);

	if (!typ.compare("вещественное")) {
		cout << file.GetValueDouble(sec, par) << endl;
	}
	else
		if (!typ.compare("строковое"))
			cout << file.GetValueString(sec, par) << endl;
		else
			if (!typ.compare("целое"))
				cout << file.GetValueInt(sec, par) << endl;
	system("pause");
	return 0;
}