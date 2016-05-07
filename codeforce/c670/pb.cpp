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
int a[1000100];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1;i <= n; i++) {
        if (k > i) k -= i;
        else {
            printf("%d\n",a[k]);
            break;
        }
    }
	return 0;
}

