#include <stdlib.h>
#include <time.h>
#include "scenes/UserGuide.h"
#include "common/Audio.h"

int main()
{
    srand(time(NULL));
    system("mode con cols=124 lines=40");
    uesr_guide_start();
    
    return 0;
}