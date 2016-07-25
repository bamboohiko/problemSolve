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
struct point {
    string nam;
    int y;
};
point a[110];
bool cmp(point a,point b) {
    return a.y > b.y;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d%*c",&n);
        for (int i = 0;i < n; i++) {
            getline(cin,a[i].nam);a[i].y = 0;
            int loc;
            for (loc = a[i].nam.length()-1;a[i].nam[loc] != ' ';loc--) ;
            for (int j = loc+1;j < a[i].nam.length(); j++) a[i].y = a[i].y*10 + a[i].nam[j] - '0';
            a[i].nam = a[i].nam.erase(loc);
            //cout << a[i].nam << "!" << a[i].y << endl;
        }
        sort(a,a+n,cmp);
        for (int i = 0;i < n; i++)
            cout << a[i].nam << endl;
    }
	return 0;
}
