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
int main() {
    cin >> st;
    for (int i = 1;i < st.size(); i++) {
        if (st[i] == st[i-1]) {
            st[i] = st[i-1] + 1;
            if (st[i] == 'z'+1) st[i] = 'a';
            if (i < st.size()-1 && st[i] == st[i+1]) st[i] += 1;
            if (st[i] == 'z'+1) st[i] = 'a';
        }
    }
    cout << st << endl;
	return 0;
}

