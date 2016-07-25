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
int exgcd(int a,int b,int& x,int& y) {
    if (a == 0 && b == 0) return -1;
    if (b == 0) {x = 1;y = 0;return a;}
    int d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
int inv(int a,int n) {
    int x,y;
    int d = exgcd(a,n,x,y);
    if (d == 1) return (x%n+n)%n;
    else
     return -
        1;
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        if (m < n/2) m = n-m;
        int ans = 1,cou = 0;
        for (int i = n; i > m; i--) {
            int k = i;
            while (k%2 == 0) {cou++;k >>= 1;}
            while (k%5 == 0) {cou--;k /= 5;}
            ans = ans*k%10;
        }
        for (int i = n-m; i > 1; i--) {
            int k = i;
            while (k%2 == 0) {cou--;k >>= 1;}
            while (k%5 == 0) {cou++;k /= 5;}
            ans = ans*inv(k,10)%10;
        }
        for (int i = 1;i <= cou; i++) ans = ans*2%10;
        printf("%d\n",ans);
    }
	return 0;
}
