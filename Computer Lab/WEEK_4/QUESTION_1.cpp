#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
};

Node* insertTerm(Node* head, int coeff, int power) {
    if (coeff == 0) {
        return head;
    }

    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    while (poly1 != nullptr || poly2 != nullptr) {
        if (poly1 == nullptr) {
            result = insertTerm(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else if (poly2 == nullptr) {
            result = insertTerm(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else {
            if (poly1->power == poly2->power) {
                int sumCoeff = poly1->coeff + poly2->coeff;
                result = insertTerm(result, sumCoeff, poly1->power);
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->power > poly2->power) {
                result = insertTerm(result, poly1->coeff, poly1->power);
                poly1 = poly1->next;
            } else {
                result = insertTerm(result, poly2->coeff, poly2->power);
                poly2 = poly2->next;
            }
        }
    }
    return result;
}

Node* multiplyByNegative(Node* poly) {
    Node* result = nullptr;
    while (poly != nullptr) {
        result = insertTerm(result, -poly->coeff, poly->power);
        poly = poly->next;
    }
    return result;
}

void displayPolynomial(Node* poly) {
    Node* current = poly;
    while (current != nullptr) {
        if (current->power == 0) {
            cout << current->coeff;
        } else {
            cout << current->coeff << "x^" << current->power;
        }
        if (current->next != nullptr) {
            cout << " + ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    int n, coeff, power;
    cout << "P.S. : Press (-1) in Power to stop accepting.\n\n";
    cout << "~: Enter the first polynomial :~\n";
    while(true){
        cout << "Enter the Coefficent & Power : ";
        cin >> coeff >> power;
        if(power == -1){break;}
        poly1 = insertTerm(poly1, coeff, power);
    }

    cout << "\n~: Enter the second polynomial :~\n";
    while(true){
        cout << "Enter the Coefficent & Power : ";
        cin >> coeff >> power;
        if(power == -1){break;}
        poly2 = insertTerm(poly2, coeff, power);
    }

    cout << "\nFirst polynomial : ";
    displayPolynomial(poly1);

    cout << "Second polynomial : ";
    displayPolynomial(poly2);

    Node* sum = addPolynomials(poly1,poly2);
    Node* negPoly2 = multiplyByNegative(poly2);

    Node* diff = addPolynomials(poly1, negPoly2);

    cout << "\nThe Sum of 2 Polynomials : ";
    displayPolynomial(sum);

    cout << "The Difference of 2 Polynomials : ";
    displayPolynomial(diff);

    return 0;
}