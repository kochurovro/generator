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

bool cmp(const pair<string, int>& first,
	const pair<string, int>& second)
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
	int inputCH = 0;
	string word;
	vector<string> words;

	if (!fin.is_open())
	{
		cout << "File " << path_input <<"can't be opened!\n";
		return 0;
	}
	else
	{
		while ((inputCH = fin.get()) != EOF)
		{
			if (isalpha(unsigned char(inputCH)))
				word += char(inputCH);
			else if (!word.empty())
			{
				words.push_back(word);
				word.clear();
			}
		}
		if (!word.empty())
		{
			words.push_back(word);
			word.clear();
		}
	}
	fin.close();

	sort(words.begin(), words.end());
	map <string, int> numberOfWords;
	map<string, int>::iterator it;
	for (const auto w : words)
	{
		it = numberOfWords.find(w);
		if (it == numberOfWords.end())
			numberOfWords.insert(pair<string, int>(w, 1));
		else
			it->second++;
	}
	vector<pair<string, int>> vectorNumberOfWords(numberOfWords.begin(), numberOfWords.end());
	sort(vectorNumberOfWords.begin(), vectorNumberOfWords.end(), cmp);
	cout << "Name output file: ";
	cin >> name_file;
	path_input = name_file + ".txt";
	ofstream fout(path_input);
	for (const auto now : vectorNumberOfWords)
		fout << now.second << ' ' << now.first << endl;
	fout.close();
	return 0;
}