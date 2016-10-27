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
char st[100100];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        scanf("%s",st);
        int cou = 0,rec = 0;
        for (int i = 0;i < n; i++) {
            if (st[i] == '(') cou++;
            else {
                --cou;
                if (cou < 0) rec = max(rec,-cou);
            }
        }
        //cout << cou << " " <<  rec << endl;
        if (cou != 0 || rec > 2 || (rec == 0 && n == 2)) puts("No");
        else puts("Yes");
    }
	return 0;
}
