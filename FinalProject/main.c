/*
 * main.c
 *
 *  Created on: Aug 6, 2024
 *      Author: Hannah
 */

/********Definition or Including Libraries used********/
#include<stdio.h>
#include<stdlib.h>
/****************************************************/

/*******Structure Creation*********/
typedef struct Car /* Creation of Structure to define any car with its own parameters*/
{
	float velocity;
	float engine_temp;
	float room_temp;
}Car; // we used typedef to make the code writing easier

/****************************************************/

char input; // Global Variable to be used in all Functions

/****************************************************/

/*******Functions ProtoTypes********/
void turnoff(char * ip); /* A Function that returns nothing and we send a
variable (Passing by Address) receiving it in a pointer of the same type_char*/

void turnon(Car * ptr_y ); /* A Function that returns nothing and we send a variable (Passing by Address)
receiving it in a pointer of the same type_Structure(pointer to structure)*

 We sent the structure by address to reduce the memory(STACK) consumption as pointer's size
 is the size of address path while if we passed it by value we'll duplicate the memory(STACK)*/

/****************************************************/

/*******Calling the main Function where the code starts running***********/

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);// to print out the statements at its place
	setvbuf(stderr, NULL, _IONBF, 0);

	Car y; // Declaration of Variable y to the type structure car
	printf("Enter Car's Speed: ");
	scanf("%f",&y.velocity); // Scanning the Velocity from the user
	printf("Enter Engine's Temperature: ");
	scanf("%f",&y.engine_temp);
	printf("Enter Room's Temperature: ");
	scanf("%f",&y.room_temp);
	void(*ptr_fn)(char*)=turnoff; // Creation of Pointer to function
	void(*ptr1_fn)(Car *)=turnon; // Creation of Pointer to function
	printf("Please Choose the Car's State:\n a-Turn On the Vehicle's Engine \n b-Turn Off the Vehicle's Engine\n c-Quit the system\n");
	/*printing the system states*/
	scanf(" %c",&input); // taking the input from user
	switch(input) /* switch case and its parameter is the i/p of user,
	 based on his choice the case will compile */
	{
	case 'a':
		(*ptr1_fn)(&y); // calling the turn on function using the pointer to function
		break; // to get out of the switch case after finishing its code
	case 'b':
		(*ptr_fn)(&input); //calling the turn on function using the pointer to function
		if(input == 'c')
		{
			printf("Quit the System\n\n");
			return 0; // to Quit the program directly without finishing it
		}
		else if(input == 'a')
		{
			(*ptr1_fn)(&y);
		}

		break;
	case 'c':
		printf("Quit the System\n\n");
		return 0;
	}
	while(input == 'c') /* we used while loop so the compiler keeps in that loop until
	 the i/p is changed*/
	{
		printf("Quit the System\n\n");
		return 0;
	}
	while(input == 'a')
	{
		(*ptr1_fn)(&y);
	}
	while(input == 'b')
	{
		(*ptr_fn)(&input);
	}
	return 0;
}

/****************************************************/

/*****Functions Used********/

void turnoff(char * ip)
{
	printf("Turn off the Vehicle's Engine\n\n");
	printf("Please Choose the Car's State:\n a-Turn On the Vehicle's Engine \n b-Turn Off the Vehicle's Engine\n c-Quit the system\n");
	scanf(" %c",ip); /* the ip variable is a pointer which points at the global variable input
	 so any change in ip will be saved in input variable as it's passing by address function*/
	return;
}

/****************************************************/

