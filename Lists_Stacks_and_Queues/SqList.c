#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 50   //线性表存储空间的初始分配量
#define LISTINCREMENT 10    //线性表存储空间的分配增量

typedef int ElemType;       //存储单元类型

typedef struct {
    ElemType *elem;         //存储空间基址
    int length;             //当前长度
    int listsize;           //当前分配的存储容量（以sizeof(EleType)为单位）
}SqList;

/**
*创建顺序表
*/
SqList CreateList_Sq()
{
    SqList* list=(SqList*)malloc(sizeof(SqList));      //创建顺序表
    return *list;
}

/**
*初始化顺序表
*返回1 表示初始化成功
*返回0 表示初始化失败
*/
int InitList_Sq(SqList* L)
{
    L->elem=(ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);  //创建动态数组并把地址赋给顺序表基址
    if(!L->elem)    //存储分配失败
        return 0;
    L->length=0;    //空表长度位0
    L->listsize=LIST_INIT_SIZE;   //初始存储容量
    return 1;
}

/**
*在顺序线性表L中第i个位置之前插入新的元素e
*i的合法值为1<=i<=ListLength_Sq(L)+1
*/
int ListInsert_Sq(SqList* L,int i,ElemType e)
{
    if(i<1||i>L->length+1)  //i值不合法
        return 0;
    if(L->length==L->listsize)     //当前存储空间已满，增加分配
    {
        ElemType* newbase=(ElemType*)realloc(L->elem,sizeof(ElemType)*(L->listsize+LISTINCREMENT));
        if(!newbase)     //存储分配失败
            return 0;
        L->elem=newbase;    //新基址
        L->listsize+=LISTINCREMENT;    //增加容量
    }
    ElemType* q=&(L->elem[i-1]);    //q为插入位置
    ElemType* p=0;
    for(p=&(L->elem[L->length-1]);p>=q;--p)   //插入位置及之后的元素右移
        *(p+1)=*p;
    *q=e;    //插入e
    ++L->length;   //表长增1
    return 1;
}

/*
*在顺序线性表L中删除第i个元素，并用e返回其值
*i的合法值为1<=i<=ListLength_Sq(L)
*/
int ListDelete_Sq(SqList* L,int i,ElemType *e)
{
    if((i<1)|| (i>L.length))
        return 0;   //i值不合法
    p=&L->elem[i-1];   //p为被删除元素的位置
    e=*p;              //被删除元素的值赋给e
    q=L->elem+L->length-1;   //表尾元素的位置
    for(++p;p<=q;++p)        //被删除元素之后的元素左移
        *(p-1)=*p;
    --L->length;             //表长减1
    return 1;
}

int main()
{
    SqList list=CreateList_Sq();
    InitList_Sq(&list);
    
    int i;
    for(i=0;i<100;i++)
	{
		ListInsert_Sq(&list,i+1,i+1);
	}
	for(i=0;i<100;i++)
	{
		printf("%d\t",list.elem[i]);
		if((i+1)%5==0)
			printf("\n");
	}
    return 0;
}
