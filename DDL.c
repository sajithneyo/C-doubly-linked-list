//
//Its menu driven and consists with sub menus for INSERT, DELETE and SEARCH functions.
// Created by Sajith Neyomal on 7/7/2017.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE* link; //node type link

struct NODE
{
	int data;
	link next; //struct NODE* next;
	link prev; //struct NODE* prev;
};

typedef struct
{
	link head; //struct NODE* head;
	link tail; //struct NODE* tail;
}HandT; //HandT = Head and Tail

///////////////////////////PROTOTYPING//////////////////////////

void flushInOut();
void initHandTnull(HandT *l);
link newNODE(int val);
void initBeginning(HandT *l);
void beginningNODE(HandT *l,link  Temp);
void initEnd(HandT *l);
void endNODE(HandT *l,link Temp);
void initBetween(HandT *l);
void betweenNODE(HandT *l,link Temp,int position,int nodeCount);
int nodeCounter(HandT *l);
void refreshPrint(HandT *l);
void printForward(HandT *l);
void printBackward(HandT *l);
void searchValue(HandT *l);
void recurringSearchValues(HandT *l);
int returnSearching(HandT *l,int sVal);
void deleteBeginning(HandT *l);
void forceDeleteBeginning(HandT *l);
void deleteEnd(HandT *l);
void forceDeleteEnd(HandT *l);
void deleteBetween(HandT *l);
void sortDLL(HandT *l);


///////////////////////////MAIN FUNCTION///////////////////////

int main()
{
	
	HandT *l = (HandT*)malloc(sizeof(HandT)); //link named l to point HandT
	int select;
	int select1;
	int select2;
	int select3;
	
	flushInOut();
	initHandTnull(l);
		
	do
	{	
		flushInOut();	
		printf("~~~~~~DOUBLY LINK LIST MAIN FUNCTIONS~~~~~~\n\n");
		printf("1=Initialize HEAD & TAIL values as NULL or DESTROY DOUBLY LINK LIST\n");
		printf("2=Insert Functions ===>\n");
		printf("3=Search Functions ===>\n");
		printf("4=Delete Functions ===>\n");
		printf("5=Sort DOUBLY LINK LIST in ASSENDING/DESSENDING order\n");
		printf("6=Print DOUBLY LINK LIST forward inorder traversal\n");
		printf("7=Print DOUBLY LINK LIST backward inorder traversal\n");
		printf("Enter any other number to exit!!!\n");
		printf("Insert your choice: ");
		scanf("%i",&select);
		switch(select)
		{
			case 1:printf("\n");initHandTnull(l);printf("Doubly Link List Destroyed!\n");printf("\n");break;
			////////
			case 2:
			do
			{
				printf("\n");
				printf("~~~Submenu for INSERT FUNCTIONS~~~\n");
				printf("\n");
				printf("1=Insert NODE at the BEGINNING\n");
				printf("2=Insert NODE at the END\n");
				printf("3=Insert NODE at the IN-BETWEEN\n");
				printf("Enter any other number to exit submenue!!!\n");
				printf("Insert your choice: ");
				scanf("%i",&select1);
				switch(select1)
				{
					case 1:printf("\n");initBeginning(l);printf("\n");break;
					case 2:printf("\n");initEnd(l);printf("\n");break;
					case 3:printf("\n");initBetween(l);printf("\n");break;
					default:printf("\n");break;
				}
			}while(select1 >0 && select1<4 );break;
			////////
			case 3:
			do
			{
				printf("\n");
				printf("~~~Submenu for SEARCH FUNCTIONS~~~\n");
				printf("\n");
				printf("1=Search for a NODE/VALUE\n");
				printf("2=Search for a recurring NODE/VALUE\n");
				printf("Enter any other number to exit submenue!!!\n");
				printf("Insert your choice: ");
				scanf("%i",&select2);
				switch(select2)
				{
					case 1:printf("\n");searchValue(l);printf("\n");break;
					case 2:printf("\n");recurringSearchValues(l);printf("\n");break;
					default:printf("\n");
				}
			}while(select2 >0 && select2<3);break;
			/////////
			case 4:
			do
			{
				printf("\n");
				printf("~~~Sub-menu for DELETE FUNCTIONS~~~\n");
				printf("\n");
				printf("1=Search and Delete NODE at the BEGINNING if only exsists\n");		
				printf("2=Search and Delete NODE at the END if only exsists\n");
				printf("3=Search and Delete NODE IN-BETWEEN if only exsists\n");
				printf("4=FORCE!!! Delete NODE at the BEGINNING\n");
				printf("5=FORCE!!! Delete NODE at the END\n");
				printf("Enter any other number to exit submenue!!!\n");
				printf("Insert your choice: ");
				scanf("%i",&select3);
				switch(select3)
				{
					case 1:printf("\n");deleteBeginning(l);printf("\n");break;
					case 2:printf("\n");deleteEnd(l);printf("\n");break;			
					case 3:printf("\n");deleteBetween(l);printf("\n");break;
					case 4:printf("\n");forceDeleteBeginning(l);printf("\n");break;
					case 5:printf("\n");forceDeleteEnd(l);printf("\n");break;
					default:printf("\n");
				}
			}while(select3 >0 && select3<5);break;
			case 5:printf("\n");sortDLL(l);printf("\n");break;
			case 6:printf("\n");printForward(l);printf("\n");break;
			case 7:printf("\n");printBackward(l);printf("\n");break;			
			default:printf("\n");printf("Worng input!!! GOODBYE!!! \n");printf("\n");exit(0);
		}
	}while(select<8);
}

