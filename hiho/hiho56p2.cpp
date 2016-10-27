#include <iostream>
#include <algorithm>
#include <iomanip>
#include<cmath>
#include<cstdio>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define N 500
#define M 1000
#define EPS 1e-5

double a[M][N],c[M],y[N];
int x[M];

int main() {
    freopen("in.txt","r",stdin);
	int n,m;
	cin >> n >> m;
	rep(i,m) {
		rep(j,n) cin >> a[i][j];
		cin >> c[i];
		x[i] = i;
	}

	rep(i,n) {
		int f = 0;
		for(int j = i; j < m; j++) {
			if(fabs(a[x[j]][i])>EPS) {
				f = 1;
				swap(x[i],x[j]);
				break;
			}
		}
		if(!f) {
			cout << "Many solutions" << endl;
			return 0;
		}
		for(int j = i+1; j < m; j++) {
			if(fabs(a[x[j]][i])>EPS) {
				double u,v; u = a[x[i]][i]; v = a[x[j]][i];
				for(int k = i; k < n; k++) {
					a[x[j]][k] = a[x[j]][k] - a[x[i]][k] * v / u;
				}
				c[x[j]] = c[x[j]] - c[x[i]] * v / u;
			}
		}
	}

	for(int j = 0; j < m; j++) {
		int f = 0;
		rep(i,n) if(fabs(a[x[j]][i])>EPS) f = 1;
		if(f==0 && fabs(c[x[j]])>EPS) {
			cout << "No solutions" << endl;
			return 0;
		}
	}

	for(int j = n-1; j >= 0; j--) {
		y[j] = c[x[j]];
		for(int i = j+1; i < n; i++) y[j] -= a[x[j]][i] * y[i];
		y[j] = y[j] / a[x[j]][j];
	}

	rep(i,n) {
		if(fabs(y[i]) <EPS)  cout << 0 << endl;
		else cout << y[i] << endl;
	}
}
