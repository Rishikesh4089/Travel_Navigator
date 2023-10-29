#include <iostream>
using namespace std;

class node;
node *start=NULL;
class node{    
    string name, src, dest;
    int age, cont, days, budget;    
    node *next;    
    public:    
    node *create_node(){        
        node *temp;
        temp=new(node);        
        temp->next=(NULL);         
         return(temp);    
    }    
    void insert(string n, int d, int x, int y, int z, string a, string b){        
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
    void del(){        
        int pos, i=1;        
        node *temp3, *temp1, *temp2;        
        temp1=start;        
        cout<<"Enter the position: ";        
        cin>>pos;        
        if(start==NULL){            
            cout<<"List is empty\n";            
            return;        
        }        
        while(i<pos-1){            
            temp1=temp1->next;            
            i++;        
        }        
        if(temp1==start){
            temp2=temp1;            
            temp2=temp2->next;            
            start=temp2;            
            delete(temp1);            
            return;        
        }        
        if(temp1->next->next==NULL){            
            temp2=temp1->next;            
            temp1->next=NULL;            
            delete(temp2);            
            return;        
        }        
        temp3=temp1->next;        
        temp2=temp1->next->next;        
        temp1->next=temp2;        
        delete(temp3);        
        return;    
    }    
    //void display(){        
        //node *temp;        
        //temp=start;
        //cout<<"The elements of the list are: \n";        
        //while(temp->next!=NULL){            
            //cout<<temp->info<<" ";            
            //temp=temp->next;        
        //}        
        //cout<<temp->info<<endl;    
    //}
};
        
        
void user_details(){    
    node n;    
    string a, f, g;
    int ch,b,c,d, e;              
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