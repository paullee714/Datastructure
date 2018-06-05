/*code written by paul lee @dongguk. univ computer science & engineering
computer network lab. Master grade
Note : Hash table with Linear Probing runs the same way as Hash table with Quadratic Probing except that in case of data collision, next position in Quadratic Probing is calculated as -:
(currentPosition + (h * h)) % arraySize, where h = 1, 2, 3, 4……
whereas in Linear Probing the formula used is -:
(currentPosition + h) % arraySize, where h = 1, 2, 3, 4……..

1.	Create a structure, item having a key and value representing data to be inserted in hash table.
2.	Create another structure, hash table_item with variable data (key and value) and flag as a status variable which informs about the status of array index.
flag = 1 : presence of some data at the array index.
flag = 0 : data not present in array index even once
flag = 2 : data had been removed from array index at least once
3.	Now create an array of structure (hashtable_item) of some certain size(10, in this case). This array will be our hash table.
4.	A menu is displayed on the screen.
5.	User must choose one option from four choices given in the menu.
6.	1st choice: Inserting item into hash table
(a) Take a key and a value as input.
(b) Calculate index as per the given key (using hashcode() function).
(c) Access the element at this calculated index in array.
(d) If there is no element at that particular array index, add straight way.
(e) If an element is present, check whether the given key matches the element’s key. If yes, then update it’s value and return. Otherwise probe through subsequent elements (looping back if necessary), to find free space. While probing
* if given key matches the element’s key, update its value and return.
* if a free space is found, add the data at that position.
Probing will stop until we reach the same element from where we began probing. Until then, if no free space is found, then add will fail.
7.	2nd choice: Removing a key from hash table
(a) Take a key as input which needs to be removed.
(b) Calculate index as per the given key (using hashcode() function).
(c) Access the element at the calculated array index.
(d) If an element is present, check whether the given key matches the element’s key. If yes, then delete the key and return decrementing the size. Otherwise probe through subsequent elements (looping back if necessary), to find free space with flag = 0. While probing
* if given key matches the element’s key, delete and return.
* if a free space is found (with flag = 2), continue to probe.
(e) If no free space (flag = 0) is found even after probing through all element it means, key does not exist in the hash table.
8.	3rd choice: Size of hash table
(a) Each time we add a new data item into the hash table, we increment it’s size by 1.
(b) Each time we remove a data item from the hash table, we decrement it’s size by 1.
(c) The size of the hash table can be determined either by size variable or size_of_hashtable() method.

9. 4th choice: Display hash table
(a) Function display() runs for displaying hash table contents.
(b) Here a for loop runs from 0 to array_size-1 with i as iterator.
(c) The code inside loop consists of taking i as index and accessing each element at that index of array.


*/
#include<stdio.h>
#include<stdlib.h>
 
/* to store a data (consisting of key and value) in hash table array */
struct item 
{
	int key;
	int value;
};
 
/* each hash table item has a flag (status) and data (consisting of key and value) */
struct hashtable_item 
{
 
	int flag;
	/*
	 * flag = 0 : data does not exist
	 * flag = 1 : data exists at given array location
	 * flag = 2 : data was present at least once
	*/
	struct item *data;
 
};
 
struct hashtable_item *array;
int size = 0;
int max = 10;
 
/* this function returns corresponding index of the given key */
int hashcode(int key)
{
	return (key % max);
}
 
/* this  function initializes the hash table array */
void init_array()
{
	int i;
	for (i = 0; i < max; i++) 
        {
		array[i].flag = 0;
		array[i].data = NULL;
	}
}
 
/* this function inserts an element in the hash table */
void insert(int key, int value)
{
	int index = hashcode(key);
 
	int i = index;
	int h = 1;
 
	struct item *new_item = (struct item*) malloc(sizeof(struct item));
	new_item->key = key;
	new_item->value = value;
 
	/* probing through the array until an empty space is found */
	while (array[i].flag == 1) 
        {
 
		if (array[i].data->key == key) 
                {
 
			/* case when already present key matches the given key */
			printf("\n This key is already present in hash table, hence updating it's value \n");
			array[i].data->value = value;
			return;
 
		}
		i = (i + (h * h)) % max;
		h++;
		if (i == index)
                {
			printf("\n Hash table is full, cannot add more elements \n");
			return;
		}
 
	}
 
	array[i].flag = 1;
	array[i].data = new_item;
	printf("\n Key (%d) has been inserted\n", key);
	size++;
 
}
 
/* to remove an element form the hash table array */
void remove_element(int key)
{
	int index = hashcode(key);
	int i = index;
	int h = 1;
 
	/* probing through the hash table until we reach at location where there had not been an element even once */
	while (array[i].flag != 0)
        {
		if (array[i].flag == 1  &&  array[i].data->key == key) 
                {
 
			/* case where data exists at the location and its key matches to the given key */
			array[i].flag = 2;
			array[i].data = NULL;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;
 
		}
		i = (i + (h * h)) % max;
		h++;
		if (i == index) 
                {
			break;
		}
	}
	printf("\n Key does not exist \n");
 
}
 
/* to display the contents of hash table */
void display()
{
 
	int i;
	for(i = 0; i < max; i++)
        {
		if (array[i].flag != 1)
                {
			printf("\n Array[%d] has no elements \n", i);
		}
		else
                {
			printf("\n Array[%d] has elements \n  %d (key) and %d (value) \n", i, array[i].data->key, array[i].data->value);
		}
	}
 
}
 
int size_of_hashtable()
{
	return size;
}
 
int main()
{
	int choice, key, value, n, c;
 
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item*));
	init_array();
 
	do {
		printf("Implementation of Hash Table in C with Quadratic Probing.\n\n");
		printf("MENU-: \n1.Inserting item in the Hash table" 
                              "\n2.Removing item from the Hash table" 
                              "\n3.Check the size of Hash table" 
                              "\n4.Display Hash table"
		       "\n\n Please enter your choice-:");
 
		scanf("%d", &choice);
 
		switch(choice)
                {
 
		case 1:
 
		      printf("Inserting element in Hash table \n");
		      printf("Enter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);
 
		      break;
 
		case 2:
 
		      printf("Deleting in Hash table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);
 
		      break;
 
		case 3:
 
		      n = size_of_hashtable();
		      printf("Size of Hash table is-:%d\n", n);
 
		      break;
 
		case 4:
 
		      display();
 
		      break;
 
		default:
 
		       printf("Wrong Input\n");
 
		}
 
		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
 
	}while(c == 1);
 
	getchar();
 
}