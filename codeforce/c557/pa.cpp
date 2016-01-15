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
int minn[5],maxn[5];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= 3; i++) {
        scanf("%d%d",&minn[i],&maxn[i]);
        n -= minn[i];
    }
    for (int i = 1;i <= 2; i++) {
        int k = min(n,maxn[i]-minn[i]);
        n -= k;
        printf("%d ",k + minn[i]);
    }
    printf("%d\n",minn[3] + n);
	return 0;
}
