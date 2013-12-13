#include<stdio.h>

#define TARGET 4000000

//Fib sequence using a for loop
//I started the sequence on the third number, which is why the sum
//begins at 2.

int main(){
  int i;
  int sum = 2;
  int current;
  int last = 2;
  int last_last = 1;

  for(i = 2;;i++){
    current = last + last_last;

	if(current > TARGET){
	  break;
	}

	last_last = last;
	last = current;

	if(current %2 == 0){
	  sum += current;
	}

  }
  printf("%d\n",sum);
}
