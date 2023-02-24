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
	string errorMessage(){return getErrorMesssage();}
};

class NodeOfStack {
private:
	int dataOfStack;
	NodeOfStack* nextNodePointer;
public:
	NodeOfStack(int dataOfStack, NodeOfStack* nextNodePointer) {
		this->dataOfStack = dataOfStack; this->nextNodePointer = nextNodePointer;
	}
	void setDataOfStack(int dataOfStack) {
		this->dataOfStack = dataOfStack;
	}
	int getDataOfStack() {
		return dataOfStack;
	}
	void setNextNodePointer(NodeOfStack * nextNodePointer) {
		this->nextNodePointer = nextNodePointer;
	}
	NodeOfStack* getNextNodePointer() {
		return nextNodePointer;
	}
};
class Stack {
private:
	NodeOfStack * topNode;
	int stackCurrentSize;
public:
	Stack() {
		/** Because you not input data of stack(This is init status) */
		stackCurrentSize = 0; topNode = NULL;
	}
	bool empty();
	int getStackCurrentSize(); 
	void push(int dataOfStack);
	void pop(); 
	void print();
};
bool Stack::empty(){
	return (topNode == NULL) ? true : false;
}
int Stack::getStackCurrentSize(){
	return stackCurrentSize;
}
void Stack::push(int dataOfStack){
	NodeOfStack* newNode = new NodeOfStack(dataOfStack,NULL);

	switch (empty()) {
		/** empty false */
		case 0:
			newNode->setNextNodePointer(topNode);
		/** empty true or For change topNode position */
		case 1:
			topNode = newNode;
	}

	stackCurrentSize++;
}
void Stack::pop(){
	try {
		switch (empty())
		{
			/** empty false */
			case 0:
			{
				NodeOfStack* tempNode = topNode;
				topNode = topNode->getNextNodePointer();

				/** skill of memory management */
				delete tempNode;

				stackCurrentSize--;
				break;
			}
			/** empty true */
			case 1:
			{
				/** There is no data to pop. WTF */
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
void Stack::print(){
for (NodeOfStack* i = topNode; i != NULL; i = i->getNextNodePointer()) {
			cout << i->getDataOfStack() << " ";
		}
		cout << "\n";

}
int main() {
	Stack stack;
	stack.push(1);
	stack.print();
	stack.push(2);
	stack.print();
	stack.push(4);
	stack.print();
	stack.push(0);
	stack.print();
	stack.push(2);
	stack.print();
	stack.pop();
	stack.print();
}