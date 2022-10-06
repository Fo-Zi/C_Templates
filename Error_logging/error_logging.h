#ifndef ERROR_LOGGING_H
#define ERROR_LOGGING_H

#include <stddef.h>

typedef struct GlobalError_type GlobalError;

void ErrorToString( GlobalError *);

void setError(GlobalError);
GlobalError getError();
void ErrorPrint(GlobalError *);
void ErrorLog(GlobalError *);
void ErrorLogPrint(GlobalError *);

#endif
