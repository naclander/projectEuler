#include<stdio.h>

#define TARGET 20

//This solution is *techinically* correct (the best kind of correct) but it is
//awefully slow.
//TODO: Replace this implementation with a more efficient one. 

long long int count_paths(int r, int c){
	if(r  == 0 || c == 0){
		return(0);
	}
	return( 1 + count_paths(r-1,c) + count_paths(r,c-1));
}

int main(){
  printf("%lld\n",count_paths(TARGET,TARGET) + 1);
}
