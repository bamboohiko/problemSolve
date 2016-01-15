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
typedef long long LL;
const int n = 5000000;
LL cou[n + 100];
int init(){
    vector<int> pri;
    for (int i = 2;i <= n; i++) {
        if (!cou[i]) {
            pri.push_back(i);
            cou[i] = 1;
        }
        for (int j = 0;j < pri.size(); j++) {
            if (pri[j]*i > n) break;
            cou[pri[j]*i] = cou[pri[j]] + cou[i];
            if (i%pri[j] == 0) break;
        }
    }
    for (int i = 2;i <= n; i++) cou[i] += cou[i-1];
}
int main()
{
    init();
    int t,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&a,&b);
        printf("%d\n",cou[a] - cou[b]);
    }
	return 0;
}
