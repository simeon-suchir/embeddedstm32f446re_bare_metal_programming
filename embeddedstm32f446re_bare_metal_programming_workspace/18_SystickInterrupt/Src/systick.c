#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL 16000
#define CTRL_ENABLE (1U<<0)
#define CTRL_CLKSRC (1U<<2)
#define CTRL_COUNTFLAG (1U<<16)
#define ONE_SEC_LOAD 16000000
#define CTRL_TICKINT (1U<<1)


void systickDelayMs(int n){
	SysTick->LOAD = SYSTICK_LOAD_VAL;
	SysTick->VAL =0;
	SysTick->CTRL =  CTRL_ENABLE|CTRL_CLKSRC;

	for(int i=0;i<n;i++){
		while((SysTick->CTRL & CTRL_COUNTFLAG)==0){}
	}
	SysTick->CTRL =0;

}

void systick_1hz_interrupt(void){
	SysTick->LOAD = ONE_SEC_LOAD - 1;
	SysTick->VAL =0;
	SysTick->CTRL =  CTRL_ENABLE|CTRL_CLKSRC|CTRL_TICKINT;


}
