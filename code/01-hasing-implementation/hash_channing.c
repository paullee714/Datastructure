/*code written by paul lee @dongguk. univ computer science & engineering
computer network lab. Master grade
1.	Create a structure, node (Linked List item) with key and value as data and next as a pointer variable which points the structure element of node type.
2.	Create another structure, arrayitem (for Linked List) with head having the address of first element of Linked List and tail having the address of last element of Linked List.
3.	Now create an array of Linked List of some certain size (10, in this case).
4.	A menu is displayed on the screen.
5.	User must choose one option from four choices given in the menu.
6.	1st choice: Inserting item into hash table
(a) Take a key and a value as input.
(b) Calculate index as per the given key.
(c) Locate the Linked List at the calculated array index.
(d) If Linked List is present, check whether the key already present in it by finding the location of key using find() method which returns -1 if key is not present. In that case, we will create a data item and add it to the end of Linked List. If key is already present in the list, we will get its location index and extract the element using get_element() function and update its value.
(e) If there is no Linked List at that particular array index, which means the key is not present in hash table, then create a data item and a Linked List and add the data item to it.
7.	2nd choice: Removing a key from hash table
(a) Take a key as input which needs to be removed.
(b) Calculate index as per the given key.
(c) Locate the Linked List at the calculated array index.
(d) If Linked List is present, find the location index of the key in Linked List using find() method which returns -1 if key not present. The key is removed using remove() method if it is present otherwise ‘Key not present’ message will get displayed.
(e) If there is no Linked List at that particular array index, which means the key is not present in hash table, therefore no deletion is required.
8.	3rd choice: Size of hash table
(a) Each time we add a new data item into the hash table, we increment its size by 1.
(b) The size of the hash table can be determined either by size variable or size_of_hashtable() method.

9. 4th choice: Display hash table
(a) Function display() runs for displaying hash table contents.
(b) Here a for loop runs from 0 to array_size-1 with i as iterator.
(c) The code inside loop consists of taking i as index and locating each Linked List at that index of array.
(d) As the content of each node of Linked List is displayed the next variable (pointer)
is used to proceed further until the end of list is reached.
*/
#include<stdio.h>
#include<stdlib.h>

/* Node for storing an item in a Linked List */
struct node 
{
	int key;
	int value;
	struct node *next;
};
 
/* For storing a Linked List at each index of Hash Table  */
struct arrayitem 
{
 
	struct node *head;   
	/* head pointing the first element of Linked List at an index of Hash Table */
 
	struct node *tail;   
	/* tail pointing the last element of Linked List at an index of Hash Table */
 
};
 
struct arrayitem *array;
int size = 0;         /* Determines the no. of elements present in Hash Table */
int max = 10;	      /* Determines the maximum capacity of Hash Table array */
 
/* This function creates an index corresponding to the every given key */
int hashcode(int key)
{
	return (key % max);
}
 
struct node* get_element(struct node *list, int find_index);
void remove_element(int key);
void rehash();
void init_array();
 
 /*
 *This function finds the given key in the Linked List
 *Returns it's index
 *Returns -1 in case key is not present
*/
int find(struct node *list, int key)
{
	int retval = 0;
	struct node *temp = list;
	while (temp != NULL) 
        {
		if (temp->key == key)
                {
			return retval;
		}
  		temp = temp->next;
		retval++;
	}
	return -1;
 
}
void insert(int key, int value)
{
  	float n = 0.0;     
	/* n => Load Factor, keeps check on whether rehashing is required or not */
 
	int index = hashcode(key);  
 
	/* Extracting Linked List at a given index */
	struct node *list = (struct node*) array[index].head;
 
	/* Creating an item to insert in the Hash Table */
	struct node *item = (struct node*) malloc(sizeof(struct node));
	item->key = key;
	item->value = value;
	item->next = NULL;
 
	if (list == NULL) 
        {
		/* Absence of Linked List at a given Index of Hash Table */
 
		printf("Inserting %d(key) and %d(value) \n", key, value);
		array[index].head = item;
		array[index].tail = item;
		size++;
 
	}
        else 
        {
		/* A Linked List is present at given index of Hash Table */
 
		int find_index = find(list, key); 
		if (find_index == -1) 
                {
			/*
			 *Key not found in existing linked list
			 *Adding the key at the end of the linked list
			*/
 
			array[index].tail->next = item;
			array[index].tail = item;
			size++;
 
		}else 
                 {
			/*
			 *Key already present in linked list
			 *Updating the value of already existing key
			*/
 
			struct node *element = get_element(list, find_index);
			element->value = value;
 
		}
 
	}
 
	//Calculating Load factor
	n = (1.0 * size) / max;
	if (n >= 0.75) 
        {
		//rehashing
 
		printf("going to rehash\n");
		rehash();
 
	}
 
}
 
