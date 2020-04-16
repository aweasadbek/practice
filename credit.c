#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h> 

int calc(long x, int length);

int main(void)
{
//Get input from the user, repeat until the number of digits is other than 15,16,13
    long number = get_long("Number: ");
//Find the length of the input
    int number_length = floor(log10(labs(number))) + 1;
//Find the first two digits in the input
    int first_two = floor(number / (pow(10, number_length - 2)));
    int first = floor(number / (pow(10, number_length - 1)));
//Check the type of credit card
//Check whether input is AMEX card
    if (number_length == 15 && (first_two == 34 || first_two == 37))
    {
//Run function calc() which checks Luhn's Algorithm and return 1 if Valid and 0 if invalid
        int a = calc(number, number_length);
        if (a) 
        {
            //If a = 1
            printf("AMEX\n");   
        } 
        else
        {
            //if a = 0
            printf("INVALID\n");
        }
//Check if input is MASTERCARD
    } 
    else if (number_length == 16 && first_two > 50 && first_two < 56)
    {
        int a = calc(number, number_length);
        if (a) 
        {
            printf("MASTERCARD\n");
        } 
        else
        {
            printf("INVALID\n");
        } 
//Check if input is VISA 
    }
    else if (number_length == 16 && first == 4) 
    {
        int a = calc(number, number_length);
        if (a) 
        {
            printf("VISA\n");
        } 
        else 
        {
            printf("INVALID\n");
        }
    } 
    else
    {
        printf("INVALID\n");
    }
}


//Function that calculates the Algorithm

//Takes card number as copy, and the number of digits as length
int calc(long copy, int length)
{
//Set count, which would hold the sum
    int count = 0;
//Declare number which would hold each digit in iteration
    int number;
//Uncomment the next line for debugging
//    printf("length: %i\n number: %li\n", length, copy);
//Check if the number of digits is even
    if (length % 2 == 0) 
    {
//Iterate throught each digit from right to left
        for (int i = length - 1; i >= 0; i--)
        {
//set off each digit
            number = floor(copy / pow(10, i));
//Uncomment the next line for debugging
//            printf("i: %i\n, copy %li\n number: %i\n", i,copy, number);
//Check if i is odd, if odd multiply by two and add digits to count,
//otherwise just add to count
            if (i % 2 != 0) 
            {
//Check whether current digit is large than 4 
                if (number > 4)
                {
//If result of multiplication is higher than 9, set off each digit, and add 
                    count += (2 * number - 10) + 1; 
                }
                else 
                {
                    count += 2 * number;
                }
            } 
            else 
            {
                count += number;
            }
            copy -= number * pow(10, i);
        }
    } 
    else 
    {
//Same as the last root if clause, differnce is that this is for inputs with odd numbers of digits
        for (int i = length - 1; i >= 0; i--)
        {
            number = floor(copy / pow(10, i));
            printf("i: %i\n, copy %li\n number: %i\n", i, copy, number);
            if (i % 2 != 0) 
            {
                if (number > 4)
                {
                    count += (2 * number - 10) + 1; 
                } 
                else 
                {
                    count += 2 * number;
                }
            } 
            else 
            {
                count += number;
            }
            copy -= number * pow(10, i);
        }
    }
//Check whether the total modulo 10 is congruent to 10
//If yes return 1, otherwise 0
    int result = (count % 10 == 0) ? 1 : 0;
//Uncomment for debugging
    printf("result: %i;\n count: %i\n", result, count);
    return result;
}
