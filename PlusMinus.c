#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    From HackerRank (https://www.hackerrank.com/challenges/plus-minus/problem)
    Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. 
    Print the decimal value of each fraction on a new line with 6 places after the decimal.


    Input Format
    The first line contains an integer, n, the size of the array. 
    The second line contains n space-separated integers that describe.

    Print the following  lines, each to  decimals:
    proportion of positive values
    proportion of negative values
    proportion of zeros
*/

float * plus_minus(int size, int* arr){
    // Allocate for proportions
    float * proportions = (float*)malloc(3*sizeof(float));
    proportions[0] = 0.0; proportions[1] = 0.0; proportions[2] = 0.0;
    int i;

    for(i=0; i<size; i++){
        if(arr[i] > 0){
            proportions[0]++;
            continue;
        }
        if(arr[i] < 0){
            proportions[1]++;
            continue;
        }
        proportions[2]++;
    }
    proportions[0]= proportions[0]/size; proportions[1]= proportions[1]/size; proportions[2]= proportions[2]/size;
    return proportions;

}

int main(){
    // Again to read files, one needs to make a File Pointer Variable 
    FILE * file_pointer;

    // We need to make a string pointer so we can use it as a buffer for the stringstream 
    char* str = (char*)malloc(100);

    // Get the files path the use fopen with 'r' as a tag
    char*  filepath = "input11.txt";
    file_pointer = fopen(filepath,"r");

    fgets(str,100,file_pointer);
    int size = atoi(&str[0]);
    fgets(str,100,file_pointer);
    char * str_arr = str;
    
    int * arr = (int*)malloc(size*sizeof(int));
    int index=0;
    int arr_index=0;
    int digit_parity;
    
    while(str_arr[index]!='\0'){
        digit_parity = 1;
        if(str_arr[index] == '-'){
            digit_parity = -1;
            index++;  
        }
        arr[arr_index] = atoi(&str_arr[index])*digit_parity;
        index+=2;
        arr_index++;
    }
    
    fclose(file_pointer);
    free(str_arr);

    float * answer = plus_minus(size,arr);
    printf("%.6f \n%.6f \n%.6f \n",answer[0],answer[1],answer[2]);

}


