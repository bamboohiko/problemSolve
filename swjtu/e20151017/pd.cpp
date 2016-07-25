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
const int use[6][3] = {1,2,3,1,3,2,2,1,3,2,3,1,3,1,2,3,2,1};
struct point {
    int x,y;
};
point a[10];
int mataix(int k1,int k2,int k3,int f1,int f2,int f3) {
    int x1 = a[k1].x,y1 = a[k1].y;
    int x2 = a[k2].x,y2 = a[k2].y;
    int x3 = a[k3].x,y3 = a[k3].y;
    if (f1) swap(x1,y1);
    if (f2) swap(x2,y2);
    if (f3) swap(x3,y3);
    if (x1 == x2 && x2 == x3 && y1+y2+y3 == x1) return x1;
    if (x1 == x2 + x3 && y2 == y3 && y1+y2 == x1) return x1;
    return 0;
}
int main() {
    while (scanf("%d%d",&a[1].x,&a[1].y) != EOF) {
        scanf("%d%d%d%d",&a[2].x,&a[2].y,&a[3].x,&a[3].y);
        int ans = 0;
        for (int d = 0;d < 6;d++)
        for (int i = 0;i <= 1;i++)
            for (int j = 0;j <= 1;j++)
                for (int k = 0;k <= 1;k++){
                    ans = mataix(use[d][0],use[d][1],use[d][2],i,j,k);
                    if (ans) goto lambel;
                }
        lambel:
        if (ans) printf("%d\n",ans);
        else printf("No\n");
    }
	return 0;
}

