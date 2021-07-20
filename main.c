
/*
Program : Reverse Linked list
Author: Anshaj vats
Date: 25/09/2020

Time spent: 1hour

purpose: to reverse a link list without lossing anything.






*/



#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h" 

int main(int argc, char* argv[])
{
	BIT_FLAGS flag_holder = NULL;
	int i;
	int x = 64;

	flag_holder = bit_flags_init_number_of_bits(x);
	if (flag_holder == NULL)
	{
		printf("Failed to start the function");
		exit(1);

	}
	int c = bit_flags_get_size(flag_holder);
	printf("size=%d\n", c);
	int d = bit_flags_get_capacity(flag_holder);
	printf("capacity=%d\n", d);



	bit_flags_set_flag(flag_holder, 3);
	bit_flags_set_flag(flag_holder, 16);
	bit_flags_set_flag(flag_holder, 31);
	
	int z = bit_flags_get_size(flag_holder);
	printf("%d\n", z);
	
	printf("set_flag= ");
		for (i = bit_flags_get_size(flag_holder)-1; i >= 0; --i)
		{
			printf("%d", bit_flags_check_flag(flag_holder, i));

			if (i % 4 == 0)
			
				printf(" ");
			
		}
	
	printf("\n");
	

	bit_flags_unset_flag(flag_holder, 31);
	bit_flags_unset_flag(flag_holder, 3);
	bit_flags_set_flag(flag_holder, 9);
	printf("unset_fg= ");
	for (i = bit_flags_get_size(flag_holder)-1; i >= 0; --i)
	{
		printf("%d", bit_flags_check_flag(flag_holder, i));

		if (i % 4 == 0)
		{
			printf(" ");
		}
		
	}
	
	printf("\n");
	

	bit_flags_destory(&flag_holder);
	
	return 0;
}
	
	
	
	






























/*struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
void struct_reverse(Node** head);


int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node).
	struct_reverse(&head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

//Define your function here

void struct_reverse(Node** head) {
	Node* prev = NULL;
	Node* curr = *head;
	Node* nxt = NULL;

	while (curr != NULL) {
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	*head = prev;
}*/
