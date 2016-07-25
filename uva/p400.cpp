#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void print(string& s,int len)
{
	cout << s;
	for (int i = s.length();i <= len; i++) cout << " ";
}
int main()
{freopen("test.in","r",stdin);
 freopen("test.out","w",stdout);
int n,t;
 string s;
	while (cin >> n)
		{vector<string> w;
		 int m = 0;
		for (int i = 1;i <= n; i++)
			{cin >> s;
			m=max(m,(int)s.length());
			w.push_back(s);
			}
		sort(w.begin(),w.end());
		for (int i = 1;i <= 60; i++) cout << "-";cout << endl;
		int c = (60-m)/(m+2)+1;
		int r = (n-1)/c+1; 
		for (int i = 0;i < r; i++)
			{for (int j = 0;j < c; j++)
				if ( (t = j*r+i) <= n) print(w[t],(j == c-1)?(m+2):m);
			cout << endl;
			}		
		}
	return 0;
}
