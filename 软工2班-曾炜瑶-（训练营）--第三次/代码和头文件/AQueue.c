#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


int main()
{

  int* data = NULL;
  void* e = NULL;
  int i=0,l,n;
  int a;
  float b;
  char c;
  AQueue *Q;
  Q=(AQueue *)malloc(sizeof(AQueue));
  printf("input the size.\n");
  scanf("%d",&(Q->data_size));
  printf("the size you input:%d\n",Q->data_size);
  InitAQueue(Q);
  printf("welcome!please input the number.PS:input -1 if you want to stop.\n");
  printf("==================\n");
  printf("1.enqueue\n");
  printf("2.delete\n");
  printf("3.destroy\n");
  printf("4.gethead\n");
  printf("5.length\n");
  printf("6.clear\n");
  printf("7.print\n");
  printf("==================\n");
  printf("number:");
  scanf("%d",&n);
  fflush(stdin);
  while(n!=-1)
  {
    fflush(stdin);
    switch(n)
    {
      case 1:
      {
        fflush(stdin);
        switch(Q->data_size)
        {
          case 1:
            scanf("%c",&c);
            EnAQueue(Q,&c);
            break;
          case 4:
            scanf("%d",&a);
            EnAQueue(Q,&a);
            break;
          case 8:
            scanf("%lf",&b);
            EnAQueue(Q,&b);
            break;
          default:
            printf("ERROR.\n");
        }

        break;
      }
      case 2:
      {
        DeAQueue(Q);
        break;
      }
      case 3:
      {
        DestoryAQueue(Q);
        break;
      }
      case 4:
      {
        GetHeadAQueue(Q,e);
        break;
      }
      case 5:
      {
        printf("length=%d\n",LengthAQueue(Q));
        break;
      }
      case 6:
      {
        ClearAQueue(Q);
        break;
      }
      case 7:
      {
        TraverseAQueue(Q,APrint);
        break;

      }
      default:
        printf("not a available number.put another.\n");
    }
    printf("number:");
    scanf("%d",&n);
  }



  return 0;
}
