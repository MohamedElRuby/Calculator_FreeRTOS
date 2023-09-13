#include "STD_TYPES.h"
#include "LCD_Interface.h"
#include "KPD_interface.h"
#include "DIO_Interface.h"
#include "Calculator.h"

u8 str[40];
u8 str_count=0;
u8 eq_flag=0;
s32 numbers_arr[20]={0};
u8 operations_arr[20];
u8 numbers_arr_count=0;
u8 operations_arr_count=0;
s32 result=0;
u8 clear_flag;

void Calculator_voidInit(void)
{
}

void Calculator_voidGetString(void)
{
	static u8 op_flag=0;
	static u8 sign_flag=0;
	u8 key=KPD_u8GetPressedKey();
	if(key!=0)
	{
		if(clear_flag==1)
		{
			clear_flag=0;
			numbers_arr_count=0;
			operations_arr_count=0;
			str_count=0;
			result=0;
			for(int i=0;str[i];i++)
			{
				str[i]=0;
			}
			for (int i=0;i<20;i++)
			{
				numbers_arr[i]=0;
				operations_arr[i]=0;
			}
			GoToXY(0,0);
			LCD_SendString("                     ");
			GoToXY(1,0);
			LCD_SendString("                     ");
			GoToXY(3,0);
			LCD_SendString("                     ");
		}
		if (str_count==0)
		{
			if ((key>='0'&&key<='9'))
			{
				str[str_count]=key;
				str_count++;
			}
			else if (key=='-')
			{
				str[str_count]=key;
				str_count++;
				sign_flag=1;
			}
		}
		else if(str_count>0)
		{
			if ((key>='0'&&key<='9'))
			{
				str[str_count]=key;
				str_count++;
				sign_flag=1;
				op_flag=0;
			}
			else if ((key=='/'||key=='*'||key=='-'||key=='+')&&op_flag==0)
			{
				str[str_count]=key;
				str_count++;
				op_flag=1;
				sign_flag=0;
			}
			else if(sign_flag==0&&key=='-'&&op_flag==1)
			{
				str[str_count]=key;
				str_count++;
				sign_flag=1;
			}
			else if ((key=='/'||key=='*'||key=='-'||key=='+')&&op_flag==1&&sign_flag==0)
			{
				str_count--;
				str[str_count]=key;
				str_count++;
			}
			else if (key=='c')
			{
				str_count--;
				str[str_count]=0;
				if((str[str_count-2]=='*'||str[str_count-2]=='/'||str[str_count-2]=='-'||str[str_count-2]=='+')&&str[str_count-1]=='-')
				{
					sign_flag=1;
					op_flag=1;
				}
				else if(str[str_count-1]=='*'||str[str_count-1]=='/'||str[str_count-1]=='-'||str[str_count-1]=='+')
				{
					sign_flag=0;
					op_flag=1;
				}
				
				
			}
			
		}
		if(str_count==40||key=='=')
		{
			eq_flag=1;
		}
		
	}
}

void Calculator_voidAnalysisString(void)
{
	s32 sign_flag=0;
	for (int i=0;i<str_count;i++)
	{
		if(str[i]=='-'&&i==0)
		{
			sign_flag=1;
		}
		else if ((str[i]=='-')&&(str[i-1]=='*'||str[i-1]=='/'||str[i-1]=='-'||str[i-1]=='+'))
		{
			sign_flag=1;
		}
		else if (str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-')
		{
			operations_arr[operations_arr_count]=str[i];
			if (sign_flag==1)
			{
				numbers_arr[numbers_arr_count]=numbers_arr[numbers_arr_count]*-1;
				sign_flag=0;
			}
			operations_arr_count++;
			numbers_arr_count++;
		}
		else if (str[i]>='0'&&str[i]<='9')
		{
			numbers_arr[numbers_arr_count]=(((s32)numbers_arr[numbers_arr_count]*(s32)10)+(s32)(str[i]-'0'));
		}

	}
	if (sign_flag==1)
	{
		numbers_arr[numbers_arr_count]=numbers_arr[numbers_arr_count]*-1;
		sign_flag=0;
	}
		
}

void Calculator_voidCalculate(void)
{
	s8 index=-1;
	u8 switch_flag=0;
	while(operations_arr_count!=0)
	{
		if (switch_flag==0)
		{
			for (u8 i=0;i<operations_arr_count;i++)
			{
				switch_flag=1;
				if(operations_arr[i]=='*')
				{
					numbers_arr[i]=numbers_arr[i]*numbers_arr[i+1];
					index=i;
					operations_arr_count--;
					switch_flag=0;
					break;
				}
				else if(operations_arr[i]=='/')
				{
					numbers_arr[i]=numbers_arr[i]/numbers_arr[i+1];
					index=i;
					operations_arr_count--;
					switch_flag=0;
					break;
				}
			}
		}
		else
		{
			for (u8 i=0;i<operations_arr_count;i++)
			{
				switch_flag=1;
				if(operations_arr[i]=='+')
				{
					numbers_arr[i]=numbers_arr[i]+numbers_arr[i+1];
					index=i;
					operations_arr_count--;
					switch_flag=0;
					break;
				}
				else if(operations_arr[i]=='-')
				{
					numbers_arr[i]=numbers_arr[i]-numbers_arr[i+1];
					index=i;
					operations_arr_count--;
					switch_flag=0;
					break;
				}
			}
		}
		
		if(index!=-1)
		{
			for (u8 i=index;i<operations_arr_count;i++)
			{
				operations_arr[i]=operations_arr[i+1];
			}
			for(u8 i=index+1;i<=operations_arr_count;i++)
			{
				numbers_arr[i]=numbers_arr[i+1];
			}
			index=-1;
		}
	}
	result=numbers_arr[0];
	
}
void Calculator_voidRunable(void)
{
	Calculator_voidGetString();
	GoToXY(0,0);
	LCD_SendString(str);
	LCD_SendString(" ");
	if (eq_flag==1)
	{
		Calculator_voidAnalysisString();
		Calculator_voidCalculate();
		GoToXY(0,0);
		LCD_sendChar('=');
		LCD_voidWriteNumber(result);
		clear_flag=1;
		eq_flag=0;
	}
	
}


