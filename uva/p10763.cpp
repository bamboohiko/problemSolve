#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int BASE=500000;
int sum;
vector<int> v;
map<int,int> loc;
map<int,int> dic;
int id(int x)
{
	if (dic.count(x)) return dic[x];
	return (dic[x] = ++sum);
}
int main()
{int n,x,y,d;
	while ((cin >> n) && (n != 0)) 
		{sum=0;
		v.resize(0);
		loc.clear();
		dic.clear();
		for (int i = 1;i <= n; i++)
			{cin >> x >> y;
			d = 1;
			if (x > y) 
				{swap(x,y);
				d = -1;
				}
			int t=id(x)*BASE+id(y);
			if (!loc.count(t))
				{v.push_back(t);
				loc[t] = d;
				}
			else loc[t]+=d;
			}
		int c = 1;
		while (!v.empty())
			{if (loc[*v.end()])
				{c = 0;
				break;
				}
			v.pop_back();
			}
		if (c) cout << "Yes" << endl;
		else cout << "No" << endl;
		}
	return 0;
}
