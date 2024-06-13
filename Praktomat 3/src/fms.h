#ifndef FMS_H
#define FMS_H

typedef struct coordinate{
    double degree; 
    double minute;
    double second;
}Coordinate;

typedef struct airport{
    char icao[4];
    char iata[3];
    Coordinate *pLatitude;
    Coordinate *pLongtitude;
    float hightAMSL;
}Airport;

typedef struct time{
    char hour[2];
    char minute[2];
}Time;

typedef struct flightPath{
    char flightPathName[7];
    Airport *pDepartureAirport;
    Airport *pArrivalAirport;
    Time *depature;
    Time *arrival;
}FlightPath;

typedef struct airplane{
    char airplaneName[4];
    char airVehicleRegestration[6];
    FlightPath* ptrFlightPaths[5];
    unsigned int cntFlightPath;
}Airplane;

typedef struct airline{
    char airlineName[10];
    Airplane* ptrAirplanes[1];
    unsigned int cntAirplain;
}Airline;

typedef struct fms{
    Airline* ptrAirlines[3];
    unsigned int cntAirline;
}FMS;

void Generate_Time_Table(FMS * pFMS);

void Generate_Distance_Table(FMS * pFMS);

void Generate_Duration_Table(FMS * pFMS);

float calculateDegree(Coordinate * pCoordinates);

float sinDeg(float num);

float cosDeg(float num);

float calculateDistance(Airport * pDepature, Airport * pArrival);

FMS* initialize(void);

#endif