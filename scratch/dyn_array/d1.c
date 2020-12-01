#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

/* 

Write a mem allocator function

This returns an array of memory when asked

This array of memory, if full, or cannot service the request, just reallocs double from the heap
from the last time around

Need index(es?) to track filled up states of array
And can return memory from new location upto size of <unit data bytes>

Let's assume array of bytes (or chars?)

Better to do this in C++ but lets start with C

Later - prove that its indeed dynamic array by accessing contents of the ith element
in an array like fashion (O(1) access?) 

Also lets prepopulate this allocated memory with some known characters that may correspond with the index.
e.g. lets say every cell is a string of value "<iteration+index>" ... perhaps encoded into a byte of data?

*/

#define fixedArraySize 10
char* localMem = NULL;

void* GetArrayMem(int req_memSize) {

    char* freeMem;
    static int actualArraySize = fixedArraySize;
    static int endFreeIndex    = fixedArraySize;

    static int startFreeIndex = 0; 

    if (localMem == NULL) { // first time request
        printf("%s: init localMem with %d\n", __FUNCTION__, actualArraySize);
        localMem = (char *)malloc(actualArraySize); // malloc should be returning consecutive bytes?
    }
    
    if (req_memSize > endFreeIndex - startFreeIndex + 1) {

        actualArraySize *= 2; // Double the array size
        printf("%s: call REALLOC of localMem with %d\n", __FUNCTION__, actualArraySize);
        localMem = (char *)realloc(localMem, actualArraySize);
        startFreeIndex = 0;
        endFreeIndex = actualArraySize;

    }

    freeMem = (localMem + req_memSize);
    startFreeIndex += req_memSize;

    printf("%s: allocate from existing localMem (start: %d, end: %d)\n", __FUNCTION__, startFreeIndex, endFreeIndex);
    assert(startFreeIndex <= endFreeIndex);

    return freeMem;
}


int main()
{

    char *arrayMem = NULL;
    //int maxMem = 2048;
    int maxMem = 6000;

    printf("Dyn Array!\n");

    for (int i = 0; i < maxMem; i++) {

        printf("Req for new mem size of %d bytes", i);
        arrayMem = GetArrayMem(i);

        for (int j = 0; j < i; j++) {
            printf(" %d ", arrayMem[j]);
        }
        printf("\n");

    }

    return 0;
}
