#include <stdio.h>
#include <math.h>
#include <time.h>
#include "random_generator.h"
#include <stdlib.h>


struct Cordinates {
    int target[30];
    int future[30];
}

struct TrainTest {
    int train_X[30];
    int train_Y[30];
    int valid_X[30];
    int valid_Y[30];
}


int* make_cordinates(){
    int lenght_nums = 30;
    int* cordinates = (int*)malloc(lenght_nums * sizeof(int));
    int ran_num = 0; 


    for(int i = 0; i < lenght_nums; i++){
	ran_num = random_generator(ran_num, 40, 0);
	cordinates[i] = ran_num;
    }
    return cordinates;
}

int gradient_decent(){
    int n, y_i, y_pred;
    int x = 1\n * pow((y_i - y_pred),2);
    w_n+1 = w_n - alpha * x;
}

int main(){
    int * X = make_cordinates();
    int * Y = make_cordinates();

    free(X);
    free(Y);
    return 0;
}


