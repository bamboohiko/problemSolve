#include<iostream>
#include<algorithm>
using namespace std;
struct ski{
	int f,t;
	ski(int f=0,int t=0):f(f),t(t) {}
};
bool cmp(ski i,ski j)
{
	if (i.t == j.t) return i.f > j.f;
	return i.t < j.t;
}
ski a[110];
int main()
{int n;
	while (cin >> n)
		{for (int i = 0;i < n; i++)
			cin >> a[i].f >> a[i].t;
		sort(a,a+n,cmp);
		int s = 0,t = 0,ans=0; 
		for (int i = 0;i < n; i++) 
			if (a[i].f >= t) 
				{ans++;
				t = a[i].t;
				}
		cout << ans << endl; 
		}
	return 0;
}
