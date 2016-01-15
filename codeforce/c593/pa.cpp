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
string st;
int cou[110][30],sum[110],len[110];
int main() {
    memset(cou,0,sizeof(cou));
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        cin >> st;
        len[i] = st.size();
        for (int j = 0;j < st.size(); j++) {
            if (!cou[i][st[j] - 'a']) sum[i]++;
            cou[i][st[j] - 'a'] = 1;
        }
    }
    int ans = 0;
    for (int i = 0;i < 26; i++)
        for (int j = i+1;j < 26; j++) {
            int fig = 0;
            for (int k = 1;k <= n; k++) {
                if (sum[k] == 2 && cou[k][i] && cou[k][j]) fig += len[k];
                if (sum[k] == 1 && (cou[k][i] || cou[k][j])) fig += len[k];
            }

            ans = max(ans,fig);
        }
    printf("%d\n",ans);
	return 0;
}
