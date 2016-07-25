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
const int mod = 142857;
int cou[100100];
int b[100100];
vector<int> G[100100];
vector<int> ans;
int main()
{
    int t;
    int n,m,k;
    int from,to;
        queue<int> Q;
        memset(cou,0,sizeof(cou));
        memset(b,0,sizeof(b));
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 1;i <= n; i++) G[i].clear();
        for (int i = 1;i <= k; i++) {
            scanf("%d",&t);
            b[t] = 1;
        }
        ans.clear();
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&from,&to);
            G[from].push_back(to);
            cou[to]++;
        }
        for (int i = 1;i <= n; i++)
            if (!cou[i]) Q.push(i);
        int sum = 0;
        while (!Q.empty()) {
            int s = Q.front();Q.pop();
            ans.push_back(s);
            sum = (sum + b[s])%mod;
            for (int i = 0;i < G[s].size(); i++) {
                int t = G[s][i];
                cou[t]--;b[t] = (b[t] + b[s])%mod;
                if (!cou[t]) {
                    Q.push(t);
                }
            }
        }
        printf("%d\n",sum);
	return 0;
}
