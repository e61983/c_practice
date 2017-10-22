#include <setjmp.h>
#include <stdio.h>

#define try do{ jmp_buf __ex_buff; switch(setjmp(__ex_buff)){ case 0:
#define catch(i) break; case i:
#define end }}while(0);
#define though(i) longjmp(__ex_buff, i)

#define INTIAL_ERROR (1)
#define SETTINT_ERROR (2)
#define RUNNING_ERROR (3)

int main (void)
{
    try{
        printf("Program start...\n");
        though(INTIAL_ERROR);
    }catch(INTIAL_ERROR){
        printf("INTIAL_ERROR\n");

    }catch(SETTINT_ERROR){
        printf("SETTINT_ERROR\n");

    }catch(RUNNING_ERROR){
        printf("RUNNING_ERROR\n");
    }
    end
}
