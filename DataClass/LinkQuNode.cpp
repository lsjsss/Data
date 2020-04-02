// Created by lsjss on 2020/4/3.
#include <iostream>
#include <malloc.h>
using namespace std;

#define MaxSize 50
typedef int ElemType;

//单链表中数据结点类型DataNode声明
typedef struct qnode
{
    ElemType data;	//数据元素
    struct qnode *next;
} DataNode;

//链队中头结点类型LinkQuNode声明
typedef struct
{  DataNode *front;	//指向单链表队头结点
    DataNode *rear; 	//指向单链表队尾结点
}  LinkQuNode;

//初始化队列
void InitQueue(LinkQuNode *&q)
{  q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL;
}

//销毁队列
void DestroyQueue(LinkQuNode *&q)
{
    DataNode *p=q->front, *r;  	//p指向队头数据结点
    if  (p!=NULL)			//释放数据结点占用空间
    {  r=p->next;
        while (r!=NULL)
        {  free(p);
            p=r;r=p->next;
        }
    }
    free(p);  free(q);		 	//释放链队结点占用空间
}

//判断队列是否为空
bool QueueEmpty(LinkQuNode *q)
{
    return(q->rear==NULL);
}

//进队
void enQueue(LinkQuNode *&q，ElemType e)
{
    DataNode *p;
    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if (q->rear==NULL)   //若链队为空，新结点是队首结点又是队尾结点
        q->front=q->rear=p;
    else
    {
        q->rear->next=p; //将p结点链到队尾，并将rear指向它
        q->rear=p;
    }
}

//出队
bool deQueue(LinkQuNode *&q，ElemType &e)
{
    DataNode *t;
    if (q->rear==NULL) return false;	//队列为空
        t=q->front;		   		//t指向第一个数据结点
    if (q->front==q->rear)  		//队列中只有一个结点时
        q->front=q->rear=NULL;
    else			   		//队列中有多个结点时
        q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}










