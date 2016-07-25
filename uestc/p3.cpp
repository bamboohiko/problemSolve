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
int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		double x,y,t,s;
		scanf("%lf%lf%lf%lf",&x,&y,&t,&s);
		if (x <= y) printf("%.3lf",t + s/x);
		else {
			double len = y*t,ans = 0;
			while (len <= s) {
				len 
			}
		}
	}
	return 0;
}
