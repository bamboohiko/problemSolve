#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int max_node = 2e6 + 7;
const int max_sig = 26;
string T;

int ch[max_node][max_sig];
int val[max_node];
int sum = 1;

//trie() {sum = 1;}//memset(ch[0],0,sizeof(ch[0]));}
void insert(string& st) {
    int loc = 0;
    for (int i = 0; i < st.size(); i++) {
        if (!ch[loc][st[i] - 'a']) {
            val[sum] = 0;
            ch[loc][st[i] - 'a']  = sum++;
        }
        loc = ch[loc][st[i] - 'a'];
    }
    val[loc] = 1;
}

int f[max_node],last[max_node];
int getFail() {
    queue<int> Q;
    f[0] = 0;
    for (int c = 0; c < max_sig; c++) {
        int u = ch[0][c];
        if (u) {
            f[u] = 0;
            Q.push(u);
            last[u] = 0;
        }
    }

    while (!Q.empty()) {
        int s = Q.front();
        Q.pop();
        for (int c = 0; c < max_sig; c++) {
            int u = ch[s][c];
            if (!u) {
                ch[s][c] = ch[f[s]][c];
                continue;
            }
            Q.push(u);
            int v = f[s];
            while (v && !ch[v][c]) v = f[v];
            f[u] = ch[v][c];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
        }
    }
}

bool find(string& st) {
    int j = 0;
    for (int i = 0; i < st.size(); i++) {
        j = ch[j][st[i] - 'a'];
        if (val[j]) return true;
        else if (last[j]) return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        cin >> T;
        insert(T);
    }
    cin >> T;
    getFail();
    if (find(T)) printf("YES\n");
    else printf("NO\n");
    return 0;
}

