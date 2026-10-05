#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int orderID;
    string customerName;
    string foodItem;
    Node* next;
};


void addOrder(Node*& head, int orderID, string customerName, string foodItem)
{
    Node* newNode = new Node;

    newNode->orderID = orderID;
    newNode->customerName = customerName;
    newNode->foodItem = foodItem;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Order added successfully." << endl;
}

// Add urgent order at the beginning
void addUrgentOrder(Node*& head, int orderID, string customerName, string foodItem)
{
    Node* newNode = new Node;

    newNode->orderID = orderID;
    newNode->customerName = customerName;
    newNode->foodItem = foodItem;

    newNode->next = head;
    head = newNode;

    cout << "Urgent order added successfully." << endl;
}

// Display all pending orders
void displayOrders(Node* head)
{
    if (head == NULL)
    {
        cout << "No pending orders." << endl;
        return;
    }

    Node* temp = head;

    cout << "\n===== Pending Orders =====" << endl;

    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID << endl;
        cout << "Customer Name: " << temp->customerName << endl;
        cout << "Food Item: " << temp->foodItem << endl;
        cout << "--------------------------" << endl;

        temp = temp->next;
    }
}

// Search for an order using Order ID
void searchOrder(Node* head, int orderID)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == orderID)
        {
            cout << "\nOrder found!" << endl;
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found." << endl;
}

// Remove an order using Order ID
void removeOrder(Node*& head, int orderID)
{
    if (head == NULL)
    {
        cout << "Order not found." << endl;
        return;
    }

    // If the order is the first node
    if (head->orderID == orderID)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        cout << "Order delivered and removed successfully." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->orderID == orderID)
        {
            Node* deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Order delivered and removed successfully." << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found." << endl;
}

int main()
{
    Node* head = NULL;

    int choice;
    int orderID;
    string customerName;
    string foodItem;

    do
    {
        cout << "\n===== Online Food Delivery System =====" << endl;
        cout << "1. Add New Order" << endl;
        cout << "2. Display Pending Orders" << endl;
        cout << "3. Search Order" << endl;
        cout << "4. Remove Delivered Order" << endl;
        cout << "5. Add Urgent Order" << endl;
        cout << "6. Display Updated Orders" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Order ID: ";
            cin >> orderID;

            cout << "Enter Customer Name: ";
            cin >> customerName;

            cout << "Enter Food Item: ";
            cin >> foodItem;

            addOrder(head, orderID, customerName, foodItem);
        }

        else if (choice == 2)
        {
            displayOrders(head);
        }

        else if (choice == 3)
        {
            cout << "Enter Order ID to search: ";
            cin >> orderID;

            searchOrder(head, orderID);
        }

        else if (choice == 4)
        {
            cout << "Enter Order ID to remove: ";
            cin >> orderID;

            removeOrder(head, orderID);
        }

        else if (choice == 5)
        {
            cout << "Enter Urgent Order ID: ";
            cin >> orderID;

            cout << "Enter Customer Name: ";
            cin >> customerName;

            cout << "Enter Food Item: ";
            cin >> foodItem;

            addUrgentOrder(head, orderID, customerName, foodItem);
        }

        else if (choice == 6)
        {
            displayOrders(head);
        }

        else if (choice == 7)
        {
            cout << "Program ended." << endl;
        }

        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    return 0;
}

