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
int a[1010],t[1010];
int n,h;
int fig(int ti) {
    int sum = 0;
    for (int i = 1;i <= n; i++) {
        sum += ti/t[i]*a[i];
        if (sum >= h) return true;
    }
    return false;
}
int main() {
    int ca;
    scanf("%d",&ca);
    while (ca--) {
        scanf("%d%d",&n,&h);
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&a[i],&t[i]);
        }
        int l = 1,r = h;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (fig(mid)) r = mid;
            else l = mid+1;
        }
        int loc = 0;
        for (int i = 1;i <= n; i++) {
            if (l%t[i] == 0 && a[i] > a[loc]) loc = i;
        }
        printf("%d %d\n",l,loc);
    }
	return 0;
}
