/**
author by 赵双全 
drawback 当有重复的元素时，还会进行一次排序产生相同信息 
*/
#include<iostream>
using namespace std;

void Perm(char list[],int k,int m);
inline void Swap(char &a,char &b);
int main(){
	int n;
	cout<<"输入元素的个数：" ;
	cin>>n;
	char* list=new char [n]; 
	for(int i=0;i<n;i++){
		cout<<"第"<<i+1<<"个数:"; 
		cin>>list[i];
	}
	Perm(list,0,n-1);
	return 0; 
}

void Perm(char list[],int k,int m)
{
	//产生List[k:m]的所有排列
	if(k==m)
	{
		//只剩下一个元素
		for(int i=0;i<=m;i++)cout<<list[i]; 
		cout<<endl; 
	} 
	else//还有多个元素待排列，递归产生排列
		for(int i=k;i<=m;i++){
			Swap(list[k],list[i]);
			Perm(list,k+1,m);
			Swap(list[k],list[i]);
		} 
}

inline void Swap(char &a,char &b){
	char temp=a;
	a=b;
	b=temp;
}
