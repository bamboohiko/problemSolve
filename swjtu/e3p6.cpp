#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int len[100];
vector<int> v;
bool can(int k,int n)
{
	v.clear();
	v.push_back(0);
	for (int i = 0;i < n; i++)
		{int ok = 0;
		for (int j = 0;j < v.size(); j++)
			if (v[j] + len[i] <= k) 
				{ok = 1;
				v[j] += len[i];
				break;
				}
		if (!ok) v.push_back(len[i]);
		}
	for (int i = 0;i < v.size(); i++)
		if (v[i] != k) return false;
	return(true);
}
bool cmp(int a,int b)
{
	return a>=b;
}
int main()
{int n;
	while (cin >> n)
		{int sum = 0;
		for (int i = 0;i < n; i++)
			{cin >> len[i];
			sum += len[i];
			}
		sort(len,len+n,cmp);
		//for (int i = 0;i < n; i++) cout << len[i] << endl;
		for (int i = n;i > 0; i--)
			if (!(sum%i) && can(sum/i,n)) 
				{cout << sum/i << endl;
				break;
				} 	
		}
	return 0;
}
