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
string a,b;
char dir[100];
int main() {
    dir['A'] = 'U';dir['C'] = 'G';dir['G'] = 'C';dir['T'] = 'A';
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        cin >> a >> b;
        bool ans = true;
        for (int i = 0;i < n; i++) {
            if (dir[a[i]] != b[i]) {
                ans = false;
                break;
            }
        }
        if (ans) puts("YES");
        else puts("NO");
    }
	return 0;
}
