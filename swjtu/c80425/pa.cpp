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
int a[50100];
bool fig(int k,int n,int m) {
    int loc = 0;
    for (int i = 1;i <= n; i++)
        if (a[i] - a[loc] >= k) loc = i;
        else {
            if (--m < 0) return false;
        }
    if (a[n+1] - a[loc] < k) return false;
    return true;
}
int main()
{
    int len,n,m;
    scanf("%d%d%d",&len,&n,&m);
    a[0] = 0;
    for (int i = 1;i <= n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    a[n+1] = len;
    int l = 1,r = 1e9;
    while (l < r) {
        //cout << l << " " << r << endl;
        int mid = l + ((r - l) >> 1) + 1;
        if (fig(mid,n,m)) l = mid;
        else r = mid-1;
    }
    printf("%d\n",l);
	return 0;
}
