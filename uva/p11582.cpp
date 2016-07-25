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
int f[1010][3010],T[1010];
LL pow(LL a,LL b,LL n) {
    a %= n;
    LL ans = 1;
    while (b) {
        if (b%2) ans = ans*a%n;
        a = a*a%n;
        b /= 2;
    }
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        LL a,b,k;int n;
        cin >> a >> b >> n;
        if (n != 1 && !T[n]) {
            f[n][0] = 0;f[n][1] = 1;
            for (int i = 2;;i++) {
                f[n][i] = (f[n][i-1] + f[n][i-2])%n;
                if (f[n][i-1] == 0 && f[n][i] == 1) {
                    T[n] = i-1;
                    break;
                }
            }
        }
        //cout << T[n] << endl;
        if (a == 0 || n == 1) k = 0;
        else if (b == 0) k = 1;
        else k = pow(a,b,T[n]);
        cout << f[n][k] << endl;
    }
    return 0;
}
