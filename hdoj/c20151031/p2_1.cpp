#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct point {
    int x,y;
};
struct Trie {
    int next[500010][26],fail[500010],end[500010];
    bool d[500010][26];
    int root,L;
    int newnode() {
        for(int i = 0; i < 26; i++)
            d[L][i] = false;
        end[L++] = 0;
        return L-1;
    }
    void init() {
        L = 0;
        //memset(check,false,sizeof(check));
        root = newnode();
    }
    void insert(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++) {
            if(!d[now][buf[i]-'a'])
                next[now][buf[i]-'a'] = newnode();
            d[now][buf[i]-'a'] = true;
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build() {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0; i < 26; i++) {
            if(!d[root][i])
                next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while( !Q.empty() ) {
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < 26; i++) {
                if(!d[now][i])
                    next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    int query(char buf[]) {
        queue<point> Q;
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++) {
            now = next[now][buf[i]-'a'];
            //cout << now << " ";
            int temp = now;
            while( temp != root ) {
                res += end[temp];
                if (end[temp]) Q.push((point){temp,end[temp]});
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        while (!Q.empty()) {
            point t = Q.front();Q.pop();
            end[t.x] = t.y;
            //cout << t.x << " ";
        }
        //cout << endl;
        return res;
    }
};
char buf[2010];
Trie ac;
int main() {
    int T;
    int n;
    scanf("%d",&T);
    for (int ca = 1;ca <= T; ca++) {
        scanf("%d%*c",&n);
        ac.init();
        int ans = -1;
        gets(buf);
        ac.insert(buf);
        ac.build();
        for(int i = 2; i <= n; i++) {
            gets(buf);
            if (ac.query(buf) != i-1) ans = i;
            //printf("%d\n",ac.query(buf));
            ac.insert(buf);
            ac.build();
        }
        printf("Case #%d: %d\n",ca, ans);
    }
    return 0;
}
