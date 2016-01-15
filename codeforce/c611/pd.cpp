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
string st;
const int mod = 1e9 + 7;
LL f[5010][5010];
int bigger[5010][5010];
void init(int n) {
    for (int j = n-1;j > 0; j--)
        for (int len = 1;len <= j; len++) {
            if (st[n-len+1] == st[j-len+1]) bigger[n-len][j-len] = bigger[n-len+1][j-len+1] + 1;
            else bigger[n-len][j-len] = 0;
            //printf("%d %d %d\n",n-len,j-len,bigger[n-len][j-len]);
        }
    /*
    for (int i = 1;i < n; i++) {
        for (int j = 0;j < i; j++) cout << bigger[i][j] << " ";
        cout << endl;
    }
    */
    /*
    for (int i = 0;i < n; i++)
        for (int j = 0;j < i; j++) {
            int k = 0;
            while (i+k < n && st[i+k+1] == st[j+k+1]) k++;
            bigger[i][j] = k;
        }
    */
}
int main() {
    int n;
    scanf("%d",&n);
    cin >> st;st = " " + st;
    init(n);
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j < i; j++) {
            if (st[i-j+1] == '0') f[i][j] = 0;
            else if (i-j-j < 0) f[i][j] = f[i-j][i-j];
            else {
                int len = bigger[i-j][i-j-j];
                if (len < j && st[i-j+len+1] > st[i-j-j+len+1]) f[i][j] = f[i-j][j];
                else f[i][j] = f[i-j][j-1];
            }
            f[i][j] = (f[i][j] + f[i][j-1])%mod;
            //cout << f[i][j] << " ";
        }
        f[i][i] = (f[i][i-1] + 1)%mod;
        //cout  << endl;
    }
    printf("%I64d\n",f[n][n]);
	return 0;
}
