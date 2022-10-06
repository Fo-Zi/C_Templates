#include "error_logging.c"

GlobalError global_err;

int foo_example(int in);

void main(){
    int a = foo_example(2);
    int b = foo_example(99);
    int c = foo_example2(90);
    
    //---------Execution of several operations----------//

    global_err = getError();
    if(global_err){
        ErrorPrint(global_err);
    }
}

int foo_example(int in){
    if(in > 100){
        global_err=(GlobalError){FOO_EXAMPLE,INPUT_OUT_OF_BOUNDS};
        setError(global_err);
    }
    return in*2;
};

int foo_example2(int in){
    if(in > 50){
        global_err=(GlobalError){FOO_EXAMPLE_2,INPUT_OUT_OF_BOUNDS};
        setError(global_err);
    }
    return in*5;
};
