//c
#include<stdio.h>
int main() {
    int a,b;
    while (scanf("%d%d",&a,&b) != EOF)
        printf("%d\n",a+b);
    return 0;
}
//c++
#include<iostream>
using namespace std;
int main() {
    int a,b;
    while (cin >> a >> b)
        cout << a+b << endl;
    return 0;
}


