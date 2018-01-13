#include<stdio.h>
void Merge(int a[],int p,int q,int r);
void MergeSort(int a[],int p,int r);
int main(){
	int a[10]={3,5,9,4,6,7,8,0,2,1};
	int i;
	printf("before sort:");
	for(i=0;i<10;i++)
	{
		printf("%3d",a[i]);
	}
	MergeSort(a,1,10);
	printf("\nafter  sort:");
	for(i=0;i<10;i++)
	{
		printf("%3d",a[i]);
	}
	return 0;	
}
void Merge(int a[],int p,int q,int r)
{
	int n1,n2,i,j,k;
	n1=q-p+1;
	n2=r-q;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=a[p+i-1];
	}
	for(j=0;j<n2;j++){
		R[j]=a[q+j];
	}
	i=0;
	j=0;
	k=p-1;
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			a[k++]=L[i++];
		}
		else{
			a[k++]=R[j++];
		}
	}
	while(i<n1){
		a[k++]=L[i++];
	}
	while(j<n2){
		a[k++]=R[j++];
	}
}
void MergeSort(int a[],int p,int r)
{
	if(p<r){
		int q=(p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
}
