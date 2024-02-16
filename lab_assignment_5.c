#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
     int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

char* toCString(node* head)
{
     int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    int i = 0;
    while(head){
        str[i++] = head->letter;
        head = head->next;
    }
    str[i] = '\0';
    return str;
}
void insertChar(node** pHead, char c)
{
    node* newNode = malloc(sizeof(node));
    node* temp = *pHead;
    newNode->letter = c;
    newNode->next = *pHead;
    *pHead = NULL;
    if (*pHead == NULL){
        *pHead = newNode;
    }
    else{
        while(temp->next !=NULL){
            temp = temp -> next;
        }
        temp ->next = newNode;
    }
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* current = *pHead;
    while(current){
        node* next = current->next;
        free(current);
        current = next;
    }
    *pHead = NULL;
}

int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs -- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}
