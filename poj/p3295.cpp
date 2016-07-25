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
int v[200];
stack<int> num;
int main() {
    while (cin >> st) {
        if (st[0] == '0') break;
        int n = st.size()-1;
        bool ok = true;
        for (int i = 0;i <= 31; i++) {
            memset(v,-1,sizeof(v));
            v['p'] = i&(1<<0);v['q'] = (i&(1<<1))>>1;v['r'] = (i&(1<<2))>>2;
            v['s'] = (i&(1<<3))>>3;v['t'] = (i&(1<<4))>>4;
            for (int i = n;i >= 0; i--) {
                if (st[i] >= 'a' && st[i] <= 'z') num.push(v[st[i]]);
                else {
                    int n2 = num.top();num.pop();
                    if (st[i] == 'N') {num.push(1-n2);continue;}
                    int n1 = num.top();num.pop();
                    if (st[i] == 'K') num.push(n1&n2);
                    if (st[i] == 'A') num.push(n1|n2);
                    if (st[i] == 'C') num.push((n1-n2 == 1)?0:1);
                    if (st[i] == 'E') num.push(1-(n1^n2));
                }
            }
            int ans = num.top();num.pop();
            if (ans == 0) {
                ok = false;
                break;
            }
        }
        if (ok) puts("tautology");
        else puts("not");
    }
	return 0;
}

