#include<iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    struct Node* next;
};

class PriorityQueue{
    private:
    Node* front;
    public:
    PriorityQueue(){
        front = NULL;
    }

    void insert(int data, int priority){
        Node* temp, *ptr;
        temp = new Node;
        temp->data = data;
        temp->priority = priority;
        if(front == NULL || priority < front->priority){
            temp->next = front;
            front = temp;
        }
        else{
            ptr = front;
            while(ptr->next!=NULL && ptr->next->priority <= priority)
                ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }

    void del(){
        Node * temp;
        if(front == NULL)
        cout<<"\nQueue underflow.";
        else{
            temp = front;
            cout<<"\nDeleted item is: "<<temp->data;
            front= front->next;
            free(temp);
        }
    }

    void show(){
        Node* ptr = front;
        if(front == NULL){
            cout<<"\n Queue empty.\n Nothing to show.";
        }
        else{
            cout<<"\nPriority\t Item"<<endl;
            while(ptr!=NULL){
                cout<<ptr->priority<<"\t"<<ptr->data<<endl;
                ptr=ptr->next;
            }
        }
    }
};

int main() {
   int choice, data, priority;
   PriorityQueue pq;
   while(true) //perform switch operation
   {
      cout<<"1.Insert\n";
      cout<<"2.Delete\n";
      cout<<"3.Display\n";
      cout<<"4.Exit\n";
      cout<<"Enter your choice : ";
      cin>>choice;
      switch(choice) {
         case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>data;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.insert(data, priority);
            break;
         case 2:
            pq.del();
            break;
         case 3:
            pq.show();
            break;
         case 4:exit(0);
            break;
         default:
            cout<<"Wrong choice\n";
            break;
      }
   }

   return 0;
}
