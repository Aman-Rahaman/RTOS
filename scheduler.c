#include <api.h>

extern void uartputc_sync(int c);

void runTask(void(*f)(void), uint64 t);
void delay(uint64 t);

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


void f1(){
    const char *s = "\nAMAN\n";
	while(*s)
		uartputc_sync(*s++);
    uartputc_sync('\n');
}

void f2(){
    const char *s = "\nNISHANT\n";
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
        delay(2);

        runTask(f1, 1);
        runTask(f2, 1);
        runTask(f3, 1);
        runTask(f4, 1);
        runTask(f5, 1);
        delay(1);
        runTask(f1, 1);
    }

    
}