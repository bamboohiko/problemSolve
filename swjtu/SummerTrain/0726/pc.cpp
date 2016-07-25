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
int a[100];
int main() {
    int n,ca = 1;
    while (scanf("%d",&n) != EOF && n) {
        printf("Set #%d\n",ca++);
        int ave = 0,ans = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            ave += a[i];
        }
        ave /= n;
        for (int i = 1;i <= n; i++)
            ans += abs(a[i] - ave);
        printf("The minimum number of moves is %d.\n\n",ans/2);
    }
	return 0;
}


