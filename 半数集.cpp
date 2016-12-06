#include<iostream>
using namespace std;
int set(int i)
{
	if(i>=2)
	{
		return set(i / 2) + set(i - 2);
	}
	else
		return 1;
}
int main(){
	int s;
	cin>>s;
	cout<<set(s)<<endl;
	return 0;
}
