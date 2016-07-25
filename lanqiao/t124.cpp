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
typedef long long LL;
int a[110][2];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n; i++) scanf("%d",&a[i][0]);
    int ans = 0,k = 0;
    while (true) {
        for (int i = 0;i < n; i++) a[i][1-k] = a[(i+1)%n][k]/2 + a[i][k]/2;
        k = 1-k;
        bool fin = true;
        for (int i = 1;i < n; i++)
            if (a[i][k] != a[0][k]) {fin = false;break;}
        if (fin) break;
        for (int i = 0;i < n; i++)
            if (a[i][k]&1) {a[i][k]++;ans++;}
    }
    printf("%d\n",ans);
	return 0;
}

