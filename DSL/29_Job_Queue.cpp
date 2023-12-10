#include<iostream>
#include<string>
using namespace std;

class Queue{
    private:
    string* queue;
    int front , rear , capacity , size;

    public:
    Queue(int capacity){
        this->capacity = capacity;
        size = 0;
        front =0;
        rear = -1;
        queue = new string[capacity];
    }    

    ~Queue(){
        delete[] queue;
    }

    bool isempty(){
        return size==0;
    }
    bool isfull(){
        return size==capacity;
    }

    void enqueue(string data){
        if(isfull())
            cout<<"\n Queue is full.\n Cannot add more job.";
        else{
            
            rear = (rear+1)%capacity;
            queue[rear]=data;
            size ++;
            cout<<"\nJob added";
        }
    }
    string dequeue(){
        if(isempty()) 
            cout<<"\n Queue empty";
        else{
            string job = queue[front];
            front = (front+1)%capacity;
            size--;
            cout<<"\n Job: "<<job<<" deleted from queue.";
        }
    }

    void display(){
        if(isempty())
        cout<<"\n Queue is empty.\n Nothing to display";
        else{
        for(int i =0; i<size;i++){
            cout<<front+1<<". "<<queue[front]<<endl;
        }
        }
    }
};

int main(){
    int capacity;
    cout << "Enter the capacity of the job queue: ";
    cin >> capacity;

    Queue jobQueue(capacity);

    int choice;
    string job;
    while (true) {
        cout << "\n 1. Add job\n 2.Delete job\n 3.Display Job Queue\n 4.Exit";
        cout << "\n\nsEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the job to be added: ";
                cin.ignore();
                getline(cin,job);
                jobQueue.enqueue(job);
                break;
            case 2:
                jobQueue.dequeue();
                break;
            case 3:
                jobQueue.display();
                break;
            case 4:
                cout<<"\nExiting...";
                exit(0);
            default:
                cout << "Invalid choice. Please try again." <<endl;
        }
    }

    return 0;
}


