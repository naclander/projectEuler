#include<stdio.h>

#define TARGET 10000

//To solve this problem I created a table where table[index] represented
//the sum of the index's divisers. To find amicable numbers we can compare 
//whether index == table[table[index]]

//Returns the sum of all proper divisibles
int get_sum_prop_divs(int num){
	int sum = 1;
	int i;
	for(i = 2; i <= num/2; i++){
		if(num % i == 0){
			sum += i;
		}
	}
	return(sum);
}

int main(){
	int sum = 0;
	int proper_divs[TARGET];
	int i;
	for(i = 0; i < TARGET; i++){
		proper_divs[i] = get_sum_prop_divs(i);
	}
	for(i = 0; i < TARGET; i++){
		int num1 = i;
		//Don't check table if sum of divisers is >=TARGET
		if(proper_divs[i] >= TARGET){
			continue;
		}
		int num2 = proper_divs[proper_divs[i]];
		if(num1 == num2 && num1 < proper_divs[i]){
			sum += num1 + proper_divs[i]; 
		}
	}
	printf("%d\n",sum);
}
