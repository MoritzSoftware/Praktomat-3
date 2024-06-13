#include "fms.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Generate_Time_Table(FMS * pFMS){
    printf("\n  Airlines|Flight No.|from|  to|Departure| Arrival|Airplain");
    printf("\n----------|----------|----|----|---------|--------|--------\n");
    for(int x = 0; pFMS->cntAirline > x; x++){
        for(int y = 0; pFMS->ptrAirlines[x]->cntAirplain > y; y++){
            printf("%d %d %d\n",x,y, pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath);
            
        }
    }
    /*for(int x=0; x<pFMS->cntAirline; x++){ //pFMS->cntAirline
        printf("ok");
        printf("%d",x);
        int y = 0;//for(int y=0; y<pFMS->ptrAirlines[x]->cntAirplain; y++){ //pFMS->ptrAirlines[x]->cntAirplain
        printf("%d",y);
             //for(int z=0; z<pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath; z++){ //pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath
                printf("%10s|", pFMS->ptrAirlines[x]->airlineName);
                printf("%10s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[0]->flightPathName);
                printf("%4s|%4s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[0]->pDepartureAirport->iata, pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[0]->pArrivalAirport->iata);
                printf("    %s:%s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[0]->depature->hour, pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[0]->depature->minute);
                printf("   %s:%s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[0]->arrival->hour, pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[0]->arrival->minute);
                printf("%8s", pFMS->ptrAirlines[x]->ptrAirplanes[y]->airVehicleRegestration);
            //}
        //}
    }*/
}



void Generate_Distance_Table(FMS * pFMS){
    for(int x=0; x < pFMS->cntAirline; x++){
        printf("\n  Airlines|Flight No.|from|  to|Distance");
        printf("\n----------|----------|----|----|--------");
        for(int y=0; y< pFMS->ptrAirlines[x]->cntAirplain; y++){
            float totalDistance = 0;
            for(int z=0; z<pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath; z++){
                printf("%10s|", pFMS->ptrAirlines[x]->airlineName);
                printf("%10s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->flightPathName);
                printf("%4s|%4s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport->iata, pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport->iata);
                printf("%8.2f", calculateDistance(pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport, pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport));
                totalDistance = totalDistance + calculateDistance(pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport, pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport);
            }
        printf("\n\nTotal Flight Distance for %s %s is %.2f\n", pFMS->ptrAirlines[x]->airlineName, pFMS->ptrAirlines[x]->ptrAirplanes[y]->airplaneName, totalDistance);
        }
    }
}

/*void Generate_Duration_Table(FMS * pFMS){
    for(int x=0; x < pFMS->cntAirline; x++){
        printf("\n  Airlines|Flight No.|from|  to|Duration");
        printf("\n----------|----------|----|----|--------");
        for(int y=0; y< pFMS->ptrAirlines[x]->cntAirplain; y++){
            float totalDuration = 0;
            for(int z=0; z<pFMS->ptrAirlines[x]->ptrAirplanes[y]->cntFlightPath; z++){
                printf("%10s|", pFMS->ptrAirlines[x]->airlineName);
                printf("%10s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->flightPathName);
                printf("%4s|%4s|", pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pDepartureAirport->iata, pFMS->ptrAirlines[x]->ptrAirplanes[y]->ptrFlightPaths[z]->pArrivalAirport->iata);
                printf("%c", calculateDuration());
                totalDuration = totalDuration + calculateDuration();
            }
        printf("\n\nTotal Flight Duration for %s %s is %c\n", pFMS->ptrAirlines[x]->airlineName, pFMS->ptrAirlines[x]->ptrAirplanes[y]->airplaneName, totalDuration);
        }
    }
}*/

float calculateDegree(Coordinate * pCoordinates){ //take degrees, minutes and seconds and add them up to one number
    float Degree = 0;
    Degree = (pCoordinates->degree + pCoordinates->minute/60 + pCoordinates->second/3600);
    return Degree;
}

float sinDeg(float num){ //calculate radiant sin value
    num = sin(num/180*M_PI);
    return num;
} 

float cosDeg(float num){ //calculate radiant cos value
    num = cos(num/180*M_PI);
    return num;
}

float calculateDistance(Airport * pDepature, Airport * pArrival){ 
    float r = 6378.388;
    float distance = r * acos(sinDeg(calculateDegree(pArrival->pLatitude)) * sinDeg(calculateDegree(pDepature->pLatitude)) + cosDeg(calculateDegree(pArrival->pLatitude)) * cosDeg(calculateDegree(pDepature->pLatitude)) * cosDeg(calculateDegree(pArrival->pLongtitude) - calculateDegree(pDepature->pLongtitude)));
    return distance;
}

//char claculateDistance(){
//
//}