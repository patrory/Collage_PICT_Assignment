#include<bits/stdc++.h>
using namespace std;
struct data{
    string name;
    int roll;
};
class se{
    public:
    int front ,rear ,n;

data* a;
se(int n1){
    n=n1;
    front = rear =-1;
    a= new data[n];
}
    int isempty();
    void enqueue();
    int isfull();
    void dequeue();
    void display();
};
int se::isempty(){
    if(front ==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int se::isfull(){
     if(front == 0 && rear == n - 1)
        {
            return 1;
        }
        if(front == rear + 1) 
        {
            return 1;
        }
        return 0;
}
void se::enqueue(){
    if( isfull()){
        cout<<"queue is full"<<endl;
    }
    else{
        if(front ==-1){
            front =0;
        }
        rear = (rear + 1) % n; 
        cout<<"name and roll"<<endl;
        cin>>a[rear].name>>a[rear].roll;
        cout<<"data inseted"<<endl;
    }
}
void se::dequeue(){
    if(isempty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<  a[front].name << " " << a[front].roll << endl;
         if(front == rear)  {    
            front = -1;
            rear = -1;
        }
        else 
        {
            front = (front+1) % n;
        }
    }
}
void se::display(){
    cout<<"displaying data"<<endl;
    for(int i= front ;i != (rear)  ; i= ((i+1)%n)){
        cout<<  a[i].name << " " << a[i].roll << endl;
    }
    cout<<  a[rear].name << " " << a[rear].roll << endl;
}
int main(){
cout<<"enter the no of student "<<endl;
int n1;
cin>>n1;
se p(n1);
while(1){
    int ops;
    cout<<"1 for adding\n2 for deletion\n3 for displaying"<<endl;
    cin>>ops;
    switch(ops){
        case 1:
        p.enqueue();
        break;
        case 2:
        p.dequeue();
        break;
        case 3:
        p.display();
        break;
        default :
        exit(0);
    }
}
return 0 ;
}