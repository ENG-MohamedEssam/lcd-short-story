#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LCD_interface.h"

#include <avr/delay.h>

u8 ch[12][8] =
{
		{0x0E,0x0E,0x15,0x0E,0x04,0x04,0x04,0x0A}, // Char stand 1
		{0x0E,0x0E,0x04,0x1F,0x04,0x04,0x04,0x0A}, // char stand 2
		{0x0E,0x0E,0x04,0x0E,0x15,0x04,0x04,0x0A}, // char stand 3
		{0x06,0x06,0x04,0x0F,0x14,0x04,0x06,0x08}, // char walk 1
		{0x06,0x06,0x04,0x0E,0x15,0x04,0x04,0x0A}, // char walk 2
		{0x06,0x06,0x15,0x0E,0x04,0x04,0x04,0x0A}, // char walk 3
		{0x0E,0x0E,0x05,0x0E,0x14,0x04,0x04,0x0A}, // greet left 1
		{0x0E,0x0E,0x04,0x0E,0x15,0x04,0x04,0x0A}, // greet left 2
		{0x0C,0x0C,0x14,0x0E,0x05,0x04,0x04,0x0A}, // greet right 1
		{0x0C,0x0C,0x04,0x0E,0x15,0x04,0x04,0x0A}, // greet right 2
		{0x00,0x0E,0x0E,0x05,0x06,0x04,0x0E,0x1A}, // propse
		{0x00,0x00,0x00,0x0A,0x15,0x11,0x0A,0x04}  // Heart
};

u8 ArNam1[4][8]=
{
	{0x00,0x00,0x00,0x01,0x1F,0x00,0x0C,0x00},
	{0x00,0x00,0x00,0x02,0x1F,0x00,0x04,0x00},
	{0x00,0x00,0x08,0x02,0x1F,0x00,0x00,0x00},
	{0x00,0x0C,0x00,0x12,0x1F,0x00,0x00,0x00}
};
u8 ArNam2[5][8]=
{
	{0x00,0x05,0x05,0x05,0x1D,0x00,0x00,0x00},
	{0x00,0x04,0x00,0x0E,0x1F,0x00,0x00,0x00},
	{0x00,0x00,0x02,0x02,0x0F,0x00,0x00,0x00},
	{0x00,0x02,0x02,0x02,0x0A,0x08,0x10,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x01}
};

void walk(void);
void stand1(void);
void stand2(void);
void stand3(void);
void greet1(void);
void greet2(void);
void stand4(void);

u16 delay = 1000;

int main (void)
{
	DIO_u8Init();
	LCD_voidInit();
	u8 Yindex = 12;

	while (1)
	{
		stand1();
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("Hey");
		_delay_ms(delay);
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("My Name is");
		_delay_ms(delay);
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("Mohamed      ");
		_delay_ms(500);
		stand3();
		stand1();
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("Who's She ?");
		_delay_ms(delay);
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("I'll go talk to");
		_delay_ms(delay);
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("Her             	 	 	   ");
		_delay_ms(delay);
		LCD_u8GoToXY(0,0);
		LCD_voidClear();
		stand3();
		walk();
		stand3();
		stand2();
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("Will You Marry");
		_delay_ms(delay);
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("Me ?           ");
		LCD_voidWriteSpecialCharacter(ch[11],6,0,13);
		stand4();
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("          Sorry");
		_delay_ms(delay);
		LCD_u8GoToXY(0,0);
		LCD_voidWriteString("         but NO!");
		_delay_ms(delay*4);
		LCD_voidClear();
		LCD_voidWriteString("                                                                                                         ");
		for (int i = 0; i < 4; i ++)
		{
			if (Yindex > 15){Yindex = 12;}
			LCD_voidWriteSpecialCharacter(ArNam1[3-i],i,0,Yindex);
			Yindex ++;
		}
		_delay_ms(delay*2);
		LCD_voidClear();
		Yindex = 11;
		for (int i = 0; i < 5; i ++)
		{
			if (Yindex > 15){Yindex = 11;}
			LCD_voidWriteSpecialCharacter(ArNam2[4-i],i,0,Yindex);
			Yindex ++;
		}
		Yindex = 12;
		_delay_ms(delay*2);
		LCD_voidClear();
		LCD_voidWriteString("     The End");
		_delay_ms(delay*4);
		LCD_voidClear();
	}

	return 0;
}

void stand1(void)
{
	for (int i = 0; i < 3; i++)
	{
		LCD_voidWriteSpecialCharacter(ch[i],i,1,0);
		_delay_ms(delay);
	}
}

void stand2(void)
{
	for (int i = 0; i < 3; i++)
	{
		LCD_voidWriteSpecialCharacter(ch[i],i,1,13);
		_delay_ms(delay);
	}
}

void walk(void)
{
	u8 i = 3;
	for (int j = 1; j < 14; j++)
	{
		LCD_voidClear();
		LCD_voidWriteSpecialCharacter(ch[i],i,1,j);
		i++;
		if (i == 6){i = 3;}
		_delay_ms(delay/2);
	}
}

void stand3(void)
{
	for (int i = 0; i < 3; i++)
	{
		LCD_voidWriteSpecialCharacter(ch[i],i,1,15);
		_delay_ms(delay);
	}
}

void greet1(void)
{
	for (int i = 6; i < 8; i++)
	{
		LCD_voidWriteSpecialCharacter(ch[i],i,1,13);
		_delay_ms(delay);
	}
}

void greet2(void)
{
	for (int i = 8; i < 10; i++)
	{
		LCD_voidWriteSpecialCharacter(ch[i],0,1,15);
		_delay_ms(delay);
	}
}
void stand4(void)
{
	LCD_voidWriteSpecialCharacter(ch[10],4,1,13);
	_delay_ms(delay*2);
}
