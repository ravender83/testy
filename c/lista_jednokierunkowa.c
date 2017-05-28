#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
  int czas;
  struct node *next;
} node_t;

node_t *head = NULL;
node_t *current = NULL;

//display the list
void printList(){
	node_t *ptr = head;
	printf("\n[ ");

	while (ptr != NULL){
		printf("(%d) ", ptr->czas);
		ptr=ptr->next;
	}
	printf(" ]");
}

//insert link at the first location
void insertFirst(int czas) {
	// utworzenie tymczasowego node'a
	node_t *link = (node_t*)malloc(sizeof(node_t));
	
	// ustawienie danych
	link->czas = czas;

	// ustawienie linka do starego heada
	link->next = head;

	// ustawienie poczatku listy na dodany node
	head = link;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   node_t *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

void deleteLast(){
	node_t *ptr;

	// sprawdzam, czy lista nie jest pusta
	if (head != NULL)
	{
		// sprawdzam, czy lista nie jest jednoelementowa
		if (head->next != NULL) {
			for(ptr = head; ptr != NULL; ptr = ptr->next){
				if (ptr->next->next == NULL) {
				free(ptr->next);
				ptr->next = NULL;
				break;
			}
			}
					
		}
		else // lista jest jednoelementowa
		{
			free(head);
			head = NULL;	
		}
	}
	
}

int main( int argc, const char* argv[] )
{
    int x;
    while(true){

    printList();
    printf("\nPodaj czas: ");
    scanf("%d", &x);
    insertFirst(x);
	while(length() > 3) deleteLast();

	}
	return 0;
}