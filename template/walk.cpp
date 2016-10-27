#include<cstdio>
#include<cstring>
const int move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,ans=1000;
int a[30][30];
int use[30][30];
int check(int x,int y)
{if ((x>=0) && (x<n) && (y>=0) && (y<m)) return(1);
 return 0;
}
void reans(int s)
{if (s<ans) ans=s;
}
void dfs(int x,int y,int s)    //s:step,ans:answer;
{int nx,ny;
 //printf("%d %d %d\n",x,y,s);
 use[x][y]=1;
 for(int i=0;i<4;i++)
   {nx=x+move[i][0];
    ny=y+move[i][1];   
    if (check(nx,ny)&&(!a[nx][ny])&&(!use[nx][ny])) 
	  if ((nx+1==n)&&(ny+1==m)) reans(s+1);
	  else dfs(nx,ny,s+1);
   }
 use[x][y]=0;
}
int main()
{
freopen("walk.in","r",stdin);
freopen("walk.out","w",stdout);
	memset(a,sizeof(a),0);
	memset(use,sizeof(use),0);
 	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	    scanf("%d",&a[i][j]);
	dfs(0,0,0);
	if (ans!=1000) printf("%d\n",ans);
	else printf("fall!/n");
 return 0;
}
