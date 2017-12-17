/*
Developer - Gitanjali Ghodake
Version - 1.0.0
Date - 14/12/2017

Information about Program -

This program accepts user input of number of consecutive/repeating 1's. And then calculates it's square.
E.g. If user enters number of consecutive 1's = 5 then it calculates (11111)^2 = 123454321.
User may enter any number of consecutive 1's  to be squared (less than or equal to 2^32 - 1). 
This program uses innovative logic & pattern recognition to calculate the result within fraction of seconds. 
Without this approach high end computers may also take few hours to calculate it. The result is calculated in three parts ' front' 'middle' & 'back'.
Similarly in future this can be extended with a logic to calculate the square of other consecutive/repeating numbers.

*/

# include <stdio.h>

void main()
{
	unsigned long int n, r , q;
	char ch;
	char *Y;
		
	do
	{
		printf ("Enter the number of consecutive 1's to be squared = ");
		scanf ("%d", &n);
		
		printf ("Square = ");
		
		r = n%9;
		q = n/9;
		
		
		if (r == 0 && q != 0) //This is a special case if n is multiple of 9 AND > 0. In this case update the 'r' & 'q' values.		
		{
			r = 9;
			q = q-1;
		}
		
		
		if (n>9)//Print the front part of the result
		{
			if (q>1)
				printf ("...(Duplicate %lu more times)<-- [123456790]", q-1); //We don't need to actually print the repetitive part on the screen.
			else printf ("123456790");//This will avoid a message to print it '0' times.
		}	
		
			
		switch (r)
		{
			default:
			Y = "Invalid";
			break;
			case 1:
			Y = "";
			break;
			case 2:
			Y = "12";
			break;
			case 3:
			Y = "1232";
			break;
			case 4:
			Y = "123432";
			break;
			case 5:
			Y = "12345432";
			break;
			case 6:
			Y = "1234565432";
			break;
			case 7:
			Y = "123456765432";
			break;
			case 8:
			Y = "12345678765432";
			break;
			case 9:
			Y = "1234567898765432";
			break;
		}
		
		printf ("%s", Y);//Print the Middle part of the result
		

		if (n>9)//Print the back part of the result
		{
			if (q>1)
				printf ("[098765432]-->(Duplicate %lu more times)...[1]", q-1);//We don't need to actually print the repetitive part on the screen.
			else printf ("0987654321");//This will avoid a message to print it '0' times.
		}	
		else if (r !=0)//If n<9 & !=0 
		{
			printf ("1");
		}	
			
	
		printf ("\nDo you want to continue: y/n = ");
		scanf (" %c", &ch);
		
		
	}while (ch == 'y');

}
	
	
	