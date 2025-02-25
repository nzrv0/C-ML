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


long long random_generator(long long X){
    int a = 2, b = 0, m = 30;
    if(X == 0){
	X = time(NULL);
    }
    else{
	m = X + m;
    }
    X = (X * a + b) % m;
    return X;
}
