#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TARGET_BASE 2
#define TARGET_EXPONENT 1000

//Similar to problem 13, I created a structure to hold an n-digit integer. 
//I used this data structure to hold the value of 2^1000 (which I found by 
//iteratively adding and doubling) and then iterating through each digit and
//adding them together.

//Data structure to hold my n-digit number
typedef struct large_num{
	int * large_num_array;
	int size;
} LargeNum;

int count_elems(int * array, int size){
	int sum = 0;
	int i;
	for(i = 0; i < size; i++){
		sum += array[i];
	}
	return sum;	
}

void double_large_num(LargeNum * large_number){
	int carry = 0;	
	int size = large_number->size;
	int * num_array = large_number->large_num_array;
	int i;
	for(i = size - 1; i >= 0; i--){
		if((num_array[i] = num_array[i] * 2 + carry) >= 10){
			carry = 1;
			num_array[i] = num_array[i] % 10;
		}
		else{
			carry = 0;
		}
	}
	if(carry){
		int * bigger_num_array = malloc((size + 1)*sizeof(int));
		memcpy(bigger_num_array + 1, num_array, size*sizeof(int));
		bigger_num_array[0] = 1;
		free(num_array);
		large_number->large_num_array = bigger_num_array;
		large_number->size += 1;			
	}
}

void mult_large_num(LargeNum * large_multiplier, int num){
	int i;
	for(i = 2; i <= num; i++){
		double_large_num(large_multiplier);
	}
}

//Exponentiate the base by multuplying it with itself "exponent" times.
void pow_large_num(LargeNum * large_base, int exponent){
	int i;
	for(i = 2; i <= exponent; i++){
		mult_large_num(large_base, TARGET_BASE);
	}
}

int main(){
	LargeNum large_exponent;
	large_exponent.large_num_array = malloc(1*sizeof(int));
	large_exponent.large_num_array[0] = TARGET_BASE;
	large_exponent.size = 1;
	pow_large_num(&large_exponent, TARGET_EXPONENT);
	printf("%d\n",
		   count_elems(large_exponent.large_num_array,
					   large_exponent.size));
}
