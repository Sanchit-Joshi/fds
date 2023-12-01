#include <iostream>
#include <string>
using namespace std;

class JobQueue {
private:
    std::string* queue;
    int front;
    int rear;
    int capacity;
    int size;

public:
    JobQueue(int capacity) {
        this->capacity = capacity;
        queue = new std::string[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~JobQueue() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(const std::string& job) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot add job." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = job;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No job to delete." << std::endl;
            return;
        }

        std::string deletedJob = queue[front];
        front = (front + 1) % capacity;
        size--;

        std::cout << "Deleted job: " << deletedJob << std::endl;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Job Queue: ";
        int count = 0;
        int index = front;
        while (count < size) {
            std::cout << queue[index] << " , ";
            index = (index + 1) % capacity;
            count++;
        }
        std::cout << std::endl;
    }
};

int main() {
    int capacity;
    std::cout << "Enter the capacity of the job queue: ";
    std::cin >> capacity;

    JobQueue jobQueue(capacity);

    int choice;
    std::string job;
    while (true) {
        std::cout << "1. Add job" << std::endl;
        std::cout << "2. Delete job" << std::endl;
        std::cout << "3. Display job queue" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the job to add: ";
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
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
