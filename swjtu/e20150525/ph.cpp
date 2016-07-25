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
const int mod =  1e9+9;
const int maxn = 1e6;
int a[maxn + 100],b[maxn + 100];
long long p[2*maxn + 100];
void init() {
    p[0] = 1;
    for (int i = 1;i <= 2*maxn; i++) {	
        p[i] = p[i-1]*i%mod;
    }
}
long long cal(int n,int m) {
	cout << m << " " << n << endl;
	m += n-1;
	return p[m]/p[n]/p[m-n];
}
int main()
{
    init();
    int t,turn = 0;
    scanf("%d",&t);
    while (turn++ < t) {
        double sum = 0;
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= m; i++)
            scanf("%d",&a[i]);
        for (int i = 1;i <= m; i++) {
            scanf("%d",&b[i]);
            sum += b[i];
        }
        long long cou = 1;
        for (int i = 2;i <= m; i++) {
            if (a[i] == a[i-1] + 1) continue;
            cou = cou * cal(a[i]-a[i-1]-1,b[i]-b[i-1]+1)%mod;
            sum += double((b[i] + b[i-1]))*(a[i] - a[i-1] - 1)/2;
		}
        printf("Case #%d: %d %.3lf\n",turn,cou,sum);
    }
	return 0;
}
