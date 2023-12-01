/*Pizza parlor accepting maximum M orders. 
Orders are served in first come first served basis. Order once placed can not be cancelled. 
Write C++ program to simulate the system using circular queue using array.
*/

#include<iostream>

using namespace std;

class CircularQueue{
    int front, rear, maxsize;
    int *queue;

    public:
        CircularQueue(int size){
            front = rear = -1;
            maxsize = size;
            queue = new int[size];
        }

        ~CircularQueue(){
            delete[] queue;
        }

        bool isempty(){
            return front==rear==-1;
        }

        bool isfull(){
            return (front==0 && rear==maxsize-1) || (rear == front -1);
        }

        void enqueue(int order){
            if(isfull())
            cout<<"Queue is full cannout accept more orders\n";
            else{
                if(front==-1)
                front = 0;
                rear = (rear+1)%maxsize;

                queue[rear] = order;
                cout<<"Order "<<order<<" placed successfully\n";
            }
        }

        void dequeue(){
            if(isempty())
            cout<<"Queue is empty, no more orders to serve\n";
            else{
                int servedOrder = queue[front];
                if(front==rear)
                front = rear = -1;
                else
                front = (front+1)%maxsize;

                cout<<"Order "<<servedOrder<<" served\n";
            }
        }
};

int main(){
    int M;
    cout<<"Enter the maximum number of orders M the pizza parlor can accept: ";
    cin>>M;
    int ch,order;
    CircularQueue pizza(M);
    while(true){
        cout<<" 1.Place order\n 2.Serve order\n 3.Exit\n\n\nEnter choice";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter order number";
                    cin>>order;
                    pizza.enqueue(order);
                    break;
            case 2: pizza.dequeue(); break;
            case 3: exit(0); break;
            default: cout<<"Invalid choice\n Please try again";
        }
    }
    return 0;
}
