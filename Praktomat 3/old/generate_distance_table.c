#include "fms.h"
#include <stdio.h>

void Generate_Distance_Table(FMS * pFMS){
    for(int x=0; x < *pFMS->cntAirline, x++){
        printf("\n  Airlines|Flight No.|from|  to|Distance");
        printf("\n----------|----------|----|----|--------");
        for(int y=0; y< *pFMS->ptrAirlines[x]->cntAirplain, y++){
            float totalDistance = 0;
            for(int z=0; z<*pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath, z++){
                printf("%10c|", *pFMS->ptrAirlines[x]->airlineName,  );
                printf("%10c|", *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->flightPathName);
                printf("%4c|%4c|", *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport->iata, *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport->iata);
                printf("%8.2f", calculateDistance(*pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport, *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport));
                totalDistance = totalDistance + calculateDistance(*pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport, *pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport);
            }
        printf("\n\nTotal Flight Distance for %c %c is %.2f\n", *pFMS->ptrAirlines[x]->airlineName, *pFMS->ptrAirlines[x]->ptrAirplanes[y], totalDistance);
        }
    }
}