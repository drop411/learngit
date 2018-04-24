#include <reg52.h>
#include <intrins.h>


typedef unsigned char u8;
typedef unsigned int u16;


sbit gBuz = P1^5;


void BuzzerOnOff(void);
void delay1ms(void);



void BuzzerOnOff(void)
{
  gBuz = 1;
  delay1ms();
  gBuz = 0;
  delay1ms();
}


void delay1ms(void)
{
  unsigned char a,b,c;
  for(c=1; c>0; c--)
    for(b=142; b>0; b--)
      for(a=2; a>0; a--);
}

void main()
{
   while(1)
     BuzzerOnOff() ;

}

