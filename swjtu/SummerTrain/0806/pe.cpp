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
int v[100],n;
set<long long> S;
void dfs(int k,int m) {
    //cout << m << endl;
    S.insert(abs(m));
    if (k > n) return;
    dfs(k+1,m+v[k]);
    dfs(k+1,m-v[k]);
    dfs(k+1,m);
}
int main() {
    int a,b;
    while (scanf("%d%d",&a,&b) != EOF) {
        int k = 1;
        while (b--) k = k*a%7;
        if (k == 0 || k == 6) printf("800 ");
        else printf("1000 ");
        scanf("%d",&n);
        long long sum = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&v[i]);
            sum += v[i];
        }
        S.clear();
        dfs(1,0);
        printf("%d %lld\n",S.size()-1,sum);
    }
	return 0;
}
