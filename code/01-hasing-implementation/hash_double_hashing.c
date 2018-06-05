/*
code written by paul lee @dongguk. univ computer science & engineering
computer network lab. Master grade
Hash Table with Double Hashing consists of probing through array elements (looping back if necessary) but differs in the way that it calculates other hash code of given key and uses that in probing
hashcode2 = primeNum – (key % primeNum) , where primeNum is largest prime number less that array size
Probing formula after calculating hashcode2 -:
(hashcode1 + (h * hashcode2)) % arraySize , h = 1, 2, 3, 4 and so on.
1.	Create a structure, item having a key and value representing data to be inserted in hash table.
2.	Create another structure, hashtable_item with variable data (key and value) and flag as a status variable which informs about the status of array index.
flag = 1 : presence of some data at the array index.
flag = 0 : data not present in array index even once
flag = 2 : data had been removed from array index at least once
3.	Now create an array of structure (hashtable_item) of some certain size(7, in this case). This array will be our hash table.
Note: array size should be taken a prime number to produce good results.
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
#include<math.h>
#include<stdlib.h>
struct data 
{
	int key;
	int value;
};
 
struct hashtable_item 
{
 
	int flag;
	/*
	 * flag = 0 : data not present
	 * flag = 1 : some data already present
	 * flag = 2 : data was present,but deleted
	*/
	struct data *item;
 
};
 
struct hashtable_item *array;
int max = 7;
int size = 0;
int prime = 3;
 
int hashcode1(int key)
{
	return (key % max);
}
 
int hashcode2(int key)
{
	return (prime - (key % prime));
}
 
void insert(int key, int value)
{
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);
 
	int index = hash1;
 
	/* create new data to insert */
	struct data *new_item = (struct data*) malloc(sizeof(struct data));
	new_item->key = key;
	new_item->value = value;
 
	if (size == max) 
        {
		printf("\n Hash Table is full, cannot insert more items \n");
		return;
	}
 
	/* probing through other array elements */
	while (array[index].flag == 1) {
		if (array[index].item->key == key)
                {
			printf("\n Key already present, hence updating its value \n");
			array[index].item->value = value;
			return;
		}
		index = (index + hash2) % max; 
		if (index == hash1)
                {
			printf("\n Add is failed \n");
			return;
		}
		printf("\n probing \n");
 
	}
 
	array[index].item = new_item;
	array[index].flag = 1;
	size++;
	printf("\n Key (%d) has been inserted \n", key);
 
}
 
/* to remove an element from the array */
void remove_element(int key)
{
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);
	int index = hash1;
 
	if (size == 0)
        {
		printf("\n Hash Table is empty \n");
		return;
	}
 
	/* probing through other elements */
	while (array[index].flag != 0)
        {
		if (array[index].flag == 1  &&  array[index].item->key == key)
                {
			array[index].item = NULL;
			array[index].flag = 2;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;
		}
		index = (index + hash2) % max;
		if (index == hash1)
                {
			break;
		}
	}
 
	printf("\n Key (%d) does not exist \n", key);
 
}
 
int size_of_hashtable()
{
	return size;
}
 
/* displays all elements of array */
void display()
{
	int i;
	for (i = 0; i < max; i++)
        {
		if (array[i].flag != 1)
                {
			printf("\n Array[%d] has no elements \n", i);
		}
		else
                {
			printf("\n Array[%d] has elements \n Key (%d) and Value (%d) \n", i, array[i].item->key, array[i].item->value);
		}
	}
}
 
 /* returns largest prime number less than size of array */
int get_prime()
{
	int i,j;
	for (i = max - 1; i >= 1; i--)
        {
		int flag = 0;
		for (j = 2; j <= (int)sqrt(i); j++)
                {
			if (i % j == 0)
                        {
				flag++;
			}
		}
		if (flag == 0)
                {
			return i;
		}
	}
	return 3;
 
}
/* initializes array */
void init_array()
{
	int i;
	for(i = 0; i < max; i++)
        {
		array[i].item = NULL;
		array[i].flag = 0;
	}
	prime = get_prime();
}
 

 
int main()
{
	int choice, key, value, n, c;
 
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
	init_array();
 
	do {
		printf("Implementation of Hash Table in C with Double Hashing.\n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table" 
                              "\n2.Removing item from the Hash Table" 
                              "\n3.Check the size of Hash Table" 
                              "\n4.Display Hash Table"
		       "\n\n Please enter your choice-:");
 
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
 
		      printf("Deleting in Hash Table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);
 
		      break;
 
		case 3:
 
		      n = size_of_hashtable();
		      printf("Size of Hash Table is-:%d\n", n);
 
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