#include "test.h"
    
    Airplane LHeins = {
        1
    };

    Airplane LHzwei ={
        2
    };

    Airline LH = { 
        "Lufthansa",
        .airplanes = {&LHeins, &LHzwei}
    };

    Airline EW = {
        "Eurowings",
        .airplanes = {&LHeins, &LHzwei}
    };

    FMS EINS = {
        1,
        .airlines = {&LH, &EW}
    };

    FMS * pFMS = &EINS;