/////////////////////////FUNCTIONS////////////////////////


void flushInOut()
{
	fflush(stdin);
	fflush(stdout);
}

void initHandTnull(HandT *l)
{
	l->head=NULL;
	l->tail=NULL;
}

link newNODE(int val) //create a new node
{
	link tempNODE = (link)malloc(sizeof(struct NODE));
	tempNODE->data = val;
	tempNODE->next = NULL;
	tempNODE->prev = NULL;
	return tempNODE;
}

void initBeginning(HandT *l)
{
	int bVal;
	char answer;
	       
    printf("Do you want to insert a NODE in the beginning(Y/N)? : ");
    scanf(" %c",&answer);
    
    while(answer=='Y' || answer=='y')
    {
    	printf("Enter NODE value: ");
    	scanf("%i",&bVal);
    	printf("\n");
    	
    	beginningNODE(l,newNODE(bVal));
		
		printf("Do you want to continue entering values to the DLL(Y/N)? : ");
    	scanf(" %c",&answer);  
    }  
}

void beginningNODE(HandT *l,link  Temp)
{
	int nodeNum=1;
	
	link temp;

	if(l->head==NULL)
	{
		l->head=Temp;
		l->tail=Temp;
	}
	else
	{	
		Temp->next=temp=l->head;
		temp->prev=l->head=Temp;		
	}
	
	refreshPrint(l);
}

void initEnd(HandT *l)
{
	int eVal;
	char answer;
 		
    printf("Do you want to insert a NODE in the end(Y/N)? : ");
    scanf(" %c",&answer);
    
    while(answer=='Y' || answer=='y')
    {
    	printf("Enter NODE value: ");
    	scanf("%i",&eVal);
    	printf("\n");
    	
    	endNODE(l,newNODE(eVal));
		
		printf("Do you want to continue entering values to the DLL(Y/N)? : ");
    	scanf(" %c",&answer);
    }  
}

void endNODE(HandT *l,link Temp)
{
	link temp;
	
	if(l->head==NULL)
	{
		l->head=Temp;
		l->tail=Temp;
	}
	else
	{
		Temp->prev=temp=l->tail;
		temp->next=l->tail=Temp;
	}
	
	refreshPrint(l);
}

