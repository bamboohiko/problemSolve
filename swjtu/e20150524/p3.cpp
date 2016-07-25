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
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int x = (n+1)/2,y = n;
    int ans = -1;
    for (int i = x;i <= y; i++)
        if (i%m == 0) {
            ans = i;
            break;
        }
    printf("%d\n",ans);
	return 0;
}
