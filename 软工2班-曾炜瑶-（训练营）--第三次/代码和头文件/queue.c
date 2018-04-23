#include<stdio.h>
#include <malloc.h>
#include"queue.h"
#include<string.h>

void InitAQueue(AQueue *Q)
{
  Q->rear=Q->front=0;


}
void DestoryAQueue(AQueue *Q)
{
  if(IsEmptyAQueue(Q)!=TRUE)
    ClearAQueue(Q);
  free(Q);


}
Status IsFullAQueue(AQueue *Q)
{
  if(Q->rear == (Q->rear+1)%MAXQUEUE)
    return TRUE;
  else return FALSE;
}

Status IsEmptyAQueue(AQueue *Q)
{
  return (Q->rear == Q->front?TRUE:FALSE);
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
  if(IsEmptyAQueue(Q)!=TRUE && e!=NULL)
  {
    int *e = (int*)Q->data[Q->front];
  }
  return TRUE;
}

int LengthAQueue(AQueue *Q)
{
  int count;
  count = (Q->rear-Q->front);
  return count;
}

Status EnAQueue(AQueue *Q, void *data)
{
  if((Q->rear+1)%MAXQUEUE == Q->front)
  {
    printf("already full!\n");
    return FALSE;
  }
  void* elemAddr = (char*)(*(Q->data)+(Q->rear)*(Q->data_size));
  memcpy(elemAddr,data,Q->data_size);
  Q->rear = (Q->rear+1)%MAXQUEUE;
  return TRUE;
}
Status DeAQueue(AQueue *Q)
{
  if(IsEmptyAQueue(Q))
    return FALSE;
  Q->front = (Q->front+1)%MAXQUEUE;
  return TRUE;
}

void ClearAQueue(AQueue *Q)
{
  Q->rear=Q->front=0;
}

Status TraverseAQueue(AQueue *Q, void (*foo)(void *q))
{
  if((*Q->data) == NULL)
    return FALSE;
  foo((void*)Q);
}

void APrint(void *q)
{
  AQueue *Q = (AQueue *)q;
  int i = Q->front;
  while(i!=Q->rear)
  {

    switch(Q->data_size)
    {
      case 1:
        while(i !=Q->rear)
        {
          printf("%c ",*(char*)(*(Q->data+i)));
          i++;
        }
        break;
      case 4:
        while(i !=Q->rear)
        {
          printf("%d ",*(int*)(*(Q->data+i)));
          i++;
        }
        break;
      case 8:
        while(i !=Q->rear)
        {
          printf("%lf ",*(double*)(*(Q->data+i)));
          i++;
        }
        break;
    }

  }
  printf("\n");
}

