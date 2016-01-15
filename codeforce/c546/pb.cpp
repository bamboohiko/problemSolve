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
int a[4010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int ans = 0;
    for (int i = 1;i < n; i++) {
        if (a[i] <= a[i-1]) {
            ans += a[i-1] + 1 - a[i];
            a[i] = a[i-1]+1;
        }
    }
    printf("%d\n",ans);
	return 0;
}
