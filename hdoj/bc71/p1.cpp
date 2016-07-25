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
typedef unsigned long long LL;
LL gcd(LL a,LL b) {
    while (b) {
        LL t = a;a = b;b = t%b;
    }
    return a;
}
int main() {
    int t;LL n;
    scanf("%d",&t);
    while (t--) {
        cin >> n;
        if (n < 4) cout << n << endl;
        else {
            LL k1 = n*(n-1)/2,k2 = (n-2)*(n-3)/2,k3 = 6;
            LL d = gcd(k1,k3);
            if (d > 1) {k1 /= d;k3 /= d;}
            d = gcd(k2,k3);
            if (d > 1) {k2 /= d;k3 /= d;}
            cout << (k1*k2 + n) << endl;
        }
    }
	return 0;
}

