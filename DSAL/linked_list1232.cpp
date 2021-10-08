#include <iostream>
using namespace std;
class node{
private:
	int info;
	node *next;
public:
	node(int val){
		next=NULL;
		info = val;
	}
	friend class LinkedList;
};
class LinkedList{
private:
	node *start;
	node * last;
public:
	LinkedList(){
		start=NULL;
		last=NULL;
	}
	void Display();
    void placesort();
	void InsertBeg();
	void InsertEnd();
	void InsertIbt();
	void DeleteFir();
	void DeleteLas();
	void DeleteInb();
	void InsertVal();
	node * ReturnAddress(int val);
	int Getvalue();
};
void LinkedList::Display(){
	if(start==NULL){
		cout<<"Nothing to Show\t List is empty"<<endl;
	}
	else{
	node *temp=start;
	while(temp != NULL){
		cout<<temp->info<<" ";
		temp=temp->next;
	}
	cout<<endl;
	}
}
int LinkedList::Getvalue(){
	int val;
	cout<<"Enter Value to be inserted"<<endl;
	cin>>val;
	return val;
}
node * LinkedList::ReturnAddress(int val){
	val = Getvalue();
	node *new1= new node(val);
	return new1;
}
void LinkedList::InsertBeg(){
	if(start==NULL){
		start= ReturnAddress(0);
		last=start;
	}
	else{
		node *temp=ReturnAddress(0);
		temp->next=start;
		start=temp;
	}
}
void LinkedList::InsertEnd(){
		if(start==NULL){
			InsertBeg();
		}
		else{
			node *temp=start;
			while(temp->next != NULL){
				temp=temp->next;
			}
			temp->next=ReturnAddress(0);
			last=temp->next;
		}
}
void LinkedList::InsertIbt(){
    // y wrong answer when we insert on location 1
	if(start==NULL){
		cout<<"since no element Node inserted at starting"<<endl;
		InsertBeg();
	}
	else{
		int index;
		cout<<"Enter the Index where to insert Node : ";
		cin>>index;
		index=index-2;
		node*temp=start;
		while((temp->next != NULL) && (index--)){
			temp=temp->next;
		}
		if(temp->next == NULL){
			InsertEnd();
		}
		else{
			node *A =ReturnAddress(0);
			A->next=temp->next;
			temp->next=A;
		}
	}
}
void LinkedList::DeleteFir(){
    if(start==NULL){
        cout<<"list is empty"<<endl;
    }
    else{
        node * temp=start;
        start=start->next;
        delete(temp);
    }
}
void LinkedList::DeleteLas(){
    if(start==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        node *temp=start;
        while(temp->next->next !=NULL){
            temp=temp->next;
        }
        delete(temp->next->next);
        temp->next=NULL;
        last=temp;
    }
}
void LinkedList::DeleteInb(){
    int position;
    cout<<"Enter From which position to Delete"<<endl;
    cin>>position;
    position=position-2;
    node *temp=start;
    while( position-- ){
        temp=temp->next;
    }
    if(temp->next->next== NULL){
        DeleteLas();
    }
    else{
   temp->next=temp->next->next;
    }
}
void LinkedList::placesort(){
    int element;
    cout<<"Enter element to be inserted  : ";
    cin>>element;
    node* temp=start;
    if(temp==NULL || start->info > element){
        cout<<"\nHey Plz enter the element again"<<endl;
        InsertBeg();
    }
    else{
       // node* counter=NULL;
       node* prev =NULL;
	   node* current =start;
	  
	   while( element > current->info &&  current != NULL){
		   prev=current;
		   current=current->next;
	   }
	   cout<<"enter the value again "<<endl;
	   node* new1= ReturnAddress(0);
	   new1->next=current;
	   prev->next=new1;
        }
    }

int main() {
	LinkedList l;
	while(true){
	cout << "1 -> Display Link List\n2-> Insert at beginning\n3->Insert at End";
	cout<<"\n4->Insert In between\n5->Delete First Node\n6->Delete Last";
	cout<<"\n7->Delete Node inbtw\n8->Place sorted element in between"<<endl;
	int optn;
	cin>>optn;
	switch(optn){
	case 1:
		l.Display();
		break;
	case 2:
		l.InsertBeg();
		break;
	case 3:
		l.InsertEnd();
		break;
	case 4 :
		l.InsertIbt();
		break;
	case 5:
		l.DeleteFir();
		break;
    case 6:
        l.DeleteLas();
         break;
    case 7:
        l.DeleteInb();
        break;
    case 8:
        l.placesort();
	}
	}
	return 0;
}
