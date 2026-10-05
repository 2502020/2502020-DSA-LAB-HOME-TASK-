#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int id;
    string name;
    int age;
    Node* next;
};
void addAtEnd(Node*& head, int id, string name, int age)
{
    Node* newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->age = age;
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
    cout << "Patient added successfully." << endl;
}
void addAtBeginning(Node*& head, int id, string name, int age)
{
    Node* newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->age = age;
    newNode->next = head;
    head = newNode;
    cout << "Emergency patient added successfully." << endl;
}
void searchPatient(Node* head, int id)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Patient found!" << endl;
            cout << "Patient ID: " << temp->id << endl;
            cout << "Patient Name: " << temp->name << endl;
            cout << "Patient Age: " << temp->age << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient does not exist." << endl;
}
void removePatient(Node*& head, int id)
{
    if (head == NULL)
    {
        cout << "Patient does not exist." << endl;
        return;
    }
    if (head->id == id)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient removed successfully." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->id == id)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Patient removed successfully." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient does not exist." << endl;
}
void displayPatients(Node* head)
{
    if (head == NULL)
    {
        cout << "No patients in the waiting list." << endl;
        return;
    }
    Node* temp = head;
    cout << "\n--- Waiting Patients ---" << endl;
    while (temp != NULL)
    {
        cout << "Patient ID: " << temp->id << endl;
        cout << "Patient Name: " << temp->name << endl;
        cout << "Patient Age: " << temp->age << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
}
int main()
{
    Node* head = NULL;
    int choice;
    int id;
    int age;
    string name;
    do
    {
        cout << "\n===== Hospital Emergency Patient Management =====" << endl;
        cout << "1. Add Patient at End" << endl;
        cout << "2. Add Emergency Patient at Beginning" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Remove Patient" << endl;
        cout << "5. Display All Patients" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> name;
            cout << "Enter Patient Age: ";
            cin >> age;
            addAtEnd(head, id, name, age);
        }
        else if (choice == 2)
        {
            cout << "Enter Emergency Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> name;
            cout << "Enter Patient Age: ";
            cin >> age;
            addAtBeginning(head, id, name, age);
        }
        else if (choice == 3)
        {
            cout << "Enter Patient ID to search: ";
            cin >> id;
            searchPatient(head, id);
        }
        else if (choice == 4)
        {
            cout << "Enter Patient ID to remove: ";
            cin >> id;
            removePatient(head, id);
        }
        else if (choice == 5)
        {
            displayPatients(head);
        }

        else if (choice == 6)
        {
            cout << "Program ended." << endl;
        }

        else
        {
            cout << "Invalid choice." << endl;
        }
    } 
	while (choice != 6);
    return 0;
}

 