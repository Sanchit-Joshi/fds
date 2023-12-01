#include<iostream>
#include<string>5
using namespace std;

class JobQueue{
    private:
    string* queue;
    int front , rear , size , capacity;

    public:
    JobQueue(int capacity){
        this->capacity = capacity;
        front = 0;
        rear = -1;
        size = 0;

    }

    ~JobQueue(){
        delete [] queue;
    }

    bool isempty(){ return size == 0; }

    bool isfull(){ return size == capacity;}

    void enqueue(string job){
        if (isfull()){
            cout<<"Queue is full, cannot add more jobs!\n";
        }
        else{
            rear = (rear+1)%capacity;
            queue[rear]=job;
            size++;

            cout<<" Job "<<job<<" added to the queue\n";
        }
    }

    void dequeue(){
        if (isempty()){ cout<<"Queue empty!\n";}
        else{
            string deletedJob = queue[front];
            front = (front+1)%capacity;
            size--;

            cout<<"Job "<<deletedJob<<" deleted from the queue.\n";
        }
    }

    void display(){
        if(isempty()){ cout<<"Queue is empty, nothing to display\n";}
        else{
            cout<<"Job queue:  ";
            int count = 0;
            int index = front;
            while(count<size){
                cout<<queue[index]<<"  |  ";
                index = (index+1)%capacity;
                count++;
            }
        }
    }
    };


int main() {
    int capacity;
    std::cout << "Enter the capacity of the job queue: ";
    std::cin >> capacity;

    JobQueue jobQueue(capacity);

    int choice;
    string job;
    while (true) {
        std::cout << "1. Add job" << std::endl;
        std::cout << "2. Delete job" << std::endl;
        std::cout << "3. Display job queue" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the job to add: ";
                cin>>ws;
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
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
