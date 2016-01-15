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
int a[510][510],cou[510];
int main()
{

    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1;i <= n; i++) {
        int sum = 0;
        for (int j = 1;j <= m; j++) {
            scanf("%d",&a[i][j]);
            if (a[i][j]) sum++;
            else {
                cou[i] = max(cou[i],sum);
                sum = 0;
            }
        }
        cou[i] = max(cou[i],sum);
    }
    for (int i = 1;i <= q; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y] = 1 - a[x][y];
        int sum = 0;cou[x] = 0;
        for (int j = 1;j <= m; j++) {
            if (a[x][j]) sum++;
            else {
                cou[x] = max(cou[x],sum);
                sum = 0;
            }
            //cout << a[x][j] << " ";
        }
        //cout << endl;
        cou[x] = max(cou[x],sum);
        int ans = 0;
        for (int j = 1;j <= n; j++) {
            ans = max(ans,cou[j]);
            //cout << cou[j] << " ";
        }
        //cout << endl;
        printf("%d\n",ans);
    }
	return 0;
}
