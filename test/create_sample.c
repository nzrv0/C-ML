#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int m = 2, n = 3;
    int ** arr;
    arr = (int **)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++){
	arr[i] = (int*)malloc(sizeof(int) * n);
    }
    for(int i = 0; i < m; i++){
	for(int j = 0; j<n; j++){
	    arr[i][j] = i * n + j + 1; 
	}
    }

    for(int i = 0; i < m; i++){
	for(int j = 0; j<n; j++){
	    printf("%i ", arr[i][j]);
	}
	printf("\n");
	free(arr[i]);
    }
    free(arr);
    return 0;
}
