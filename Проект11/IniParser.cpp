#include <iostream> 
#include <fstream> 
#include <cstdio>
#include <string> 
#include <algorithm>
#include <map>
#include <cstring>
#include<locale>  
#include "IniParser.h"
#include "FNFException.h"

using namespace std;



IniParser::IniParser(string file_name)
	{
		Initialize(file_name);
	}

IniParser::~IniParser() {}

void IniParser::Initialize(string file_name)
	{
		//file_for_read = ifstream(file_name);
	file_for_read.open(file_name);
	if (!file_for_read.is_open())
		throw FileNotFoundException("No such file");
	ReadFile(file_name);
	}

bool IniParser::IsHaveSection(string section_name)
	{
		auto search = sections.find(section_name);
		if (search != sections.end())
			return true;
		else
			return false;
	}

bool IniParser::IsHaveParam(string section_name, string param_name)
	{
		auto search = sections[section_name].find(param_name);
		if (search != sections[section_name].end())
			return true;
		else
			return false;
	}

void IniParser::ReadFile(string file_name)
	{
		char buf[100] = "";
		string this_section = "";
		string this_str = "";
		while (file_for_read.getline(buf, 100))
		{
			this_str = string(buf);
			//cout << this_str << endl;
			if (!(this_str.find(';') == string::npos))
			{
				size_t pos = this_str.find(";");
				this_str.erase(this_str.begin() + pos, this_str.end());
			}
			//cout << this_str << endl;
			if (!((this_str.find('[') == string::npos) && (this_str.find(']') == string::npos)))
			{
				this_str.erase(this_str.begin(), this_str.begin() + 1);
				this_str.erase(this_str.end() - 1, this_str.end());
				sections[this_str] = *new map<string, string>;
				this_section = this_str;
			}
			else {
				if (!(this_str.find('=') == string::npos))
				{

					size_t pos = this_str.find("=");
					string param = this_str.substr(pos + 1);
					param.erase(remove(param.begin(), param.end(), ' '),
						param.end());
					string name = this_str.substr(0, pos);
					name.erase(remove(name.begin(), name.end(), ' '),
						name.end());
					sections[this_section][name] = param;
				}
			}
			cout << this_str << endl;
		}
	}

int IniParser::GetValueInt(string section_name, string param_name)
	{
		if (IsHaveSection(section_name) && (IsHaveParam(section_name, param_name)))
			return stoi(sections[section_name][param_name]);
	}

double IniParser::GetValueDouble(string section_name, string param_name)
	{
		if (IsHaveSection(section_name) && (IsHaveParam(section_name, param_name)))
			return stod(sections[section_name][param_name]);
	}

string IniParser::GetValueString(string section_name, string param_name)
	{
	if (IsHaveSection(section_name) && (IsHaveParam(section_name, param_name)))
		return sections[section_name][param_name];
	else
		return "die";
	}
