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
string sav[100] = {"H","He","Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu",
"Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr",
"Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag",
"Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba",
"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd",
"Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta",
"W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb",
"Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
"U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm"};
map<string,int> dir;
void init() {
    for (int i = 0;i < 100; i++)
        dir[sav[i]] = i+1;
}

int a[20],b[20],n,m;
bool vis[20];
bool dfs(int k,int v,int fr) {
    //cout << k << " " << v << " " << fr << endl;
    if (k == m+1) return true;
    for (int i = fr;i <= n; i++) {
        if (!vis[i-1] && a[i] == a[i-1]) continue;
        if (!vis[i] && v+a[i] <= b[k]) {
            vis[i] = true;
            if (v+a[i] == b[k]) {
                if (dfs(k+1,0,1)) return true;
                else {
                    vis[i] = false;
                    break;
                }
            } else {
                if (dfs(k,v+a[i],i+1)) return true;
            }
            vis[i] = false;
        }
    }
    return false;
}
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    init();
    int t,ca = 1;
    scanf("%d",&t);
    while (t--) {
        int sum = 0;
        scanf("%d%d",&n,&m);
        string st;
        for (int i = 1;i <= n; i++) {
            cin >> st;
            a[i] = dir[st];
            sum += a[i];
        }
        sort(a+1,a+n+1,cmp);
        for (int i = 1;i <= m; i++) {
            cin >> st;
            b[i] = dir[st];
            sum -= b[i];
        }
        sort(b+1,b+m+1,cmp);
        //for (int i = 1;i <= n; i++) cout << a[i] << " ";cout << endl;
        //for (int i = 1;i <= m; i++) cout << b[i] << " ";cout << endl;
        printf("Case #%d: ",ca++);
        memset(vis,0,sizeof(vis));
        if (sum == 0 && dfs(1,0,1)) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
