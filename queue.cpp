#include <iostream>
using namespace std;
class Error {
private:
    string errMsg;
public:
    Error(string errMsg) { this->errMsg = errMsg; }
    string getErrorMesssage() { return errMsg; }
};

class OutOfBoundError :public Error {
public:
    OutOfBoundError(string errorMsg = "generation of \"OutOfBoundError\" ") :Error(errorMsg) {}
    string errorMessage() { return getErrorMesssage(); }
};

class NodeOfQueue {
private:
    int dataOfQueue;
    NodeOfQueue* nextNodePointer;
public:
    NodeOfQueue(int dataOfQueue, NodeOfQueue* nextNodePointer) {
        this->dataOfQueue = dataOfQueue;
        this->nextNodePointer = nextNodePointer;
    }
    void setDataOfQueue(int dataOfQueue) {
        this->dataOfQueue = dataOfQueue;
    }
    int getDataOfQueue() {
        return dataOfQueue;
    }
    void setNextNodePointer(NodeOfQueue* nextNodePointer) {
        this->nextNodePointer = nextNodePointer;
    }
    NodeOfQueue* getNextNodePointer() {
        return nextNodePointer;
    }
};

class Queue {
private:
    NodeOfQueue* frontNode, * rearNode;
    int queueCurrentSize;
public:
    Queue() {
        queueCurrentSize = 0; frontNode = NULL; rearNode = NULL;
    }
    bool empty();
    int getQueueCurrentSize();
    void push(int dataOfQueue);
    void pop();
    void print();
};
bool Queue::empty() {
    return (frontNode == NULL && rearNode == NULL) ? true : false;
}
int Queue::getQueueCurrentSize() {
    return queueCurrentSize;
}
void Queue::push(int dataOfQueue) {
    NodeOfQueue* newNode = new NodeOfQueue(dataOfQueue, NULL);
    switch (empty())
    {
    case 0:
        rearNode->setNextNodePointer(newNode);
        rearNode = rearNode->getNextNodePointer();
        rearNode = newNode;
        break;
    case 1:
        frontNode = newNode;
        rearNode = newNode;
        break;
    }
    queueCurrentSize++;
}
void Queue::pop() {
    try {
        switch (empty())
        {
            case 0:
            {
                NodeOfQueue* tempNode = frontNode;
                frontNode = frontNode->getNextNodePointer();
                if(frontNode == rearNode){ frontNode = NULL; rearNode = NULL; }
                else{ delete tempNode; }
                queueCurrentSize--;
                break;
            }
            case 1:
            {
                throw OutOfBoundError();
                break;
            }
        }
    }
    catch (OutOfBoundError outOfBoundError) {
        cout << outOfBoundError.errorMessage() << "\n";
        exit(1);
    }
}
void Queue::print() {
    for (NodeOfQueue* i = frontNode; i != NULL; i = i->getNextNodePointer()) {
        cout << i->getDataOfQueue() << " ";
    }
    cout << "\n";
}

int main() {
    Queue queue;
    queue.push(2);
    queue.print();
    queue.push(3);
    queue.print();
    queue.push(1);
    queue.print();
    queue.push(5);
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
}