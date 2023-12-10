#include<iostream>
#include<string>
using namespace std;

class CircularQueue{
    private:
        int front, rear , size , *queue;

    public:
        CircularQueue(int size){ //paramterized constructor
            front = rear = -1;
            this->size= size;
            queue = new int[size];
        }

        ~CircularQueue(){ //destructor
            delete[] queue;
        }

        bool isempty(){ 
            return front ==-1 && rear==-1;
            }  //check if queue is empty
        bool isfull(){
             return rear == size-1;
             }      //check if queue is full

        void enqueue(int data){
            if(isfull())
                cout<<"\n Queue is full\n Cannot take more orders!";
            else{
                if(front==-1)
                    front =0;
                rear = (rear+1)%size;
                queue[rear]=data;

                cout<<"\n Order "<<data<<" taken successfully!";
            }
        }//enqueue ends

        void dequeue(){
            if(isempty()) 
                {cout<<"\n Queue is empty\n No more orders to serve.";}
            else{
                int served = queue[front];
                if(front ==rear){
                     front = rear= -1;
                      }
                else {
                    front = (front+1)%size;
                     }
                
                cout<<"\nOrder number "<<served<<" served.";

            }
        }//dequeue ends
};//class ends

int main(){
    cout<<"\n---Welcome to the Pizza Parlour---\n\n";
    cout<<"\n Enter the maximum number of orders M which pizza parlour can accept: ";
    int M;
    cin>>M;
    CircularQueue pizza(M);
    int choice;
    int order;
    while(true){
        cout<<"\n 1.Take order\n 2.Serve Order\n 3.Exit\n\n  Enter you choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\n Enter order number: ";
                    cin>>order;
                    pizza.enqueue(order);
                    break;
            case 2: pizza.dequeue();
                    break;
            case 3: exit(0);
                    break;
            default: cout<<"\nInvalid choice,\n Enter your choice properly. ";
                    break;
        }//switch case
    }//while loo[]
    return 0;
}