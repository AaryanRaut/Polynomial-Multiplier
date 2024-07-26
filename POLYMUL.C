#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};

     void create(struct node *first);
     void disp(struct node *first);
     void mulpoly(struct node *f1 , struct node *f2 ,struct node *f3);

  int menu()
  {
       int choice;

       clrscr();

       printf("\n 1] Create first poly ");
       printf("\n 2] Display first poly ");
       printf("\n 3] Create second poly ");
       printf("\n 4] Display second poly ");
       printf("\n 5] Multiply poly ");
       printf("\n 6] Disp mul ");
       printf("\n 7] Exit ");

       printf("\n\n Enter your choice : ");
	    scanf("%d" ,&choice);

	    return choice;
  }


void main()
{
   int ch;
   struct node *start1 , *start2  , *start3 ;

  clrscr();

       do
       {
	    ch = menu();

	    switch(ch)
	    {
		case 1:
			 start1 = (struct node *)malloc(sizeof(struct node));
			 create(start1);
			 disp(start1);
			  break;
		case 2:
			 disp(start1);
			  break;
		case 3:
			 start2 = (struct node *)malloc(sizeof(struct node));
			 create(start2);
			 disp(start2);
			 break;
		case 4:
			 disp(start2);
			 break;
		case 5:
			 start3 = (struct node *)malloc(sizeof(struct node));
			 mulpoly(start1 , start2 , start3);
			 disp(start3);
			 break;
		case 6:
			 disp(start3);
			 break;
		case 7:
			  printf("\n\n THANK YOU ! ");
			     getch();
			     exit(0);
		default:
			  printf("\n NOT VALID");
	    }
	      getch();
       }while(ch != 7);
}

     void create(struct node *first)
     {
	  int ch;

	   printf("\n\n Enter coeff : ");
	    scanf("%d" , &first->coeff);

	   printf("\n\n Enter power : ");
	    scanf("%d" , &first->power);

	    printf("\n\n Do you want to continue (1/0)? : ");
		scanf("%d",&ch);

		if(ch == 1)
		{
		     first->next = (struct node *)malloc(sizeof(struct node));
			 create(first->next);
		}
		if(ch == 0)
		{
		     first->next = NULL;
		}
     }


     void disp(struct node *first)
     {
	if(first == NULL)
	{
	     printf("\n EMPTY");
	}
	else
	{
	       printf("\n\n");

	     while(first != NULL)
	     {
		 printf(" %dx^%d ",first->coeff , first->power);
		 printf("+");
		 first = first->next;
	     }
		   printf("\b ");
	}
     }

     void  mulpoly(struct node *f1 , struct node *f2 ,struct node *f3)
     {
	 struct node *temp = f2;

	while(f1 != NULL)
	{
	  while(f2 != NULL)
	  {
	    f3->coeff = f1->coeff * f2->coeff;
	    f3->power = f1->power + f2->power;

	       f2 = f2->next;

	      if(f2 == NULL)
	      {
		 f3->next = NULL;
	      }
	      else
	      {
		 f3->next = (struct node*)malloc(sizeof(struct node*));
		   f3 = f3->next;
	      }
	  }

	      f1 = f1->next;

	      if(f1 != NULL)
	      {
		 f3->next = (struct node*)malloc(sizeof(struct node*));
		 f3 = f3->next;
	      }
		  f2 = temp;
	 }
     }
