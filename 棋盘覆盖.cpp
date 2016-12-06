//author 赵双全
#include <iostream>
#define BoardSize 4
using namespace std; 

int Board[BoardSize][BoardSize];

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
	if(size==1)
	return ;
	static int tile=1;
	int t=tile++;  //L型骨牌号 
	int s=size/2;  //分割棋盘 
	//覆盖左上角的子棋盘 
	if(dr<tr+s&&dc<tc+s)  // 特殊方格在此棋盘中 
		ChessBoard(tr,tc,dr,dc,s);
	else  //这个棋盘中没有特殊方格 
	{
		Board[tr+s-1][tc+s-1]=t;
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	
	if(dr<tr+s&&dc>=tc+s)
		ChessBoard(tr,tc+s,dr,dc,s);
	else
	{
		Board[tr+s-1][tc+s]=t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	
	if(dr>=tr+s&&dc<tc+s)
		ChessBoard(tr+s,tc,dr,dc,s);
	else
	{
		Board[tr+s][tc+s-1]=t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	
	if(dr>=tr+s&&dc>=tc+s)
		ChessBoard(tr+s,tc+s,dr,dc,s);
	else
	{
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
		Board[tr+s][tc+s]=t;
	}
}

int main()
{
	Board[2][2]=0;
	ChessBoard(0,0,3,3,BoardSize);
	for(int i=0;i<BoardSize;i++)
	{
		for(int j=0;j<BoardSize;j++)
			cout<<" "<<Board[i][j];
			cout<<endl;
	}
}
