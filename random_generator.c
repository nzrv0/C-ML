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


int random_generator(){
    long long X = time(NULL);
    int a = 2, b = 0, m = 20;
    X = (X * a + b) % m;
    return X;
}
