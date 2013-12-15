#include<stdio.h>

//We have to use an integer type that supports at least 12 digits, hence the 
//usage of the long long int type in this problem. 
//
//Simply iterates over all primes below 2*10^6 and adds them.

#define TARGET 2000000

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
  long long int sum = 0;
  int i;
  for(i = 2;i < TARGET; i++){
    if(is_prime(i)){
	  sum += i;
	}
  }
  printf("%lld\n",sum);
  return;
}
