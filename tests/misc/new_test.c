#include <stdio.h>


typedef struct tpos_* tpos;

struct tpos_ {
int line;
int col;
};

main()
{

tpos pos=(tpos) malloc(sizeof(struct tpos_));
#ifdef PRN
printf("hello world!\n");
#endif

}
