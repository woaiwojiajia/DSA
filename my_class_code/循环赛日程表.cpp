#include<stdio.h>

#include<Windows.h>
#define MAXN 64
int a[MAXN+1] [MAXN+1]={0};
void gamecal(int k,int n)		//处理编号k开始的n个选手的日程 
{
	int i,j;
	if(n==2){			//递归终止的条件，只剩两个人来直接安排 
		a[k][1]=k;		//参赛选手编号
		a[k][2]=k+1;	//对阵选手编号
		a[k+1][1]=k+1;	//参赛选手编号
		a[k+1][2]=k;	//对阵选手编号		 
	} 
	else{				
		gamecal(k,n/2);			 //将参赛选手递归分成两部分 
		gamecal(k+n/2,n/2);			//同上 
		for(i=k;i<k+n/2;i++){		//将左下角的数据填到右上角 
			for(j=n/2+1;j<=n;j++){
				a[i][j]=a[i+n/2][j-n/2];
			}
		} 
		for(i=k+n/2;i<k+n;i++){		//将左上角的数据填到右下角 
			for(j=n/2+1;j<=n;j++){
				a[i][j]=a[i-n/2][j-n/2];
			}
		}
	} 
} 

int main(){
	int m,i,j;
	printf("输入参赛选手人数：");
	scanf("%d",&m);
	j=2;
	for(i=2;i<8;i++){
		j*=2;
		if(j==m)break;
	}
	if(i>=8){
		printf("参赛选手人数必须为2的整数次幂，且不超过64\n");
		system("pause");
		return 0;
	}
	gamecal(1,m);
	printf("\n编号\t"); 
	for(i=2;i<=m;i++){
		printf("%d天\t",i-1); 
	} 
	printf("\n");
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n\n");
	} 
	system("pause");
	return 0;
}
