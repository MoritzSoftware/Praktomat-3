#include <stdio.h>
#include <math.h>

/*Passt*/float calculateDegree(Coordinate * pCoordinates){ //take degrees, minutes and seconds and add them up to one number
    float Degree = 0;
    Degree = (*pCoordinates->degree + *pCoordinates->minute/60 + *pCoordinates->second/3600);
    return Degree;
}

/*Passt*/float sinDeg(float num){ //calculate radiant sin value
    num = sin(num/180*M_PI);
    return num;
} 

/*Passt*/float cosDeg(float num){ //calculate radiant cos value
    num = cos(num/180*M_PI);
    return num;
}

float calculateDistance(Airport * pDepature, Airport * pArrival){ 
    float r = 6378.388;
    float distance = r * acos(sinDeg(calculateDegree(*pArrival->pLatitude)) * sinDeg(calculateDegree(*pDepature->pLatitude)) + cosDeg(calculateDegree(*pArrival->pLatitude)) * cosDeg(calculateDegree(*pDepature->pLatitude)) * cosDeg(calculateDegree(*pArrival->pLongtitude) - calculateDegree(*pDepature->pLongtitude)));
    return distance;
}