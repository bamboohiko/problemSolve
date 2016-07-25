#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> dic;
int main()
{int n,ans=0;
string st;
	cin >> n;
	for (int i = 1;i <= n; i++)
		{getline(cin,st);
		if (dic.count(st)) dic[st]++;
		else dic[st] = 1;
		if (dic[st] == 3) ans++;
		}
	cout << ans << endl;
	return 0;
}
