#include <api.h>

extern void uartputc_sync(int c);

void runTask(void(*f)(void), uint64 t);


void f1(){
    const char *s = "AMAN\n";
	while(*s)
		uartputc_sync(*s++);
    uartputc_sync('\n');
}

void f2(){
    const char *s = "NISHANT\n";
	while(*s)
		uartputc_sync(*s++);
    uartputc_sync('\n');
}

void f3(){
    const char *s = "TAPI\n";
	while(*s)
		uartputc_sync(*s++);
    uartputc_sync('\n');
    while(1){}
}

void f4(){
    const char *s = "SAMI\n";
	while(*s)
		uartputc_sync(*s++);
    uartputc_sync('\n');
}

void f5(){
    const char *s = "xxxx\n";
	while(*s)
		uartputc_sync(*s++);
    uartputc_sync('\n');
}



void schedule(){
    while(1){
        print();
        // delay(1);

        runTask(f1, 1);
        runTask(f2, 1);
        runTask(f3, 1);
        runTask(f4, 1);
        runTask(f5, 1);
        // delay(1);
        // runTask(f1, 1);
    }

    
}