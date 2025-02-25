#include <stdio.h>
#include <math.h>
#include <time.h>
#include "random_generator.h"

int main(){
    double cordinates[] = {};
    int lenght_nums = 30;
    long long ran_num = 0; 
    for(int i = 1; i <= lenght_nums; i++){
	ran_num = random_generator(ran_num);
	printf("%lld \n",ran_num);
    }
    return 0;
}


