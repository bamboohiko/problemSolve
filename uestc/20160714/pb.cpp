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
int f(int k) {
    int p = 2;
    while (k >= p) {
        k -= k/p;
        p++;
    }
    return k;
}
int main() {
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",f(r)-f(l-1));
	return 0;
}
