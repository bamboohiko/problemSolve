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
const int maxn = 1e5 + 10;
int main()
{
    int n,t,turn = 0;
    char st[maxn],ans[maxn];
    scanf("%d%*c",&t);
    while (turn++ < t) {
        gets(st);
        scanf("%d%*c",&n);
        strcpy(ans,st);
        int len = strlen(st),r = len/n + 1,c = len%n;
        int x,y;
        for (int i = 0;i < len; i++) {
            if (i < r*c) {
                y = i%r;
                x = i/r;
            } else {
                y = (i - r*c)%(r-1);
                x = c + (i - r*c)/(r-1);
            }
            //cout << y <<":" <<x <<endl;
            ans[y*n+x] = st[i];
        }
        printf("Case #%d:\n%s\n",turn,ans);
    }
	return 0;
}
