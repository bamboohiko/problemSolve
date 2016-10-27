#include<iostream>
#include<algorithm>
using namespace std;
int a[110],b[110];
int comp(int n)
{int i=0,j=0;	 
	while ((i < n) && (j < n))
		 	{if (a[i] == b[j])
		 		{do i++; while ((i < n) && (a[i] == a[i-1]));
		 		 do j++; while ((j < n) && (b[j] == b[j-1]));
		 		}
		 	 else return 0;
		 	}
 if ((i == n) && (j == n)) return 1;
 else return 0;
}
int main()
{freopen("soeasy.in","r",stdin);
 freopen("soeasy.out","w",stdout); 
int n; 
	while (cin >> n) 
		{for (int i = 0 ; i < n ; i++ ) cin >> a[i];
		 for (int i = 0 ; i < n ; i++ ) cin >> b[i];
		 sort(a,a+n);
		 sort(b,b+n);
		 if (comp(n) == 1) cout << "YES" << endl;
		 else cout << "NO" << endl;
		}	
	return 0;
}
