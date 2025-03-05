#include <stdio.h>
#include <math.h>
#include <time.h>
#include "random_generator.h"
#include <inttypes.h>

// use struct when you need different memory allocation otherwise union will do the job 
struct Cordinates {
    int * target;
    int * future;
};
union Train {
    uint64_t * X_train;
    uint64_t * y_valid;
};
union Test {
    uint64_t * X_valid;
    uint64_t * y_valid;
};
struct TrainTest {
    union Train train;
    union Test test;
};

typedef struct Cordinates cords;
typedef struct TrainTest train_test;
cords make_cordinates(int arr_len){
    cords init_cords;
    init_cords.target = (int*)malloc(arr_len * sizeof(int));
    init_cords.future = (int*)malloc(arr_len * sizeof(int));
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

train_test split_data(int * target, int *future){
    train_test train_test_split;
    int target_len = sizeof(*target) / target[0];
    int future_len = sizeof(*target) / target[0];
    train_test_split.train = (train_test *)malloc(target_len*sizeof(*target));
    train_test_split.test = (union Test*)malloc(future_len*sizeof(*future));
    
    return train_test_split;
}

int main(){
    cords test1 = make_cordinates(40);
    split_data(test1.target, test1.future);
    free(test1.target);
    free(test1.future);
    int n_iter;
    
   /* int x = 1/n_iter * pow((y_i - y_pred),2);
    */ 
    /*w_n+1 = w_n - alpha * x;
     */

    return 0;
}


