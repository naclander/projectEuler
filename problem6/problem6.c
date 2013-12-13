#include<stdio.h>

//Calculate square of sums and sum of squares first, then subtract them.

#define TARGET 100

int get_sum_of_squares(){
  int i;
  int sum= 0;
  for(i = 1; i <= TARGET; i++){
    sum += i*i;
  }
  return sum;
}
int get_square_of_sums(){
  int i;
  int sum = 0;
  for(i = 1; i <= TARGET; i++){
    sum += i;
  }
  return sum*sum;
}

int main(){
  int sum_of_squares = get_sum_of_squares();
  int square_of_sums = get_square_of_sums();
  printf("%d\n",square_of_sums - sum_of_squares);
}
