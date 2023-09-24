/*
	This file contains application callback hooks
*/

/** Header files inclusion **/
#include "FreeRTOS.h"
#include "task.h"

/** Callback Definitions **/
void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName )
{
	while(1);
}

void vApplicationMallocFailedHook( void )
{
	while(1);
}
