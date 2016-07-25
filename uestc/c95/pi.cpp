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
set<int> S,L;
queue<int> Q;
void rlt() {
    for (set<int>::iterator i = S.begin();i != S.end(); i++)
        cout << *i << " ";cout << endl;
    for (set<int>::iterator i = L.begin();i != L.end(); i++)
        cout << *i << " ";cout << endl;
}
int main() {
    int n;
    scanf("%d",&n);
    int op,x,k = 0;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&op);
        if (op == 1) {
            scanf("%d",&x);Q.push(x);k++;
            if (S.empty() || x > *(S.rbegin())) L.insert(x);
            else S.insert(x);
            if (S.size() > k/2) {int y = *(S.rbegin());S.erase(y);L.insert(y);}
            if (S.size() < k/2) {int y = *(L.begin());L.erase(y);S.insert(y);}
            //rlt();
        }
        if (op == 2) {
            x = Q.front();Q.pop();k--;
            if (S.count(x)) S.erase(x);
            else L.erase(x);
            if (S.size() > k/2) {int y = *(S.rbegin());S.erase(y);L.insert(y);}
            if (S.size() < k/2) {int y = *(L.begin());L.erase(y);S.insert(y);}
            //rlt();
        }
        if (op == 3) {
            int x = *(L.begin());
            printf("%d\n",x);
        }
    }
	return 0;
}

