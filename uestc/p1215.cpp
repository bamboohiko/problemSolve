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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
int a[10],b[10];
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        scanf("%d%d%d%d",&a[0],&a[1],&a[3],&a[2]);
        scanf("%d%d%d%d",&b[0],&b[1],&b[3],&b[2]);
        bool ok = false;
        for (int i = 0;i < 4; i++) {
            bool can = true;
            for (int j = 0;j < 4; j++)
                if (a[j] != b[(i+j)%4]) {
                    can = false;
                    break;
                }
            if (can) {ok = true;break;}
        }
        printf("Case #%d: ",ca);
        if (ok) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
	return 0;
}
