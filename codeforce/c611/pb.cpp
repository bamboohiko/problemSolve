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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int main() {
    LL a,b,ans = 0;
    scanf("%I64d%I64d",&a,&b);
    for (int i = 0;i < 64; i++) {
        LL k = ((LL)1 << i)-1;
        for (int j = 0;j < i-1; j++) {
            LL h = k - ((LL)1 << j);
            //cout << h << endl;
            if (h <= b && h >= a) {
                ans++;
                //cout <<k << " " <<h <<endl;
            }
        }
    }
    printf("%I64d\n",ans);
	return 0;
}
