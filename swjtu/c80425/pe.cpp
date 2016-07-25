#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
struct point {
    int s,f;
};
bool fig(int k,int n,int m) {
    for (int i = 1;i <= n; i++) {

    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF && (n || m)) {
        for (int i = 1;i <= n; i++) scanf("%d",a[i].s);
        for (int i = 1;i <= n; i++) scanf("%d",a[i].f);
        int l = 0,r = 100;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (fig(mid,n,m)) r = mid;
            else l = mid + 1;
        }
    }
	return 0;
}
