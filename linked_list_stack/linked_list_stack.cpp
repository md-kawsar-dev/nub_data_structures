#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Stack{
    private:
        Node* top;
    public:
        Stack(){
            top = nullptr;
        }
    void push(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout<<value<<" pushed to stack\n";
    }
    void pop()
    {
        if(isEmpty()){
            cout<<"Stack is Empty.\n";
        }
        Node* temp = top;
        top = top->next;
        cout<<temp->data<<" popped from stack.\n";
        delete temp;

    }
    bool isEmpty()
    {
        return top == nullptr;
    }
     // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout<<"After Pop"<<endl;
    s.pop();
    s.display();

    return 0;
}
