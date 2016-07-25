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
int n,m,a[100100];
bool tfill(int v) {
    int sum = 0,lef = m;
    for (int i = 1;i <= n; i++) {
        if (sum + a[i] <= v) sum += a[i];
        else {
            sum = a[i];
            if (--lef <= 0) return false;
        }
    }
    return true;
}
int main()
{

    scanf("%d%d",&n,&m);
    int l = 0,r = 0;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        l = max(l,a[i]);
        r += a[i];
    }
    while (l < r) {
        //cout << l << " " << r << endl;
        int mid = (l + r) >> 1;
        if (tfill(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d\n",l);
	return 0;
}
