#include<stdio.h>
#include<stdlib.h>

#define TARGET 1000000

//Iterate over all numbers under 1 million, keeping track of the longest chain
//for each one. Numbers in the chain got quite big, hence the usage of 
//long long int.

get_c_seq(unsigned long long int seq_start){
	if(seq_start < 0){
		printf("neg seq_start\n");
		exit(1);
	}
	if(seq_start == 1){
		return(0);
	}
	if(seq_start%2 == 0){
		return(1 + get_c_seq(seq_start/2));
	}
	else{
		return(1 + get_c_seq(3*seq_start + 1));
	}
}

int main(){
	int i;
	unsigned long long int largest_c_seq = 0;
	unsigned long long int starting_c_seq_num = 0;
	for(i = 1; i < TARGET; i++){
		unsigned long long int new_c_seq = get_c_seq(i);
		if(new_c_seq > largest_c_seq){
			largest_c_seq = new_c_seq;
			starting_c_seq_num = i;
		}
	}
	printf("%d\n",starting_c_seq_num);
}
