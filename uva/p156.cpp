#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cctype>
using namespace std;
map<string,int> con;
vector<string> sav,pr;
string low(string& a)
{string b(a);
	for (int i = 0;i < a.length(); i++)
		b[i]=toupper(a[i]);
	sort(b.begin(),b.end());
	return b;
}
int main()
{string s1,s2;
	while ((cin >> s1) && (s1 != "#"))
		{sav.push_back(s1);
		s2=low(s1);
		if (!con.count(s2)) con[s2]=0;
		else con[s2]++;
		}
	for (int i = 0;i < sav.size(); i++)
		if (!con[low(sav[i])]) pr.push_back(sav[i]);
	sort(pr.begin(),pr.end());
	for (int i = 0;i <pr.size(); i++)
		cout << pr[i] << endl;
	return 0;
}
