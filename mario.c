#include <cs50.h>
#include <stdio.h>

//Declaration of functions to use them inside main function
void build(int x);
int get(void);

//main logic of program
int main(void)
{
//Get input from user, using function get
   int number = get();
//Difficult to explain, so take a look 
   for (int i = 1; i <= number; i++)
   {
	for (int j = 0; j < number - i; j++)
	{
		printf(" ");
	}
	build(i);
   }
}

void build(int x)
{	
//Define each case for each integer between 1 and 8 both inclusive
    switch(x)
    {
	case 1:
	    printf("#  #\n");
	    break;
	case 2:
	    printf("##  ##\n");
	    break;
	case 3:
	    printf("###  ###\n");
	    break;
	case 4:
	    printf("####  ####\n");
	    break;
	case 5:
	    printf("#####  #####\n");
	    break;
	case 6:
	    printf("######  ######\n");
	    break;
	case 7:
	    printf("#######  #######\n");
	    break;
	case 8:
	    printf("########  ########\n");
	    break;
    }
}

int get(void)
{
    int number;
    do
    {
	number = get_int("Height: ");
    }
//Checking whether input is integer between 1 and 8 both inclusive
    while (number < 1 || number > 8);
    return number;
}	
