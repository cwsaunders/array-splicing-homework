//<CSIS 112-002 Lab 5 Christian Saunders> -- This program takes two arrays and creates a third array with a splice point.
//CSIS 112-<002>

//Include statements
#include <iostream>
#include <stdlib.h> //for srand, and rand

using namespace std;

//Function prototypes
int* splice(int[], int[], unsigned int, unsigned int, unsigned int);

int main()
{
	cout << "Lab 5 -- Christian Saunders" << endl << endl;

	//Variable declarations
	unsigned int arraySizeOne;
	unsigned int arraySizeTwo;
	unsigned int splicePoint;
	int *arrayReturn=NULL;

	//Program logic
	cout << "Enter size of first array: " << endl; //Prompt
	cin >> arraySizeOne;
	while (cin.fail() || arraySizeOne < 0 || arraySizeOne>100)
	{

		cout << "Input must be a positive integer larger than 0, and smaller than 101" << endl; //Error message
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> arraySizeOne;
	}

	cout << "Enter size of second array: " << endl; //Prompt
	cin >> arraySizeTwo;
	while (cin.fail() || arraySizeTwo < 0 || arraySizeTwo>100)
	{

		cout << "Input must be a positive integer larger than 0, and smaller than 101" << endl; //Error message
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> arraySizeTwo;
	}

	cout << "Enter the splice point: " << endl; //Prompt
	cin >> splicePoint;
	while (cin.fail() || splicePoint < 0 || splicePoint>100 || splicePoint>arraySizeOne)
	{

		cout << "Input must be a positive integer larger than 0, and smaller than 101, and smaller than the size of the first array" << endl; //Error message
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> splicePoint;
	}

	int * arrayOne = new int[arraySizeOne]; //On the heap
	int * arrayTwo = new int[arraySizeTwo]; //On the heap
	//************
	//Prints array
	cout << "Spliced arrays:" << endl << endl;
	arrayReturn = splice(arrayOne,arrayTwo,arraySizeOne,arraySizeTwo,splicePoint); 
	for (int i = 0; i < (arraySizeOne+arraySizeTwo); i++)
	{
		cout << *(arrayReturn + i) << endl;
	}
	
	//************

	
	

	
	arrayReturn = NULL;
	delete[] arrayOne;
	delete[] arrayTwo;
	
	
	

	//Closing program statements
	system("pause");
	return 0;	
}

//Function definitions

int* splice(int passedArrayOne[], int passedArrayTwo[], unsigned int arraySizeOne, unsigned int arraySizeTwo, unsigned int splicePoint)
{
	unsigned int arraySizeThree = arraySizeOne + arraySizeTwo;

	int * thirdArray = new int[arraySizeThree]; //Final array to be returned to main()

	//********************************************
	//Logic for filling first two arrays:
	srand(100);
	for (unsigned int i = 0; i < arraySizeOne; i++)
	{
		passedArrayOne[i] = 1 + rand() % 100;
	}
	for (unsigned int i = 0; i < arraySizeTwo; i++)
	{
		passedArrayTwo[i] = 1 + rand() % 100;
	}

	
	//********************************************

	//********************************************
	//Logic for putting together the two arrays:

	for (unsigned int i = splicePoint; i < arraySizeOne;i++) //Takes third array and iterates second part of first array into it at the beginning
	{	
				for (unsigned int j = 0; j < splicePoint; j++)
				{
					
						thirdArray[j] = passedArrayOne[i];
					
				}
			
	}
	
	for (unsigned int i = 0; i < arraySizeTwo; i++) //Iterates the second array into the second part of the third array
	{
		for (unsigned int j = splicePoint; j < (splicePoint + arraySizeTwo); j++)
		{
			thirdArray[j] = passedArrayTwo[i];
		}
	}
	for (unsigned int i = 0; i < splicePoint; i++) //Iterates first part of first array into last part of third array
	{
		for (unsigned int j = (splicePoint + arraySizeTwo); j < arraySizeThree; j++)
		{
			thirdArray[j] = passedArrayOne[i];
		}
	}

	//********************************************


	return thirdArray;
}