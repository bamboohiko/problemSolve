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
int a[100100];
int main() {
    int n,l,r,sum = 0;
    scanf("%d",&n);
    for (int i = 0;i < n; i++) {
        scanf("%d%d",&l,&r);
        a[i] = l-r;
        sum += l-r;
    }
    int maxval = abs(sum),maxloc = 0;
    for (int i = 0;i < n; i++) {
        a[i] = abs(sum - (a[i] << 1));
        if (a[i] > maxval) {maxval = a[i];maxloc = i+1;}
    }
    printf("%d\n",maxloc);
	return 0;
}
