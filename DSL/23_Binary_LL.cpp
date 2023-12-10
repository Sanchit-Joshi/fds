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

    DLL* copy(){
        DLL*copy = new DLL;
        Node* temp = head;  
        while(temp!=NULL){
            copy->insert(temp->data);
            temp=temp->next;
        }
        return copy;
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

DLL* add(DLL* num1, DLL* num2) {
    DLL* result = new DLL;
    Node* node1 = num1->tail;
    Node* node2 = num2->tail;

    int carry = 0;
    while (node1 != NULL || node2 != NULL || carry != 0) {
        int value1 = (node1 != NULL) ? node1->data : 0;
        int value2 = (node2 != NULL) ? node2->data : 0;

        int sum = value1 + value2 + carry;
        result->insert(sum % 2);
        carry = sum / 2;

        if (node1 != NULL) node1 = node1->prev;
        if (node2 != NULL) node2 = node2->prev;
    }

    return result;
}

void reverse() { //sliding pointers logic
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        temp->next = temp->prev;
        temp->prev = next;

        temp = next;
    }

    temp = head;
    head = tail;
    tail = temp;
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
 DLL num1, num2;
    string binary1, binary2;

    cout << "Enter the first binary number: ";
    cin >> binary1;
    for (char bit : binary1) {
        num1.insert(bit - '0'); 
    }
    DLL* num1Copy = num1.copy();
    cout << "Enter the second binary number: ";
    cin >> binary2;
    for (char bit : binary2) {
        num2.insert(bit - '0'); 
    }
    DLL* num2Copy = num2.copy();

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
                
                num1Copy->ones_comp();
                num1Copy->display();
                cout<<"\n1's complement of second number: ";
                
                num2Copy->ones_comp();
                num2Copy->display();
                break;
        case 3: cout<<"2's complement of first number: ";
                
                num1Copy->twos_comp();
                num1Copy->display();
                cout<<"\n2's complement of second number: ";
               
                num2Copy->twos_comp();
                num2Copy->display();
                break;
        case 4: cout<<"Addition of two numbers: ";
                result = num1.add(&num1,&num2);
                result->reverse();
                result->display();
                break;
        case 5: exit(0);
                break;
        default: cout<<"Invalid choice";
    }
    }

}