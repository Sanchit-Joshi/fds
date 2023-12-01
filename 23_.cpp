#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DLL{

    private:
    Node* head;
    Node* tail;

    public:
    DLL(){
        head = NULL;
        tail = NULL;
    }

    void insert(int data){
        Node * newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;

        if(head == NULL){
            newnode->prev=NULL;
            head=newnode;
            tail=newnode;
        }
        else{
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }

    void ones_comp(){
        Node* temp = head;
        while(temp!=NULL){
            temp->data = !temp->data;
            temp=temp->next;
        }
    }

    void twos_comp(){
        Node* temp = tail;
        while(temp!=NULL){
            if(temp->data==0){
                temp->data=1;
                break;
            }
            else{
                temp->data=0;
                temp=temp->prev;
            }
        }
    }

    DLL* add(DLL* num1, DLL* num2){
        DLL* result = new DLL;
        Node* temp1 = num1->tail;
        Node* temp2 = num2->tail;


        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1 != NULL){
                sum+= temp1->data;
                temp1=temp1->prev;
            }
            if(temp2!=NULL){
                sum+= temp2->data;
                temp2=temp2->prev;
            }

            result->insert(sum%2);
            carry = sum/2;
        }

        if(carry!=0){
            result->insert(carry);     
        }
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;

        }
    }
};

int main(){
    DLL num1;
    int n1;
    cout<<"Enter first binary number: ";
    cin>>n1;
    while(n1!=0){
        num1.insert(n1%10);
        n1/=10;
    }

    DLL num2;
    int n2;
    cout<<"Enter second binary number: ";
    cin>>n2;
    while(n2!=0){
        num2.insert(n2%10);
        n2/=10;
    }

    int ch;
    DLL* result = nullptr;
    while(true){
    cout<<"\n\n 1. Display numbers\n 2. 1's complement\n 3. 2's complement\n 4. Add\n 5. Exit\n\n Enter your choice: ";
    
    cin>>ch;
    switch(ch){
        case 1: cout<<"First number: ";
                num1.display();
                cout<<"\nSecond number: ";
                num2.display();
                break;
        case 2: cout<<"1's complement of first number: ";
                num1.ones_comp();
                num1.display();
                cout<<"\n1's complement of second number: ";
                num2.ones_comp();
                num2.display();
                break;
        case 3: cout<<"2's complement of first number: ";
                num1.twos_comp();
                num1.display();
                cout<<"\n2's complement of second number: ";
                num2.twos_comp();
                num2.display();
                break;
        case 4: cout<<"Addition of two numbers: ";
                result = num1.add(&num1,&num2);
                result->display();
                break;
        case 5: exit(0);
                break;
        default: cout<<"Invalid choice";
    }
    }

}