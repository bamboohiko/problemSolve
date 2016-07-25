#include<iostream>
#include<cstring>
using namespace std;
int w = 0;
char mod[15]={'+','-','+','|',' ','|','+','-','+','|',' ','|','+','-','+'};
bool map[5][100];
bool graph[11][15]={
	{1,1,1,1,0,1,1,0,1,1,0,1,1,1,1},//0
	{0,0,1,0,0,1,0,0,1,0,0,1,0,0,1},//1
	{1,1,1,0,0,1,1,1,1,1,0,0,1,1,1},//2
	{1,1,1,0,0,1,1,1,1,0,0,1,1,1,1},//3
	{1,0,1,1,0,1,1,1,1,0,0,1,0,0,1},//4
	{1,1,1,1,0,0,1,1,1,0,0,1,1,1,1},//5
	{1,1,1,1,0,0,1,1,1,1,0,1,1,1,1},//6
	{1,1,1,0,0,1,0,0,1,0,0,1,0,0,1},//7
	{1,1,1,1,0,1,1,1,1,1,0,1,1,1,1},//8
	{1,1,1,1,0,1,1,1,1,0,0,1,1,1,1},//9
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//space
};
int search(int x,int y){
	int i,j;
	int t = y;
	bool f[11];
	for(i = 0; i < 11;i++)
		f[i] = true;
	for(i = 0; i < 15; i++){
		for(j = 0;j < 11; j++){
				if((map[x][y] != graph[j][i])&&(f[j])){
					f[j] = false;
				}
		}
		y++;
		if(y>t+2){
			x++;
			y = t;
		}
	}
	for(i=0;i<11;i++)
		if(f[i])
			return i;
	return 12;
}
void print(int num){
	int n[10];
	int len=0;
	if(num == 0){
		n[0] = 0;
		len = 1;
	}else while(num!=0){
		n[len] = num%10;
		num /=10;
		len++;
	}
	for(int j = 0; j<5;j++){
		for(int i = len-1 ; i >= 0; i--){
			for(int k = j*3;k<=j*3+2;k++)
				if(graph[n[i]][k])
					cout<<mod[k];
				else
					cout<<' ';
			if(i!=0)
				cout<<" ";
		}
		cout<<endl;
	}
}
int main(){
	
	char temp[100];
	int len;
	
	for(int i=0;i<5;i++){
		cin.getline(temp,100);
		len = strlen(temp);
		if(len > w)
			w = len;
		for(int j = 0 ; j < len;j++)
			if((temp[j]=='+')||(temp[j]=='-')||(temp[j]=='|')){
				map[i][j] = 1;
			}else{
				map[i][j] = 0;
			}
	}
	int x = 0,y = 0;
	int num[100];
	int l = 0,pos;
	int num1 = 0;
	int num2 = 0;
	while(y<len){
		num[l] = search(x,y);
		l++;
		y += 4;
	}
	for(int i = 0;i < len; i++)
		if(num[i] == 10){
			pos = i;
			break;
		}
	for(int i = 0 ; i < pos ; i++)
		num1 = num[i]+num1*10;
	for(int i = pos+1; i < l; i++)
		num2 = num[i]+num2*10;
	print(num1+num2);
	return 0;
}
