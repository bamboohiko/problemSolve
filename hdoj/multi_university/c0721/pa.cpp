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
const int mod = 1e9 + 7;
const int maxn = 1e4;
vector<int> sav[maxn + 100];
vector<int> dev[maxn + 100];
int n;
int lower(vector<int>& a,int k) {
    int l = 0,r = a.size()-1;
    if (k > a[r]) return n;
    while (l < r) {
        int mid = l + ((r-l) >> 1);
        if (k >= a[mid]) mid = r;
        else l = mid + 1;
    }
    return a[l]-1;
}
int upper(vector<int>& a,int k) {
    int l = 0,r = a.size()-1;
    if (k < a[l]) return 1;
    while (l < r) {
        int mid = l + ((r-l) >> 1);
        if (k <= a[mid]) l = mid;
        else r = mid-1;
    }
    return a[l]+1;
}
int main() {
    for (int i = 2;i <= maxn; i++) {
        for (int j = 1;j <= sqrt(i + 0.5); j++)
            if (i%j == 0) {
                dev[i].push_back(j);
                dev[i].push_back(i/j);
            }
        sort(dev[i].begin(),dev[i].end());
        //for (int j = 0;j < dev[i].size(); j++) cout << dev[i][j] << " ";cout << endl;
    }
    while (scanf("%d",&n) != EOF) {
        int x;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            sav[x].push_back(i);
        }
        int ans = 0;
        for (int i = 1;i <= maxn; i++) {
            for (int j = 0;j < sav[i].size(); j++) {
                int loc = sav[i][j];
                int l = 1,r = n;
                for (int k = 0;k < (int)dev[i].size()- 1; k++) {
                    //cout << i << ":" << dev[i][k] << endl;
                    vector<int>& a = sav[dev[i][k]];
                    if (!a.size()) continue;
                    //for (int i = 0;i < a.size(); i++) cout << a[i] << " ";cout << "#" << endl;
                    r = min(lower(a,loc),r);
                    l = max(upper(a,loc),l);
                    //cout << l << " " << r << endl;
                }
                ans = (ans + (r-loc+1)*(loc-l+1))%mod;
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}
