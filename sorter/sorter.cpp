// sorter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>  
#include <vector>  
#include <iterator>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;


bool cmp(const std::pair<string, int>& first,
	const std::pair<string, int>& second)
{
	return first.second > second.second;
}

int main()
{
	setlocale(LC_ALL, "rus");
	string name_file;
	cout << "Name input file: ";
	cin >> name_file;
	string path_input = name_file + ".txt";
	ifstream fin(path_input);
	int ch = 0;
	string s;
	vector<string> v;

	if (!fin.is_open())
	{
		cout << "Файл " << path_input <<"не может быть открыт!\n";
		return 0;
	}
	else
	{
		while ((ch = fin.get()) != EOF)
		{
			if (isalpha(unsigned char(ch)))
				s += char(ch);
			else if (!s.empty())
			{
				v.push_back(s);
				s.clear();
			}
		}
		if (!s.empty())
		{
			v.push_back(s);
			s.clear();
		}
	}
	fin.close();

	sort(v.begin(), v.end());
	map <string, int> table;
	map<string, int>::iterator it;
	for (int i = 0; i < v.size(); i++)
	{
		it = table.find(v[i]);
		if (it == table.end())
			table.insert(pair<string, int>(v[i], 1));
		else
			it->second++;
	}
	vector<pair<string, int>> vec(table.begin(),table.end());
	sort(vec.begin(), vec.end(), cmp);
	cout << "Name output file: ";
	cin >> name_file;
	path_input = name_file + ".txt";
	ofstream fout(path_input);
	for (const auto p : vec)
		fout << p.second << ' ' << p.first << endl;
	fout.close();
	return 0;
}

