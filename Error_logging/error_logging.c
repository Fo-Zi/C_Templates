// The interesting of this design is that it poses as an abstraction layer between the actual errors
// and whatever action we may want to implement with them. Example: ErrorPrint as it's implemented
// below, simply outputs through a print statement, but this could be replaced easily with an LCD
// display, or whatever method we want to use, and by doing so we don't need to actually change the rest
// of the code base.

#include "error_logging.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"

#define FIRST_ERROR 1

enum ErrorSource{
    FOO_EXAMPLE			=1,
    FOO_EXAMPLE_2		=2,
};
    
enum ErrorType{
    INPUT_OUT_OF_BOUNDS		=100,
    OUT_OF_MEMORY		=101,
    IO_FAILED			=102,
};

typedef struct GlobalError_type{
	ErrorSource Source,
	ErrorType Type,
}GlobalError;

#if FIRST_ERROR
    GlobalError first_err;
#else
    GlobalError last_err;
#endif

char * strErr[2];

void ErrorToString(GlobalError * GlobErr){
    switch (GlobErr->Source){
        case FOO_EXAMPLE:
            strErr[0]="FOO_EXAMPLE";
            break;
        case FOO_EXAMPLE_2:
            strErr[0]="FOO_EXAMPLE_2";
            break;
        default:
            strErr[0]="UNDEFINED";
            break;
    }
    switch (GlobErr->Type){
        case INPUT_OUT_OF_BOUNDS:
            strErr[1]="Input out of bounds";
            break;
        case OUT_OF_MEMORY:
            strErr[1]="Out of memory";
            break;
        case IO_FAILED:
            strErr[1]="IO operation failed";
            break;
        default:
            strErr[1]="UNDEFINED";
            break;
    }
};    

#if FIRST_ERROR
    void setError(GlobalError GlobErr){
        static bool firstErrSet = false;
        if(!firstErrSet){
            first_err = GlobErr;
            firstErrSet = true;
        }
    };
    GlobalError getError(){
        return first_err;
    };
#else
    void setError(GlobalError GlobErr){
        last_err = GlobErr;
    };
    GlobalError getError(){
        return last_err;
    };
#endif

void ErrorPrint(GlobalError * GlobalError){
    ErrorToString(GlobalError); 
    printf("An error occured. Source: %s -- Cause: %s.\n",strErr[0],strErr[1]);
};

void ErrorLogAdd(GlobalError * GlobalError){

};

void ErrorLogPrint(GlobalError * GlobalError){

};
