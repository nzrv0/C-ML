#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

/*
 * linear congruential generator (LCG)
 * X_n+1 = (X*a +b ) % m
 * 0 < m - modul
 * 0 < a < m - mutliplayer
 * 0 <= b < m - increment
 * 0 <= X < m - seed
*/

int random_generator(int init_state, int max_len, int min_len){
    unsigned long int cur_mult = 349534943943, cur_add = 2421321534343, cur_mod = (max_len-min_len);
    if(init_state == 0){
	init_state = time(NULL);
    }
    else{
	cur_mult *= cur_mult;
	cur_add =  (cur_mult + 1) * cur_add;
    } 
    return (init_state * cur_mult + cur_add) % cur_mod;
}
