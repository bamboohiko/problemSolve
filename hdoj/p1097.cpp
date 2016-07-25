#include<iostream>
#include<cstring>
using namespace std;
int rec[15];
int num[15];
int main()
{int a,b,now,k,i;
	while (cin >> a >> b)
		{memset(num,0,sizeof(num));
		 now=k=a%10;i=0;
		 while (!num[now])
			{num[now]=1;
			 rec[i++]=now;
			 now=now*k%10;
			}
		 cout << rec[(b-1)%i] << endl;		 
		}
	 
	return 0;
}
