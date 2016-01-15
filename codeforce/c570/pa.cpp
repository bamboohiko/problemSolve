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
int cou[100];
int main() {
    int n,m,x;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= m; i++) {
        int p = 1,maxx = 0;
        for (int j = 1;j <= n; j++) {
            scanf("%d",&x);
            if (x > maxx) {
                maxx = x;
                p = j;
            }
        }
        cou[p]++;
    }
    int p = 1,maxx = 0;
    for (int i = 1;i <= n; i++) {
        if (cou[i] > maxx) {
            maxx = cou[i];
            p = i;
        }
    }
    printf("%d\n",p);
	return 0;
}
