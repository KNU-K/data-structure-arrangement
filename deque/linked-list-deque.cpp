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

class NodeOfDeque {
private:
    int dataOfDeque;
    NodeOfDeque* prevNodePointer;
    NodeOfDeque* nextNodePointer;
public:
    NodeOfDeque(NodeOfDeque* prevNodePointer, int dataOfDeque, NodeOfDeque* nextNodePointer) {
        this->prevNodePointer = prevNodePointer;
        this->dataOfDeque = dataOfDeque;
        this->nextNodePointer = nextNodePointer;
    }
    void setDataOfDeque(int dataOfDeque) {
        this->dataOfDeque = dataOfDeque;
    }
    int getDataOfDeque() {
        return dataOfDeque;
    }
    void setNextNodePointer(NodeOfDeque* nextNodePointer) {
        this->nextNodePointer = nextNodePointer;
    }
    NodeOfDeque* getNextNodePointer() {
        return nextNodePointer;
    }
    void setPrevNodePointer(NodeOfDeque* prevNodePointer) {
        this->prevNodePointer = prevNodePointer;
    }
    NodeOfDeque* getPrevNodePointer() {
        return prevNodePointer;
    }
};
class Deque {
private:
    NodeOfDeque* frontNode, * rearNode;
    int dequeCurrentSize;
public:
    Deque() { frontNode = NULL; rearNode = NULL; dequeCurrentSize = 0; }
    ~Deque() {
        delete frontNode,rearNode;
    }
    bool empty();
    void push_back(int dataOfDeque);
    void pop_back();
    void push_front(int dataOfDeque);
    void pop_front();
    void print();
};
bool Deque::empty() {
    return (frontNode == NULL && rearNode == NULL) ? true : false;
}
void Deque::push_back(int dataOfDeque) {
    NodeOfDeque* newNode = new NodeOfDeque(NULL, dataOfDeque, NULL);
    switch (empty())
    {
    case 0:
        newNode->setPrevNodePointer(rearNode);
        rearNode->setNextNodePointer(newNode);
        rearNode = rearNode->getNextNodePointer();
        break;
    case 1:
        frontNode = newNode;
        rearNode = newNode;
        break;
    }
    dequeCurrentSize++;
}
void Deque::pop_back() {
    try {
        switch (empty())
        {
        case 0:
        {
            NodeOfDeque* tempNode = rearNode;
            if (frontNode == rearNode) { frontNode = NULL; rearNode = NULL; return; }
            rearNode = rearNode->getPrevNodePointer();
            rearNode->setNextNodePointer(NULL);
            dequeCurrentSize--;
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
void Deque::push_front(int dataOfDeque) {
    NodeOfDeque* newNode = new NodeOfDeque(NULL, dataOfDeque, NULL);
    switch (empty())
    {
    case 0:
        newNode->setNextNodePointer(frontNode);
        frontNode->setPrevNodePointer(newNode);
        frontNode = frontNode->getPrevNodePointer();
        break;
    case 1:
        frontNode = newNode;
        rearNode = newNode;
        break;
    }
    dequeCurrentSize++;
}
void Deque::pop_front() {
    try {
        switch (empty())
        {
        case 0:
        {
            NodeOfDeque* tempNode = frontNode;
            if (frontNode == rearNode) { frontNode = NULL; rearNode = NULL; return; }
            frontNode = frontNode->getNextNodePointer();
            rearNode->setPrevNodePointer(NULL);
            dequeCurrentSize--;
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
void Deque::print() {
    for (NodeOfDeque* i = frontNode; i != NULL; i = i->getNextNodePointer()) {
        cout << i->getDataOfDeque() << " ";
    }
    cout << "\n";
}
int main() {
    Deque deque;
    deque.push_back(1);
    deque.push_back(3);
    deque.push_back(4);
    deque.push_front(4);
    deque.push_front(0);
    deque.push_front(1);
    deque.print();
    deque.pop_back();
    deque.print();
    deque.pop_back();
    deque.print();
    deque.pop_back();
    deque.print();
    deque.pop_back();
    deque.print();
    deque.pop_back();
    deque.print();
    deque.pop_front();
    deque.print();
    deque.pop_front();
}