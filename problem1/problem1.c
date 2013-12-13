#include<stdio.h>

#define TARGET 1000

//Simple for loop checking if the iterator is divisible by 3 or 5, and if so
//adds the value to sum variable.

int main(){
  int i;
  int sum = 0;
  for(i = 0; i < TARGET; i++){
    if(i % 3 == 0 || i % 5 == 0){
	  sum += i;
	}
  }
  printf("%d\n",sum);
}
