/**
author by ��˫ȫ 
drawback �����ظ���Ԫ��ʱ���������һ�����������ͬ��Ϣ 
*/
#include<iostream>
using namespace std;

void Perm(char list[],int k,int m);
inline void Swap(char &a,char &b);
int main(){
	int n;
	cout<<"����Ԫ�صĸ�����" ;
	cin>>n;
	char* list=new char [n]; 
	for(int i=0;i<n;i++){
		cout<<"��"<<i+1<<"����:"; 
		cin>>list[i];
	}
	Perm(list,0,n-1);
	return 0; 
}

void Perm(char list[],int k,int m)
{
	//����List[k:m]����������
	if(k==m)
	{
		//ֻʣ��һ��Ԫ��
		for(int i=0;i<=m;i++)cout<<list[i]; 
		cout<<endl; 
	} 
	else//���ж��Ԫ�ش����У��ݹ��������
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
