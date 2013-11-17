#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
	char a[64];
} mystruct;


mystruct * allocfunc(char *mypointer)
{
	void *mem;
	void *aligned_ptr;
	mystruct *mys = NULL;
	

	mem = malloc(sizeof(mystruct) + 128);
	if(mem!=NULL)
	{
		printf("allocfunc: base memory address = %x\n",mem);	
		
		//logic explanation to get address aligned with 128 byte boundary
		//127 should be the maximum pad bytes for a 128 byte aligned address
		//128 = 0x80 = 1000 0000.  And with logical not of 0111 1111 = 0x7F to get the aligned address
	    aligned_ptr = ((long unsigned int)mem + (128-1)) & ~(long unsigned int)0x7F;
	    printf("allocfunc: aligned memory address = %x\n",aligned_ptr);
	
	   //save the unaligned mem address in the unused space
	    *((long unsigned int*)aligned_ptr - sizeof(long unsigned int)) = mem;
					

     	printf("allocfunc: data stored at loc  *((long unsigned int*)aligned_ptr - sizeof(long unsigned int))  = %x\n", \
		*((long unsigned int*)aligned_ptr - sizeof(long unsigned int)) );		
	
		mys = (mystruct*)aligned_ptr;
	}
	else
	{
		printf("allocfunc: call to malloc failed\n");
	}
	
	return mys;
}


// mys is a pointer to the aligned address
// mys - sizeof(ptr) contains the address of the (original) unaligned address
void freefunc(mystruct *mys)
{
   void *ptr;
   void *free_ptr;   
  
   ptr = (void*)mys;

   free_ptr = *((long unsigned int*)ptr - sizeof(long unsigned int));
       
   printf("freefunc: mys = %x\n",mys);
   printf("freefunc: addr = %x\n",free_ptr);
			
   free(free_ptr);
      
}

int main(int argc, char **argv)
{
	char *mypointer;
	mystruct *mystuff;

	printf("addr allocated(before) = %x\n",mypointer);	
	mystuff = allocfunc(&mypointer);
	printf("addr allocated = %x\n",mypointer);
	printf("addr aligned = %x\n",mystuff);
	

	freefunc(mystuff);
	
	printf("lab 2\n");
	
	
	return 0;
}
