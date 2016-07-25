#include<iostream>
#include<string>
#include<set>
#include<cctype>
#include<sstream>
using namespace std;
set<string> dic;
int main()
{string s1,s2;
	while (getline(cin,s1)) 
		{for (int i = 0;i < s1.length(); i++)
			if (isalpha(s1[i])) tolower(s1[i]);
			else s1[i]=' ';
		stringstream ss(s1);
		while (ss >> s2) dic.insert(s2);
		}
	for (set<string>::iterator i = dic.begin();i != dic.end(); i++)
		cout << *i << endl;
	return 0;
}
