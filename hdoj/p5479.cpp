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
int main() {
    int t;
    scanf("%d",&t);
    string st;
    while (t--) {
        cin >> st;
        int ans = st.length();
        for (int i = 0;i <= st.length(); i++) {
            int sum = 0;
            for (int j = 0;j < i; j++) if (st[j] != ')') sum++;
            for (int j = i;j < st.length(); j++) if (st[j] != '(') sum++;
            ans = min(sum,ans);
        }
        printf("%d\n",ans);
    }
	return 0;
}

