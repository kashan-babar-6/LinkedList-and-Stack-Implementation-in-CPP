#include<iostream>
#include<stdlib.h> //for clear screen functionality
#include<conio.h> //for getch functionality
#include<string>
using namespace std;
#define arraySize 5

/*---Declaring User-Define Functions---*/
void startUpMenu();
void stackMenu();
void nodesMainMenu();
void menuSinglyLinkedList();
void menuDoublyLinkedList();
void menuCirculyLinkedList();


/*---Class of Stack Data Structure---*/
class Stack {
    int stackArray[arraySize];
    int top;

    public:
        Stack();
        bool isEmpty();
        bool isFull();
        void push(int);
        void pop();
        void showTop();
        void displayStack();
};
Stack::Stack() {
    top= -1;
}
bool Stack::isEmpty() {
    if(top == -1) return true;
    return false;
}
bool Stack::isFull() {
    if(top == arraySize-1) return true;
    return false;
}
void Stack::push(int inValue) {
    if(isFull())
        cout<<"\n*Error: Stack Overflowed!"<<endl;
    else {
        top++;
        stackArray[top]= inValue;
    }   
}
void Stack::pop() {
    if(isEmpty())
        cout<<"\n*Error: Stack has no element to delete!"<<endl;
    else 
        top--;
}
void Stack::showTop() {
    if(isEmpty())
        cout<<"\n*Error: Stack is Empty!"<<endl;
    else 
        cout<<"\nThe top value of Stack is '"<<stackArray[top]<<"' at index "<<top<<endl;
}
void Stack::displayStack() {
    if(isEmpty())
        cout<<"\n\n*Error: Stack is Empty!"<<endl;
    else {
        cout<<"\nData in stack is: ";
        for(int i=0; i<=top; i++) {
            cout<<stackArray[i];
            if(i != top) {
                cout<<", ";
            }
        }
        cout<<"\n\nThere are "<<arraySize-1-top<<" slots left in stack"<<endl;
    }
}


/*---Creating Nodes of all types---*/
class SinglyNode {
    public:
        int data;
        SinglyNode *next;

        SinglyNode(int);
};
SinglyNode::SinglyNode(int inValue) {
    data= inValue;
    next= NULL;
}

class DoublyNode {
    public:
        int data;
        DoublyNode *next, *prev;

        DoublyNode(int);
};
DoublyNode::DoublyNode(int inValue) {
    data= inValue;
    next= NULL;
    prev= NULL;
}

class CirculyNode {
    public:
        int data;
        CirculyNode *next;

        CirculyNode(int);
};
CirculyNode::CirculyNode(int inValue) {
    data= inValue;
    next= NULL;
}