void initBetween(HandT *l)
{
	char answer;	
 	int newVal,position,nodeCount;
 	
 	nodeCount = nodeCounter(l);
 	
 	printf("There are %i NODE/S in the DLL\n",nodeCount);
    printf("Do you want to insert a NODE in-between(Y/N)? : ");
    scanf(" %c",&answer);
    
    while(answer=='Y' || answer=='y')
    {
    	printf("Enter the position where you need to enter new value: ");
    	scanf("%i",&position);
    	nodeCount = nodeCounter(l);
    	if(position<0) //checks if enetring possion is negative
    	{
    		printf("Invalid Position!!!\n");
	    	break;
	    }
	    
	    if(position==1 && nodeCount==1)//if DLL consists 1 node and user inputs '1' as possition user will be redirected to head or a tail insertion
	    {
    		int userIn=0;
    		
    		printf("\n");
	    	printf("DLL contains only 1 NODE! please press (1) to BEGINNING INSERT ro enter (2) to END INSERT \n");
	    	scanf("%i",&userIn);
	    	printf("\n");
	    	
	    	if(userIn==1)
	    	{
	    		initBeginning(l);
	    		break;
	    	}
	    	else if(userIn==2)
	    	{
	    		initEnd(l);
	    		break;
	    	}
	    	else
			{
	    		printf("Invalid Input!!!\n");
	    		break;
	    	}
    	}
	    
	    if(position==0 && nodeCount>0) //if entering possition is 0,then it's a beginning insertion
	    {
	    	printf("\n");
	    	printf("Will be re-directed to BEGINNING insertion!!!\n");
	    	printf("\n");
    		initBeginning(l);
    		break;
    	}
    	
    	if(position==0 && nodeCount==0) //checks whether DDL is null.IF null you can enter in BEGINNING or END
    	{
    		int userIn=0;
    		
    		printf("\n");
	    	printf("DLL is empty! please press (1) to BEGINNING INSERT ro enter (2) to END INSERT \n");
	    	scanf("%i",&userIn);
	    	printf("\n");
	    	
	    	if(userIn==1)
	    	{
	    		initBeginning(l);
	    		break;
	    	}
	    	else if(userIn==2)
	    	{
	    		initEnd(l);
	    		break;
	    	}
	    	else
			{
	    		printf("Invalid Input!!!\n");
	    		break;
	    	}
	    }
	    
	    if(nodeCount+1==position) //checks if the node count +1 is equal to the entered possion. If so it's a END insertion
	    {
	    	printf("\n");
    		printf("Will be re-directed to END insertion!!!\n");
    		printf("\n");
    		initEnd(l);
    		break;
    	}	 	
    	
		//ideal checking for instances other than above mentioned. This will filter only middle insertion instance!
	    if((nodeCount>1) && (((position<nodeCount) || (position==nodeCount))&&(position>0)))
	    {	
   			printf("Enter the new NODE value you need to insert: ");
   			scanf("%i",&newVal);
   			
   			betweenNODE(l,newNODE(newVal),position,nodeCount);
   			
   			nodeCount = nodeCounter(l);	
 			printf("There are %i NODE/S in the DLL\n",nodeCount);
   			printf("Do you want to continue entering values to the DLL(Y/N)? : ");
    		scanf(" %c",&answer);  
    	}
		else
		{
			printf("Invalid Input!!!\n");
			break;
		} 
    } 
}

