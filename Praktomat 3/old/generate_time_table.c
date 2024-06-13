#include "fms.h"
#include <stdio.h>

void Generate_Time_Table(FMS * pFMS){
    printf("\n  Airlines|Flight No.|from|  to|Departure| Arrival|Airplain");
    printf("\n----------|----------|----|----|---------|--------|--------");
/*Count throu Airlines*/    for(int i=0; x<*pFMS->cntAirline, x++){
/*Count throu Airlplanes*/        for(int y=0; y<*pFMS->ptrAirlines[x]->cntAirplain, y++){
/*Count throu Flightpaths*/             for(int z=0; z<*pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath, z++){
        printf("%10c|", *pFMS->ptrAirlines[x]->airlineName,  );
        printf("%10c|", *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->flightPathName);
        printf("%4c|%4c|", *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport->iata, *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport->iata);
        printf("    %02c:%02c|", *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->depature.hour, *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->depature.minute);
        printf("   %02c:%02c|", *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->arrival.hour, *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->arrival.minute);
        printf("%8c", *pFMS->ptrAirlines[x]->ptrAirplanes[y]->airVehicleRegestration);
            }
        }
    }
}