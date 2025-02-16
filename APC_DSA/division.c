/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <string.h>

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR , int argc , char *argv[] )
{
	/* Definition goes here */
	int count = 0 ;
	int data ;
	if ( *argv[3] == '0'  && strlen( argv[3] ) == 1 ) 
	{
		printf("Error : Divide by zero\n") ;
		return SUCCESS ;
	} 

	if ( ( *argv[3] == '1' ) && ( strlen( argv[3] ) == 1 ) )
	{
		
		*headR = *head1 ;
		*tailR = *tail1 ;
		print_list ( *headR ) ;
		return SUCCESS ;
	}

	if ( finding_the_largest_number ( head1 , tail1 , head2 , tail2 ) == SUCCESS ) 
	{
		Dlist *temphead1 = *head1 ;
		Dlist *temptail1 = *tail1 ;
	
		while ( ( finding_the_largest_number ( &temphead1 , &temptail1 , head2 , tail2 ) == SUCCESS ) )
		{
			subtraction( &temphead1 , &temptail1 , head2 , tail2 , headR , tailR , argc , argv  ) ;
			temphead1 = *headR ;
			temptail1 = *tailR ;
			*headR = NULL ;
			*tailR = NULL ;
			count++ ;
		}
		if ( ( finding_the_largest_number ( &temphead1 , &temptail1 , head2 , tail2 ) == EQUAL ))
				count++ ;
		
		printf("Head -> ") ;
		printf( "%d " , count ) ;
		printf("Tail\n") ;
		
		
		return SUCCESS ;

	}
	else if ( finding_the_largest_number ( head1 , tail1 , head2 , tail2 ) == EQUAL )
	{
		data = 1 ;
		create_result_node( headR , tailR , data ) ;
		print_list ( *headR ) ;
		return SUCCESS ;
	}
	else
	{
		data = 0 ;
		create_result_node( headR , tailR , data ) ;
		print_list ( *headR ) ;
		return SUCCESS ;
	}
}
