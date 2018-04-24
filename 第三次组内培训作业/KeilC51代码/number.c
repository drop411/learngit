#include <reg51.h>

#define uchar unsigned char

uchar display_code[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
uchar display_data[8]={0,0,0,0,0,0,0,0};   //倒着存放每一位的数字

void delay(void)
{
 uchar i;
 for(i=150;i>0;i--);
}

void display()
{
  uchar i,k;
  k=0x80;
  for(i=0;i<8;i++)
  {
  P2=0;
  P0=display_code[display_data[i]];
  P0=~P0;
  P2=k;
  k=k>>1; //改变数字显示位置
  delay();
  }
  P2=0;
}


void count()
{
 display_data[7]++;

 if(display_data[7]>9)
 {
     display_data[7]=0;
     display_data[6]++;
     if(display_data[6]>9)
    {
	     display_data[7]=0;
         display_data[6]=0;
		 display_data[5]++;
		  if(display_data[5]>9)
                {	
				     display_data[7]=0;
                     display_data[6]=0;  
                     display_data[5]=0;
		             display_data[4]++;

				}
		   
     }
  }
}


void main(void)
{
uchar i;
 while(1)
{
 for(i=0;i<250;i++)
  {
  display();
  }
   count();
 }
}