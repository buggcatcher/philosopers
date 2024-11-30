#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RST 	"\033[0m"
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"

typedef struct Node {
    char* philo;
    int death;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(const char* philo, int death)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->philo = strdup(philo);
    newNode->death = death;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertEnd(Node** head, const char* philo, int death)
{
    Node* newNode = createNode(philo, death);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* last = (*head)->prev;
    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

void displayList(Node* head)
{
    Node* temp = head;

    if (head == NULL)
    {
        printf(RED"La lista è vuota.\n"RST);
        return;
    }
    while (temp != NULL)
    {
        printf(BLUE"Filosofo: %s"BLUE"  \tAnno di morte: "RST MAGENTA"%d\n"RST, temp->philo, temp->death);
        temp = temp->next;
        if (temp == head)
            break;
    }
}


int main()
{
    Node* head = NULL;

    insertEnd(&head, CYAN "Platone" RST, -347);
    insertEnd(&head, CYAN "Kant" RST, 1804);
    insertEnd(&head, CYAN "Marx" RST, 1883);
    insertEnd(&head, CYAN "Nietzsche" RST, 1900);

    printf(GREEN "Lista Doppiamente Collegata:\n" RST);
    displayList(head);

    return 0;
}
