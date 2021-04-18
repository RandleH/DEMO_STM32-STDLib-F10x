

#include "delay.h"
#include "cpu.h"  
#include "os.h"
#include "lib_mem.h"
#include "cpu_core.h"
#include "system_stm32f10x.h"

OS_ERR          OS_err_code;

OS_TCB          TCB_Task_1;
CPU_STK         STK_Task_1[32];
void FUN_Task_1(void* param){
    //...//
    while(1){
        //...//
    }
}

OS_TCB          TCB_Task_2;
CPU_STK         STK_Task_2[32];
void FUN_Task_2(void* param){
    //...//
    while(1){
        //...//
    }
}


int main(void)
{
    delay_init(72);

    Mem_Init();

    OSInit(&OS_err_code);    
    CPU_Init(); 
    
    OS_CPU_SysTickInit(SystemCoreClock / (CPU_INT32U)OSCfg_TickRate_Hz);
    
    OSTaskCreate((OS_TCB     *)&TCB_Task_1,                  /* Create the task                 */
                 (CPU_CHAR   *)"TASK_1",
                 (OS_TASK_PTR ) FUN_Task_1,
                 (void       *) 0,
                 (OS_PRIO     ) 3,
                 (CPU_STK    *)&STK_Task_1[0],
                 (CPU_STK_SIZE) sizeof(STK_Task_1) / 10,     /* 90% of Stack Memory is available */
                 (CPU_STK_SIZE) sizeof(STK_Task_1),
                 (OS_MSG_QTY  ) 5u,
                 (OS_TICK     ) 0u,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK ),
                 (OS_ERR     *)&OS_err_code);

    OSTaskCreate((OS_TCB     *)&TCB_Task_2,                  /* Create the task                 */
                 (CPU_CHAR   *)"TASK_2",
                 (OS_TASK_PTR ) FUN_Task_2,
                 (void       *) 0,
                 (OS_PRIO     ) 3,
                 (CPU_STK    *)&STK_Task_2[0],
                 (CPU_STK_SIZE) sizeof(STK_Task_2) / 20,     /* 80% of Stack Memory is available */
                 (CPU_STK_SIZE) sizeof(STK_Task_2),
                 (OS_MSG_QTY  ) 5u,
                 (OS_TICK     ) 0u,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK ),
                 (OS_ERR     *)&OS_err_code);


    OSStart(&OS_err_code);
                 

}



