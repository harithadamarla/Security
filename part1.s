
.section .data
name: .string "/bin/sh"

.section .text
.globl _start
_start:

movl $name,%edi
# holds the parameter to execl
movl $59,%eax 
#eax register holds the address of system call. Here we are storing address of execl syscall
movl $0,%esi 
#holds the parameter to execl
movl $0,%edx 
# holds the parameter to execl
syscall
