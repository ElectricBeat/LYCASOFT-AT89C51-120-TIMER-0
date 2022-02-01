#include <regx51.h>
void T0_delay(unsigned int i)
{                        
	int c=0;
  while(c<i)
  {
		TMOD=0x01;			//Timer 0 is in use. 16-bit Timer Mode is selected.  
    TH0=0xFC;				//Load value for THx register
    TL0=0x66;				//Load value for TLx register
    TR0= 1;					//Run Timer-0
    while(!TF0);		//Poll TFx
    TR0=0;					//If TF=1 stop the timer by making TR=0
    TF0=0;					//Make TF=0 for next counting
    c++;
   }
}

void main()
{
	P2=0x00;
  while(1)
  {
		P2 = 0X01;
		T0_delay(500);
		P2 = 0X00;		
		T0_delay(500);
  }
}