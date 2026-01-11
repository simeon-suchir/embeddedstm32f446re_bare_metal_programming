#include <stdio.h>
#include "stm32f4xx.h"
#include <stdint.h>

int main(void){
	uar2_tx_init();
	while(1){
		printf("Hello this is Sim.....\n\r");
 	}
}



