/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include "stdio.h"
#include "stdlib.h"

#define READBUF_LENGTH 16
#define TRBUF_LENGTH 64

#ifdef DEBUG
volatile uint32 SysCntVal;
volatile uint32 debugregs[4] = {};
#endif

int main()
{
  CyGlobalIntEnable; /* Enable global interrupts. */

  /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  Control_Reg_PWM_Reset_Write(1);
  PWM_A_Start();
  Control_Reg_PWM_Reset_Write(0);
  
  UART_1_Start();
    ISR_PWM_TC_Start();
  
  char TransmitBuffer[TRBUF_LENGTH];
  char ReadBuffer[READBUF_LENGTH];
  char tmpchar;
  int readcnt = 0;
  uint8 deadcount = PWM_A_ReadDeadTime();
  
  sprintf(TransmitBuffer, "Dead Time count - 1 = %d\r\n", deadcount);
  UART_1_PutString(TransmitBuffer);

  for(;;)
  {
    /* Place your application code here. */
    #ifdef DEBUG
    // sprintf(TransmitBuffer, "%ld %ld %ld %ld\r\n", debugregs[0], debugregs[1], debugregs[2], debugregs[3]);
    // UART_1_PutString(TransmitBuffer);
    #endif

    if(UART_1_ReadRxStatus() & UART_1_RX_STS_FIFO_NOTEMPTY){
      tmpchar = UART_1_ReadRxData();
      if(isprint((unsigned char)tmpchar)){
        ReadBuffer[readcnt++] = tmpchar;
        if(readcnt == READBUF_LENGTH) readcnt = 0;
      } else if(tmpchar == '\n'){
        ReadBuffer[readcnt++] = '\0';
        
        deadcount = (uint8) strtol(ReadBuffer, NULL, 10);
        PWM_A_WriteDeadTime(deadcount);
        
        sprintf(TransmitBuffer, "Dead Time count - 1 = %d\r\n", deadcount);
        UART_1_PutString(TransmitBuffer);   
        
        readcnt = 0;
      }
    }
  }
}

/* [] END OF FILE */
