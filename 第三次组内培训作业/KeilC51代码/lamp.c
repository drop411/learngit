
#include <reg52.h>
#define LED_PORT			P2

void Delay(void);
void FlashLed1(void);
void FlashLed2(void);


void main(void)
{
  while (1)
  {

    FlashLed();
  }
}


void Delay(void)
{
  unsigned char i = 0, j = 0, k = 0;

  for (i=0; i<50; i++)
    for (j=0; j<50; j++)
      for (k=0; k<50; k++);
}


void FlashLed(void)
{
  unsigned char i = 0;

  for (i=0; i<5; i++)
  {
    LED_PORT  = (0xff & ~(1<<i));
    Delay();
  }
}





