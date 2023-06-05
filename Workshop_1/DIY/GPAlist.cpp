/*****************************************************************************
							 Workshop - #1
Full Name  : Gleison Vieira Dutra
Student ID#: 119237220

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "File.h"
#include "UI.h"
#include "GPA.h"

#define STUDENTNUM 100


namespace sdds {

	GPA student[STUDENTNUM];
	GPA studentTemp[STUDENTNUM];
	char input[5];

	bool gpaQuery(const char* filename) {
		GPA std;
		bool read = true;
		int stdNum = 0; //Number of students read
		char option[5]; //Variable that represents the symbol the user entered
		double value; //Represents the GPA value the user entered

		if (openFile(filename)) {
			while (read && stdNum < 100) {
				read = readStdName(std.name) &&
					readStdNum(&std.stno) &&
					readStdGPA(&std.gpa);


				if (read) student[stdNum++] = std;
			}
			closeFile();
		}

		if (stdNum)
		{


			std::cout << "Enter GPA query..." << std::endl;
			char exit = 'a';

			do {
				readUserInput(option);
				int counter = 0;

				if (option[1] != '\0') {

					value = atof(option + 1);
				}

				if (option[0] == '~') {
					for (int i = 0; i < stdNum; i++)
					{
						if ((student[i].gpa <= value + 0.05 && student[i].gpa >= value - 0.05)) {
							printf("[%d] %d: %.1lf (%s)\n", counter + 1, student[i].stno, student[i].gpa, student[i].name);
							counter++;
						}
					}
				}
				else if (option[0] == '<') {



					for (int i = 0; i < stdNum; i++) //This loop creates an array which contains only the students that met the search criteria
					{
						if (student[i].gpa < value) {
							studentTemp[counter].gpa = student[i].gpa;
							studentTemp[counter].stno = student[i].stno;
							strcpy(studentTemp[counter].name, student[i].name);
							counter++;
						}
					}

					// This loop order the grades in ascending order
					for (int i = 0; i < counter; i++)
					{
						for (int j = 0; j < counter; j++)
						{
							if (studentTemp[i].gpa < studentTemp[j].gpa) {
								double gpa = studentTemp[i].gpa;
								studentTemp[i].gpa = studentTemp[j].gpa;
								studentTemp[j].gpa = gpa;
								char name[116];
								strcpy(name, studentTemp[i].name);
								strcpy(studentTemp[i].name, studentTemp[j].name);
								strcpy(studentTemp[j].name, name);
								int numb = studentTemp[i].stno;
								studentTemp[i].stno = studentTemp[j].stno;
								studentTemp[j].stno = numb;
							}
						}
					}

					// This loop order the names alphabetically
					for (int i = 0; i < counter; i++)
					{
						for (int j = 0; j < counter; j++)
						{
							if (studentTemp[i].gpa == studentTemp[j].gpa) {
								if (strcmp(studentTemp[i].name, studentTemp[j].name) < 0)
								{
									double gpa = studentTemp[i].gpa;
									studentTemp[i].gpa = studentTemp[j].gpa;
									studentTemp[j].gpa = gpa;
									char name[116];
									strcpy(name, studentTemp[i].name);
									strcpy(studentTemp[i].name, studentTemp[j].name);
									strcpy(studentTemp[j].name, name);
									int numb = studentTemp[i].stno;
									studentTemp[i].stno = studentTemp[j].stno;
									studentTemp[j].stno = numb;
								}
							}
						}
					}


					for (int i = 0; i < counter; i++) //Prints output to screen
					{
						printf("[%d] %d: %.1lf (%s)\n", i + 1, studentTemp[i].stno, studentTemp[i].gpa, studentTemp[i].name);
					}

				}
				else if (option[0] == '>') {
					for (int i = 0; i < stdNum; i++) //This loop creates an array which contains only the students that met the search criteria
					{
						if (student[i].gpa > value) {
							studentTemp[counter].gpa = student[i].gpa;
							studentTemp[counter].stno = student[i].stno;
							strcpy(studentTemp[counter].name, student[i].name);
							counter++;
						}
					}
					// This loop order the grades in ascending order
					for (int i = 0; i < counter; i++) 
					{
						for (int j = 0; j < counter; j++)
						{
							if (studentTemp[i].gpa < studentTemp[j].gpa) {
								double gpa = studentTemp[i].gpa;
								studentTemp[i].gpa = studentTemp[j].gpa;
								studentTemp[j].gpa = gpa;
								char name[116];
								strcpy(name, studentTemp[i].name);
								strcpy(studentTemp[i].name, studentTemp[j].name);
								strcpy(studentTemp[j].name, name);
								int numb = studentTemp[i].stno;
								studentTemp[i].stno = studentTemp[j].stno;
								studentTemp[j].stno = numb;
							}
						}
					}	
					// This loop order the names alphabetically
					for (int i = 0; i < counter; i++) 
					{
						for (int j = 0; j < counter; j++)
						{
							if (studentTemp[i].gpa == studentTemp[j].gpa) {
								if (strcmp(studentTemp[i].name, studentTemp[j].name) < 0 )
								{
									double gpa = studentTemp[i].gpa;
									studentTemp[i].gpa = studentTemp[j].gpa;
									studentTemp[j].gpa = gpa;
									char name[116];
									strcpy(name, studentTemp[i].name);
									strcpy(studentTemp[i].name, studentTemp[j].name);
									strcpy(studentTemp[j].name, name);
									int numb = studentTemp[i].stno;
									studentTemp[i].stno = studentTemp[j].stno;
									studentTemp[j].stno = numb;
								}
							}
						}
					}

					//Prints output to screen
					for (int i = 0; i < counter; i++) 
					{
						printf("[%d] %d: %.1lf (%s)\n", i + 1, studentTemp[i].stno, studentTemp[i].gpa, studentTemp[i].name);
					}

				}
				else
				{
					std::cout << "Exit the program? (Y)es/(N)o: ";
					std::cin >> exit;
				}

			} while (exit != 'y' && exit != 'Y');

		}
			return (!read) ;
	}
}

