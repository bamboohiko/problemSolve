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
const int maxm = 1e6;
int ans[maxm + 100],sum[maxm + 100];
int main() {
    for (int i = 0;i*i <= maxm; i++)
        for (int j = 0;i*i + j*j <= maxm; j++)
            ans[i*i + j*j]++;
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        int n;
        scanf("%d",&n);
        int sum = 0;
        for (int i = 0;i <= n; i++) sum += ans[i]*ans[n-i];
        printf("Case #%d: %d\n",ca,sum);
    }
	return 0;
}
