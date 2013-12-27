#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TARGET 100

//I solved this problem by using a data structure to hold n-digit numbers,
//and then taking the factorial of a number and storing it in the n-digit
//number. Factorial was implemented by repeatedly adding numbers.
//The algorithm to add 2 n-digit numbers is replicated from problem 13.

//Data structure to hold an n-digit number
typedef struct large_num{
	int * large_num_array;
	int size;
} LargeNum;

init_large_num(LargeNum * num){
	num->large_num_array = malloc(1*sizeof(int));
	num->size = 1;
}

//Copy num1 into num2
copy_large_num(LargeNum * num2, LargeNum * num1){
	num2->large_num_array = malloc(num1->size*sizeof(int));
	memcpy(num2->large_num_array, num1->large_num_array,num1->size*sizeof(int));
	num2->size = num1->size;
}

delete_large_num(LargeNum * num){
	free(num->large_num_array);
}

int digit_sum(LargeNum * num){
	int sum = 0;
	int i;
	for(i = 0; i < num->size; i++){
		sum += num->large_num_array[i];
	}
	return(sum);
}

void add_large_nums(LargeNum * large_num1, LargeNum * large_num2){
	int carry = 0;
	int sum = 0;
	int size1 = large_num1->size;
	int size2 = large_num2->size;
	int * num_array1 = large_num1->large_num_array;
	int * num_array2 = large_num2->large_num_array;
	int i,k;
	//add two n-digit numbers, propigating the carry along
	for(i = size2 - 1, k = size1 - 1; i >= 0; i--, k--){
		sum = num_array2[i] + num_array1[k] + carry;
		carry = (sum - sum%10)/10;
		num_array1[k] = sum % 10;
	}
	//propigate carry if there are more digits
	if(k > i){
		for(; k >= 0; k--){
			sum = num_array1[k] + carry;
			carry = (sum - sum%10)/10;
			num_array1[k] = sum%10;	
		}
	}
	//Increase our n-digit array by 1 of carry still present
	if(carry){
		int * bigger_num_array = malloc((size1 + 1)*sizeof(int));
		memcpy(bigger_num_array + 1, num_array1, size1*sizeof(int));
		bigger_num_array[0] = 1;
		free(num_array1);
		large_num1->large_num_array = bigger_num_array;
		large_num1->size += 1;			
	}
}

void mult_large_num(LargeNum * num, int target){
	LargeNum temp_large_num;
	init_large_num(&temp_large_num);
	copy_large_num(&temp_large_num,num);
	int i;
	for(i = 1; i < target; i++){
		add_large_nums(num,&temp_large_num);
	}
	delete_large_num(&temp_large_num);
}

void fact_large_num(LargeNum * num, int target){
	num->large_num_array[0] = 1;
	int i;
	for(i = 2; i <= target; i++){
		mult_large_num(num,i);
	}
}

int main(){
	LargeNum large_factorial;
	init_large_num(&large_factorial);
	fact_large_num(&large_factorial,TARGET);
	printf("%d\n",digit_sum(&large_factorial));
}
