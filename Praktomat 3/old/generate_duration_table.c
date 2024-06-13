#include "fms.h"
#include <stdio.h>

void Generate_Duration_Table(FMS * pFMS){
    for(int x=0; x<*pFMS->cntAirline, x++){
        printf("\n  Airlines|Flight No.|from|  to|Duration");
        printf("\n----------|----------|----|----|--------");
        for(int y=0; y<*pFMS->ptrAirlines[x]->cntAirplain, z++){
            for(int z=0; z<pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath, z++){
                
            }
        }
    }
}