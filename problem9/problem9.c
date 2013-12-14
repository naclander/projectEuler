#include<stdio.h>
#include<math.h>

//Simple implementation. Iterate through all potential a's and b's looking for
//a c that adds up to TARGET, and fits the Pythagorean theorem.

#define TARGET 1000

int main(){
  int a,b,c;
  for(a = 1; a <= TARGET; a++){
    for(b = 1; b <= TARGET; b++){
	  //Gurantee a + b + c sum up to TARGET
	  c = TARGET - a - b;
	  double potential_c = hypot(a,b);
	  //Check whether our potential c is a perfect square and adds up to TARGET
	  if(potential_c == floor(potential_c) && potential_c == c){
	    printf("%d\n",a*b*c);
		return;
	  }
	}
  }
}
