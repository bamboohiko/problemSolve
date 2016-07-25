#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1e8;
bool check[maxn + 10];
int phi[maxn + 10],prime[maxn + 10],tot = 0;
void phi(int n) {
    memset(check,false,sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i = 2;i <= n; i++) {
        if (!check[i]) {
            prime[tot++] = i;
            phi[i] = i-1;
        }
        for (int j - 0;j < tot; j++) {
            if (i*prime[j] > n) break;
            check[i*prime[j]] = true;
            if (i%prime[j] == 0) {
                phi[i*prime[j]] = phi[i]*prime[j];
                break;
            } else {
                phi[i*prime[j]] = phi[i]*(prime[j] - 1);
            }
        }
    }
}
int main()
{
    phi(maxn);
    int t,n;
    scanf("%d",&t);
    while (t--) {

    }
	return 0;
}