/*---Functions Class of Singly Linked List---*/
class SinglyFunction {
    public:
        SinglyNode* singlyInsertAtTail(SinglyNode* &, int);
        SinglyNode* singlyInsertAtHead(SinglyNode* &, int);
        SinglyNode* singlyInsertAtMid(SinglyNode* &, int, int);
        void singlyDeleteFromHead(SinglyNode* &);
        void singlyDeleteFromTail(SinglyNode* &);
        void singlyDeleteFromMid(SinglyNode* &, int);
        void singlysearch(SinglyNode* &, int);
        SinglyNode* singlyReverse(SinglyNode* &);
        void singlyDisplay(SinglyNode* &);
};
SinglyNode* SinglyFunction::singlyInsertAtTail(SinglyNode* &inNode, int inValue) {
    SinglyNode *newNode= new SinglyNode(inValue);

    if(inNode == NULL) {
        inNode= newNode;
        return newNode;
    }

    SinglyNode *tempNode= inNode;

    while(tempNode->next != NULL) {
        tempNode= tempNode->next;
    }
    newNode->next= tempNode->next;
    tempNode->next= newNode;
    return newNode;
}
SinglyNode* SinglyFunction::singlyInsertAtHead(SinglyNode* &inNode, int inValue) {
    SinglyNode *newNode= new SinglyNode(inValue);
    if(inNode == NULL) {
        inNode= newNode;
        return newNode;
    }
    newNode->next= inNode;
    inNode= newNode;
    return newNode;
}
SinglyNode* SinglyFunction::singlyInsertAtMid(SinglyNode* &inNode, int beforeValue, int invalue) {
    bool beforeValueFound= false;
    if(inNode == NULL) {
        cout<<"The list is empty"<<endl;
        return NULL;
    }
    SinglyNode *newNode= new SinglyNode(invalue);
    SinglyNode *tempNode= inNode;
    while(tempNode != NULL) {
        if(tempNode->data == beforeValue) {
            newNode->next= tempNode->next;
            tempNode->next= newNode;
            beforeValueFound= true;
            return newNode;
            break;
        }
        tempNode= tempNode->next;
    }
    if(!beforeValueFound) {
        cout<<"\n*Error: The before value did not found!"<<endl;
        return newNode;
    }
    return NULL;
}
void SinglyFunction::singlyDeleteFromHead(SinglyNode* &inNode) {
    if(inNode ==  NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    SinglyNode *toDelete= inNode;
    inNode= inNode->next;
    delete toDelete;
    return;
}
void SinglyFunction::singlyDeleteFromTail(SinglyNode* &inNode) {
    if(inNode ==  NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    SinglyNode *tempNode= inNode;
    if(tempNode->next == NULL) {
        delete tempNode;
        inNode= NULL;
        return;
    }
    while(tempNode->next->next != NULL) {
        tempNode= tempNode->next;
    }
    SinglyNode *toDelete= tempNode->next;
    tempNode->next= NULL;
    delete toDelete;
    return;
}
void SinglyFunction::singlyDeleteFromMid(SinglyNode* &inNode, int delValue) {
    bool delValueFound= false;
    if(inNode ==  NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    SinglyNode *tempNode= inNode;
    if(tempNode->data == delValue) {
        inNode= tempNode->next;
        delValueFound= true;
        delete tempNode;
        return;
    }
    while(tempNode != NULL) {
        if(tempNode->next->data == delValue) {
            SinglyNode *toDelete= tempNode->next;
            tempNode->next= toDelete->next;
            delValueFound= true;
            delete toDelete;
            break;
        }
        tempNode= tempNode->next;
    }


    if(!delValueFound) {
        cout<<"\n*Error: The before value did not found!"<<endl;
        return;
    }
    return;
}
void SinglyFunction::singlysearch(SinglyNode* &inNode, int searchVal) {
    bool searchFound= false;
    int nodeTracker=0;
    SinglyNode *tempNode= inNode;
    if(tempNode == NULL) {
        cout<<"\nThe list is empty";
        return;
    }
    while(tempNode != NULL) {
        nodeTracker++;
        if(tempNode->data == searchVal) {
            searchFound= true;
            cout<<"\nThe value '"<<tempNode->data<<"' found at node number '"<<nodeTracker<<"'";
        }
        tempNode= tempNode->next;
    }
    if(!searchFound) {
        cout<<"\n*Error: The value did not found in the list!";
        return;
    }
    return;
}
void SinglyFunction::singlyDisplay(SinglyNode* &inNode) {
    if(inNode == NULL) {
        cout<<"NULL"<<endl;
        return;
    }
    SinglyNode *tempNode= inNode;
    while(tempNode != NULL) {
        cout<<tempNode->data<<" -> ";
        tempNode= tempNode->next;
    }
    cout<<"NULL";
    return;
}
SinglyNode* SinglyFunction::singlyReverse(SinglyNode* &inNode) {
    SinglyNode *prevNode= NULL;
    SinglyNode *currentNode= inNode;
    SinglyNode *nextNode;

    while(currentNode != NULL) {
        nextNode= currentNode->next;
        currentNode->next= prevNode;


        prevNode= currentNode;
        currentNode= nextNode;
    }
    inNode= prevNode;
    return inNode;
}

/*---Functions Class of Doubly Linked List---*/
class DoublyFunction {
    public:
        DoublyNode *head, *tail;

        DoublyFunction();
        DoublyNode* doublyInsertAtTail(int);
        DoublyNode* doublyInsertAtHead(int);
        DoublyNode* doublyInsertAtMid(int, int);
        void doublyDeleteFromHead();
        void doublyDeleteFromTail();
        void doublyDeleteFromMid(int);
        void doublySearch(int);
        DoublyNode* doublyReverse();
        void doublyDisplay();
};
DoublyFunction::DoublyFunction() {
    head= NULL;
    tail= NULL;
}
DoublyNode* DoublyFunction::doublyInsertAtTail(int inValue) {
    DoublyNode *newNode= new DoublyNode(inValue);
    if(head == NULL) {
        head= newNode;
        tail= newNode;
        return newNode;
    }
    newNode->next= tail->next;
    tail->next= newNode;
    newNode->prev= tail;
    tail= newNode;
    return newNode;
}
DoublyNode* DoublyFunction::doublyInsertAtHead(int inValue) {
    DoublyNode *newNode= new DoublyNode(inValue);
    if(head == NULL) {
        head= newNode;
        tail= newNode;
        return newNode;
    }
    newNode->next= head;
    newNode->prev= head;
    head->prev= newNode;
    head= newNode;
    return newNode;
}
DoublyNode* DoublyFunction::doublyInsertAtMid(int beforevalue, int inValue) {
    DoublyNode *newNode= new DoublyNode(inValue);
    if(head == NULL) {
        cout<<"\nThe list is empty";
        return newNode;
    }
    DoublyNode *tempNode= head;
    bool searchFound= false;
    while(tempNode != NULL) {
        if(tempNode->data == beforevalue) {
            newNode->next= tempNode->next;
            tempNode->next= newNode;
            newNode->prev= tempNode;
            searchFound= true;
            break;
        }
        tempNode= tempNode->next;
    }
    if(!searchFound) {
        cout<<"\n*Error: Before value did not found in the list"<<endl;
        return newNode;
    }
    return newNode;
}
void DoublyFunction::doublyDeleteFromHead() {
    if(head == NULL) {
        cout<<"\nThe list is empty";
        return;
    }
    DoublyNode *toDelete= head;
    if(head->next == NULL) {
        head= NULL;
        tail= NULL;
        delete toDelete;
        return;
    }
    head= head->next;
    head->prev= NULL;
    delete toDelete;
    return;
}
void DoublyFunction::doublyDeleteFromTail() {
    if(head ==  NULL) {
        cout<<"\nThe list is empty";
        return;
    }
    DoublyNode *toDelete= tail;
    if(head->next == NULL) {
        tail= NULL;
        head= NULL;
        delete toDelete;
        return;
    }
    tail= tail->prev;
    tail->next= toDelete->next;
    delete toDelete;
    return;
}
void DoublyFunction::doublyDeleteFromMid(int delValue) {
    bool delValueFound= false;
    if(head == NULL) {
        cout<<"\nThe list is empty";
        return;
    }
    DoublyNode *tempNode= head;
    while(tempNode != NULL) {
        if(tempNode->data == delValue) {
            DoublyNode *toDelete= tempNode;
            tempNode= tempNode->prev;
            tempNode->next= toDelete->next;
            toDelete->next->prev= tempNode;
            delete toDelete;
            delValueFound= true;
            break;
        }
        tempNode= tempNode->next;
    }
    if(!delValueFound) {
        cout<<"\n*Error: The delete value did not found";
        return;
    }
    return;
}
void DoublyFunction::doublySearch(int searchVal) {
    bool searchFound= false;
    int nodeTracker=0;
    DoublyNode *tempNode= head;
    if(tempNode == NULL) {
        cout<<"\nThe list is empty";
        return;
    }
    while(tempNode != NULL) {
        nodeTracker++;
        if(tempNode->data == searchVal) {
            searchFound= true;
            cout<<"\nThe value '"<<tempNode->data<<"' found at node number '"<<nodeTracker<<"'";
        }
        tempNode= tempNode->next;
    }
    if(!searchFound) {
        cout<<"\n*Error: The value did not found in the list!";
        return;
    }
    return;
}
void DoublyFunction::doublyDisplay() {
    if(head ==  NULL) {
        cout<<"NULL";
        return;
    }
    DoublyNode *tempNode= head;
    while(tempNode != NULL) {
        cout<<tempNode->data<<" <-> ";
        tempNode= tempNode->next;
    }
    cout<<"NULL";
    return;
}
DoublyNode* DoublyFunction::doublyReverse() {
    DoublyNode *currentNode= head;
    DoublyNode *nextNode= currentNode->next;

    currentNode->next= NULL;
    currentNode->prev= nextNode;
    while(nextNode != NULL) {
        nextNode->prev= nextNode->next;
        nextNode->next= currentNode;
        currentNode= nextNode;
        nextNode= nextNode->prev;
    }
    head= currentNode;
    return head; 
}

/*---Functions Class of Circuly Linked List---*/
class CirculyFunction {
    public:
        CirculyNode *head, *tail;
        CirculyFunction();
        CirculyNode* circulyInsertAtTail(int);
        CirculyNode* circulyInsertAtHead(int);
        CirculyNode* circulyInsertAtMid(int, int);
        void circulyDeleteFromHead();
        void circulyDeleteFromTail();
        void circulyDeleteFromMid(int);
        void circulysearch(int);
        CirculyNode* circulyReverse();
        void circulyDisplay();
};
CirculyFunction::CirculyFunction() {
    head= NULL;
    tail= NULL;
}
CirculyNode* CirculyFunction::circulyInsertAtTail(int inValue) {
    CirculyNode *newNode= new CirculyNode(inValue);

    if(head == NULL) {
        head= newNode;
        tail= newNode;
        newNode->next= head;
        return newNode;
    }

    tail->next= newNode;
    newNode->next= head;
    tail= tail->next;
    return newNode;
}
CirculyNode* CirculyFunction::circulyInsertAtHead(int inValue) {
    CirculyNode *newNode= new CirculyNode(inValue);
    CirculyNode *tempNode= head;
    if(head == NULL) {
        head= newNode;
        newNode->next= head;
        return newNode;
    }

    newNode->next= tempNode;
    while(tempNode->next != head) {
        tempNode= tempNode->next;
    }
    head= newNode;
    tempNode->next= newNode;
    return newNode;
}
CirculyNode* CirculyFunction::circulyInsertAtMid(int beforeValue, int inValue) {
    bool beforeValueFound= false;
    if(head == NULL) {
        cout<<"The list is empty"<<endl;
        return NULL;
    }
    CirculyNode *newNode= new CirculyNode(inValue);
    CirculyNode *tempNode= head;
    while(tempNode->next != head) {
        if(tempNode->data == beforeValue) {
            newNode->next= tempNode->next;
            tempNode->next= newNode;
            beforeValueFound= true;
            return newNode;
            break;
        }
        tempNode= tempNode->next;
    }
    if(!beforeValueFound) {
        if(tempNode->data == beforeValue) {
            newNode->next= tempNode->next;
            tempNode->next= newNode;
            tail= newNode;
            beforeValueFound= true;
            return newNode;
        }
    }
    if(!beforeValueFound) {
        cout<<"\n*Error: The before value did not found!"<<endl;
        delete newNode;
        return NULL;
    }
    return NULL;
}
void CirculyFunction::circulyDeleteFromHead() {
    if(head ==  NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    CirculyNode *toDelete= head;
    head= head->next;
    tail->next= head;
    delete toDelete;
    return;
}
void CirculyFunction::circulyDeleteFromTail() {
    if(head ==  NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    CirculyNode *tempNode= head;
    if(tempNode->next == tempNode) {
        delete tempNode;
        head= NULL;
        tail= NULL;
        return;
    }
    while(tempNode->next->next != head) {
        tempNode= tempNode->next;
    }
    CirculyNode *toDelete= tempNode->next;
    tempNode->next= head;
    tail= tempNode;
    delete toDelete;
    return;
}
void CirculyFunction::circulyDeleteFromMid(int delValue) {
    bool delValueFound= false;
    if(head ==  NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    CirculyNode *tempNode= head;
    CirculyNode *toDelete;
    if(tempNode->data == delValue) {
        head= tempNode->next;
        tail->next= head;
        if(tempNode->next == NULL) {
            tail= NULL;
            head= NULL;
        }
        delValueFound= true;
        delete tempNode;
        return;
    }
    while(tempNode->next->data != delValue) {
        tempNode= tempNode->next;
        if(tempNode == tail->next) {
            break;
        }
    }
    if(tempNode->next->data == delValue) {
            toDelete= tempNode->next;
            tempNode->next= toDelete->next;
            if(toDelete->next == head) {
                tail= tempNode;
            }
            delete toDelete;
            delValueFound= true;
            return;
        }
    if(!delValueFound) {
        cout<<"\n*Error: The before value did not found!"<<endl;
        return;
    }
    return;
}
void CirculyFunction::circulysearch(int searchVal) {
    bool searchFound= false;
    int nodeTracker=0;
    CirculyNode *tempNode= head;
    if(tempNode == NULL) {
        cout<<"\nThe list is empty";
        return;
    }
    while(tempNode->next != head) {
        nodeTracker++;
        if(tempNode->data == searchVal) {
            searchFound= true;
            cout<<"\nThe value '"<<tempNode->data<<"' found at node number '"<<nodeTracker<<"'";
        }
        tempNode= tempNode->next;
    }
    if(tempNode->data == searchVal) {
        nodeTracker++;
        searchFound= true;
        cout<<"\nThe value '"<<tempNode->data<<"' found at node number '"<<nodeTracker<<"'";
    }
    if(!searchFound) {
        cout<<"\n*Error: The value did not found in the list!";
        return;
    }
    return;
}
CirculyNode* CirculyFunction::circulyReverse() {
    CirculyNode *prevNode;
    CirculyNode *currentNode;
    CirculyNode *nextNode;

    tail= head;
    prevNode= head;
    currentNode= head->next;
    head= head->next;

    while(head != tail) {
        head= head->next;
        currentNode->next= prevNode;

        prevNode= currentNode;
        currentNode= head;
    }
    currentNode->next= prevNode;
    head= prevNode;
    return head;
}
void CirculyFunction::circulyDisplay() {
    if(head == NULL) {
        cout<<"NULL"<<endl;
        return;
    }
    CirculyNode *tempNode= head;
    while(tempNode->next != head) {
        cout<<tempNode->data<<" -> ";
        tempNode= tempNode->next;
    }
    cout<<tempNode->data<<" -> Head";
    return;
}


int main() {

    startUpMenu();

}

void startUpMenu() {
    
    int startMenuChoice=0;
    bool startmenuChoiceError= false;

    while(true) {
        system("CLS");
        cout<<"---Choose your Data Structure---"<<endl<<endl;

        cout<<"Enter '1' to choose Linked List"<<endl
            <<"Enter '2' to choose Stack"<<endl
            <<"Enter '3' to exit"<<endl;

        if(startmenuChoiceError) {
            cout<<"\n*Error: Invald Choice Command!"<<endl;
        }

        cout<<"\nEner your choice command: ";
        cin>>startMenuChoice;

        if(startMenuChoice == 1) {
            nodesMainMenu();
        }
        else if(startMenuChoice == 2) {
            stackMenu();
        }
        else if(startMenuChoice == 3) {
            cout<<"\nProgram Exit Sucessfully!"<<endl;
            break;
        }
        else {
            startmenuChoiceError= true;
        }
    }

}

void stackMenu() {

    int stackMenuChoice=0;
    bool stackMenuChoiceError= false;
    Stack stackOne;

    while(true) {
        system("CLS");
        cout<<"---Stack Operations---"<<endl<<endl;
        cout<<"*Stack has "<<arraySize<<" slots"<<endl<<endl;

        cout<<"Enter '1' to push data in Stack"<<endl
            <<"Enter '2' to pop data from Stack"<<endl
            <<"Enter '3' to see the top value of Stack"<<endl
            <<"Enter '4' to display Stack"<<endl
            <<"Enter '5' to go back"<<endl<<endl;

        if(stackMenuChoiceError)
            cout<<"*Error: Invalid Choice Command!"<<endl<<endl;

        cout<<"Enter your choice command: ";
        cin>>stackMenuChoice;

        if(stackMenuChoice == 1) {
            int stackValue=0;
            cout<<"\n\tEnter the numeric value you want to add in stack: ";
            cin>>stackValue;
            stackOne.push(stackValue);
            stackOne.displayStack();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(stackMenuChoice == 2) {
            stackOne.pop();
            stackOne.displayStack();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(stackMenuChoice == 3) {
            stackOne.showTop();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(stackMenuChoice == 4) {
            stackOne.displayStack();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(stackMenuChoice == 5) {
            break;
        }
        else {
            stackMenuChoiceError= true;
        }
    }

}

void nodesMainMenu() {

    int nodesMenuChoice=0;
    bool nodesMenuChoiceError= false;

    while(true) {
        system("CLS");
        cout<<"---Basic Node Operations---"<<endl<<endl;

        cout<<"Enter '1' for Singly Linked List"<<endl
            <<"Enter '2' for Doubly Linked List"<<endl
            <<"Enter '3' for Circular Linked List"<<endl
            <<"Enter '4' to go back"<<endl<<endl;

        if(nodesMenuChoiceError == true) {
            cout<<"*Error: Invalid Choice Command!"<<endl<<endl;
        }

        cout<<"Enter your choice command: ";
        cin>>nodesMenuChoice;

        if(nodesMenuChoice == 1) {
            menuSinglyLinkedList();
        }
        else if(nodesMenuChoice == 2){
            menuDoublyLinkedList();
        }
        else if(nodesMenuChoice == 3) {
            menuCirculyLinkedList();
        }
        else if(nodesMenuChoice == 4) {
            break;
        }
        else {
            nodesMenuChoiceError= true;
        }
    }
}

void menuSinglyLinkedList() {
    
    int singlyMenuChoice=0;
    bool singlyMenuChoiceError= false, insertDatainListError= false;
    SinglyNode *singlyHead= NULL;
    SinglyFunction singleList;

    while(true) {
        system("CLS");
        cout<<"---Basic Node Operations for Singly Linked List---"<<endl<<endl;

        cout<<"Enter '1' to create Singly Linked List"<<endl
            <<"Enter '2' to insert data in the list"<<endl
            <<"Enter '3' for node deletion"<<endl
            <<"Enter '4' to search list"<<endl
            <<"Enter '5' to reverse the list"<<endl
            <<"Enter '6' to display list"<<endl
            <<"Enter '7' to go back"<<endl<<endl;

        if(singlyMenuChoiceError == true) {
            cout<<"*Error: Invalid Choice Command!"<<endl<<endl;
        }

        cout<<"Enter your choice command: ";
        cin>>singlyMenuChoice;

        if(singlyMenuChoice == 1) {
            int NoOdNodes=0, nodeDataNumeric=0;
            cout<<"\nHow many node you want to enter: ";
            cin>>NoOdNodes;
            cout<<endl;
            for(int i=0; i<NoOdNodes; i++) {
                cout<<"\tEnter numeric value in Node "<<i+1<<": ";
                cin>>nodeDataNumeric;
                singleList.singlyInsertAtTail(singlyHead, nodeDataNumeric);
            }
            cout<<"\nCreated Singly Linked List is "<<endl;
            singleList.singlyDisplay(singlyHead);
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
                return;
            }
            break;
        }
        else if(singlyMenuChoice == 2) {
            bool singlyInsertDataError= false;
            int singlyInsertDataChoice=0, singlyInsertData=0;
            cout<<"\n\nEnter '1' to insert data at head"<<endl
                <<"Enter '2' to insert data at tail"<<endl
                <<"Enter '3' to insert in the middle"<<endl;
            while(true) {
                if(singlyInsertDataError) {
                    cout<<"\n*Error: Invalid Choice Command!"<<endl;
                }
                cout<<"\nEnter your choice command: ";
                cin>>singlyInsertDataChoice;
                if(singlyInsertDataChoice == 1){
                    cout<<"\n\tEnter numeric data you want to add at head: ";
                    cin>>singlyInsertData;
                    singleList.singlyInsertAtHead(singlyHead, singlyInsertData);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    singleList.singlyDisplay(singlyHead);
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(singlyInsertDataChoice == 2){
                    cout<<"\n\tEnter numeric data you want to add at tail: ";
                    cin>>singlyInsertData;
                    singleList.singlyInsertAtTail(singlyHead, singlyInsertData);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    singleList.singlyDisplay(singlyHead);
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(singlyInsertDataChoice == 3) {
                    int beforeValue= 0;
                    cout<<"\n\tEnter numeric data after which you want to add node: ";
                    cin>>beforeValue;
                    cout<<"\n\tEnter numeric data you want to add at tail: ";
                    cin>>singlyInsertData;
                    singleList.singlyInsertAtMid(singlyHead, beforeValue, singlyInsertData);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    singleList.singlyDisplay(singlyHead);
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else {
                    singlyInsertDataError= true;
                }
            }
        }
        else if(singlyMenuChoice == 3) {
            bool singlyDeleteDataError= false;
            int singlyDeleteDataChoice=0, singlyDeleteData=0;
            cout<<"\n\nEnter '1' to delete from head"<<endl
                <<"Enter '2' to delete from tail"<<endl
                <<"Enter '3' to delete from middle"<<endl;
            while(true) {
                if(singlyDeleteDataError) {
                    cout<<"\n*Error: Invalid Choice Command!"<<endl;
                }
                cout<<"\nEnter your choice command: ";
                cin>>singlyDeleteDataChoice;
                if(singlyDeleteDataChoice == 1) {
                    singleList.singlyDeleteFromHead(singlyHead);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    singleList.singlyDisplay(singlyHead);
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                if(singlyDeleteDataChoice == 2) {
                    singleList.singlyDeleteFromTail(singlyHead);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    singleList.singlyDisplay(singlyHead);
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                if(singlyDeleteDataChoice == 3) {
                    int delValue=0;
                    cout<<"\n\tEnter the numeric value you want to delete: ";
                    cin>>delValue;
                    singleList.singlyDeleteFromMid(singlyHead, delValue);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    singleList.singlyDisplay(singlyHead);
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else {
                    singlyDeleteDataError= true;
                }
            }
        }
        else if(singlyMenuChoice == 4) {
            int searchVal=0;
            bool searchValError= false;
            cout<<"\nEnter numeric value you want to search: ";
            cin>>searchVal;
            singleList.singlysearch(singlyHead, searchVal);
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(singlyMenuChoice == 5) {
            cout<<"\nThe reverse of the singly linked list is"<<endl;
            singleList.singlyReverse(singlyHead);
            singleList.singlyDisplay(singlyHead);
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(singlyMenuChoice == 6) {
            cout<<endl;
            singleList.singlyDisplay(singlyHead);
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(singlyMenuChoice == 7) {
            break;
        }
        else {
            singlyMenuChoiceError= true;
        }
    }
}

void menuDoublyLinkedList() {

    int doublyMenuChoice=0;
    bool doublyMenuChoiceError= false, insertDatainListError= false;
    DoublyFunction doubleList;

    while(true) {
        system("CLS");
        cout<<"---Basic Node Operations for Doubly Linked List---"<<endl<<endl;

        cout<<"Enter '1' to create Doubly Linked List"<<endl
            <<"Enter '2' to insert data in the list"<<endl
            <<"Enter '3' for node deletion"<<endl
            <<"Enter '4' to search list"<<endl
            <<"Enter '5' to reverse the list"<<endl
            <<"Enter '6' to display list"<<endl
            <<"Enter '7' to go back"<<endl<<endl;

        if(doublyMenuChoiceError == true) {
            cout<<"*Error: Invalid Choice Command!"<<endl<<endl;
        }

        cout<<"Enter your choice command: ";
        cin>>doublyMenuChoice;

        if(doublyMenuChoice == 1) {
            int NoOdNodes=0, nodeDataNumeric=0;
            cout<<"\nHow many node you want to enter: ";
            cin>>NoOdNodes;
            cout<<endl;
            for(int i=0; i<NoOdNodes; i++) {
                cout<<"\tEnter numeric value in Node "<<i+1<<": ";
                cin>>nodeDataNumeric;
                doubleList.doublyInsertAtTail(nodeDataNumeric);
            }
            cout<<"\nCreated Doubly Linked List is "<<endl;
            doubleList.doublyDisplay();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
                return;
            }
            break;
        }
        else if(doublyMenuChoice == 2) {
            bool doublyInsertDataError= false;
            int doublyInsertDataChoice=0, doublyInsertData=0;
            cout<<"\n\nEnter '1' to insert data at head"<<endl
                <<"Enter '2' to insert data at tail"<<endl
                <<"Enter '3' to insert in the middle"<<endl;
            while(true) {
                if(doublyInsertDataError) {
                    cout<<"\n*Error: Invalid Choice Command!"<<endl;
                }
                cout<<"\nEnter your choice command: ";
                cin>>doublyInsertDataChoice;
                if(doublyInsertDataChoice == 1){
                    cout<<"\n\tEnter numeric data you want to add at head: ";
                    cin>>doublyInsertData;
                    doubleList.doublyInsertAtHead(doublyInsertData);
                    cout<<"\n\nThe update doubly list is:"<<endl;
                    doubleList.doublyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(doublyInsertDataChoice == 2){
                    cout<<"\n\tEnter numeric data you want to add at tail: ";
                    cin>>doublyInsertData;
                    doubleList.doublyInsertAtTail(doublyInsertData);
                    cout<<"\n\nThe update doubly list is:"<<endl;
                    doubleList.doublyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(doublyInsertDataChoice == 3) {
                    int beforeValue= 0;
                    cout<<"\n\tEnter numeric data after which you want to add node: ";
                    cin>>beforeValue;
                    cout<<"\n\tEnter numeric data you want to add at tail: ";
                    cin>>doublyInsertData;
                    doubleList.doublyInsertAtMid(beforeValue, doublyInsertData);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    doubleList.doublyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
            }
        }
        else if(doublyMenuChoice == 3) {
            bool doublyDeleteDataError= false;
            int doublyDeleteDataChoice=0, doublyDeleteData=0;
            cout<<"\n\nEnter '1' to delete from head"<<endl
                <<"Enter '2' to delete from tail"<<endl
                <<"Enter '3' to delete from middle"<<endl;
            while(true) {
                if(doublyDeleteDataError) {
                    cout<<"\n*Error: Invalid Choice Command!"<<endl;
                }
                cout<<"\nEnter your choice command: ";
                cin>>doublyDeleteDataChoice;
                if(doublyDeleteDataChoice == 1) {
                    doubleList.doublyDeleteFromHead();
                    cout<<"\n\nThe update singly list is:"<<endl;
                    doubleList.doublyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(doublyDeleteDataChoice == 2) {
                    doubleList.doublyDeleteFromTail();
                    cout<<"\n\nThe update singly list is:"<<endl;
                    doubleList.doublyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(doublyDeleteDataChoice == 3) {
                    int delValue=0;
                    cout<<"\n\tEnter the numeric value you want to delete: ";
                    cin>>delValue;
                    doubleList.doublyDeleteFromMid(delValue);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    doubleList.doublyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else {
                    doublyDeleteDataError= true;
                }
            }
        }
        else if(doublyMenuChoice == 4) {
            int searchVal=0;
            bool searchValError= false;
            cout<<"\nEnter numeric value you want to search: ";
            cin>>searchVal;
            doubleList.doublySearch(searchVal);
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
         }
        else if(doublyMenuChoice == 5) {
            cout<<"\nThe reverse of the singly linked list is"<<endl;
            doubleList.doublyReverse();
            doubleList.doublyDisplay();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(doublyMenuChoice == 6) {
            cout<<endl;
            doubleList.doublyDisplay();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(doublyMenuChoice == 7) {
            break;
        }
        else {
            doublyMenuChoiceError= true;
        }
    }
}

void menuCirculyLinkedList() {
    int circulyMenuChoice=0;
    bool circulyMenuChoiceError= false, insertDatainListError= false;
    CirculyFunction circleList;

    while(true) {
        system("CLS");
        cout<<"---Basic Node Operations for Circuly Linked List---"<<endl<<endl;

        cout<<"Enter '1' to create Circuly Linked List"<<endl
            <<"Enter '2' to insert data in the list"<<endl
            <<"Enter '3' for node deletion"<<endl
            <<"Enter '4' to search list"<<endl
            <<"Enter '5' to reverse the list"<<endl
            <<"Enter '6' to display list"<<endl
            <<"Enter '7' to go back"<<endl<<endl;

        if(circulyMenuChoiceError == true) {
            cout<<"*Error: Invalid Choice Command!"<<endl<<endl;
        }

        cout<<"Enter your choice command: ";
        cin>>circulyMenuChoice;

        if(circulyMenuChoice == 1) {
            int NoOdNodes=0, nodeDataNumeric=0;
            cout<<"\nHow many node you want to enter: ";
            cin>>NoOdNodes;
            cout<<endl;
            for(int i=0; i<NoOdNodes; i++) {
                cout<<"\tEnter numeric value in Node "<<i+1<<": ";
                cin>>nodeDataNumeric;
                circleList.circulyInsertAtTail(nodeDataNumeric);
            }
            cout<<"\nCreated Circuly Linked List is "<<endl;
            circleList.circulyDisplay();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
                return;
            }
            break;
        }
        else if(circulyMenuChoice == 2) {
            bool circulyInsertDataError= false;
            int circulyInsertDataChoice=0, circulyInsertData=0;
            cout<<"\n\nEnter '1' to insert data at head"<<endl
                <<"Enter '2' to insert data at tail"<<endl
                <<"Enter '3' to insert in the middle"<<endl;
            while(true) {
                if(circulyInsertDataError) {
                    cout<<"\n*Error: Invalid Choice Command!"<<endl;
                }
                cout<<"\nEnter your choice command: ";
                cin>>circulyInsertDataChoice;
                if(circulyInsertDataChoice == 1){
                    cout<<"\n\tEnter numeric data you want to add at head: ";
                    cin>>circulyInsertData;
                    circleList.circulyInsertAtHead(circulyInsertData);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    circleList.circulyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(circulyInsertDataChoice == 2){
                    cout<<"\n\tEnter numeric data you want to add at tail: ";
                    cin>>circulyInsertData;
                    circleList.circulyInsertAtTail(circulyInsertData);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    circleList.circulyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else if(circulyInsertDataChoice == 3) {
                    int beforeValue= 0;
                    cout<<"\n\tEnter numeric data after which you want to add node: ";
                    cin>>beforeValue;
                    cout<<"\n\tEnter numeric data you want to add at tail: ";
                    cin>>circulyInsertData;
                    circleList.circulyInsertAtMid(beforeValue, circulyInsertData);
                    cout<<"\n\nThe update singly list is:"<<endl;
                    circleList.circulyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else {
                    circulyInsertDataError= true;
                }
            }
        }
        else if(circulyMenuChoice == 3) {
            bool singlyDeleteDataError= false;
            int singlyDeleteDataChoice=0, singlyDeleteData=0;
            cout<<"\n\nEnter '1' to delete from head"<<endl
                <<"Enter '2' to delete from tail"<<endl
                <<"Enter '3' to delete from middle"<<endl;
            while(true) {
                if(singlyDeleteDataError) {
                    cout<<"\n*Error: Invalid Choice Command!"<<endl;
                }
                cout<<"\nEnter your choice command: ";
                cin>>singlyDeleteDataChoice;
                if(singlyDeleteDataChoice == 1) {
                    circleList.circulyDeleteFromHead();
                    cout<<"\n\nThe update circuly list is:"<<endl;
                    circleList.circulyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                if(singlyDeleteDataChoice == 2) {
                    circleList.circulyDeleteFromTail();
                    cout<<"\n\nThe update circuly list is:"<<endl;
                    circleList.circulyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                if(singlyDeleteDataChoice == 3) {
                    int delValue=0;
                    cout<<"\n\tEnter the numeric value you want to delete: ";
                    cin.ignore();
                    cin>>delValue;
                    circleList.circulyDeleteFromMid(delValue);
                    cout<<"\n\nThe update circuly list is:"<<endl;
                    circleList.circulyDisplay();
                    cout<<"\n\nPress any key to go back";
                    if(getch()) {
                        break;
                    }
                }
                else {
                    singlyDeleteDataError= true;
                }
            }
        }
        else if(circulyMenuChoice == 4) {
            int searchVal=0;
            bool searchValError= false;
            cout<<"\nEnter numeric value you want to search: ";
            cin>>searchVal;
            circleList.circulysearch(searchVal);
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(circulyMenuChoice == 5) {
            cout<<"\nThe reverse of the circuly linked list is"<<endl;
            circleList.circulyReverse();
            circleList.circulyDisplay();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(circulyMenuChoice == 6) {
            cout<<endl;
            circleList.circulyDisplay();
            cout<<"\n\nPress any key to go back";
            if(getch()) {
                continue;
            }
        }
        else if(circulyMenuChoice == 7) {
            break;
        }
        else {
            circulyMenuChoiceError= true;
        }
    }
}

