#include<iostream>
#include<string>
using namespace std;
 //   build a node  
class node 
{
	public:
	    int ID;
	    string title,author,publication;
	    double price;           
	    int copies;
        node* next;
};
class bookshop
{
	public:
	    node *head;
	    bookshop()
	    {
	    	head=NULL;
		}
	    void beg();
        void add_first_book();      
	    void create_list_books();
	    void del_books();
	    void modify();
	    int display();
	    void purchase_books();
	    int search(int id);
};
//      for entering(saving) 1st record in list
void bookshop::add_first_book()      
{
	int id,co;          
	string name,au,pub;
	double pri;          
	struct node *t=new node;
	cout<<"\n\n\t\t\tEnter book ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\n\n\t\t\tEnter book Title:-";
	cin>>name;
	t->title=name;
	cout<<"\n\n\t\t\tEnter book Author:-";
	cin>>au;
	t->author=au;
	cout<<"\n\n\t\t\tEnter book publication:-";
	cin>>pub;
	t->publication=pub;
	cout<<"\n\n\t\t\tEnter book price:-";
	cin>>pri;
	t->price=pri;
	cout<<"\n\n\t\t\tEnter book copies:-";
	cin>>co;
	t->copies=co;
	t->next=head;
	head=t;
		cout<<"\n\n\t\t\t\tThis book is Added !\n\n\n";
}

// for entering(saving) 2nd and onward records in list
void bookshop::create_list_books()
{
	int id,co;     
	string name,au,pub;
	double pri;           
	struct node *t=new node;
	struct node *p=head;
	cout<<"\n\n\t\t\tEnter book ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\n\n\t\t\tEnter book Title:-";
	cin>>name;
	t->title=name;
	cout<<"\n\n\t\t\tEnter book Author:-";
	cin>>au;
	t->author=au;
	cout<<"\n\n\t\t\tEnter book publication:-";
	cin>>pub;
	t->publication=pub;
	cout<<"\n\n\t\t\tEnter book price:-";
	cin>>pri;
	t->price=pri;
	cout<<"\n\n\t\t\tEnter book copies:-";
	cin>>co;
	t->copies=co;
		while(p->next!=NULL)
		{
		p=p->next;
		}
			p->next=t;
			t->next=NULL;
		cout<<"\n\n\t\t\t\tThis BOOK is Added !\n\n\n";
}


void bookshop::del_books()
{
	cout<<"\n                                                   List Of all the books\n";
	int count=display();
	int id;
    node *cur=head;
	node *pre=head;
	cout<<"\n\nEnter ID to delete that BOOK:\n\n";
	cin>>id;
	if (head == NULL)
    {
    	system("cls");
        cout<<"Stock is empty"<<endl;
    }
	int pos=0;
	pos=search(id);                        //   for check weather desire node is exist or not    
	if(pos<=count)
	{
		while(cur->ID!=id)
		{               
		    pre=cur;
		    cur=cur->next;
        }
		pre->next=cur->next;
		cout<<"\n\n<<Book is deleted>>\n";
	}
	else
	{
		cout<<"\n<<<BOOK Not found>>\n\n";
	}
	cout<<"________________________________________________________________________________________________________________________________________________________________________________\n\n";   
}


	
void bookshop::modify()
{
	int id;
	double pre;        //    pre for price
	string pName; //   pName for new name
	char ans;     
	if (head == NULL)
    {
    	system("cls");
        cout<<"Stock is empty"<<endl;
    }
	else
	{
		int count=display();  
		cout<<"\n\nEnter ID to search and modify BooK Name and its price:\n";
		cin>>id;
		node *cur=head;
		int pos=0;        
	    pos=search(id); 
		cout<<"\nDo You Want to modify the Book Details...?????(y/n)";   
		cin>>ans;               
	    if(pos<=count)
		{
		    while(cur->ID!=id)
			{
			    cur=cur->next;
		    }
		    while(ans=='y')
		    {  
		        cout<<"\nOld Title : "<<cur->title;
		        cout<<"\nOld Price : "<<cur->price<<endl;
		        cout<<"Enter new Title:";
		        cin>>pName;
		        cur->title=pName;
		        cout<<"Enter new Price:";
		        cin>>pre;
		        cur->price=pre;
		        break;
	        }    
	    }
	    else
		{
		    cout<<id<<" is <<<Not found>>\n\n";
	    }		
	}
	cout<<"__________________________________________________________________________________________________________________________________________________________________________________\n\n";
}
	

