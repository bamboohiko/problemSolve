#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int rec[10][10];
int f[100];
int main()
{
	int a,b,n;
	while (cin >> a >> b >> n && a && b && n)
	{
		memset(rec,0,sizeof(rec));
		rec[1][1] = 2;
		f[1] = f[2] = 1;
		int sav = 0;
		for (int i = 3;i <= n; i++)
		{
			f[i] = (a*f[i-1] + b*f[i-2])%7;
			if (rec[f[i-1]][f[i]]) 
			{
				sav = i;
				break;
			}
			else
				rec[f[i-1]][f[i]] = i; 
		}
		if (sav)
		{
			int t = rec[f[sav-1]][f[sav]];
			//cout << sav << " " << t << endl;
			cout << f[t + (n -sav)%(sav - t)] << endl;
		} 
		else 
			cout << f[n] << endl;
	}
	return 0;
}
