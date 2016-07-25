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
int main()
{
    int n,k;
    while (scanf("%d",&n) != EOF) {
        int ans = 0;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++) {
                scanf("%d",&k);
                if (i < j && k)  ans += 2;
            }
        printf("%d\n",2*n+ans);
    }
	return 0;
}
