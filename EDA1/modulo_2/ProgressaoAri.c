#include <stdio.h>

int pa_recursiva (int *v, int primeiro, int ultimo){
    //printf("%d %d\n", primeiro, ultimo);
       //printf("%d  %d\n", (v[primeiro]+v[ultimo]), (v[primeiro+1]+v[ultimo-1]));
    if((v[primeiro]+v[ultimo]) != (v[primeiro+1]+v[ultimo-1])){
        return 0;
    }else if(primeiro==(ultimo-3)){
        return 1;
    }else
        return 1*pa_recursiva(v, primeiro+1, ultimo-1);
}
