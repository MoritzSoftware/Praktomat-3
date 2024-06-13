#ifndef TEST_H
#define TEST_H

    typedef struct airplane{
        int num;
    }Airplane;

    typedef struct airline{
        char name[10];
        Airplane* airplanes[2];
    }Airline;

    typedef struct fms{
        int num;
        Airline* airlines[2];
    }FMS;

#endif