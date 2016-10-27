#include<iostream>
using namespace std;
int a[100010],f[100010];
int main()
{int t,n,ans,fir,pos;
	cin >> t;
	f[0]=0;
	for (int j = 1; j <= t; j++)
		{cin >> n >> a[1];
		ans = f[1] = a[1];
		for (int i = 2;i <= n; i++)
			{cin >> a[i];
			f[i]=max(f[i-1],0)+a[i];
			//cout << f[i] << " ";
			if (f[i] > ans)
				{ans=f[i];
				 pos=i;
				}
			}
		fir = pos;
		for (int i = pos;(i) && (f[i] == f[i-1]+a[i]); i-- ) fir=i;
		cout << "Case: " << j << endl;
		cout << ans << " " << fir << " " << pos << endl; 
		}
	return 0;
}
