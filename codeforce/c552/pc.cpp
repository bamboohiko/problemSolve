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
vector<int> a;
int main()
{
    int w,m;
    scanf("%d%d",&w,&m);
    while (m) {
        a.push_back(m%w);
        m /= w;
    }
    //for (int i = 0;i < a.size(); i++) cout <<a[i] <<" "; cout << endl;
    bool ans = true;
    for (int i = 0;i < a.size(); i++) {
        if (a[i] >= w) {
            if (a.size()-1 == i) a.push_back(0);
            a[i+1] += a[i]/w;
            a[i] = a[i]%w;
        }
        if (a[i] == w-1) a[i+1]++;
        if (a[i] > 1 && a[i] < w-1) {
            ans = false;
            break;
        }
    }
    if (w == 2 || ans) printf("YES\n");
    else printf("NO\n");
	return 0;
}
