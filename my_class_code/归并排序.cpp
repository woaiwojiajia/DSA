#include<stdio.h>


void MergeSort(int a[],int b[],int left,int right);
void Copy(int a[],int b[],int left,int right);
void Merge(int a[],int b[],int left,int i,int right);
int main()
{
	int i;
	int a[10]={3,5,9,4,6,7,8,0,2,1};
	int b[10]={0};
	MergeSort(a,b,0,9);

	for(i=0;i<10;i++)
	{
		printf("%3d",a[i]);
	}
	return 0;	
}
void MergeSort(int a[],int b[],int left,int right)
{
	if(left<right){    //至少有两个元素
		int i=(left+right)/2;        //取中点
		MergeSort(a,b,left,i);
		MergeSort(a,b,i+1,right);
		Merge(a,b,left,i,right);    //合并到数组b
		Copy(a,b,left,right);       //复制回数组a
	}	

}
void Merge(int a[],int b[],int left,int i,int right)
{
	int m=left,n=i+1,k=left,x;
	
	while(m<=i&&n<=right)
	{
		if(a[m]<a[n])
			b[k++]=a[m++];
		else
			b[k++]=a[n++];
	}
	if(m<=i)
	{
		for(x=m;x<=i;x++)
			b[k++]=a[x];
	}
	if(n<=right)
	{
		for(x=n;x<=right;x++)
			b[k++]=a[x];
	}
}

void Copy(int a[],int b[],int left,int right)
{
	int i;
	for(i=left;i<=right;i++)
	{
		a[i]=b[i];
	}

}
