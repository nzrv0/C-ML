#include <stdio.h>
#include <math.h>
#include <time.h>
#include "random_generator.h"
#include <stdlib.h>

// use struct when you need different memory allocation otherwise union will do the job 
struct Cordinates {
    int * target;
    int * future;
};

struct TrainTest {
    int train_X[30];
    int train_Y[30];
    int valid_X[30];
    int valid_Y[30];
};

typedef struct Cordinates cords;

cords make_cordinates(int arr_len){
    cords init_cords;
    init_cords.target = (int*)malloc(arr_len * sizeof(int));
    init_cords.future = (int*)malloc(arr_len * sizeof(int));
    int ran_num = 0;
    pcg32_srandom(40u, 42u);
    for(int i = 0; i < arr_len; i++){
	ran_num = pcg32_random();
	init_cords.target[i] = ran_num;
	init_cords.future[i] = ran_num * init_cords.target[i];
	printf("%i\n", ran_num % (20));
    }
    return init_cords;
}

int main(){

    cords test1 = make_cordinates(30);
    printf("this is target - %i\n", test1.target[0]);
    free(test1.target);
    free(test1.future);
    int n_iter;

   /* int x = 1/n_iter * pow((y_i - y_pred),2);
    */ 
    /*w_n+1 = w_n - alpha * x;
     */

    return 0;
}


