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
stack<LL> num;
stack<char> op;
void fig() {
    LL k2 = num.top();num.pop();
    LL k1 = num.top();num.pop();
    char act = op.top();op.pop();
    //cout << k1 << act << k2 << endl;
    if (act == '+') k1 += k2;
    if (act == '-') k1 -= k2;
    if (act == '*') k1 *= k2;
    if (act == '/') k1 /= k2;
    num.push(k1);
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        num.push(0);
        LL k = 0;int sgn = 1;
        cin >> st;
        for (int i = 0;i < st.size(); i++) {
            if (st[i] >= '0' && st[i] <= '9') k = k*10 + (st[i] - '0')*sgn;
            else {
                //cout << k << endl;
                num.push(k);k = 0;
                while (!op.empty() && (op.top() == '*' || op.top() == '/')) fig();
                if (st[i] == '-') {
                    st[i] = '+';
                    sgn = -1;
                } else sgn = 1;
                op.push(st[i]);
            }
        }
        num.push(k);k = 0;
        while (!op.empty()) fig();
        if (!num.empty()) {
            printf("%lld\n",num.top());
            while (!num.empty()) num.pop();
        }
    }
	return 0;
}

