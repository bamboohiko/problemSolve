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
typedef long long LL;
LL qpow(LL a,LL b,LL n) {
    LL t = 1;
    while (b) {
        if (b&1) t = t*a%n;
        a = a*a%n;
        b >>= 1;
    }
    return t;
}
bool check(LL x,LL n) {
    LL y = n-1;
    while (!(y&1)) y >>= 1;
    x = qpow(x,y,n);
    while (y < n-1 && x != 1 && x != n-1) x = (x*x)%n,y <<= 1;
    return x == n-1 || y&1 == 1;
}
bool ispri(int x) {
    if (x == 2 || x == 7 || x == 61) return true;
    if (x%2 == 0 || x == 1) return false;
    return check(2,x)&&check(7,x)&&check(61,x);
}
int main() {
    int l,r;
    while (scanf("%d%d",&l,&r) != EOF) {
        int cou = 0;
        for (int i = l;i <= r; i++)
            if (ispri(i)) cou++;
        printf("%d\n",cou);
    }
	return 0;
}
