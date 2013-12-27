#include<stdio.h>

//I solved this problem by first iterating through the year 1900 to figure out
//which day of the week it was on January 1st 1901, and then counting the 
//Sundays on the first of every month from January 1st 1901 - December 31st 
//2000.

#define monday 		0
#define tuesday 	1
#define wednesday 	2
#define thursday 	3
#define friday 		4
#define saturday 	5
#define sunday 		6

#define january 	0
#define february 	1
#define march 		2
#define april 		3
#define may  		4
#define june  		5
#define july  		6
#define august  	7
#define september 	8
#define october 	9
#define november 	10
#define december 	11

typedef struct Date{
	int day;
	int day_name;
	int month;
	int year;
} date;

int next_month(date * current_date){
	current_date->month = (current_date->month + 1) % 12;
	current_date->day = 0;
	current_date->day_name = (current_date->day_name + 1 ) % 7;
	if(current_date->day_name == sunday){
		return(1);
	}
	return(0);
}

//A leap year occurs on any year evenly divisible by 4, but not on a century 
//unless it is divisible by 400.
int is_leap_year(int year){
	if( year % 100 == 0){
		if(year % 400 == 0){
			return(1);
		}	
		else{
			return(0);
		}
	}
	if(year % 4 == 0){
		return(1);
	}
	return(0);
}

//This function iterates from current_date to count_to_date and counts all 
//Sundays on the first of the month.
int count_sundays(date * current_date, int count_to_date){
	int sum = 0;
	while(current_date->year != count_to_date){
		if(current_date->day == 30){
			if(current_date->month == december){
				current_date->year++;
			}
			sum += next_month(current_date);	
			
		}
		else if(current_date->day == 29 && (current_date->month == april    || 
									   	    current_date->month == june     ||
									   	    current_date->month == september|| 
									        current_date->month == november )){
			sum += next_month(current_date);	
		}	
		else if(current_date->day == 28 && current_date->month == february){
			sum += next_month(current_date);
		}
		else if( current_date->day == 27 && current_date->month == february
										 && !is_leap_year(current_date->year)){
			sum += next_month(current_date);	
		}
		else{
			current_date->day++;	
			current_date->day_name = (current_date->day_name + 1 ) % 7;
		}
	}
	return(sum);
}



int main(){
	date current_date = {0,0,0,1900};
	//Set out date to 1901 so we know what day of the week to start on
	//Note we do not actually care about the number of Sundays in the year 1900,
	//we are just using the function to put us in the correct date.
	count_sundays(&current_date,1901);
	//Count sundays every first of the month
  	printf("%d\n",count_sundays(&current_date,2001));
}
