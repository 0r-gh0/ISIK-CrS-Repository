#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* head = NULL;
void push(char value) {
    Node* newNode = new (Node);
    newNode->next = head;
    newNode->data= value;
    head = newNode;
}
    
void display(){
    Node* temp;
    temp = head;
    while( temp != nullptr ){
        cout << temp -> data;
        temp = temp -> next;
    }
}

char pop() {
    if (head == nullptr) {
        return '$';
    }
    char value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return value;
}

char peek() {
    if (head == nullptr)
        return '$';
    return head->data;
}

bool isEmpty() {
    if (head == nullptr)
        return true;
    return false;
}

bool Operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    	return true;
    return false;
}

bool Operand(char c)
{
	if (isalnum(c))
		return true;
	return false;
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

string infixToPrefix(string &infix) {
    string prefix = "";
    int len = infix.length();
    for (int i = len-1; i >=0; i--) {
        char c = infix[i];
        if (Operand(c)) {
            prefix = c + prefix;
        } else if (c == ')') {
            push(c);
        } else if (c == '(') {
            while (!isEmpty() && peek() != ')') {
                prefix = pop() + prefix;
            }
            pop();
        } else if (Operator(c)) {
            while (!isEmpty() && precedence(c) <= precedence(peek())) {
                prefix = pop() + prefix;
            }
            push(c);
        }
    display(); // Not asked in the question 
    cout << "\t" << prefix << "\t\t\t" << peek() << endl;
    }
    while (!isEmpty()) {
        prefix = pop() + prefix;
    }
    return prefix;
}

int main() {
    string  infixExpression;
    cout << "Enter your expression : ";
    getline(cin,infixExpression);
    
    // string  infixExpression = "(a+(b-c*g)*h)";
    // string  infixExpression = "(a+(b*c-(d/e^f)*g)*h)";
    
    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Infix Expression : " << infixExpression << endl;
    cout << "Prefix Expression : " << prefixExpression << endl;
    
    return 0;
}