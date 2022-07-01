#include<iostream>
#include<string>
using namespace std;

struct Node{
    string name, contact, email, place;
    struct Node *next;
}*first=NULL;

struct Node *temp;

void insert_sorted(struct Node *p){
    struct Node *t,*q = NULL;
    t=new Node;
    cout<<"Enter the name: "; cin>>t->name;
    cout<<"Enter the phn no: "; cin>>t->contact;
    cout<<"Enter the email id: "; cin>>t->email;
    cout<<"Enter the place: "; cin>>t->place;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->name < t->name){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
} 

//function to create a new node
void create(){
    struct Node *t = new Node;        
    cout<<"Enter the name: "; cin>>t->name;
    cout<<"Enter the phn no: "; cin>>t->contact;
    cout<<"Enter the email id: "; cin>>t->email;
    cout<<"Enter the place: "; cin>>t->place;
    t->next=NULL;
    if(first==NULL){
        first = t;
        temp = t;
    }
    else{
        temp->next = t;
        temp = t;
    }
}

void display(struct Node *p){
    int count = 0;
    if(first==NULL){ cout<<"Phone Book is Empty"<<endl;}
    else{
        while(p){
            cout<<"\nName: "<<p->name<<"\nPhone no: "<<p->contact<<"\nEmail id: "<<p->email<<"\nPlace: "<<p->place<<endl;
            p=p->next;
            count++;
        }
        cout<<"\nTotal contacts in the phone book: "<<count<<endl;
    }
}

int count(struct Node *p){
    int count=0;
    while(p){
        p=p->next;
        count++;
    }
    return count;
}

void search(struct Node *p){
    int c=0;
    string s;
    bool found;
    cout<<"Enter the desired string";
    cin>>s;
    if(first==NULL){cout<<"Contact List is empty";}
    else{
        while(p){
            if(p->name==s || p->contact==s){
                found=true;
                cout<<"\nINDEX: "<<c+1;
                cout<<"\n"<<p->name<<" "<<p->contact<<" "<<p->email<<" "<<p->place<<endl;
            }
            c++;
            p=p->next;
        }
    }
    if(found!=true){
        cout<<"NOT IN THE PHONE BOOK, ADD IT!";
    }
}

void delete_(struct Node *p){
    int pos;
    cout<<"Enter the position from where u want to delete the contact"<<endl;
    cin>>pos;
    if(first==NULL){cout<<"Contact List is Empty!"<<endl;}
    else if(pos>count(first)){cout<<"Invalid position"<<endl;}
    else if(pos==0){
        struct Node *t = first;
        first=first->next;
        delete t;
        cout<<"Successfully deleted"<<endl;
    }
    else{
  for (int i = 1 ; i<pos ; i++) { 
      p = p->next;
  } 
      struct Node *t = p->next;
      p->next = t->next; 
      delete t;
      cout<<"Successfully deleted"<<endl;
    }
}

void clear_all (struct Node *p) { 
    if(first == NULL) { 
        cout<<"Phone Book is Empty "<<endl; } 
        else { 
            while (p) { 
                struct Node *temp = first; 
                delete temp; 
                first = first->next; } 
                cout<<"\n\t\tALL contacts has been deleted "<<endl; 
            
} }

void suggestions () { 
    struct Node *search_node = first; 
    string srch; 
    cout<<"Enter string you want to search "; 
    cin>>srch; bool found = false; 
    if(first == NULL) { 
        cout<<"Contact list is Empty "<<endl; } 
        else { while (search_node != NULL) { 
            if(search_node->name.find(srch,0) == 0 ) { 
                cout<<"\n\t\tName: "<<search_node->name<<endl; 
                cout<<"\t\tPhone number: "<<search_node->contact<<endl; 
                found =true; } search_node = search_node->next; } } 
                if(found == false) { cout<<"Not found "<<endl; 
                }
}

void choice(){
    cout<<"Enter 1 to add a contact"<<endl;
    cout<<"Enter 2 to display all the contacts"<<endl;
    cout<<"Enter 3 for search by name and find position"<<endl;
    cout<<"Enter 4 for search by contact and find position"<<endl;
    cout<<"Enter 5 to delete the contact"<<endl;
    cout<<"Enter 6 to empty the phone book"<<endl;
    cout<<"Enter 7 to search by suggestions"<<endl;
}


void search(struct Node *p,string key){ 
    while(p){
        if(p->name==key);
    }
}
int main(){
    int n;          //for choice

    while(true){
        choice();
        cin>>n;
        switch(n){
            case 1:
            insert_sorted(first);
            break;
            case 2:
            display(first);
            break;
            case 3:
            search(first);
            break;
            case 4:
            search(first);
            break;
            case 5:
            delete_(first);
            break;
            case 6:
            clear_all(first);
            break;
            case 7:
            suggestions();
            break;
            default:
            cout<<"Invalid choice"<<endl;
        }
    }

}