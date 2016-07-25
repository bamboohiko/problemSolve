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
string st;
set<LL> S;
int main() {
    int n;LL k,p;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        cin >> st;
        k = 0;p = 1;
        for (int i = 4;i < st.length(); i++) {
            k = k*10 + st[i] - '0';
            p *= 10;
        }
        if (k < 1989) while (k < 1989) k += p;
        else k += p;
        printf("%I64d\n",k);
        S.insert(k);
    }
	return 0;
}