void betweenNODE(HandT *l,link Temp,int position,int nodeCount)
{
	int userIn;
	int counter;
	link temp1,temp2;
	
	if(position==1)
	{
		printf("Do you want to enter before(1) the FIRST NODE or after(2) the FIRST NODE? ");
		scanf("%d",&userIn);
		
		if(userIn==1)
		{
			Temp->next=temp1=l->head;
			temp1->prev=l->head=Temp;			
		}
		else if(userIn==2)
		{
			temp1=l->head;
			temp2=temp1->next;
			Temp->prev=temp1;
			Temp->next=temp2;
			temp2->prev=Temp;
			temp1->next=Temp;	
		}
		else
		{
			printf("\n");
			printf("Invalid Input!!!\n");
			printf("\n");
		}
	}
	else if(position==nodeCount)
	{
		printf("Do you want to enter before(1) the END NODE or after(2) the END NODE? ");
		scanf("%i",&userIn);
		
		if(userIn==1)
		{
			temp1=l->tail;
			temp2=temp1->prev;
			Temp->prev=temp2;
			Temp->next=temp1;
			temp1->prev=Temp;
			temp2->next=Temp;
		}		
		else if(userIn==2)
		{
			Temp->prev=temp1=l->tail;
			temp1->next=l->tail=Temp;
		}
		else
		{
			printf("\n");
			printf("Invalid Input!!!\n");
			printf("\n");
		}		
	}
	else
	{
		printf("Do you want to enter before(1) the NODE or after(2) the NODE? ");
		scanf("%i",&userIn);
						
		temp1=l->head;
		
		counter=1;
		
		while(counter!=position)
		{
			temp1=temp1->next;
			counter++;
		}
		
		if(userIn==1)
		{
			temp2=temp1->prev;
			Temp->prev=temp2;
			Temp->next=temp1;
			temp1->prev=Temp;
			temp2->next=Temp;	
		}
		else if(userIn==2)
		{
			temp2=temp1->next;
			Temp->prev=temp1;
			Temp->next=temp2;
			temp2->prev=Temp;
			temp1->next=Temp;
		}
		else
		{
			printf("\n");
			printf("Invalid Input!!!\n");
			printf("\n");
		}
	}
	refreshPrint(l);
}

void searchValue(HandT *l)
{
	int sVal,counter;
	int found=0;
	
	link temp;
	
    printf("Enter the NODE value to be searched: \n");
    scanf("%i",&sVal);
    printf("\n");
     
    temp=l->head;
    
    counter=1;
    
    if(l->head==NULL)
    {
		printf("Doubly Link List is empty!!!\n");
    }
    else if(temp->data==sVal)
    {
    	printf("Search value found! Searched value is %i and the NODE containing the value is in the Possition %i \n",sVal,counter);
    	found=1;
    }   
    else
    {
	    while(temp!=NULL && (!found))
	    {
	    	if(temp->data==sVal)
	    	{
		    	printf("Search value found! Searched value is %i and the NODE containing the value is in the Possition %i \n",sVal,counter);
		    	found=1;
		    }
		    else
		    {
    			counter++;
	    		temp=temp->next;
    		}	    	
	    }		
    }
    
    if(!found)
    {
    	printf("Searched value not found!!! \n");
    }   
}

void recurringSearchValues(HandT *l)
{
	int sVal,counter;
	int found=0;
	
	link temp;
	
    printf("Enter the NODE value to be searched: \n");
    scanf("%i",&sVal);
    printf("\n");
     
    temp=l->head;
    
    counter=1;
    
    if(l->head==NULL)
    {
		printf("Doubly Link List is empty!!!\n");
    }
    else
    {
    	while(temp!=NULL)
	    {
	    	if(temp->data==sVal)
	    	{
		    	printf("Search value found! Searched value is %i and the NODE containing the value is in the Possition %i \n",sVal,counter);
		    	found=1;
		    	counter++;
		    	temp=temp->next;
		    }
		    else
		    {
    			counter++;
	    		temp=temp->next;
    		}	    	
	    }		
    }   
 
    if(!found)
    {
    	printf("Searched value not found!!! \n");
    }   
}

void deleteBeginning(HandT *l)
{
	int status;
	int sVal;
		
	link temp1,temp2;
	
	printf("Enter the value to be deleted from the beginning: \n");
	scanf("%i",&sVal);
	
 	status = returnSearching(l,sVal);

 	if(l->head==NULL)
 	{
	 	printf("Dubly Link List is NULL!!!\n");	
	}
 	else
 	{
	 	if(status)
	 	{
	 		temp1=l->head;
	 		printf("Value need to be deleted found!\n");
	 		
	 		if(temp1->data!=sVal)
	 		{
		 		printf("Sorry searched value is not in the beginning!\n");
		 	}
		 	else
		 	{
	 			if(temp1->next==NULL)
		 		{
		 			printf("Consists only 1 node! Node deleted successfully!\n");
					initHandTnull(l);
				}
				else
				{
					temp2=temp1->next;
					l->head=temp2;
					temp1->next=NULL;
					temp2->prev=NULL;
				}
				printf("Successfully deleted value :%i\n",sVal);
	 		}	
		}
		else
		{
			printf("Value not found!!!\n");
		}
	}
 	
}

