#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

void push(Node **head, char value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    
    *head = newNode;
}

char pop(Node **head) {
    if (*head == NULL) return '\0';

    Node *delete = *head;
    char temp = delete->data;

    (*head) = (*head)->next;

    free(delete);
    return temp;
}



int main() {
    int n;

	scanf("%d", &n);

    for (int testCases = 0; testCases < n; testCases++) {
        char diamonds[1000];
        Node *head = NULL; // Reinicializa a pilha para cada caso de teste
        
        scanf("%s", diamonds);
        
        int len = strlen(diamonds);
        char ch;
        int closing = 0;

		for (int i = 0; i < len; i++) { 

			if (diamonds[i]=='<'){//caso de fechamento
				push(&head, '<');
			}
			else if(diamonds[i]=='>'){

				if((ch=pop(&head))=='<'){
					closing++;
						}
					}
			}

		while (head != NULL) {
			pop(&head);
		}
        printf("%d", closing);
}


    return 0;

}