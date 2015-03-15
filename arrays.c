/* ------------------------------------------------------------------------
Program file: pletc1.c
Athor: Marcos R. Pletcher
Email: marcos_rochapletcher@student.uml.edu
Date: February, 1 2015
Assignment: Program 1
Course #: 90.211.031
Objective: This program will make some calculations in order to find the average, maximum, minimum, and median grades of an exam. First, it will prompt for class name, number of grades, and grades to the user. Afterwards, It will check each grade, through if statement for outputting valuated results.
--------------------------------------------------------------------------- */
#include <stdio.h>

void main(void) 

{
	
	/* Variable Declarations. */ 
	/* --------------------- */
	
	float classAverage, t, medGrade = 0;
	int grades[50];
	int maxGrade = 0;
	int minGrade = grades [0];
	int numGrades, i, j, totalGrades=0;
	
	/* Program declares variables character array to store a name. */
	/* --------------------------------------------------------- */

	char    className[10];  

     /* It srompts user to type his/her class name. */
     /* ------------------------------------------ */

     printf ("Please enter your class name: ");
	 gets(className);     
     fflush(stdin);

	/* Output initial greeting. */
	/* ----------------------- */ 	
 	
 	printf ("\nWelcome to the %s Grade Calculator.\n\n", className);

  	/* Program prompts user to input his/her number of grades. */
 	/* Program checks if those inputs are correct. */
 	/* --------------------------------------------- */
 	
 	do
 	{
    	printf ("\nEnter the number of grades to process (1 - 50): ");
    	scanf  ("%i", &numGrades);
    	fflush(stdin);
    
    	if (numGrades < 0 || numGrades > 50)
   	 	printf("Error: Number of grades must be between 0 and 50, please re-enter.\n\n");
   	 	continue;
      
 	} while (numGrades < 0 || numGrades > 50);  /* End do-while. */ 
 	
	/* For Loop processes each student grades. */
	/* ------------------------------------- */  
	
	for (i = 0; i < numGrades; i++)
 	{
 		
  	  
		do
	  	{
			printf ("Enter grade for student #%i: ", i+1);
			scanf  ("%i", &grades[i]);
			fflush(stdin);
			
				
		/* Conditional statament tests entered grades */
		/* ---------------------------------------- */ 
		
		if (grades[i] > 100 || grades[i] < 0)
			printf("\n*** Invalid grade entered. Please enter 0 - 100. ***\n");
  			continue;
	
		} while (grades[i] > 100 || grades[i] < 0);  /* End do-while */ 
   		 
		/* If statement finds the maximum and mininum grades. */
					
			if(grades[i] > maxGrade)
  		   	{	
				 maxGrade = grades[i];
  		   	}
 	 		if(grades[i] < minGrade)
  			{	
				  minGrade = grades[i];
  			}
  			
 		/* It adds up all grades to total grades . */
		/* ------------------------------------ */	
		
		totalGrades = totalGrades + grades[i];   
 
	}; /* End the For Loop. */	

	/* For loop, after checking every number entered, processes in ascending order those values. */
	/* ------------------------------------------------------------------------------- */  		  
	
	for (i=0; i < numGrades; i++)
		{	
			for (j = 0; j < numGrades; j++)
			{
				if (grades[j] > grades [j+1])
				{
		
			t = grades[j];
			grades[j] = grades[j+1];
			grades[j+1] = t;
		
				}
		else continue;
	
				}
		} /* End the For Loop. */
		
	/* It outputs the ascending array. */
	/* ------------------------------- */  	
			
 	printf ("\nThe %i grades sorted:\n\n", numGrades);
	for (i=0; i < numGrades; i++)
	printf ("%i ", grades[i]);
	  
			
		
	/* Program calculates the calculate the class average grade. */	
	/* --------------------------------------------------------- */  	
			
	classAverage = totalGrades / numGrades;

   	
 	/* Program calculates the median grade. */
	/* ---------------------------------- */  

	if( numGrades % 2 == 0) 
		medGrade = (float)(grades[numGrades / 2-1] + (float)grades[numGrades / 2 ]) / 2;
	
	else  
		medGrade = grades[numGrades / 2 + 1];
	    	
	/* It outputs the minimum grade */
	/* ------------------- */  
					
	printf ("\n\nThe minimum is %i", minGrade);
    	
	/* It outputs the maximum grade */
	/* ------------------- */ 
		    			
	printf ("\nThe maximum is %i", maxGrade);
		
	/* It outputs the median grade */
	/* ------------------------- */ 
						
	printf ("\nThe median grade is %2.1f\n", medGrade );

	/* It outputs the class average grade */
	/* --------------------------------- */ 
						
	printf ("\n\nThe %s class average rounded is %.0f\n", className, classAverage);
				
	getchar(); /* Wait for character. */
			
} /* End main. */
