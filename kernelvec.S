
.globl kerneltrap
.globl kernelvec
.align 4
kernelvec:

        # call the C trap handler in kernel.c
        #call timer_interrupt_handler
        
        # return to whatever we were doing in the kernel.
        #mret

        call intr_off
        #call print

        
        #lw sp, saved_sp
        
        la a0, saved_sp           # Load the address of saved_sp into a0
        ld s0, 0(a0)              # Load the value of saved_sp into s0
        mv sp, s0                 # Move the value from s0 into the sp register

        #call print
        
        

        # Load the return address from the global variable saved_ra
        la a1, saved_ra    # Load the address of saved_ra into a1
        ld ra, 0(a1)       # Load the saved return address from saved_ra into ra

        jalr x0, ra, 0     # Jump to the address in ra (return to scheduler)