void forceDeleteBeginning(HandT *l)
{
	int status;
	int sVal;
		
	link temp1,temp2;
	
	char ans;
	
	temp1=l->head;
	
 	if(l->head==NULL)
 	{
	 	printf("Dubly Link List is NULL!!!\n");	
	}
 	else if(temp1->next==NULL)
 	{
 		printf("Dubly Link List consists only with one NODE!!! value=%i\n",temp1->data);
 		printf("Are you sure you want to delete NODE(Y/N)???\n");
 		scanf(" %c",&ans);
 		if(ans=='Y' || ans=='y')
 		{
		 	initHandTnull(l);
		 	printf("Value deleted!!!\n");
		}
	}
	else
	{
		printf("Dubly Link List first NODE value= %i\n",temp1->data);
		printf("Are you sure you want to delete NODE(Y/N)???\n");
		scanf(" %c",&ans);
 		if(ans=='Y' || ans=='y')
 		{
		 	temp2=temp1->next;
			l->head=temp2;
			temp1->next=NULL;
			temp2->prev=NULL;
			printf("Value deleted!!!\n");
		}
	}	
}

void deleteEnd(HandT *l)
{
	int status;
	int sVal;
		
	link temp1,temp2;
	
	printf("Enter the value to be deleted from the end: \n");
	scanf("%i",&sVal);
	
 	status = returnSearching(l,sVal);
 	
 	if(l->head==NULL)
 	{
	 	printf("Dubly Link List is NULL!!!\n");	
	}
	else
	{
		if(status)
	 	{
	 		printf("Value need to be deleted found!\n");
	 		
	 		temp1=l->tail;
	 		
	 		if(temp1->data!=sVal)
	 		{
		 		printf("Sorry searched value is not in the end!\n");
		 	}
		 	else
		 	{
	 			if(temp1->prev==NULL)
		 		{
		 			printf("Consists only 1 node! Node deleted successfully!\n");
					initHandTnull(l);	
				}
				else
				{
					temp2=temp1->prev;
					l->tail=temp2;
					temp1->prev=NULL;
					temp2->next=NULL;
				}
				printf("Successfully deleted value :%i\n",sVal);	
	 		}
		}
		else
		{
			printf("Value not found!!!\n");
		}
	}
}

void forceDeleteEnd(HandT *l)
{
	int status;
	int sVal;
		
	link temp1,temp2;
	
	char ans;
	
	temp1=l->head;
	
 	if(l->head==NULL)
 	{
	 	printf("Dubly Link List is NULL!!!\n");	
	}
 	else if(temp1->next==NULL)
 	{
 		temp1=l->tail;
 		printf("Dubly Link List consists only with one NODE!!!value=%i\n",temp1->data);
 		printf("Are you sure you want to delete NODE(Y/N)???\n");
 		scanf(" %c",&ans);
 		if(ans=='Y' || ans=='y')
 		{
		 	initHandTnull(l);
		 	printf("Value deleted!!!\n");
		}
	}
	else
	{
		temp1=l->tail;
		printf("Dubly Link List last NODE value= %i\n",temp1->data);
		printf("Are you sure you want to delete NODE(Y/N)???\n");
		scanf(" %c",&ans);
 		if(ans=='Y' || ans=='y')
 		{
		 	temp2=temp1->prev;
			l->tail=temp2;
			temp1->prev=NULL;
			temp2->next=NULL;
			printf("Value deleted!!!\n");
		}
	}	
}


