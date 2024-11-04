#include <api.h>

extern void uartputc_sync(int c);


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
}



// struct scheduler
// {
//     void()
// };


void schedule(){
    while(1){
        print();
        delay(1);

        runTask(f1, 2);

        runTask(f2, 2);

        runTask(f3, 2);

    }

    // print();
    // delay(1);
    // runTask(f2, 2);
    // runTask(f1, 2);

    
}