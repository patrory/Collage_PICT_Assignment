
#include <iostream>
#include <string>
using namespace std;
struct data
{
    string name;
    int roll_no;
};
class p
{
    //private :
    data *q;

public:
    int front, rear, n;
    p(int n1)
    {
        n = n1;
        q = new data[n];
        front = rear = -1;
    }

    int isempty();
    void enqueue();
    int isfull();
    void dequeue();
    void display();
};
int p::isempty()
{
    if (front > rear || (front == -1))
    {
        return 1;
    }
    return 0;
}
int p::isfull()
{
    if (rear < n && front <= rear)
    {
        return 0;
    }
    return 1;
}
void p::enqueue()
{
    rear++;
    if (front == -1)
    {
        front = 0;
    }
    if (isfull())
    {
        cout << "data overflow" << endl;
        return;
    }
    else
    {
        cin >> q[rear].name >> q[rear].roll_no;
        cout << endl;
    }
}
void p::dequeue()
{
    if (isempty())
    {
        cout << "data underflow" << endl;
    }
    else
    {
        cout << q[front].name << " " << q[front].roll_no << endl;
        front++;
    }
}
void p::display()
{
    cout << "displaying value" << endl;
    if (isempty())
    {
        cout << "Emty Queue" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << q[i].name << " " << q[i].roll_no << endl;
        }
    }
}
int main()
{
    cout << "Enter the no of student" << endl;
    int n1;
    cin >> n1;
    p a(n1);
    while (1)
    {   cout<<"enter opertion"<<endl;
        int ops;
        cin >> ops;
        switch (ops)
        {
        case 1:
            a.enqueue();
            break;
        case 2:
            a.dequeue();
            break;
        case 3:
            a.display();
            break;
        }
    }

    return 0;
}