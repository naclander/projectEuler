#include<stdio.h>

#define TARGET 500


//This function finds the factors of given num. 
//More information on the divisor function can be found here: 
//https://en.wikipedia.org/wiki/Divisor_function
//but explained better here:
//http://stackoverflow.com/questions/2844703/algorithm-to-find-the-factors-of-a-given-number-shortest-method
//Basically:
//If we can write num as n = p1^e1 * p2^e2 * ... * pk^ek where
//p is a prime number, then:
//numb_factors = (e1 + 1)*(e2 + 1)* ... *(ek + 1)
int get_num_factors(int num){
	int num_factors = 1;
	int number= num;
	int i;
	for(i = 2; i*i <= num; i++){
		int power = 0;
		while(number%i == 0){
			power++;
			number /= i;
		}
		num_factors *= (power + 1);
	}
	if( number > 1){
		num_factors *= 2;
	}
	return(num_factors);
}

int main(){
	int tri_num = 0;
	int i;
	for(i = 1;; i++){
		tri_num += i;
		if(get_num_factors(tri_num) > TARGET){
			printf("%d\n",tri_num);
			return;
		}
	}
}