void turnon(Car * ptr_y )
{
	char i_p; // character declaration to use in the switch operation
	char traffic; //character declaration to use in the switch operation
	printf("Turn on the Vehicle's Engine\n\n");
	printf("The Sensors set menu:\n a-Turn off the engine\n b-Set the traffic light color\n c-Set the room temperature\n d-Set the engine temperature");
	scanf(" %c",&i_p);
	/*****I used Nested switch operations**********/
	switch(i_p)//The first switch operation
	{
	case 'a':
		turnoff(&input); // calling the turn off function
		break;
	case 'b':
		printf("Enter the traffic color: ");
		scanf(" %c",&traffic);
		switch(traffic)//the nested switch operation
		{
		case 'g':
			ptr_y->velocity=100.0;/*I used the arrow operator with the pointer to
			structure instead of using (dereference operator with dot operator)*/
			printf("Engine is ON\n");
			if((ptr_y->room_temp < 10.0 || ptr_y->room_temp > 30.0))
				/*if operation to process on the room's temperature*/
			{
				ptr_y->room_temp=20.0; /* accessing the room's temperature using the pointer and changing its value
and its values changed as this function is passing by address not by value*/
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is ON\n");
			}
			else
			{
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is OFF\n");

			}
			printf("Vehicle's Speed = %f Km/Hr \n",ptr_y->velocity);
			if(ptr_y->engine_temp<100.0)
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else if(ptr_y->engine_temp>150.0)
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else
			{
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is OFF\n");
			}
			turnon( ptr_y ); /* calling the function again to represent the sensors menu
			 and choose any other sensor*/
			break;
		case 'o':
			ptr_y->velocity=30.0;
			ptr_y->room_temp = (ptr_y->room_temp * 1.25) + 1;//doing mathematical operations
			ptr_y->engine_temp = (ptr_y->engine_temp * 1.25) +1;
			printf("Engine is ON\n");
			printf("Room Temperature = %f\n",ptr_y->room_temp);
			printf("AC is ON\n");
			printf("Vehicle's Speed = %f Km/Hr \n",ptr_y->velocity);
			printf("Engine Temperature Controller is ON\n");
			printf("Engine Temperature = %f\n",ptr_y->engine_temp);
			input='a';/*another way of calling the function one more time as I wrote in the main
			 function that if input = 'a' call turn on function*/
			break;
		case 'r':
			ptr_y->velocity=0.0;
			printf("Engine is ON\n");
			if((ptr_y->room_temp < 10.0 || ptr_y->room_temp > 30.0))
			{
				ptr_y->room_temp=20.0;
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is ON\n");
			}
			else
			{
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is OFF\n");

			}
			printf("Vehicle's Speed = %f Km/Hr \n",ptr_y->velocity);
			if(ptr_y->engine_temp<100.0)
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else if(ptr_y->engine_temp>150.0)
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else
			{
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is OFF\n");
			}
			turnon( ptr_y );
			break;
		}
		break;
		case 'c':
			printf("Enter the required Room Temperature: ");
			scanf("%f",&ptr_y->room_temp);
			printf("Engine is ON\n");
			if((ptr_y->room_temp < 10.0 || ptr_y->room_temp > 30.0)) /* using logical or to enter execute the code
			 inside if operation if any condition of the conditions inside was true*/
			{
				ptr_y->room_temp=20.0;
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is ON\n");

			}
			else
			{
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is OFF\n");
			}
			printf("Vehicle's Speed = %f Km/Hr \n",ptr_y->velocity);
			if(ptr_y->engine_temp<100.0)
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else if(ptr_y->engine_temp>150.0)//using else if to loop on more than one state
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else /* else is used as if there is no state was found in the if else operations, code inside
			 else will be executed*/
			{
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is OFF\n");
			}
			turnon( ptr_y );
			break;

		case 'd':
			printf("Enter the required Engine Temperature: ");
			scanf("%f",&ptr_y->engine_temp);
			printf("Engine is ON\n");
			if(ptr_y->engine_temp<100.0)
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else if(ptr_y->engine_temp>150.0)
			{
				ptr_y->engine_temp = 125.0;
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is ON\n");
			}
			else
			{
				printf("Engine Temperature = %f\n",ptr_y->engine_temp);
				printf("Engine Temperature Controller is OFF\n");
			}
			printf("Vehicle's Speed = %f Km/Hr \n",ptr_y->velocity);
			if((ptr_y->room_temp < 10.0 || ptr_y->room_temp > 30.0))
			{
				ptr_y->room_temp=20.0;
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is ON\n");

			}
			else
			{
				printf("Room Temperature = %f\n",ptr_y->room_temp);
				printf("AC is OFF\n");
			}
			turnon( ptr_y );
			break;
	}
	return;
}
/****************************************************/