void deleteBetween(HandT *l)
{
	int countedVal = nodeCounter(l);
	int userIn;
	int status;
	int val;	
	link temp1,temp2,temp3;
	
	if(l->head==NULL)
 	{
	 	printf("Dubly Link List is NULL!!!\n");	
	}
	else
	{
		if(countedVal<3)
		{
			printf("Will be re-directed to Beginning(1) or End(2) delete. Enter: ");
			scanf("%i",&userIn);
			
			if(userIn==1)
			{
				deleteBeginning(l);
			}
			else if(userIn==2)
			{
				deleteEnd(l);
			}	
			else
			{
				printf("\n");
				printf("Invalid Input!!!\n");
				printf("\n");
			}
		}
		else
		{
			printf("Enter the value to be deleted: ");
			scanf("%i",&val);
			
			status = returnSearching(l,val);
			
			if(status)
			{
				temp1=l->head;
				while(temp1!=NULL)
				{		
					if(temp1->data==val)
					{
						temp3=temp1->next;
						temp2=temp1->prev;
						temp2->next=temp3;
						temp3->prev=temp2;
						temp1->data=NULL;
						temp1->next=NULL;
						temp1->prev=NULL;
					}
					temp1=temp1->next;
				}
				printf("Successfully deleted value :%i\n",val);
			}
			else
			{
				printf("Value not found!!!\n");
			}		
		}
	}
		
}

void sortDLL(HandT *l)
{
	int dllS = nodeCounter(l); //dllS=Doubly Link List Size
	int arr[dllS];
	int i,j,k,x;
	int userIn;
	link temp;
	link temp3;
	link temp1 = (link)malloc(sizeof(struct NODE));
	
		
	if(l->head==NULL || dllS==1)
	{
		printf("\n");
		printf("Doubly link list empty or consists only with single node. No way of sorting!!!\n");
		printf("\n");
	}
	else
	{
		i=0;
		temp=l->head;
		while(temp!=NULL)
		{
			arr[i]=temp->data;
			temp=temp->next;
			i++;
		}
		
		for(i=1;i<dllS;i++) 
		{
			x=arr[i];
			for (j=0;(arr[i]>arr[j])&&(j<i);j++);
				for (k=i;k>j;k--)
	 			{
					arr[k]=arr[k-1];
	 			}
	   			arr[j]=x;
		}
		
		printf("Assending Sorted List\n");
		for(k=0;k<dllS;k++)
		{
			printf("%i \n",arr[k]);
		}
		
		printf("\n");
		
		printf("Dessending Sorted List\n");
		for(k=dllS;k>0;k--)
		{
			printf("%i \n",arr[k-1]);
		}
		
		
		printf("How do you want to sort? (1)ASSENDING or (2)DESSENDING? ");
		scanf("%i",&userIn);
		
		if(userIn==1)
		{
			initHandTnull(l);
			
			l->head=temp1;
			l->tail=temp1;
			
			temp1->data=arr[0];
			
			temp3=temp1;
			for(k=1;k<dllS;k++)
			{
				link temp2 = (link)malloc(sizeof(struct NODE));
				temp1->prev=NULL;
				temp2->data=arr[k];
				temp2->prev=temp3;
				l->tail=temp2;
				temp3->next=temp2;
				temp2->next=NULL;
				temp3=temp2;
			}
			refreshPrint(l);
		}
		else if(userIn==2)
		{
			initHandTnull(l);
			
			l->head=temp1;
			l->tail=temp1;
			
			temp1->data=arr[dllS-1];
			
			temp3=temp1;
			for(k=dllS-2;k>-1;k--)
			{
				link temp2 = (link)malloc(sizeof(struct NODE));
				temp1->prev=NULL;
				temp2->data=arr[k];
				temp2->prev=temp3;
				l->tail=temp2;
				temp3->next=temp2;
				temp2->next=NULL;
				temp3=temp2;
			}
			refreshPrint(l);
		}
		else
		{
			printf("\n");
			printf("Invalid Input!!!\n");
			printf("\n");
		}	
	}	
}


