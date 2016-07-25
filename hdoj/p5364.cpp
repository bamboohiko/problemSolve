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
const int maxn = 1e4;
int a[10100];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        memset(a,0,sizeof(a));
        int x;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            a[x]++;
        }
        int ans = -1;
        for (int i = 0;i <= maxn; i++) {
            if (a[i] > n/2) {
                ans = i;
                break;

            }
        }
        printf("%d\n",ans);
    }
	return 0;
}

