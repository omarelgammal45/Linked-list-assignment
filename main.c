#include <stdio.h>
#include <stdlib.h>
struct student
{
	char name[25];
	int ID;
	int birth_day;
	int birth_month;
	int birth_year;
	int score;
	struct student* ptr;
};

void LinkedList_Insert(struct student** head, struct student** tail, int size);
void LinkedList_Insert_Beginning(struct student** head, struct student** tail, struct student* newNode);
void LinkedList_Insert_End(struct student** head, struct student** tail, struct student* newNode);
void LinkedList_Insert_Middle(struct student** head, struct student** tail, struct student* newNode, int index);
void LinkedList_Display(struct student* head, struct student* tail);
void LinkedList_Delete(struct student** head, struct student** tail);

int main()
{
	struct student* head = NULL;
	struct student* tail = NULL;
	int n = 0;

	printf("Enter the size of the linked list: ");
	scanf("%d", &n);
	LinkedList_Insert(&head, &tail, n);
	LinkedList_Display(head, tail);
	struct student* s1 = (struct student*)malloc(sizeof(struct student));
	s1->ID = 10;
	s1->ptr = NULL;
	LinkedList_Insert_Middle(&head, &tail, s1, 3);
	LinkedList_Display(head, tail);
	LinkedList_Insert_Beginning(&head, &tail, s1);
	LinkedList_Display(head, tail);
	LinkedList_Insert_End(&head, &tail, s1);
	LinkedList_Display(head, tail);
	LinkedList_Delete(&head, &tail);
	free(s1);
	return 0;
}



void LinkedList_Insert(struct student** head, struct student** tail, int size)
{
	while (size--)
	{
		struct student* newNode = (struct student*)malloc(sizeof(struct student));
		printf("Enter the student's ID: ");
		scanf("%d", &(newNode->ID));

		if (*head == NULL)
		{
			*head = *tail = newNode;
		}
		else
		{
			(*tail)->ptr = newNode;
			*tail = newNode;
		}
		newNode->ptr = NULL;
	}

}
void LinkedList_Insert_Beginning(struct student** head, struct student** tail, struct student* newNode)
{
	//Initialize  new Node 
	struct student* tmp = (struct student*) malloc(sizeof(struct student));
	//Make a deep copy to avoid pointing to the same memory location
	tmp->ID = newNode->ID;
	if (*head == NULL)
	{
		*head = *tail = tmp;
		tmp->ptr = NULL;
	}
	else
	{
		tmp->ptr = *head;
		*head = tmp;
	}
}
void LinkedList_Insert_End(struct student** head, struct student** tail, struct student* newNode)
{
	//Initialize  new Node 
	struct student* tmp = (struct student*) malloc(sizeof(struct student));
	//Make a deep copy to avoid pointing to the same memory location
	tmp->ID = newNode->ID;
	if (*head == NULL)
	{
		*head = *tail = tmp;
	}
	else
	{
		(*tail)->ptr = tmp;
		*tail = tmp;
	}
	tmp->ptr = NULL;
}
void LinkedList_Insert_Middle(struct student** head, struct student** tail, struct student* newNode, int index)
{
	//Initialize  new Node 
	struct student* tmp = (struct student*) malloc(sizeof(struct student));
	//Make a deep copy to avoid pointing to the same memory location 
	tmp->ID = newNode->ID;
	if (*head == NULL) // In case of empty array
	{
		*head = *tail = tmp;
		tmp->ptr = NULL;
	}
	else
	{
		index--; // Make the loop stop at the prevNode before the required position to change its nextPtr
		int i = 0;
		struct student* start = *head;
		while (i < index && start != NULL)
		{
			start = start->ptr;
			i++;
		}
		if (i != index)
		{
			printf("The index is not found \n");
		}
		else
		{
			tmp->ptr = start->ptr;
			start->ptr = tmp;
		}
	}
}
void LinkedList_Display(struct student* head, struct student* tail)
{
	while (head != NULL)
	{
		printf("%d ", head->ID);
		head = head->ptr;
	}
	printf("\n");
}
void LinkedList_Delete(struct student** head, struct student** tail)
{
	struct student* tmp = *head;
	while (*head)
	{
		*head = (*head)->ptr;
		free(tmp);
		tmp = *head;
	}
	*tail = NULL;
}
