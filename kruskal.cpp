#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
	int x,y,w;
	edge(int x=0,int y=0,int w=0):x(x),y(y),w(w) {}
};
edge e[100010];
int f[1010];
vector<int> v;
vector<int> adj[1010];
bool cmp(edge i,edge j)
{
	return i.w<j.w;
}
int find(int x)
{
	vector<int> acr;
	while (f[x] != x) 
		{acr.push_back(x);
		x = f[x];
		}
	while (!acr.empty())
		{f[*acr.end()]=x;
		acr.pop_back();
		}
	return x;
}
int main()
{int n,m;
	while (cin >> n >> m)
		{int sum=1,len=0;
		for (int i = 1;i <= m; i++)
			cin >> e[i].x >> e[i].y >> e[i].w;
		sort(e,e+m,cmp);
		for (int i = 1;i <= m; i++)
			if (find(e[i].x) != find(e[i].y)) 
				{f[find(e[i].x)] = f[find(e[i].y)];
				v.push_back(i);
				sum++;
				len+=e[i].w; 
				}
		if (sum < n) cout << "No answer" << endl;
		else {
			cout << len << endl;
			for (int i = n-1;i >= 1; i++)
				{//adj[e[i].x].push_back(e[i].y);
				 //adj[e[i].y].push_back(e[i].x);
				 cout << e[i].x << " " << e[i].y << endl;
		 		}
			}
		}
	return 0;
}
