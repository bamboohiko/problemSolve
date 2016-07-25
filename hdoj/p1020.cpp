#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
void claim(int cou,char sav)
{
	if (cou != 1) cout << cou;
	cout << sav; 
}
int main()
{int t;
	cin >> t;
	while (t--)
	{
		string st;
		cin >> st;
		int cou = 1;
		char sav = st[0];
		for (int i = 1;i < st.size(); i++)
			if (st[i] != sav) 
			{
				claim(cou,sav);
				cou = 1;
				sav = st[i];
			}
			else cou++;
		claim(cou,sav);
		cout << endl;
	}
	return 0;
}
