foo:
    addi    sp, sp, -16   ; Allocate 16 bytes of stack space
    sw      ra, 12(sp)     ; Save the return address
    sw      s0, 0(sp)     ; Save the old frame pointer
    addi    s0, sp, 16    ; Set the new frame pointer

    li      a0, 0         ; Load the return value (0) into a0

    lw      ra, 12(sp)     ; Restore the return address
    lw      s0, 0(sp)     ; Restore the old frame pointer
    addi    sp, sp, 16    ; Restore the stack pointer
    ret                   ; Return to the caller
