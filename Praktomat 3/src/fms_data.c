#include "fms.h"
#include <stdlib.h>
#include <stdio.h>

FMS* initialize(void){
//FMS *pFMS = malloc(sizeof(FMS));

Coordinate HAMLatitude ={
    53,37,49
};
Coordinate HAMLongtitude ={
    9,59,18
};

Coordinate CGNLatitude ={
    50,51,57
};
Coordinate CGNLongtitude ={
    7,8,34 
};

Coordinate DUSLatitude ={
    51,16,51
};
Coordinate DUSLongtitude ={
    6,45,26
};

Coordinate FRALatitude ={
    50,1,59
};
Coordinate FRALongtitude ={
    8,34,14
};

Coordinate BERLatitude ={
    52,21,44
};
Coordinate BERLongtitude ={
    13,30,2
};

Coordinate MUCLatitude ={
    48,21,14
};
Coordinate MUCLongtitude ={
    11,47,10
};

Coordinate STRLatitude ={
    48,41,23.56
};
Coordinate STRLongtitude ={
    9,13,19.07
};



Time t0300 ={
    "03","00"
};
Time t0415 ={
    "04","15"
};
Time t0800 ={
    "8","00"
};
Time t1000 ={
    "10","00"
};
Time t1012 ={
    "10","12"
};
Time t1015 ={
    "10","15"
};
Time t1130 ={
    "11","30"
};
Time t1300 ={
    "13","00"
};
Time t1310 ={
    "13","10"
};
Time t1315 ={
    "14","15"
};
Time t1430 ={
    "14","30"
};
Time t1500 ={
    "15","00"
};
Time t1512 ={
    "15","12"
};
Time t1530 ={
    "15","30"
};
Time t1630 ={
    "16","30"
};
Time t1700 ={
    "17","00"
};
Time t1800 ={
    "18","00"
};
Time t1830 ={
    "18","30"
};
Time t2030 ={
    "20","30"
};
Time t2045 ={
    "20","45"
};
Time t2145 ={
    "21","45"
};
Time t2200 ={
    "22","00"
};
Time t2230 ={
    "22","30"
};
Time t2330 ={
    "23","30"
};
Time t2400 ={
    "24","00"
};



Airport HAM ={
    "EDDH",
    "HAM",
    &HAMLatitude,
    &HAMLongtitude,
    5
};
Airport CGN ={
    "EDDK",
    "CGN",
    &CGNLatitude,
    &CGNLongtitude,
    5
};
Airport DUS ={
    "EDDL",
    "DUS",
    &DUSLatitude,
    &DUSLongtitude,
    5
};
Airport FRA ={
    "EDDF",
    "FRA",
    &FRALatitude,
    &FRALongtitude,
    5
};
Airport BER ={
    "EDDB",
    "BER",
    &BERLatitude,
    &BERLongtitude,
    5
};
Airport MUC ={
    "EDDM",
    "MUC",
    &MUCLatitude,
    &MUCLongtitude,
    5
};
Airport STR ={
    "EDDS",
    "STR",
    &STRLatitude,
    &STRLongtitude,
    5
};



FlightPath LHOne ={
    "LH 2147",
    &MUC,
    &HAM,
    &t1130,
    &t1430
};
FlightPath LHTwo ={
    "LH 2147",
    &HAM,
    &FRA,
    &t1530,
    &t1630
};
FlightPath LHThree ={
    "LH 2147",
    &FRA,
    &MUC,
    &t1830,
    &t2030
};
FlightPath LHFour ={
    "LH 2147",
    &MUC,
    &HAM,
    &t2045,
    &t2200
};
FlightPath LHFive ={
    "LH 2147",
    &HAM,
    &MUC,
    &t2230,
    &t2330
};

FlightPath EWOne ={
    "EW 2147",
    &MUC,
    &DUS,
    &t0300,
    &t0415
};
FlightPath EWTwo ={
    "EW 2147",
    &DUS,
    &BER,
    &t0800,
    &t1000
};
FlightPath EWThree ={
    "EW 2147",
    &BER,
    &CGN,
    &t1012,
    &t1315
};
FlightPath EWFour ={
    "EW 2147",
    &CGN,
    &MUC,
    &t1800,
    &t2030
};
FlightPath EWFive ={
    "EW 2147",
    &MUC,
    &DUS,
    &t2145,
    &t2330
};

FlightPath TUIOne ={
    "X3 2174",
    &HAM,
    &STR,
    &t0800,
    &t1000
};
FlightPath TUITwo ={
    "X3 2174",
    &STR,
    &BER,
    &t1015,
    &t1300
};
FlightPath TUIThree ={
    "X3 2174",
    &BER,
    &FRA,
    &t1310,
    &t1500
};
FlightPath TUIFour ={
    "X3 2174",
    &FRA,
    &HAM,
    &t1512,
    &t1700
};
FlightPath TUIFive ={
    "X3 2174",
    &HAM,
    &FRA,
    &t2200,
    &t2400
};



Airplane LHA380 ={
    "A380",
    "D-AIMA",
    .ptrFlightPaths = {&LHOne, &LHTwo, &LHThree, &LHFour, &LHFive},
    6
};

Airplane EWA320 ={
    "A320",
    "D-AIAB",
    .ptrFlightPaths = {&EWOne, &EWTwo, &EWThree, &EWFour, &EWFive},
    5
};
Airplane TUIB747 ={
    "B747",
    "D-ABCD",
    .ptrFlightPaths = {&TUIOne, &TUITwo, &TUIThree, &TUIFour, &TUIFive},
    5
};



Airline LUFTHANSA ={
    "Lufthansa\0",
    .ptrAirplanes = {&LHA380},
    1
};
Airline EUROWINGS ={
    "Eurowings\0",
    .ptrAirplanes = {&EWA320},
    1
};
Airline TUIFLY ={
    "TUIFly\0",
    .ptrAirplanes = {&TUIB747},
    1
};



FMS fms = {
    .ptrAirlines = {&LUFTHANSA, &EUROWINGS, &TUIFLY},
    3
};

FMS *pFMS = &fms;
//printf("Data %d", pFMS->cntAirline);
printf(" ");
return pFMS;
}