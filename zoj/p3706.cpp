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
set<int> S;
int add(int a,int b,int c) {
    S.clear();
    for (int i = -1;i <= 1; i++)
        for (int j = -1;j <= 1; j++)
            for (int k = -1;k <= 1; k++) {
                int sum = i*a + j*b + k*c;
                if (sum > 0) S.insert(sum);
            }
    return (int)S.size();
}
int main() {
    int t,x,y;
    scanf("%d",&t);
    while (t--) {
        int ans = 0;
        scanf("%d%d",&x,&y);
        for (int i = 1;i <= (x >> 1); i++) ans = max(ans,add(i,x-i,y));
        for (int i = 1;i <= (y >> 1); i++) ans = max(ans,add(x,i,y-i));
        printf("%d\n",ans);
    }
	return 0;
}
