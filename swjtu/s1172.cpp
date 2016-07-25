#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int rec[2100],use[1100];
bool cmp(int k1,int k2,int len)
{
	for (int i = 1;i <= len; i++)
		if (rec[k1+i] != rec[k2+i]) return false;
	return true;
}
int main()
{int n,m;
	while (cin >> n >> m && n && m)
		{int k = 0,ans = 0,d1,d2;
		memset(use,-1,sizeof(use));
		use[n] = 0;
		while (n)
			{n *= 10;
			rec[++k] = n/m;
			n %= m;
			if (use[n] == -1) use[n] = k;
			else break;		
			}
		cout << ".";
		int cou = 1;
		for (int i = 1;i <= k; i++)
			{cout << rec[i];
			if (++cou == 50) 
				{cout << endl;
				cou = 0;
				}
			}
		if (cou) cout << endl;
		if (n) printf("The last %d digits repeat forever.",k - use[n]);
		else printf("This expansion terminates.");
		cout << endl;
		}
	return 0;
}

