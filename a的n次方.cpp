//author ��˫ȫ 
#include<iostream>
using namespace std;
long int pow(int a,int n){
	if(n==0){
		return 1;
	}
	long int b=pow(a,n/2);
	b*=b;
	if(n%2==1){   //ָ��Ϊ�����Ĵ������ 
		b*=a;
	}
	return b;
} 
int main(){
	int a,n;
	long int result;
	cout<<"input a :";
	cin>>a;
	cout<<"input n :";
	cin>>n;
	result=pow(a,n);
	cout<<"a^n="<<result<<endl; 
	return 0;
}
