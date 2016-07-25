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
long long fig(int k) {
    long long b = 0;int p = 2;
    while (k >= p) {
        b += k/p;
        p *= 2;
    }
    return b;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        long long ans = fig(n) - fig(n-k) - fig(k);
        if (ans == 0) printf("Odd\n");
        else printf("Even\n");
    }
	return 0;
}
