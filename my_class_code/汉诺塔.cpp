#include<iostream>  
using namespace std;
void move(char x, char y);
void hanoi(int n,char a,char b,char c);
int main()  
{  
     int m;  
     cout<<"ÊäÈëÅÌ×ÓÊý:";  
     cin>>m;;  
     hanoi(m,'A','B','C'); 
	 return 0; 
} 
void hanoi(int n,char a,char b,char c)  
{   
     if (n == 1)  
     {  
           move(a,b);  
     }  
     else  
     {  
         hanoi(n-1,a,c,b);
         move(a,b);
         hanoi(n-1,c,b,a);
     }  
}
void move(char x, char y)  
{  
     cout<<x<<"-->"<<y<<endl;  
}  
