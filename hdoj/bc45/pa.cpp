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
int main()
{
    int t;long long n;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld",&n);
        int k = 0;
        while (n) {
            a[k++] = n%2;
            n /= 2;
        }
        int ans = 0,sum = 0;
        for (int i = 0;i < k; i++) {
            if (a[i] == 1) sum = 1;
            else {
                ans += sum;
                sum = 0;
            }
        }
        ans += sum;
        printf("%d\n",ans);
    }
	return 0;
}
