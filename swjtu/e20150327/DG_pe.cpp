#include "bits/stdc++.h"
using namespace std;
 
const int maxn = 6e5 + 20;
const int sigma_size = 3;
 
struct Node {
    int cnt;
    bool isEnd;
    Node *next[sigma_size];
} trie[maxn];
 
typedef Node Trie;
int cnt_node = 0;
 
void insert_Trie (char *str, Trie *root) {
    root -> cnt ++;
    if (str[0] == 0) {
        root -> isEnd = 1;
        return ;
    }
    if (root -> next[str[0] - 'a'] == 0) {
        cnt_node ++;
        root -> next[str[0] - 'a'] = trie + cnt_node;
        root -> isEnd = 0;
    }
    insert_Trie (str + 1, root -> next[str[0] - 'a']);
}
 
bool query_Trie (char *str, Trie *root, bool isChange) {
    if (str[0]) {
        int index = str[0] - 'a';
        if (root -> next[index] != 0) {
            if (query_Trie (str + 1, root -> next[index], isChange)) {
                return true;
            }
        }
        if (isChange == 0) {
            for (int i = 0; i < sigma_size; ++ i) {
                if (i == index || root -> next[i] == 0) continue;
                if (query_Trie (str + 1, root -> next[i], true)) {
                    return true;
                }
            }
        }
    } else {
        if (isChange && root -> isEnd) return true;
    }
    return false;
}
 
 
char text[maxn];
 
int main () {
    int n, m;
    memset (trie, 0, sizeof (trie));
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf ("%s", text);
        insert_Trie (text, trie);
    }
    for (int i = 0;i < cnt_node; i++)
    {
    	cout << i << " " << trie[i].isEnd << endl;
    }
    for (int i = 0; i < m; ++ i) {
        scanf ("%s", text);
        if (query_Trie (text, trie, 0)) {
            puts ("YES");
        } else {
            puts ("NO");
        }
    }
    return 0;
}
