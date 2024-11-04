#include <kernel.h>
extern void (*saved_ra)();
extern void (*saved_sp)();

// void store_sp() {
//     // Inline assembly to store the value of a register (e.g., t0) into global_var
//     asm volatile (
//         "sw s0, %0"         // Store the value of t0 into the global variable
//         : /* no output operands */
//         : "m" (saved_sp)  // Input operand: address of global_var
//         : "t0"              // Clobber list: t0 is modified
//     );
// }



void runTask(void (*f)(void), uint64 t){
    saved_ra = __builtin_return_address(0);
    // asm volatile (
    //     "mv t0, s0\n"
    //     "sw t0, %0"         // Store the value of s0 into global_var
    //     : /* no output operands */
    //     : "m" (saved_sp)  // Input operand: address of global_var
    //     : "t0"              // Clobber list: s0 is modified
    // );

    set_timer_interrupt_at(t);

    f();

    while(1){}
    
    return;
}



void delay(uint64 t){
    saved_ra = __builtin_return_address(0);
    // asm volatile (
    //     "mv t0, s0\n"
    //     "sw t0, %0"         // Store the value of s0 into global_var
    //     : /* no output operands */
    //     : "m" (saved_sp)  // Input operand: address of global_var
    //     : "t0"              // Clobber list: s0 is modified
    // );

    set_timer_interrupt_at(t);

    while(1){}

    return;

    // uint64 target = r_time() + ( t * 10000 );
    // while( r_time() < target ){}

}

void write(){}

void read(){}