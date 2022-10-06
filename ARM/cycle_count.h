/* --------------------------BRIEFING-------------------------- */
/* This header contains register mapping and function-like macros regarding    */
/* the DWT register that every Cortex M3-M4-M7 has, and allows us to easily    */
/* measure time execution of portions of our code, with very little overhead   */

#ifndef CYCLE_COUNT_H
#define CYCLE_COUNT_H
    
    /*----------------- REGISTER MAPPING -----------------*/

    /* Control register DWT  */
    #define DWT_CONTROL             (*((volatile uint32_t*)0xE0001000))
     
    /* CYCCNTENA bit */
    #define DWT_CYCCNTENA_BIT       (1UL<<0)
        
    /* DWT Cycle Counter register */
    #define DWT_CYCCNT              (*((volatile uint32_t*)0xE0001004))
        
    /* DEMCR: "Debug Exception and Monitor Control Register" */
    #define DEMCR                   (*((volatile uint32_t*)0xE000EDFC))

    /* Trace enable bit in DEMCR register */
    #define TRCENA_BIT              (1UL<<24)


    /*-----------------  FUNCTION-LIKE MACROS  -----------------*/
    
    #define InitCycleCounter()      DEMCR |= TRCENA_BIT 
       
    #define ResetCycleCounter()     DWT_CYCCNT = 0 

    #define StartCycleCounter()     DWT_CONTROL |= DWT_CYCCNTENA_BIT 

    #define StopCycleCounter()      DWT_CONTROL &= ~DWT_CYCCNTENA_BIT 

    #define GetCycleCounter()       ( DWT_CYCCNT )
    
#endif
