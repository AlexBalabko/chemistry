#include "general.h"

unsigned int * serieskle(void){

    unsigned int series [SIZE] = {0};
    unsigned int help; 

    char twonum;

    size_t couter = 0;
    size_t *couterPtr = &couter;

    for( size_t i = 1; i < 6; ++i ){
        for ( size_t j = 0; j < i; ++j){                      //inzilization array 

            series[ *couterPtr ] |= (i << 4);
            series[ *couterPtr ] |= j;

            ++ (*couterPtr);

        }
    }

    for( size_t i = 0 ; i < SIZE; ++i ){                                                                          // first conditinal 

        if( (series[i + 1] & 0x0F) + (series[i + 1] >> 4) < (series[i] & 0x0F) + (series[i] >> 4)){

            help = series[i];
            series[i] = series[ i + 1];
            series[i + 1] = help;
        }

        }


        for( size_t i = 0 ; i < SIZE; ++i ){
            
            if( ((series[ i + 1]) >> 4) < (series[i] >>4 )  ){                                                       //second conditional 
            
            help = series[i];
            series[i] = series[ i + 1];
            series[i + 1] = help;
        }
        }

        return series;



        /*for( size_t i = 0; i < SIZE; ++i){

            switch ( series[i] & 0x0F)
            {
            case 0:
                twonum = 's';
                break;

            case 1:
                twonum = 'p';
                break;
            
            case 2:
                twonum = 'd';
                break;

            case 3:
                twonum = 'f';
                break;
            
            case 4:
                twonum = 'g';
                break;
            }

            printf("%d%c\n", (series[i] >> 4), twonum);

        }*/

}


unsigned int determineseries ( int number, unsigned int *array ){

    unsigned int check = 0;
    number /= 2;

    for ( size_t i = 0; i < SIZE; ++i){

        if ( number <= 0 ){
            break;
        }

        switch ( array[i] & 0x0F){
        case 0 :
            number -=1; 
            check = array[i];


            break;

        case 1 :
            number -=3;
            check = array[i];
            
            break;

        case 2 :
             number -=5;
             check = array[i];
            
            break;

        case 3 :
            number -=7;
            check = array[i];
            
            break;
            
        case 4 :
            number -=9;
            check = array[i];
            
            break;
        }
    }

    return check;
}