void rehash()
{
	struct arrayitem *temp = array;     
	/* temp pointing to the current Hash Table array */
 
	int i = 0, n = max;
	size = 0;
	max = 2 * max;
 
	/*
	 *array variable is assigned with newly created Hash Table
	 *with double of previous array size
	*/
	array = (struct arrayitem*) malloc(max * sizeof(struct node));
	init_array();
 
	for (i = 0; i < n; i++) 
        {
 
		/* Extracting the Linked List at position i of Hash Table array */
 		struct node* list = (struct node*) temp[i].head;
 
		if (list == NULL) 
                {
 
			/* if there is no Linked List, then continue */
			continue;
 
		}
                else 
                {
			/*
			 *Presence of Linked List at i
			 *Keep moving and accessing the Linked List item until the end.
			 *Get one key and value at a time and add it to new Hash Table array.
			*/
 
			while (list != NULL) 
                        {
				insert(list->key, list->value);
				list = list->next;
			}
 
		}
 
	}
	temp = NULL;
}
 

 
/* Returns the node (Linked List item) located at given find_index  */
struct node* get_element(struct node *list, int find_index)
{
	int i = 0;
	struct node *temp = list;
	while (i != find_index) 
        {
		temp = temp->next;
		i++;
	}
	return temp;
}
 
/* To remove an element from Hash Table */ 
void remove_element(int key)
{
	int index = hashcode(key);
	struct node *list = (struct node*) array[index].head;
 
	if (list == NULL) 
        {
		printf("This key does not exists\n");
 
	}
        else 
        {
		int find_index = find(list, key);
 
		if (find_index == -1) 
                {
			printf("This key does not exists\n");
 
		}
                else 
                {
 			struct node *temp = list;
			if (temp->key == key) 
                        {
 
  				array[index].head = temp->next;
				printf("This key has been removed\n");
				return;
			}
 
			while (temp->next->key != key) 
                        {
 				temp = temp->next;
			}
 
  			if (array[index].tail == temp->next) 
                        {
				temp->next = NULL;
				array[index].tail = temp;
 
			}
                        else 
                        {
				temp->next = temp->next->next;
 
			}
 
			printf("This key has been removed\n");
 
		}
 
	}
 
}
 
/* To display the contents of Hash Table */
void display()
{
	int i = 0;
	for (i = 0; i < max; i++) 
        {
		struct node *temp = array[i].head;
		if (temp == NULL) 
                {
			printf("array[%d] has no elements\n", i);
 
		}
                else 
                {
			printf("array[%d] has elements-: ", i);
			while (temp != NULL)
                        {
				printf("key= %d  value= %d\t", temp->key, temp->value);
				temp = temp->next;
			}
			printf("\n");
 
		}
	}
}
 
/* For initializing the Hash Table */
void init_array()
{
	int i = 0;
	for (i = 0; i < max; i++)
        {
		array[i].head = NULL;
		array[i].tail = NULL;
	}
 
}
 
/* Returns size of Hash Table */ 
int size_of_array()
{
	return size;
}
 
int main() 
{
	int choice, key, value, n, c;
 
	array = (struct arrayitem*) malloc(max * sizeof(struct arrayitem*));
	init_array();
 
	do {
		printf("Implementation of Hash Table in C chaining with Singly Linked List \n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table"
                              "\n2.Removing item from the Hash Table"
                              "\n3.Check the size of Hash Table" 
                              "\n4.To display a Hash Table"
		       "\n\n Please enter your choice -: ");
 
 		scanf("%d", &choice);
 
		switch(choice) 
                {
 
		case 1:
 
		      printf("Inserting element in Hash Table\n");
		      printf("Enter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);
 
		      break;
 
		case 2:
 
		      printf("Deleting in Hash Table \nEnter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);
 
		      break;
 
		case 3:
 
		      n = size_of_array();
		      printf("Size of Hash Table is-:%d\n", n);
 
		      break;
 
		case 4:
 
		      display();
 
		      break;
 
		default:
 
		       printf("Wrong Input\n");
 
		}
 
		printf("\nDo you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
 
	}while(c == 1);
 
	getchar();
 
}