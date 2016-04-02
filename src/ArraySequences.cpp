/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int apseq(int *arr, int *res, int strt,int flag){
	int ap1mean,i;
	ap1mean = arr[strt+1] - arr[strt];
	if (flag){
		if (strt < res[0])
			res[0] = strt;
	}
	else{
		if (strt < res[2])
			res[2] = strt;
	}
	i = strt;
	while ((arr[i + 1] - arr[i]) == ap1mean){
		i += 1;
	}
	if (flag){
		if (i>res[1])
			res[1] = i;
	}
	else{
		if (i > res[3])
			res[3] = i;
	}
	return i;
}

int gpseq(int *arr, int *res, int strt){
	int gpmean, i;
	gpmean = arr[strt + 1] / arr[strt];
	if (strt<res[4])
		res[4] = strt;
	i = strt;
	while ((arr[i + 1] / arr[i])){
		i += 1;
	}
	if (i>res[5])
		res[5] = i;
	return i;
}

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int *res, i, j, next,flag=1;
	res = (int *)malloc(sizeof(int)* 6);
	res[0] = -1;
	res[1] = 8;
	res[2] = -1;
	res[3] = 8;
	res[4] = -1;
	res[5] = 8;
	i = 0;
	while (i < 6){
		if ((arr[i+1] - arr[i]) == (arr[i+2] - arr[i+1])){
			next = apseq(arr, res, i, flag);
			flag = 0;
		}
		else if (arr[i+1] / arr[i] == arr[i+2] / arr[i]){
			next = gpseq(arr, res, i);
		}
		i +=1;
	}
	return res;
}