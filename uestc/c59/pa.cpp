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
long long t[1001000];
int data[100100][4],sum = 0;
vector<int> loc;
set<int> cou;
void put(int k) {
	if (!cou.count(k)) {
		cou.insert(k);
		loc.push_back(k);
	}
}
int lowbit(int k) {
	return k & (-k);
}
void output() {
	for (int i = 1;i <= loc.size(); i++)
	  cout << t[i] << " "; cout << endl;
}
void updata(int k,int inc) {
	while (k > 0) {
		t[k] += inc;
		k -= lowbit(k);
	}
	output();
}
long long getsum(int k) {
	long long ans = 0;
	while (k <= loc.size()) {
		ans += t[k];
		k += lowbit(k);
	}
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	put(1);put(n);
	for (int i = 1;i <= m; i++) {
		scanf("%d%d",&data[i][0],&data[i][1]);
		if (!data[i][0]) {
			scanf("%d%d",&data[i][2],&data[i][3]);
			put(data[i][1]);put(data[i][2]);
		}
	}
	sort(loc.begin(),loc.end());
	for (int i = 1;i <= m; i++) {
		if (!data[i][0]) {
			int l = lower_bound(loc.begin(),loc.end(),data[i][1]) - loc.begin() + 1;
			int r = lower_bound(loc.begin(),loc.end(),data[i][2]) - loc.begin() + 1;
			updata(r,data[i][3]);
			updata(l-1,-data[i][3]);
		}
		else {
			int k1 = lower_bound(loc.begin(),loc.end(),data[i][1]) - loc.begin() + 1;
			int k2 = upper_bound(loc.begin(),loc.end(),data[i][1]) - loc.begin() + 1;
			printf("%lld %lld\n",getsum(k1),getsum(k2));
		}
	}
	return 0;
}
