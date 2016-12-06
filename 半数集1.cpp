#include<iostream>
using namespace std;
int set(int i);

int main(){
	int s;
	cin>>s;
	cout<<set(s)<<endl;
	return 0;
}

int set(int n)      
{   int ans=1;
    if(n>1)
        for(int i=1;i<=n/2;i++)
            ans+=set(i);
    return ans;
}
