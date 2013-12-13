#include<stdio.h>
#include<string.h>
#include<stdlib.h>// for malloc 
#include<math.h>  // for pow

//This seems to me like a rather naive implementation. I will try to make it 
//better in the future.
//
//I iterate over all products of 3 digit numbers and check if those are 
//palindromes.
//
//I check for number palindromes by first sprintf'ing the number into a 
//string (this is the part that I don't like). The solution is also rather slow
//but it works for now.

#define TARGET 3 //Number of digits

int is_palindrome(char * str){
  int end = strlen(str) - 1;
  int begin = 0;
  while(begin < end){
    if(str[begin] == str[end]){
	  begin++;
	  end--;
	  continue;
	}
	return 0;
  }
  return 1;
}

int is_num_palindrome(int num){
  char * s_num = malloc(1024);
  sprintf(s_num,"%d",num);
  return is_palindrome(s_num);
}

int main(){
     int largest_pal = 0;
	 int num = pow(10,TARGET)-1;
     int num1 = num;
	 int num2 = num;
	 for(;num2 > 0; num2--){
	   for(;num1 > 0; num1--){
	     int cur_sum = num1*num2;
         if(is_num_palindrome(cur_sum)){
		   if(cur_sum > largest_pal){
		     largest_pal = cur_sum;
		   }
	     }
	   }	 
	   num1 = num;
	 }
	 printf("%d\n",largest_pal);
}
