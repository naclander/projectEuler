#include<stdio.h>


//Values <10 are factors of the values 11<x<20 
//so we do not need to check these
int is_evdev_20(int num){
  int i;
  for(i = 11;i<=20;i++){
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
