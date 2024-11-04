#include <kernel.h>
extern void (*saved_ra)();
extern void (*saved_sp)();



void runTask(void (*f)(void), uint64 t){
    saved_ra = __builtin_return_address(0);
    __asm__ volatile (
        "addi sp, sp, -8\n" 
        "sd s0, 0(sp)\n"    
        "ld %0, 0(sp)\n"    
        "addi sp, sp, 8\n"  
        : "=r" (saved_sp)   
        :                   
        : "memory"          
    );

    set_timer_interrupt_at(t);

    f();

    while(1){}
    
    return;
}



void delay(uint64 t){
    saved_ra = __builtin_return_address(0);
    __asm__ volatile (
        "addi sp, sp, -8\n" 
        "sd s0, 0(sp)\n"    
        "ld %0, 0(sp)\n"    
        "addi sp, sp, 8\n"  
        : "=r" (saved_sp)   
        :                   
        : "memory"          
    );

    set_timer_interrupt_at(t);

    while(1){}

    return;


}

void write(){}

void read(){}