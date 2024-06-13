#include "fms.h"

int main(void){
    
    FMS *pFMS = initialize();
    Generate_Time_Table(pFMS);
    //Generate_Duration_Table(pFMS);
    //Generate_Distance_Table(pFMS);
    //free(pFMS);
    return 0;
}