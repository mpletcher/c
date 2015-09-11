/* ------------------------------------------------------------------------
Program file: pletchp5.c
Author: Marcos R. Pletcher
Email: marcos_rochapletcher@student.uml.edu
Date: November, 16 2014
Assignment: Program 5
Course #: 90.211.031
Objective: This banking system program will take an initial balance amount typed by its user, add deposits also typed for the user, decrease withdrawals from total balance. 
Subsequently, after checking for invalid entries, it will print out a final report. 
--------------------------------------------------------------------------- */
#include <stdio.h>
#include <conio.h>

void main(void) 
{
	
	
	/* Variable Declarations. */ 
	/* --------------------- */

	float deposit[50], withdrawal[50], totalBalance, startBalance = 0.0;
	int i, numberDeposit, numberWithdrawal;

	/* Declare variables character array to store a name. */
	/* ------------------------------------------------ */
	char    clientName[20];   
	 	
	/* Output initial greeting. */
	/* ----------------------- */ 	
 	
 	printf ("Welcome to the Pletcher Banking System.\n\n");
          
     /* Prompt user to type his/her name. */
     /* ------------------------------- */

     printf ("Please enter your name: ");
     scanf ("%s", clientName);      
     fflush(stdin);

     /* Display first name back to user. */

     printf ("\nHello %s.\n\n", clientName);
     
     /* Prompt user to type his/her current balance. */
 	/* ----------------------------------------- */
 
 	do
 	{
    	printf ("Enter your current balance in dollars and cents: ");
    	scanf  ("%f", &startBalance);
    	fflush(stdin);
    
    	if (startBalance < 0.0)
    	printf("Error: Beginning balance must be at least zero, please re-enter.\n\n");
    	continue;
    	
 	}while (startBalance < 0.0);  /* End do-while. */ 
 	
 	totalBalance = startBalance;
 	
 	/* Prompt user to input his/her number of withdrawals. */
 	/* Program checks if those inputs are correct. */
 	/* ------------------------------------------------- */
 	
 	do
 	{
    	printf ("\nEnter the number of withdrawals: ");
    	scanf  ("%i", &numberWithdrawal);
    	fflush(stdin);
    
    	if (numberWithdrawal < 0 || numberWithdrawal > 50)
      	printf("Error: Number of withdrawals must be between 0 and 50, please re-enter.\n\n");
      	continue;
      	
 	} while (numberWithdrawal < 0 || numberWithdrawal > 50);  /* End do-while. */ 

  	/* Prompt user to input his/her number of deposits. */
 	/* Program checks if those inputs are correct. */
 	/* --------------------------------------------- */
 	
 	do
 	{
    	printf ("\nEnter the number of deposits: ");
    	scanf  ("%i", &numberDeposit);
    	fflush(stdin);
    
    	if (numberDeposit < 0 || numberDeposit > 50)
   	 	printf("Error: Number of deposits must be between 0 and 50, please re-enter.\n\n");
   	 	continue;
      
 	} while (numberDeposit < 0 || numberDeposit > 50);  /* End do-while. */ 
 	
	/* For Loop processes the deposit amount. */
	/* ------------------------------------- */  
	
	for (i = 0; i < numberDeposit; i++)
 	{
 		
  	/* Trap Loop for deposit amount.  */
 	/* ----------------------------- */
	  
		do
	  	{
			printf ("Enter the amount of deposit #%i: ", i+1);
			scanf  ("%f", &deposit[i]);
			fflush(stdin);
      
			if (deposit[i] <= 0.0)
			printf("\nDeposit amount must be positive! Please re-enter.\n");
  			continue;
	
		} while (deposit[i] <= 0.0);  /* End do-while */ 		
	
		/* It adds up all good deposits to total balance. */
		/* --------------------------------------------- */
	
		totalBalance = totalBalance + deposit[i];
	
	}/* End the For Loop. */
		
	/* For Loop processes the amount of withdrawals. */
	/* ------------------------------------------- */  
	
 	for (i = 0; i < numberWithdrawal; i++)
 	{
 		/* Prompt use to input his/her withdrawal amounts. */
  		/* Trap Loop checks if his/her amount is bigger than zero and if his/her balance is positive. */
 		/* ----------------------------------------------------------------------------------------- */
 		
		  	if (totalBalance == 0)
		  	printf("\n*** I'm sorry but your balance is at zero and no further withdrawals are permitted.***\n");
	  		if (totalBalance == 0)
		  	break;
  		do
  		{
			printf ("Enter the amount of withdrawal #%i: ", i+1);
			scanf  ("%f", &withdrawal[i]);
			fflush(stdin);
      								    			
  			if (withdrawal[i] <= 0.0 || withdrawal[i] > totalBalance)
			printf("\n*** Withdrawal amount exceeds current balance. ***\n"); 			
  			continue;
			
		} while (withdrawal[i] <= 0.0 || withdrawal[i] > totalBalance);  /* End do-while. */ 

		/* It decreases all good withdrawals to total balance. */
		/* -------------------------------------------------- */
	
		totalBalance = totalBalance - withdrawal[i];
		
	}/* End the For Loop. */				
				
	/* Output the ending balance. */
	/* ------------------------ */ 	

	printf ("\n*** The closing balance %s is $%.2f\n", clientName, totalBalance);
	
 	/* Through an If statement, the program outputs a message for different ending balances. */
 	/* ----------------------------------------------------------------------------------- */

	if (totalBalance > 0.00 || totalBalance < 999.99)
  		printf ("*** %s your balance is getting low. ***\n\n", clientName);
  	else
	if (totalBalance > 1000.00 || totalBalance < 14999.99)
  		printf ("*** %s keep up the good work! ***\n\n", clientName);	  	
 	else 
	if (totalBalance > 15000.00 || totalBalance < 49999.99)
  		printf ("*** %s maybe you should consider a CD. ***\n\n", clientName);  		
 	else
 	if (totalBalance >= 50000.00)
  		printf ("*** %s it is time to invest some money! ***\n\n", clientName);
  					 
 	/* Final Report header. */
 	/* ------------------ */
	 	 		 
	printf("*** Banking Summary ***	\n");
	
 	/* Initial Balance. */
 	/* -------------- */
 	
	printf("Start Balance:$	%14.2f\n", startBalance);
	printf("\n");
	
	/* Deposit Report. */
 	/* -------------- */		 	

	for(i = 0; i < numberDeposit; i++)
	{
		
		printf("Deposit #%i	%14.2f\n", i + 1, deposit[i]);
		
	}; /* End the For Loop. */
	
	/* Withdrawal Report. */
 	/* ---------------- */	 
 	
	printf("\n");
	for(i = 0; i < numberWithdrawal; i++)
	{
		
		printf("Withdrawal #%i	%14.2f\n", i + 1, withdrawal[i]);

	}; /* End the For Loop. */
	
	/*Program Displays the ending balance. */
 	
	printf ("\nEnding Balance:$%14.2f\n", totalBalance);
       
getchar(); /* Wait for character. */
	
} /* End main. */
