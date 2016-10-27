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
struct node{
    int cou;
    int s[2];
};
vector<node> V;
int root;
int newnode() {
    node p;
    p.cou = p.s[0] = p.s[1] = 0;
    V.push_back(p);
    return V.size()-1;
}
void ins(int k) {
    int p = root;
    for (int i = 29;i >= 0; i--) {
        int loc = (k&(1 << i))?1:0;
        if (V[p].s[loc]) p = V[p].s[loc];
        else {
            int sav = newnode();
            V[p].s[loc] = sav;
            p = V[p].s[loc];
        }
        V[p].cou++;
    }
}
void del(int k) {
    int p = root;
    for (int i = 29;i >= 0; i--) {
        int loc = (k&(1 << i))?1:0;
        int sp = V[p].s[loc];
        if ((--V[sp].cou) == 0) {
            V[p].s[loc] = 0;
            break;
        }
        p = sp;
    }
}
int query(int k) {
    int p = root,ans = 0;
    for (int i = 29;i >= 0; i--) {
        int loc = (k&(1 << i))?0:1;
        int sp = V[p].s[loc],nsp = V[p].s[loc^1];
        if (sp && V[sp].cou) {
            p = sp;
            ans += (1 << i);
        } else if (nsp && V[nsp].cou) {
            p = nsp;
        } else {
            ans += ((1 << (i+1))-1)&k;
            break;
        }
    }
    return max(ans,k);
}
int main() {
    int n;
    scanf("%d%*c",&n);
    root = newnode();
    char ch;int k;
    while (n--) {
        scanf("%c%d%*c",&ch,&k);
        if (ch == '+') ins(k);
        if (ch == '-') del(k);
        if (ch == '?') printf("%d\n",query(k));
    }
	return 0;
}
