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
const int maxn = 1e5;
int a[100],f[maxn + 10];
int main() {
    a[0] = 0;a[1] = 1;
    f[0] = 1;
    for (int i = 2; ;i++) {
        a[i] = a[i-2] + a[i-1];
        if (a[i] > maxn) break;
        for (int j = maxn;j >= a[i]; j--)
            f[j] += f[j-a[i]];
    }
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
	return 0;
}
