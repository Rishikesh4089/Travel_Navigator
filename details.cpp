#include <iostream>
using namespace std;

class node;
node *start=NULL;
class node{    
    string name, src, dest;
    long int cont;
    int age, days, budget;    
    node *next;    
    public:    

    node *create_node(){        
        node *temp;
        temp=new(node);        
        temp->next=(NULL);         
         return(temp);    
    } 

    void insert(string n, int d, long int x, int y, int z, string a, string b){        
        node *newnode, *temp;        
        newnode=create_node();        
        newnode->name=n;
        newnode->age=d;
        newnode->cont=x;
        newnode->days=y;
        newnode->budget=z;
        newnode->src=a;
        newnode->dest=b;        
        temp=start; 
        if(start==NULL){           
            start=newnode;            
            return;        
        }
        while(temp->next!=NULL){            
            temp=temp->next;        
        }        
        temp->next=newnode;        
        newnode->next=NULL;        
        return;    
    }    

    int tourDays(){
        node *temp;
        temp = start;
        while(temp != NULL){
            return temp->days;
            temp=temp->next;
        }
        return 0;
    }
    int budgetDisplay(){
        node *temp;
        temp = start;
        while(temp != NULL){
            return temp->budget;
            temp=temp->next;
        }
        return 0;
    }
    string startNode(){
        node *temp;
        temp = start;
        while(temp != NULL){
            return temp->src;
            temp=temp->next;
        }
        return 0;
    }
    string endNode(){
        node *temp;
        temp = start;
        while(temp != NULL){
            return temp->dest;
            temp=temp->next;
        }
        return 0;
    }
};
        
        
void user_details(){    
    node n;    
    string a, f, g;
    long int c;
    int ch,b,d, e;              
    cout<<"Enter your name: ";  
    cin>>a;
    cout<<"Enter your age: ";  
    cin>>b;
    cout<<"Enter your contact number: ";  
    cin>>c;
    cout<<"Enter the number of days you want to take a tour for: ";  
    cin>>d;
    cout<<"Enter your budget: ";  
    cin>>e;
    cout<<"Which city do you wish to start from: ";
    cin>>f;
    cout<<"Which city do you want to be your destination: ";
    cin>>g;
    n.insert(a,b, c, d, e, f, g);
    cout<<endl;
}

int checkBudget(int x, int y){
    if(x<=y){
        cout<<"This tour is suitable for you\n";
        return 0;
    }else{
        cout<<"The tour cost exceeds your budget\n";
        return -1;
    }
}
