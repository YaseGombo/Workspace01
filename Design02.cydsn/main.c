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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    int32 i, ans;
    char buffer[32];
    
    UART_1_Start();
    UART_1_PutString("COM Port Open");
  
    for(i = 0; i < 4; i++)
    {
        /* Place your application code here. */
      ans = i / 4;
      sprintf(buffer, "%ld / 4 = %ld\r\n", i, ans);
      UART_1_PutString(buffer);
    }
    
    for(; ; i--){
      ans = i / 4;
      sprintf(buffer, "%ld / 4 = %ld\r\n", i, ans);
      UART_1_PutString(buffer);
    }
}

/* [] END OF FILE */
