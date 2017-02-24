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

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus"); 
	ifstream fin("in.txt"); 
	int ch = 0;
	string s;  
	vector<string> v; 

	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n"; 
	else
	{  
		while ((ch = fin.get()) != EOF)
		{
			if (isalpha(unsigned char(ch)))
			{
				s += char(ch);
			}
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
	copy(v.begin(), v.end(), std::ostream_iterator<string>(cout, "\n\n"));
	system("pause");
	return 0;
}

