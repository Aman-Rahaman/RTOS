#include <scheduler.h>
#include <types.h>
#include <csr.h>

char kstack[4096];


// void (*saved_ra)();
// void (*saved_sp)();
uint64 saved_ra;
uint64 saved_sp;
uint64 TRAPFRAME[32];



extern void uartputc_sync(int c);
void timer_interrupt();


void kernelvec();
void kernelvec2();




void print(){
  char* s = "Hello World\n";
  while(*s){
    uartputc_sync(*s++);
  }
}


#define MIE_STIE (1L << 5)  // supervisor timer
int kmain() {

  unsigned long x = r_mstatus();
  w_mstatus(x | (1<<3)); // mie bit is at index 3

  // w_mtvec((uint64)kernelvec);

  w_mtvec((uint64)kernelvec2);


  schedule();



	return 0;
}


#define MSTATUS_SIE (1L << 1)  // Supervisor Interrupt Enable
#define MSTATUS_MIE (1L << 3)  
// enable device interrupts
static inline void
intr_on()
{
  w_mstatus(r_mstatus() | MSTATUS_SIE);
  w_mstatus(r_mstatus() | MSTATUS_MIE);
}

// disable device interrupts
// static inline 
void
intr_off()
{
  w_mstatus(r_mstatus() & ~MSTATUS_SIE);
  w_mstatus(r_mstatus() & ~MSTATUS_MIE);
}



void enable_timer_interrupt(){
  w_mie(r_mie() | MIE_STIE);
}

void disable_timer_interrupt(){
  w_mie(r_mie() & ~MIE_STIE);
}




void
set_timer_interrupt_at(uint64 x)
{
  intr_off();
  enable_timer_interrupt();

  w_stimecmp(r_time() + (10000000*x));
  // w_stimecmp(r_time() + x);
  intr_on();
}

void
timer_interrupt_handler()
{
  
  intr_off();
  print();

  disable_timer_interrupt();
  intr_on();
  
  // w_stimecmp(r_time() + 10000000);
  // asm volatile("wfi");
}