int returnSearching(HandT *l,int sVal)
{
 	int counter;
	int found=0;
	
	link temp;
	
    //printf("Enter the NODE value to be searched: \n");
    //scanf("%i",&sVal);
    
    temp=l->head;
    
    counter=1;
    
    if(l->head==NULL)
    {
    	return 0;
    }
    
    if(temp->data==sVal)
    {
    	//printf("Search value found! Searched value is %i and the NODE containing the value is in the Possition %i \n",sVal,counter);
    	found=1;
    	return 1;
    }   
    else
    {
	    while(temp!=NULL && (!found))
	    {
	    	if(temp->data==sVal)
	    	{
		    	//printf("Search value found! Searched value is %i and the NODE containing the value is in the Possition %i \n",sVal,counter);
		    	found=1;
		    	return 1;
		    }
		    else
		    {
    			counter++;
	    		temp=temp->next;
    		}	    	
	    }		
    }
    
    if(!found)
    {
    	//printf("Searched value not found! \n");
    	return 0;
    }    
}

int nodeCounter(HandT *l)
{
	int counter=0;
	link search;
	search=l->head;
	if(l->head==NULL)
	{
		return 0;
	}
	else
	{	
		while(search!= NULL)
		{
			counter++;
			search=search->next;
		}
		return counter;
	}
}

void refreshPrint(HandT *l)
{
	int nodeNum=1;
	link temp;
	
	printf("HEAD pointer address : %p\n",l->head);
	printf("\n");
	temp=l->head;
	
	while(temp!=NULL)
	{
		printf("==NODE Number %i== \n",nodeNum);
		printf("NODE previous pointer : %p \n",temp->prev);
		printf("NODE stored value     : %i \n",temp->data);
		printf("NODE address          : %p \n",temp);
		printf("NODE next pointer     : %p \n",temp->next);		
		printf("=================== \n");
		printf("\n");
		temp=temp->next;
		nodeNum++;
	}
	printf("TAIL pointer address : %p\n",l->tail);
	printf("\n");
}

void printForward(HandT *l)
{
	int nodeNum=1;
	link temp;
	
	printf("======== Print Function START ========\n");
	
	if(l->head==NULL)
	{
		printf("HEAD pointer address : %p\n",l->head);
		printf("TAIL pointer address : %p\n",l->tail);
	}
	else
	{
		printf("HEAD pointer address : %p\n",l->head);
		printf("\n");
		temp=l->head;
	
		while(temp!=NULL)
		{
			printf("==NODE Number %i== \n",nodeNum);
			printf("NODE previous pointer : %p \n",temp->prev);
			printf("NODE stored value     : %i \n",temp->data);
			printf("NODE address          : %p \n",temp);
			printf("NODE next pointer     : %p \n",temp->next);		
			printf("=================== \n");
			printf("\n");
			temp=temp->next;
			nodeNum++;
		}
		printf("TAIL pointer address : %p\n",l->tail);
		printf("\n");
	}
	printf("======== Print Function END ========\n");
	printf("\n");
}

void printBackward(HandT *l)
{
	int nodeNum;
	link temp;
	
	printf("======== Print Function START ========\n");
	
	if(l->head==NULL)
	{
		printf("HEAD pointer address : %p\n",l->head);
		printf("TAIL pointer address : %p\n",l->tail);
	}
	else
	{
		printf("TAIL pointer address : %p\n",l->tail);
		printf("\n");
		
		nodeNum=nodeCounter(l);
		
		temp=l->tail;
	
		while(temp!=NULL)
		{
			printf("==NODE Number %i== \n",nodeNum);
			printf("NODE next pointer     : %p \n",temp->next);				
			printf("NODE stored value     : %i \n",temp->data);
			printf("NODE address          : %p \n",temp);
			printf("NODE previous pointer : %p \n",temp->prev);	
			printf("=================== \n");
			printf("\n");
			temp=temp->prev;
			nodeNum--;
		}
		printf("HEAD pointer address : %p\n",l->head);
		printf("\n");
	}
	printf("======== Print Function END ========\n");
	printf("\n");
}
