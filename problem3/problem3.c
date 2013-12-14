#include<stdio.h>

//The i*i <= num condition must be present in is_prime or else is_prime takes
//far too much time.  We can count up until sqrt(num) instead of all the way to
//num/2

//This program iterates through all numbers between 2 and sqrt(TARGET) and
//checks if they are prime AND if they are factors of TARGET.

#define  TARGET  600851475143


int is_prime(int num){
  long long int i;
  for(i = 2; i*i < num; i++){
    if( num %i == 0){      
	  return 0;
    }
  }
  return 1;
}

int main(){
  long long int i;
  long long int largest_prime_factor = 0;
  for(i = 2; i*i < TARGET; i++){
    if(is_prime(i) && TARGET%i == 0){
	  largest_prime_factor = i;
	}
  }
  printf("%d\n",largest_prime_factor);

}
