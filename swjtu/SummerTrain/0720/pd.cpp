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
    for (int ca = 1;ca <= t; ca++) {
        printf("Case #%d: ",ca);
        string st;
        cin >> st;
        while (true) {
            int loc = st.find("football");
            if (loc == -1) break;
            st = st.replace(loc,8,"");
        }
        if (st.size()) cout << st << endl;
        else cout << "OHaHa" << endl;
    }
	return 0;
}
