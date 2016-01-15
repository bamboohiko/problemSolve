#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	int loc,len;
};
struct block{
	int l,r;
};
vector<point> sumh,sumv;
block h[50100],v[50100];
int rec[50100],ans[50100],maxh,maxv;
bool a[50100];
bool cmp(point a,point b)
{
	return a.len < b.len;
}
int main()
{
	int w,h,n;
	while (scanf("%d%d%d%*c",&w,&h,&n) != EOF)
	{
		char ch;int k,numh = 0,numw = 0;
		sumh.clear();sumh.push_back((point){0,0});
		sumv.clear();sumv.push.back((point){0,0});
		for (int i = 1;i <= n; i++)
		{
			scanf("%c %d%*c",&ch,&k);
			if (ch == 'H') 
			{
				sumh.push_back((point){k,i});
				a[i] = true;
			}
			else
			{
				sumv.push_back((point){k,i});
				a[i] = false;
			}
		}
		sumh.push_back((point){w,0});
		sumv.push.back((point){h,0});
		sort(sumh.begin(),sumh.end(),cmp);
		sort(sumv.begin(),sumv.end(),cmp);
	////
		for (int i = 0;i < sumh.size(); i++)
			cout << sumh[i].loc << " " << sumh[i].len << endl;
	////
		for (int i = 0;i < sumh.size(); i++)
			rec[sumh[i].loc] = i;
		for (int i = 0;i < sumv.size(); i++)
			rec[sumv[i].loc] = i;
	////build
		for (int i = n;i >= 1; i--)
		{
			
		}
	}
	return 0;
}
