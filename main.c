#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint8;
struct Node
{
uint8 StudentID;
uint8 StudentYear;
uint8 Course_1ID;
uint8 Course_1Grade;
uint8 Course_2ID;
uint8 Course_2Grade;
uint8 Course_3ID;
uint8 Course_3Grade;
struct Node *next;
};
int count=0;
void SDB_isfull(){
  if(count==0)
  printf("List Is Empty\n");
  else if (count==10)
  printf("List Is full\n");
  else
  printf("List Is Not full but not Empty\n");
}
void Add_std(struct Node** head_ref,uint8 StudentID,uint8 StudentYear,uint8 Course_1ID,uint8 Course_1Grade,uint8 Course_2ID,uint8 Course_2Grade,uint8 Course_3ID,uint8 Course_3Grade)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->StudentID  = StudentID;
    new_node->StudentYear  = StudentYear;
    new_node->Course_1ID  = Course_1ID;
    new_node->Course_1Grade  = Course_1Grade;
    new_node->Course_2ID  = Course_2ID;
    new_node->Course_2Grade  = Course_2Grade;
    new_node->Course_3ID  = Course_3ID;
    new_node->Course_3Grade  = Course_3Grade;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
count=count+1;
}


void deleteNode(struct Node** head_ref, int id)
{
  struct Node* temp=*head_ref,*prev;
  if(temp!=NULL&&temp->StudentID==id)
  {
        *head_ref = temp->next;
    free(temp);
count=count-1;
    return;
  }
  while(temp!=NULL&&temp->StudentID!=id)
  {
    prev=temp;
    temp=temp->next;
  }
}
void search(struct Node** head_ref, int id)
{
  struct Node* temp=*head_ref,*prev;
  if(temp!=NULL&&temp->StudentID==id)
  {
    *head_ref = temp->next;
    printf("StudentID is:%d\n",temp->StudentID);
    printf("StudentYear is:%d\n",temp->StudentYear);
    printf("Course_1ID is:%d\n",temp->Course_1ID);
    printf("Course_1Grade is:%d\n",temp->Course_1Grade);
    printf("Course_2ID is:%d\n",temp->Course_2ID);
    printf("Course_2Grade is:%d\n",temp->Course_2Grade);
    printf("Course_3ID is:%d\n",temp->Course_3ID);
    printf("Course_3Grade is:%d\n",temp->Course_3Grade);

    return;
  }
  while(temp!=NULL&&temp->StudentID!=id)
  {
    prev=temp;
    temp=temp->next;
  }
}
void is_exist(struct Node** head_ref, int id)
{
  struct Node* temp=*head_ref,*prev;
  if(temp!=NULL&&temp->StudentID==id)
  {
        *head_ref = temp->next;
    printf("  StudentID is Exist \n");
    return;
  }
  while(temp!=NULL&&temp->StudentID!=id)
  {
    prev=temp;
    temp=temp->next;
  }
}
void counter()
{
  printf("Number of students in database = %d \n",count);
}
void printID(struct Node *node)
{
  while (node != NULL)
  {
    printf("StudentID Number %d is:%d\n",count,node->StudentID);
     node = node->next;
  }}
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf(" StudentID is:%d\n",node->StudentID);
    printf(" StudentYear is:%d\n",node->StudentYear);
    printf(" Course_1ID is:%d\n",node->Course_1ID);
    printf(" Course_1Grade is:%d\n",node->Course_1Grade);
    printf(" Course_2ID is:%d\n",node->Course_2ID);
    printf(" Course_2Grade is:%d\n",node->Course_2Grade);
    printf(" Course_3ID is:%d\n",node->Course_3ID);
    printf(" Course_3Grade is:%d\n",node->Course_3Grade);
    node = node->next;
    printf("------------------------------\n");
  }
}
int main()
{
  struct Node* head = NULL;
uint8 StID;uint8 StYear;uint8 C_1ID;uint8 C_1Grade;uint8 C_2ID;uint8 C_2Grade;uint8 C_3ID;uint8 C_3Grade;
uint8 num,id;
A:printf("      >>Welcome in universty System<<   ");
  printf("\n");
  printf("if you want to insert student in first press 1:\n");
  printf("if you want to delete student press 2:\n");
  printf("if you want to search student press 3:\n");
  printf("if you want to print students Data press 4:\n");
  printf("if you want to print students ID press 5:\n");
  printf("if you want to search student id is exist or not press 6:\n");
  printf("if you want to know how many student in database press 7:\n");
  printf("if you want to know database is full or not press 8:\n");
  printf("if you want to Exit System press 0:\n");
  scanf("%d",&num);
  printf("------------------------------\n");
  while(num!=0){
  switch(num)
  {

  case 1:
  {
    printf("Enter Student ID: ");
    scanf("%d",&StID);
    printf("Enter Student Year: ");
    scanf("%d",&StYear);
    printf("Enter Course_1 ID: ");
    scanf("%d",&C_1ID);
    printf("Enter Course_1 Grade: ");
    scanf("%d",&C_1Grade);
    printf("Enter Course_2 ID: ");
    scanf("%d",&C_2ID);
    printf("Enter Course_2 Grade: ");
    scanf("%d",&C_2Grade);
    printf("Enter Course_3 ID: ");
    scanf("%d",&C_3ID);
    printf("Enter Course_3 Grade: ");
    scanf("%d",&C_3Grade);
     printf("------------------------------\n");
  Add_std(&head,StID,StYear,C_1ID,C_1Grade,C_2ID,C_2Grade,C_3ID,C_3Grade);
  break;}

  case 2:
  {
    printf("Enter Student id to delete it");
    scanf("%d",&id);
  deleteNode(&head,id);
  break;}
  case 3:
  {
  printf("Enter Student id to search it");
  scanf("%d",&id);
  search(&head,id);
  break;}
  case 4:
  {
    printList(head);
  break;}
   case 5:
  {
    printID(head);
  break;}
 case 6:
  {
  printf("Enter Student id to search it");
  scanf("%d",&id);
  is_exist(&head,id);
  break;}
 case 7:
  {
  counter();
  break;}
   case 8:
  {
  SDB_isfull();
  break;}
  default:
  break;
    }
  goto A;
  }
  printf("Think you for using universty System \n");
  return 0;
}
