#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


typedef struct node{
	char username[50];
	char password[50];
	struct node *next;
};

struct node * newUser(struct node * head){
	
	char username[50], password[50];
	struct node * newNode = (struct node*)malloc(sizeof(struct node));
	
	printf("\nEnter new username : ");
	scanf("%s", &username);
	printf("\nEnter new password : ");
	scanf("%s", &password);
	
	if(head == NULL){
		strcpy(newNode->username,username);
		strcpy(newNode->password,password);
		head = newNode;
		head->next = NULL;
	}
	
	else {
		struct node * iterable = head;
		
		while(iterable->next != NULL){
			iterable = iterable->next;
		}
		
		strcpy(newNode->username,username);
		strcpy(newNode->password,password);
		newNode->next = NULL;
		iterable->next = newNode;
	}
	
	printf("\nNew user added successfully!"); 
	return head;
}

int loginUser( struct node * head){
	
	char username[50], password[50];
	
	printf("\nEnter your username : ");
	scanf("%s", &username);
	
	
	struct node * iterable = head;
	
	while(strcmp(iterable->username,username) != 0){
		iterable = iterable->next;
		if(iterable == NULL) break;
	}
	
	if(iterable == NULL){
		return -1;
	}
	
	else {
		printf("\nEnter your password : ");
		scanf("%s", &password);
		
		if(strcmp(iterable->password,password) == 0){
			return 1;
		}
		else return 0;
	}
	return -1;
	
}

printAllUsers(struct node * head){
	struct node * iterable = head;
	
	if(iterable == NULL) printf("\nNo registered users"); return;
	
	while(iterable != NULL){
		printf("\n%s", iterable->username);
		iterable = iterable->next;
	}
}



void main(){
	
	struct node * head = NULL;
	int choice,n;
	
	do {
		printf("\n\n.............................................");
		printf("\n1.Register\n2.Login\n3.View all registered users\n\nEnter choice : ");
		scanf("%d", &choice);
	
		switch(choice){
			case 1 : head = newUser(head); break;
			case 2 : 
				switch(loginUser(head)){
					case 1 : printf("\nLogin Successfull!"); break;
					case 0 : printf("\nLogin unuccessfull! Invalid password"); break;
					case -1 : printf("\nInvalid Username! User does not exist!"); break;
					default : printf("\nAn error occurred");
				}
				break;
			case 3 : printAllUsers(head); break;	 
			default: printf("\nIncorrect choice!");
		}
	} while(1);
	
	
	
}



















