
#include <iostream>
using namespace std;
#include <string>
#include <fstream>

bool match(const string &pattern , const string & strMatch)
{
	int nPos = 0;
	cout << "pattern : " << pattern << endl << "match : " << strMatch << endl;
	while(nPos < strMatch.size() && nPos < pattern.size() && ('?' == pattern[nPos] || pattern[nPos] == strMatch[nPos]))
	{
		++nPos;
	}
	if(nPos == pattern.size())
	{
		return nPos == strMatch.size(); /* 完全对应 */
	}
	//遇到* 跳过字符
	if('*' == pattern[nPos])
	{
		for(int skip = 0; nPos + skip <= strMatch.size(); ++skip)
		{
			//前边匹配完全  *后边模式匹配
			if(match(pattern.substr(nPos + 1) , strMatch.substr(nPos + skip)))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	string pattern , astrMatch[10];
//	ifstream data("data.txt");
	int nTotal , nCount;
//	if(data.is_open())
//	{
		cin >> nTotal;
		for(int i = 0; i < nTotal; ++i)
		{
			cin >> pattern;
			cin >> nCount;
			for(int j = 0; j < nCount; ++j)
			{
				cin >> astrMatch[j];
			}
			cout << "****** begin ******" << endl;
			for(j = 0; j < nCount; ++j)
			{
				if(match(pattern , astrMatch[j]))
				{
					cout << "-------------" << endl << "YES " << astrMatch[j] << endl << "-------------" << endl;
				}
			}
			cout << "****** end ******" << endl;
		}
//	}
	return 0;
}