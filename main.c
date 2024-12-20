//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;
static int consumed_cal = 2000;   //Recommended daily calories consumed

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadExercises(EXERCISEFILEPATH);     //load exercise list
    loadDiets(DIETFILEPATH);   // load diets list
	loadHealthdata();    
    

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	if (consumed_cal == 0){          //consumed_calories are zero
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        } 
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	loadExercises(EXERCISEFILEPATH);  //output exercise list
                break;
                
            case 2:
            	loadDiets(DIETFILEPATH);   //output diets list
                break;
                
            case 3:
            	printHealthdata();   //output current information based on the exercise and intake by selected by the user
                break;
                
            case 4:
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        } 
    } while (choice != 4);

    return 0;
}