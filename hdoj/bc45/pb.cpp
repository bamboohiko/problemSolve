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
int cou[1010][1010];
int tree[1010][1010];
int a[1010];
int lowbit(int k) {
    return k & (-k);
}
void add(int loc,int k,int d) {
    while (k <= loc) {
        tree[k][loc] += d;
        k += lowbit(k);
    }
}
int sum(int loc,int k) {
    int ans = 0;
    while (k > 0) {
        ans += tree[k][loc];
        k -= lowbit(k);
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++)
        scanf("%d",&a[i]);
    for (int i = 1;i <= n; i++)
        for (int j = i+1;j <= n; j++)
            if (a[j] < a[i]) cou[i][j] = cou[i][j-1] + 1;
            else cou[i][j] = cou[i][j-1];
   /*
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j <= n; j++) cout << cou[i][j] << " ";
        cout << endl;
    }
    */
    for (int j = 1;j <= n; j++)
        for (int i = 1;i < j; i++)
            add(j,i,cou[i][j]);
    /*
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j <= n; j++) cout << tree[i][j] << " ";
        cout << endl;
    }
    */
    int l,r;
    for (int i = 1;i <= m; i++) {
        scanf("%d%d",&l,&r);
        printf("%d\n",sum(r,r) - sum(r,l-1));
    }
	return 0;
}
