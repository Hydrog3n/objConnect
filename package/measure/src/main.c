#include <stdio.h>
#include <unistd.h>

#include "BNO055.h"

int main()
{
BNO055 bno;
int temp;
    if (BNO055_init(&bno, -1, BNO055_ADDRESS_A, 2) != 0) {
      fprintf(stderr,"Erreur initialisation capteur !\n");
      return 1;
    }

    BNO055_begin(&bno, OPERATION_MODE_NDOF_FMC_OFF);

    usleep(1000000);
    temp = BNO055_getTemp(&bno);
    printf("Current Temperature: %d C\n",temp);

    return 0;
}

