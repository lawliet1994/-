#include <reg52.h>
#include <intrins.h>

#define KEY_PRESS P1
#define NUM_DISPLAY P0

typedef unsigned char u8;
typedef unsigned int u16;

u8 lastnum;

u8 code array[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay(u16 i)
{
	while(i--)
	{
	
	}
}

void key_display(void)
{
	char a = 0 ; 
	KEY_PRESS = 0x0f ;
	if (KEY_PRESS != 0x0f)
	{
		delay(1000);
		if (KEY_PRESS != 0x0f)
		{
			switch(KEY_PRESS)
			{
				case(0x07) : lastnum = 0 ;break ;
				case(0x0b) : lastnum = 1 ;break ;
				case(0x0d) : lastnum = 2 ;break ;
				case(0x0e) : lastnum = 3 ;break ;
			}

			KEY_PRESS = 0xf0 ;

			switch(KEY_PRESS)
			{
				case(0x70) : lastnum = lastnum ;break ;
				case(0xb0) : lastnum = lastnum + 4 ;break ;
				case(0xd0) : lastnum = lastnum + 8 ;break ;
				case(0xe0) : lastnum = lastnum + 12 ;break ;
			}
			while((a<50) && (KEY_PRESS == 0xf0))
			{
				delay(1000);
				a++;	
			}
		}
	}	
}


void main()
{
	while(1)
	{
		key_display();
		NUM_DISPLAY=~array[lastnum];
	}
}