/* ------------------------------------------------------------------------
Program file: pletc3.c
Author: Marcos R. Pletcher
Email: marcos_rochapletcher@student.uml.edu
Date: March, 1 2015
Assignment: Program #3
Course #: 90.212.061
Objective: Program will prompt the client to input personal information, 
such as his/her name, address, city, state, zip code, age, and gender.
After validating this inputted data, it displays a block of information.

--------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

/* Info structure */
/* -------------- */

struct info
	{
		char 		name [35];
  		char 		address[50];
  		char 		city[25];
  		char 		state[3];
  		long int 	zipCode;
  		int 		age;
  		char 		gender;
 	};


/* Main Function */
/* -------------*/

int main()
{

	/* Variable Declarations. */ 
	/* --------------------- */
	
 	int 	numClients;
 	int 	i;
 	struct	info clients[10];

	/* Display initial greeting */
	/*--------------------------*/
 	
 	printf ("Welcome to the Pletcher Form!\n\n");
 
 	printf ("How many clients would you like to input(from 1 to 10)?\n");
 
 	scanf ("%i", &numClients);
 	fflush (stdin);
 
 	/* while loop traps user to input number of clients. */
 	/* ------------------------------------------------- */
 
 	while (numClients < 1 || numClients > 10)
 	{
  		printf ("Please, type a number of clients from 1 to 10.\n");
  		scanf ("%i", &numClients);
  		fflush (stdin);
 	}
 

	/* Loop for each input. */
	/*----------------------*/
 
 	for (i = 0; i < numClients; i++)
 	{
  		printf ("\nEnter name: ");
  		gets (clients[i].name);
  
	  	printf ("Enter street address: ");
	  	gets(clients[i].address);
	  
	  	printf ("Enter city: ");
	  	gets (clients[i].city);
	  
	  	printf ("Enter state: ");
	  	scanf("%2s", clients[i].state);
	  	fflush (stdin);
	  
	  	printf ("Enter zip code: ");
	  	scanf ("%ld", &clients[i].zipCode);
	  	fflush (stdin);
	  
	  	printf ("Enter age: ");
	  	scanf ("%i", &clients[i].age);
	  	fflush (stdin);
	  
	  	printf ("Enter gender (M or F): ");
	  	clients[i].gender = getchar();
	  	fflush (stdin);
	  
		/* While loop checks if client is inputting an age between 1 and 120. */
		/* ----------------------------------------------------------------- */
	  
	  	while (clients[i].age < 1 || clients[i].age > 121)
	  	{ 
	   		printf ("*** Invalid age. Please, type an age from 1 to 120. ***\n");
	   		scanf ("%i", &clients[i].age);
	   		fflush (stdin);
	   		
		} /* End While loop. */
		
		/* While loop checks if client is inputting a gender of "m", "M", "f", "F", or space. */
		/* ----------------------------------------------------------------- */
		
		while (clients[i].zipCode < 1 || clients[i].zipCode > 99999)
	  	{ 
	   		printf ("*** Invalid zip code. Please enter a valid 5-digit zip code.***\n");
	   		scanf ("%ld", &clients[i].zipCode);
	   		fflush (stdin);
	   		
		} /* End While loop. */
		
		/* While loop checks if client is inputting a gender of "m", "M", "f", "F", or space. */
		/* ----------------------------------------------------------------- */
		
		while (clients[i].gender != 'm' && clients[i].gender != 'M' 
		&& clients[i].gender != 'f' && clients[i].gender != 'F' && clients[i].gender != ' ')
	  	{ 
	   		printf ("*** Invalid gender. Please, type m, f, or leave blank by entering space. ***\n");
	   		scanf ("%c", &clients[i].gender);
	   		fflush (stdin);
	   		
		} /* End While loop. */
	  
	  	printf ("\n");
  
	} /* End For loop. */
 
 	printf ("The information you entered is: \n\n");
 
 	for (i = 0; i < numClients; i++)
 	{
  		printf ("%s\n%s\n%s, %s %05ld\n", clients[i].name, clients[i].address, clients[i].city, 
		  clients[i].state, clients[i].zipCode);
  
   	/* Conditional statements checks the client genders. */
   	/* ------------------------------------------------ */
  
   if (clients[i].gender == 'm' || clients[i].gender == 'M')
    printf ("He is %i years old.\n\n", clients[i].age);
    
   else if (clients[i].gender == 'f' || clients[i].gender == 'F')
    printf ("She is %i years old.\n\n", clients[i].age);
   
   else
    printf ("Age is %i\n", clients[i].age);
    
 	} /* End For loop. */
 

return 0;
 
} /* End Main. */
