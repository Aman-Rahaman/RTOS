#include <kernel.h>

void runTask(void (*f)(void), int t);

void delay(uint64 t);

void write();

void read();