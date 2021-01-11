/*
 * Linkedlist_final.c
 *
 *  Created on: 10.01.2021
 *      Author: atta-es
 */

/*
 * main.c
 *
 *  Created on: 08.01.2021
 *      Author: atta-es
 */
#ifndef NULL
#define NULL   ((void *) 0)
#endif
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

// effective data
////////////////////////////////////////////////////////////////////////////
struct Sdata {
	int ID;
	char name[40];
	float height;
};
////////////////////////////////////////////////////////////////////////////
// linked list node
struct SStudent
{
	struct Sdata Student ;
	struct SStudent* PnextStudent;
};

////////////////////////////////////////////////////////////////////////////
struct SStudent* gpfirstStudent = NULL ;
////////////////////////////////////////////////////////////////////////////
void Filldata(struct SStudent* ptr)
{


	char temp_text[40];
	printf("\n Enter ID:");

	gets(temp_text);
	ptr->Student.ID = atoi(temp_text);
	printf("\n Enter student name :");

	gets (ptr->Student.name );
	printf("\n Enter student height :");
	gets(temp_text);
	ptr->Student.height = atof(temp_text);


}
////////////////////////////////////////////////////////////////////////////
void AddStudent()
{
	struct SStudent* pNewStudent;
	struct SStudent* pLasttudent;
	// check list is empty == yes
	if (gpfirstStudent == NULL)
	{
		// create new record
		pNewStudent =(struct SStudent*) malloc(sizeof(struct SStudent));
		gpfirstStudent = pNewStudent;
	}
	else
	{
		pLasttudent = gpfirstStudent;
		while (pLasttudent->PnextStudent ){
			pLasttudent = pLasttudent ->PnextStudent;
		}
		pNewStudent =(struct SStudent*) malloc(sizeof(struct SStudent));
		pLasttudent->PnextStudent = pNewStudent;
	}
	Filldata(pNewStudent);
	pNewStudent-> PnextStudent = NULL;

}
/////////////////////////////////////////////////
int Delete_student ()
{
	if (gpfirstStudent == NULL)
	{
		printf("List is empty");
		// return to main menu ;
	}
	else
	{
		struct SStudent* find = gpfirstStudent;
		struct SStudent* pPrevstudent = NULL;
		int ID;
		printf("Enter student ID need to be deleted : ");
		fflush( stdout); fflush(stdin);
		scanf("%d", &ID);
		// where is the ID
		while (find)
		{

			if (find->Student.ID == ID)
			{
				if (pPrevstudent)
				{

					pPrevstudent->PnextStudent = find->PnextStudent;
				}
				else
				{

					gpfirstStudent = find->PnextStudent ;
				}
				free (find);
				return 1;
			}
			pPrevstudent = find;
			find = find->PnextStudent;

		}
	}
	printf("\n cannot find student ID. ");
	return 0;
}
/////////////////////////////////////////////////
void delete_all(){
	struct SStudent* pCurruntstudent = gpfirstStudent;

	if (gpfirstStudent == NULL) printf("\n list is empty");

	while (pCurruntstudent)
	{
		struct SStudent* pTemp = pCurruntstudent;
		pCurruntstudent = pCurruntstudent->PnextStudent;
		free(pTemp);
	}
	gpfirstStudent = NULL;


}

void View_students (){
	struct SStudent* p_next = gpfirstStudent;
	int count = 0 ;
	if (gpfirstStudent)
	{
		while (p_next)
		{
			printf("\n Record number: %d"
					"\nStudent ID  is :%d "
					"\nStudent is : %s "
					"\n Student height is :%f",count, p_next->Student.ID, p_next->Student.name, p_next->Student.height );
			p_next= p_next->PnextStudent;
			count ++;
		}
	}
	else printf("List is empty");

}


void main ()
{

	char temp_text[40];
	while (1){
		printf("\n===================="
				"\n\t Choose one of the following options \n"
				"\n 1: Add student"
				"\n 2: Delete student"
				"\n 3: View Students"
				"\n 4: Delete All"
				"\n Enter option number:");

		gets(temp_text);
		printf("\n======================");
		switch(atoi(temp_text)){
		case 1:
			AddStudent();
			break;
		case 2 :
			Delete_student();
			break;
		case 3:
			View_students();
			break;
		case 4:
			delete_all();
			break;
		default :
			printf("\n wrong entry");
			break;
		}
	}


}
