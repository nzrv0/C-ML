#include <stdio.h>
#include <math.h>
#include <time.h>
#include "random_generator.h"
#include <inttypes.h>
#include <stdlib.h>

// use struct when you need different memory allocation otherwise union will do the job 
struct Cordinates {
    uint64_t * target;
    uint64_t * future;
};
struct Split {
    uint64_t * X;
    uint64_t * y;
};
struct TrainTest {
    struct Split train;
    struct Split test;
};

typedef struct Cordinates cords;
typedef struct TrainTest train_test;
cords make_cordinates(int arr_len){
    cords init_cords;
    int alloc_size = arr_len * sizeof(uint64_t);

    init_cords.target = (uint64_t*)malloc(alloc_size);
    init_cords.future = (uint64_t*)malloc(alloc_size);

    uint64_t ran_num = 0;
    pcg32_srandom(40u, 42u);
    for(int i = 0; i < arr_len; i++){
	ran_num = pcg32_random(40, 20);
	init_cords.target[i] = ran_num;
	init_cords.future[i] = ran_num * init_cords.target[i];
	printf("%i\n", ran_num);
    }
    return init_cords;
}

train_test * split_data(uint64_t * target, uint64_t *future){
    train_test * train_test_split = (train_test *)malloc(sizeof(train_test));
    int target_len = sizeof(*target) / sizeof(target[0]);
    int future_len = sizeof(*target) / target[0];

    int target_portion = (40 * 80) / 100;

    train_test_split->train.X = (uint64_t *)malloc(target_portion*sizeof(uint64_t));
    train_test_split->train.y = (uint64_t *)malloc(target_portion*sizeof(uint64_t));

    for(int i = 0; i < target_portion; i++){
	train_test_split->train.X[i] = target[i];
	train_test_split->train.y[i] = future[i];
    }

    return train_test_split;
}

int main(){
    cords test1 = make_cordinates(40);
    train_test* test2 = split_data(test1.target, test1.future);

    free(test2->train.X);
    free(test2->train.y);
    free(test2);

    free(test1.target);
    free(test1.future);
    int n_iter;
    
   /* int x = 1/n_iter * pow((y_i - y_pred),2);
    */ 
    /*w_n+1 = w_n - alpha * x;
     */

    return 0;
}


