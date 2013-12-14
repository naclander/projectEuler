#include<stdio.h>

//Uses a simple (inneficient) method of finding primes.

#define TARGET 10001

int is_prime(int num){
  int i;
  for(i = 2; i*i <= num; i++){
    if(num%i == 0){
	  return 0;
	}
  }
  return 1;
}

int main(){
  int count_primes = 0;
  int i;
  for(i = 2;;i++){
    if(is_prime(i)){
	  count_primes++;
	}
	if(count_primes == TARGET){
	  printf("%d\n",i);
	  return;
	}
  }
}
