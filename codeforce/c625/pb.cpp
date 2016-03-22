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
string a,b;
int main() {
    cin >> a >> b;
    int ans = 0,last = -1;
    for (int i = 0;i < a.size(); i++) {
        bool rec = true;
        for (int j = 0;j < b.size(); j++) {
            if (a[i+j] != b[j]) {
                rec = false;
                break;
            }
        }
        if (rec && i > last) {
            ans++;
            last = i + b.size()-1;
        }
    }
    printf("%d\n",ans);
	return 0;
}
