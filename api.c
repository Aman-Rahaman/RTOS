#include <kernel.h>

extern void uartputc_sync(int c);

// extern void (*saved_ra)();
// extern void (*saved_sp)();

extern uint64 saved_ra;
extern uint64 saved_sp;


// static char digits[] = "0123456789abcdef";

// static void
// printint(long long xx, int base, int sign)
// {
//   char buf[16];
//   int i;
//   unsigned long long x;

//   if(sign && (sign = (xx < 0)))
//     x = -xx;
//   else
//     x = xx;

//   i = 0;
//   do {
//     buf[i++] = digits[x % base];
//   } while((x /= base) != 0);

//   if(sign)
//     buf[i++] = '-';

//   while(--i >= 0)
//     uartputc_sync(buf[i]);
// }


// void runTask(void (*f)(void), uint64 t){
//     saved_ra = (uint64)__builtin_return_address(0);
//     __asm__ volatile (
//         "addi sp, sp, -8\n" 
//         "sd s0, 0(sp)\n"    
//         "ld %0, 0(sp)\n"    
//         "addi sp, sp, 8\n"  
//         : "=r" (saved_sp)   
//         :                   
//         : "memory"          
//     );

//     printint((uint64)(saved_ra), 10, 0);
//     uartputc_sync('\n');
//     printint((uint64)(saved_sp), 10, 0);

//     set_timer_interrupt_at(t);

//     f();

//     while(1){}
    
//     return;
// }



void delay(uint64 t){
    saved_ra = (uint64)__builtin_return_address(0);
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