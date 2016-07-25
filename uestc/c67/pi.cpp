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
    const int maxn = 210;
    int G[maxn][maxn];
    vector<int> ans;
    priority_queue<int,vector<int>, greater<int> > Q;
    int cou[maxn];
    int main()
    {
        int t;
        int from,to;
        int n,m;
        scanf("%d",&t);
        while (t--) {
            scanf("%d%d",&n,&m);
            //for (int i = 1;i <= n; i++) G[i].resize(0);
            memset(G,0,sizeof(G));
            ans.resize(0);
            memset(cou,0,sizeof(cou));
            for (int i = 1;i <= m; i++) {
                scanf("%d%d",&from,&to);
                if (!G[from][to]) cou[to]++;
                G[from][to] = 1;
            }
            for (int i = 1;i <= n; i++)
                if (!cou[i]) Q.push(i);
            while (!Q.empty()) {
                int s = Q.top();Q.pop();
                //cout << s << endl;
                ans.push_back(s);
                for (int i = 1;i < n; i++)
                    if (G[s][i] && s != i) {
                        //int t = G[s][i];
                        cou[i]--;
                        if (!cou[i]) Q.push(i);
                    }
            }
            if (ans.size() != n) printf("%d\n",-1);
            else {
                printf("%d",ans[0]);
                for (int i = 1;i < ans.size(); i++)
                    printf(" %d",ans[i]);
                printf("\n");
            }
        }
        return 0;
    }
