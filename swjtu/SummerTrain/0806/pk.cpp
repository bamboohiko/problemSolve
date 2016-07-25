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
const int pow2[18] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int maxd,n;
set<int> S;
bool dfs(int k,int m) {
    //cout << k << " " << m << endl;
    if (m == n) return true;
    if (m > n) {
        if (k == maxd) return false;
        for (set<int>::iterator i = S.begin();i != S.end(); i++) {
            if (m - *i == n) return true;
        }
        return false;
    }
    if (k == maxd || m*pow2[maxd - k] < n) return false;
    for (set<int>::iterator i = S.end();i != S.begin(); i--)
        for (set<int>::iterator j = S.end();j != S.begin(); j--) {
            if (*j > *i) continue;
            int sav = *i + *j;
            if (S.count(sav)) continue;
            S.insert(sav);
            if (dfs(k+1,max(sav,m))) return true;
            S.erase(sav);
        }
    return false;
}
int main() {
    //while (scanf("%d",&n) != EOF) {
    for (n = 1;n <= 1000; n++) {
        if (n == 1) {printf("0,");continue;}
        if (n == 2) {printf("1,");continue;}
        S.clear();
        S.insert(1);
        for (maxd = 1; ;maxd++)
            if (dfs(0,1)) break;
        printf("%d,",maxd);
    }
	return 0;
}