int bookshop::display()
{
	int c=0;             //   c for count 
    node *p=head;
	while(p!=NULL)
	{
		cout<<"ID : "<<p->ID<<"  |  "<<"BOOK TITLE: "<<p->title<<"  |  "<<"BOOK AUTHOR : "<<p->author<<"  |  "<<"PUBLCATION : "<<p->publication<<"  |  "<<"BOOK PRICE : "<<p->price<<"  |  "<<"BOOK COIPES : "<<p->copies<<"\n"; //    call   check func and pass quantity
		p=p->next;
		c=c+1;
	}
	cout<<"\n\n\t\t\t\t\t\tTotal products in our store is : "<<c<<"\n\n\n";
	cout<<"_____________________________________________________________________________________________________________________________________________________________________\n\n";   
	return c;
}	
	    
	    
void bookshop::purchase_books()
{
	string products[20]; 
	int pay=0,no,c=0,price,id,i=1;
	if(head==NULL) 
	{
	    cout<<"\n<<<<There are no book to buy>>>>\n\n";	
	}
	else
	{
		cout<<"\n\n            How many books you wanna to purchase!\n";
		cin>>no;
		int count=display();           //   for store no of nodes  in c
		while (i<=no)
		{
			node *cur=head;
			int quant,cho;              //   quant   for quantity  and cho for choice
	        cout<<"\n\n                  Enter id of book that you want to purchase: ";
            int id,pos=0;
	        cin>>id;
	        pos=search(id);
	        if(pos<=count)
			{  
	            while(cur->ID!=id)
				{
			        cur=cur->next;
		        }
                cout<<"\n\n                  How many quantities you want:";
	            cin>>quant;
	            products[c]=cur->title; c++;
	            pay=pay+(cur->price*quant);         //     calculate Bill	
	            cur->copies=cur->copies-quant;           //    change quantity
	            i++;	
	        }
	        else
			{
		        cout<<"\n<<<<<<<<<This book is not available in our store at this time>>>>\n\n";
	        }
        }
	    system("cls");	
	    cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";       
	    cout<<"                                                                                        BILL \n\n";
	    cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n \t\t\t\t\t\t\n"; 
		cout<<"\n\n\n\n\t\t\t     You have bought : ";
        for(int i=0;i<no;i++)
		{              //    show that book you have bought
	        cout<<i+1<<") "<<products[i]<<"\n\t\t\t\t\t\t";
        }	
        price=pay*(0.95);           //    with 5% discount
	    cout<<"\n\n               Original price : "<<pay<<"/-";
        cout<<"\n\n              *****with 5% discount*****: "<<price<<"/-"<<"\n\n=========================================                 THANK YOU FOR PURCHASING.....!!!!!!!!!!!               =================================================\n\n";
		}
        cout<<"___________________________________________________________________________________________________________________________________________________________________\n\n";   
}
	
int bookshop::search(int id)                     //    for search book in stock
{
    int count=1;
    node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 		{
 			cout<<"\n\nBOOK IS FOUND IN THE STOCK............";
 			break; 
 			
		 }
 		else
 		count++;
 		p=p->next;
	}
 	return count;
}
int main()
{
	bookshop bk;
	while(true)
	{
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";       
	cout<<"                                                                               BOOKSHOP MANAGEMENT SYSTEM\n\n";
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n \t\t\t\t\t\t\n"; 
	int temp=1;
	int ch;                    
	cout<<"\t\t\t\t\t\t\tEnter 1 || ADD A NEW BOOK ||\n\n\t\t\t\t\t\t\tEnter 2 || DISPLAY ALL BOOKS||\n\n\t\t\t\t\t\t\tEnter 3 || SEARCH AND MODIFY DETAILS OF EXIXTING BOOKS ||\n\n"; 
	cout<<"\t\t\t\t\t\t\tEnter 4 || DELETE A BOOK ||\n\n\t\t\t\t\t\t\tEnter 5 || PURCHASE BOOKS ||\n\n\t\t\t\t\t\t\tEnter 0 || EXIT ||\n\n";
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*";   
	cout<<"\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE :";
	cin>>ch;     
	switch(ch)
	{
	case 1:
		system("cls");
        cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";            
	    cout<<"                                                                                 ADDING NEW BOOK\n\n";
	    cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n \t\t\t\t\t\t\n"; 
	    if (temp==0)
		{             
	        bk.create_list_books();	
	    }
	    if(temp==1)
		{              
	        bk.add_first_book();	
	        temp=0;
		}
	    break;
    case 2:
    system("cls");
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";            
	cout<<"                                                                               DISPLAYING ALL BOOKS\n\n";
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n \t\t\t\t\t\t\n";
	bk.display();
    break; 
    case 3:
	system("cls");
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";            
	cout<<"                                                                              SEARCH AND MODIFY DETAILS OF BOOK\n\n";
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n \t\t\t\t\t\t\n";  
	bk.modify();
	break;
    case 4:
	system("cls");
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";            
	cout<<"                                                                              DELETE BOOKS\n\n";
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n \t\t\t\t\t\t\n";  
	bk.del_books();
	break;
    case 5:
	system("cls");
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";            
	cout<<"                                                                              PURCHASE BOOKS\n\n";
	cout<<"                                                =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n \t\t\t\t\t\t\n";  
	bk.purchase_books();
	break;		
    case 0:
        cout<<"Exiting..."<<endl;
	    exit(true);                    //   exit from while loop
        break; 
    default: system("cls");
         cout<<"\t\t<<<Wrong choice>>>\n\n";
	}
}
return 0;	
}

