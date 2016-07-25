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
struct point {
    int x,h;
};
point a[100100];
bool cmp(point a,point b) {
    if (a.h == b.h) return a.x < b.x;
    return a.h < b.h;
}
int find(int k,int n) {
    int l = 1,r = n;
    while (l < r) {
        int mid = (l+r) >> 1;
        if (a[mid] <= k)
    }
    if (a[l].h == k) return a[l].x;
    else return -1;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        for (int i = 1;i <= n; i++) {
            scanf("%d",a[i].h);
            a[i].x = i;
        }
        sort(a+1,a+n+1,cmp);
        int k;
        for (int i = 1;i <= m; i++) {
            scanf("%d",&k);
            printf("%d\n",find(k,n));
        }
    }
	return 0;
}
