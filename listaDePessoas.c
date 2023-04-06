#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Person{
		char cpf[15]; 
		char name[50];
		int age; 
		char address[100];
}person;

typedef struct Node{
		struct Node* next; 
		person data; 
}node; 

node* insert(node* head, person personData){
		node* newNode = (node*) malloc(sizeof(node));
		
		newNode->data = personData;
		newNode->next = NULL;  

		if (head == NULL){
			head = newNode; 	
		} else{
			node* current = head; 
		while (current->next != NULL){
			current = current->next; 
		}
			current->next = newNode;	
		}

		return head; 
}

void searchCPF(node* head, char cpf[]){
	node* aux = head; 

	if (head == NULL){
		printf ("não há pessoas cadastradas na lista");
		return; 
	}

	while (aux->next != NULL){
		if (strcmp(cpf, aux->data.cpf) == 0){
			printf ("cpf: %s\n", aux->data.cpf);
			printf("name: %s\n", aux->data.name);
			printf("age: %d\n", aux->data.age);
			printf("address: %s\n", aux->data.address);
			return;
		}	
		else 
			aux = aux->next; 
	}

	printf ("A pessoa procurada não foi encontrada");
}

node* removeNode(node* head, char name[]) {
    node* previousNode = NULL;
    node* currentNode = head;

    if (head == NULL) { 
        return NULL; 
    }

    if (strcmp(currentNode->data.name, name) == 0) {
        head = currentNode->next;  
        free(currentNode);
        return head; 
    }

    while (currentNode != NULL) {
        if (strcmp(currentNode->data.name, name) == 0) {
            previousNode->next = currentNode->next;
            free(currentNode);
            return head; 
        }
        
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    return head;
}

void printElements(node* head){
	node* aux = head; 
	while (aux != NULL){
		printf ("-------------------------------");
		printf ("CPF: %s\n", aux->data.cpf);
		printf("\nNAME: %s\n", aux->data.name);
		printf("AGE: %d\n", aux->data.age);
		printf("ADDRESS: %s \n", aux->data.address);
		printf ("-------------------------------");
		aux = aux->next; 
	}
	
}

person readElements(person personData){

	printf("inform your CPF: \n");
	fgets(personData.cpf, sizeof(personData.cpf), stdin);
	personData.cpf[strcspn(personData.cpf, "\n")] = '\0';


	while (getchar() != '\n');
	printf("inform your name: \n");
	fgets(personData.name, sizeof(personData.name), stdin);
	personData.name[strcspn(personData.name, "\n")] = '\0';

  printf("inform your age: \n");
  scanf("%d", &personData.age);
  getchar();
	
	printf("inform your address:\n");
	fgets(personData.address, sizeof(personData.address), stdin);
	personData.address[strcspn(personData.address, "\n")] = '\0';
	return personData;  
}

int main(){
    node* head = NULL;
    person personData;
    int op; 

    printf(" [1] - insert\n [2] - search\n [3] - remove\n [4] - print\n [0] - finish\n");

    while (1){
        scanf("%d", &op);

        switch (op){
            case 1:
                personData = readElements(personData); 
                head = insert(head, personData);
                break;

            case 2:
                printf("(1) - searchCPF; (2) - searchName; (3) - backMenu\n");
                scanf("%d", &op);

                if (op == 1){
                    //searchCPF(); 
                }
                if (op == 2){
                    while (getchar() != '\n');
                    printf("inform name: \n"); 
                    fgets(personData.name, sizeof(personData.name), stdin);
                    personData.name[strcspn(personData.name, "\n")] = '\0';
                    //searchName();
                }
                if (op == 3){
                    op = -1; // setando para um valor inválido para entrar no while abaixo
                }    		
                break;

            case 3: 
                while (getchar() != '\n');
                printf("inform name: \n");
                fgets(personData.name, sizeof(personData.name), stdin);
                personData.name[strcspn(personData.name, "\n")] = '\0';
                head = removeNode(head, personData.name);
                break; 

            case 4: 
                printElements(head);
                break; 

            case 0:
                return 0;

            default:
                printf("Invalid option!\n");
                break;
        }	

        // adicionando o while para voltar ao menu principal
        while (op == -1) {
            printf(" [1] - insert\n [2] - search\n [3] - remove\n [4] - print\n [0] - finish\n");
            scanf("%d", &op);
        }
    }
}
