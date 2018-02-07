#pragma once
#include <iostream> 
#include <fstream> 
#include <cstdio>
#include <string> 
#include <algorithm>
#include <map>
#include <cstring>
#include<locale>  
using namespace std;


class IniParser {
private:

	ifstream file_for_read;

public:

	map<string, map<string, string>> sections;

	IniParser(string file_name);

	~IniParser();

	void Initialize(string file_name);

	bool IsHaveSection(string section_name);

	bool IsHaveParam(string section_name, string param_name);

	void ReadFile(string file_name);

	int GetValueInt(string section_name, string param_name);

	double GetValueDouble(string section_name, string param_name);

	string GetValueString(string section_name, string param_name);
};