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
cords make_cordinates(int arr_len, int alloc_size){
    cords init_cords;

    init_cords.target = (uint64_t*)malloc(alloc_size);
    init_cords.future = (uint64_t*)malloc(alloc_size);

    uint64_t ran_num = 0;
    pcg32_srandom(40u, 42u);
    for(int i = 0; i < arr_len; i++){
	ran_num = pcg32_random(40, 20);
	init_cords.target[i] = ran_num;
	init_cords.future[i] = ran_num * init_cords.target[i];
    }
    return init_cords;
}

typedef struct TrainTest train_test;
train_test * split_data(uint64_t * target, uint64_t *future,uint64_t target_portion, uint64_t test_portion){
    train_test * train_test_split = (train_test *)malloc(sizeof(train_test));

    train_test_split->train.X = (uint64_t *)malloc(target_portion*sizeof(uint64_t));
    train_test_split->train.y = (uint64_t *)malloc(target_portion*sizeof(uint64_t));

    for(int i = 0; i < target_portion; i++){
	train_test_split->train.X[i] = target[i];
	train_test_split->train.y[i] = future[i];
    }

    train_test_split->test.X = (uint64_t *)malloc(test_portion*sizeof(uint64_t));
    train_test_split->test.y = (uint64_t *)malloc(test_portion*sizeof(uint64_t));

    for(int i = 0; i < test_portion; i++){
	train_test_split->test.X[i] = target[i];
	train_test_split->test.y[i] = future[i];
    }

    return train_test_split;
}
double learning_rate(float learn_rate, int iter);
double * gradient_decent(uint64_t *x, uint64_t *y, uint64_t size){
    // J(w, b) = 1/m*sum(y-y_pred)**2
    // w_n + 1 = w_n - alpha * d(J(w, b))/ dw
    uint64_t init_weight = pcg32_random(40, 20);
    double learn_rate = 0.002;
    uint64_t len_num = size; 
    double theta = init_weight;
    double * y_pred = (double *)malloc(len_num * sizeof(double));
    double sum = 0;
    for(int i = 0;i < len_num; i++){
	for (int i = 0;i < len_num;i++){
	    y_pred[i] = theta * x[i]; 
	    sum += -(y[i] - y_pred[i])*x[i];
	}
	printf("Sum - %f\n", sum);
	double cost_w = (2*sum)/len_num;
	printf("Coast funciton - %f\n", cost_w);
	theta = theta - learn_rate * cost_w;
	learn_rate = learning_rate(learn_rate, i);
	printf("last weight - %f\n", theta);
    }
    return y_pred; 
}

double learning_rate(float learn_rate, int iter){
    float decay = 0.01;
    double new_rate = learn_rate/(1 + decay * iter);
    printf("%f\n", new_rate);
    return new_rate;
}

int main(){
    uint64_t arr_len = 40;
    uint64_t alloc_size = arr_len * sizeof(uint64_t);
     
    cords test1 = make_cordinates(arr_len, alloc_size);

    uint64_t target_len = alloc_size / sizeof(test1.target[0]);
    uint64_t future_len = alloc_size / sizeof(test1.future[0]);
    uint64_t target_portion = (target_len * 80) / 100;
    uint64_t test_portion = (target_len - target_portion);

    train_test* test2 = split_data(test1.target, test1.future, target_portion, test_portion);
    double * y_pred = gradient_decent(test2->train.X, test2->train.y, target_portion);
    

    free(y_pred);

    free(test2->train.X);
    free(test2->train.y);
    free(test2->test.X);
    free(test2->test.y);
    free(test2);

    free(test1.target);
    free(test1.future);
    
    return 0;
}

