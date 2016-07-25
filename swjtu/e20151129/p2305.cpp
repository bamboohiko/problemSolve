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
int gcd(int a,int b) {
    while (b) {
        int t = a;a = b;b = t%b;
    }
    return a;
}
int main() {
    int n,m,k;
    while (scanf("%d%d%d",&n,&m,&k) != EOF) {
        //printf("%d %d\n",(n-1)<<1,k);
        if (n==1||gcd((n-1)<<1,k) == 1) puts("YES");
        else puts("NO");
    }
	return 0;
}
