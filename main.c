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



void ARRAY_INSERT_MIDDLE(student*& TARGET_ARRAY_PTR, int& TARGET_ARRAY_SIZE, const student& INSERTED_ELEMENT, int WANTED_INDEX);
void ARRAY_INSERT_BEGINNING(student*& TARGET_ARRAY_PTR, int& TARGET_ARRAY_SIZE, const student& INSERTED_ELEMENT);
void ARRAY_INSERT_END(student*& TARGET_ARRAY_PTR, int& TARGET_ARRAY_SIZE, const student& INSERTED_ELEMENT);
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



void ARRAY_INSERT_END(student*& TARGET_ARRAY_PTR, int& TARGET_ARRAY_SIZE, const student& INSERTED_ELEMENT)
//PASSING THE POINTER OF THE FIRST ELEMENT OF THE ARRAY BY REFERENCE AND THE OLD SIZE AND THE NEW ELEMENT
{
    TARGET_ARRAY_SIZE++; //SIZE INCREAMENTED BY 1
    student* temp_array = (student*)calloc(TARGET_ARRAY_SIZE, sizeof(student));   
    // MAKING TEMPORARY ARRAY HAVING THE NEW ELEMENT WITH THE NEW ARRAY SIZE
    if (temp_array == NULL)  // CHECKING IF THE NEW ARRAY IS ALLOCATED OR NOT 
        // IF ALLOCATED INSERT THE ELEMENT IF NOT THEN DONT INSERT
        puts("\ncan't insert another element because there is no space in memory\ntry another time!!!");
    else {  
        for (int i = 0; i < TARGET_ARRAY_SIZE - 1; i++) // COPYING THE OLD ARRAY 
        {
            *(temp_array + i) = *(TARGET_ARRAY_PTR + i);
        }
        *(temp_array + TARGET_ARRAY_SIZE - 1) = INSERTED_ELEMENT;   // INSERT THE NEW ELEMENT AT THE END 
        free(TARGET_ARRAY_PTR);   // FREE THE OLD ARRAY
        TARGET_ARRAY_PTR = temp_array;  // NOW WE HAVE THE NEW ARRAY 

        puts("element successfully added");

    }

}

void ARRAY_INSERT_BEGINNING(student*& TARGET_ARRAY_PTR, int& TARGET_ARRAY_SIZE, const student& INSERTED_ELEMENT)
//PASSING THE POINTER OF THE FIRST ELEMENT OF THE ARRAY BY REFERENCE AND THE OLD SIZE AND THE NEW ELEMENT
{
    TARGET_ARRAY_SIZE++; //SIZE INCREAMENTED BY 1
    student* temp_array = (student*)calloc(TARGET_ARRAY_SIZE, sizeof(student));
    // MAKING TEMPORARY ARRAY HAVING THE NEW ELEMENT WITH THE NEW ARRAY SIZE

    if (temp_array == NULL) // CHECKING IF THE NEW ARRAY IS ALLOCATED OR NOT 
        // IF ALLOCATED INSERT THE ELEMENT IF NOT THEN DONT INSERT
        puts("\ncan't insert another element because there is no space in memory\ntry another time!!!");
    else {
        *(temp_array) = INSERTED_ELEMENT;  // INSERT THE NEW ELEMENT AT THE BEGINNING 

        for (int i = 0; i < TARGET_ARRAY_SIZE - 1; i++)   // COPYING THE OLD ARRAY
        {
            *(temp_array + i + 1) = *(TARGET_ARRAY_PTR + i);
        }
        free(TARGET_ARRAY_PTR);  // FREE THE OLD ARRAY
        TARGET_ARRAY_PTR = temp_array;   // NOW WE HAVE THE NEW ARRAY
        puts("element successfully added");

    }

}

void ARRAY_INSERT_MIDDLE(student*& TARGET_ARRAY_PTR, int& TARGET_ARRAY_SIZE, const student& INSERTED_ELEMENT, int WANTED_INDEX)
//PASSING THE POINTER OF THE FIRST ELEMENT OF THE ARRAY BY REFERENCE AND THE OLD SIZE AND THE NEW ELEMENT AND THE WANTED INDEX TO BE INSERTED
{
    if (WANTED_INDEX >= TARGET_ARRAY_SIZE || WANTED_INDEX < 1)//CHECKING IF THE WANTED INDEX IS IN THE PERMITTED RANGE [1,SIZE[ (NOT IN BEGINNING OR END)
    {
        puts("Choose suitable index");
    }
    else {
        TARGET_ARRAY_SIZE++;  //SIZE INCREAMENTED BY 1
        student* temp_array = (student*)calloc(TARGET_ARRAY_SIZE, sizeof(student));
        // MAKING TEMPORARY ARRAY HAVING THE NEW ELEMENT WITH THE NEW ARRAY SIZE
        if (temp_array == NULL) // CHECKING IF THE NEW ARRAY IS ALLOCATED OR NOT 
        // IF ALLOCATED INSERT THE ELEMENT IF NOT THEN DONT INSERT
            puts("\ncan't insert another element because there is no space in memory\ntry another time!!!");
        else {

            for (int i = 0; i < WANTED_INDEX; i++)// INSERT THE OLD ELEMENTS BEFORE THE WANTED INDEX
            {
                *(temp_array + i) = *(TARGET_ARRAY_PTR + i);
            }
            *(temp_array + WANTED_INDEX) = INSERTED_ELEMENT;  // INSERT THE NEW ELEMENT 
            for (int i = WANTED_INDEX + 1; i < TARGET_ARRAY_SIZE; i++) // INSERT THE OLD ELEMENTS AFTER THE WANTED ELEMENTS AND INDEX SHIFTED BY 1
            {
                *(temp_array + i) = *(TARGET_ARRAY_PTR + i - 1);
            }
            /*  HERE WHAT HAPPEND IN THE LOOP 
            IF WE HAVE ARRAY OF 5 ELEMENTS                  
            AND WANTED TO INSERT X IN INEDEX 2
            TO BE LIKE THAT     0   1   X   2   3   4


             OLD INDEX -->     0    1       2   3   4
                               ^    ^       ^   ^   ^
                               |    |       |   |   |
                               |    |       |   |   |
             NEW INDEX  -->    0    1   2   3   4   5
             NEW ELEMENTS-->   0    1   X   2   3   4
            */
            free(TARGET_ARRAY_PTR);  // FREE THE OLD ARRAY
            TARGET_ARRAY_PTR = temp_array;   // HERE IS THE NEW ARRAY
            puts("element successfully added");

        }
    }
}