#include<stdio.h>

//Starting from 0,check whether the current number is divisible by 11 - 20


#define TARGET 20

//Values <10 are factors of the values 11<x<20 
//so we do not need to check these. If TARGET changes then there are possibly
//more numbers we can skip
int is_evdev_20(int num){
  int i;
  for(i = 11;i<=TARGET;i++){
    if(num%i != 0){
	  return 0;
	}
  }
  return 1;
}

int main(){
 int i = 1;
 while(1){
   if(is_evdev_20(i)){
     printf("%d\n",i);
	 return;
   }
   i++;
 } 
}
