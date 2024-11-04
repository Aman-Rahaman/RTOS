
.globl kerneltrap
.globl kernelvec
.align 4
kernelvec:

        # call the C trap handler in kernel.c
        #call timer_interrupt_handler
        
        # return to whatever we were doing in the kernel.
        #mret


        #lw sp, saved_sp
        
        call intr_off

        # Load the return address from the global variable saved_ra
        la a1, saved_ra    # Load the address of saved_ra into a1
        ld ra, 0(a1)       # Load the saved return address from saved_ra into ra

        jalr x0, ra, 0     # Jump to the address in ra (return to scheduler)
