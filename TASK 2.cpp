#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int rollNo;
    string name;
    string attendance;
    Node* next;
};
void addStudent(Node*& head, int rollNo, string name, string attendance)
{
    Node* newNode = new Node;
    newNode->rollNo = rollNo;
    newNode->name = name;
    newNode->attendance = attendance;
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
    cout << "Student added successfully." << endl;
}
void searchStudent(Node* head, int rollNo)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cout << "\nStudent found!" << endl;
            cout << "Roll Number: " << temp->rollNo << endl;
            cout << "Student Name: " << temp->name << endl;
            cout << "Attendance: " << temp->attendance << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found." << endl;
}

// Delete a student using Roll Number
void deleteStudent(Node*& head, int rollNo)
{
    if (head == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    // If the student is the first node
    if (head->rollNo == rollNo)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Student deleted successfully." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->rollNo == rollNo)
        {
            Node* deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Student deleted successfully." << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found." << endl;
}

// Display all students
void displayStudents(Node* head)
{
    if (head == NULL)
    {
        cout << "Attendance list is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "\n===== Attendance List =====" << endl;

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNo << endl;
        cout << "Student Name: " << temp->name << endl;
        cout << "Attendance: " << temp->attendance << endl;
        cout << "---------------------------" << endl;

        temp = temp->next;
    }
}

// Count total present students
void countPresent(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->attendance == "Present" ||
            temp->attendance == "present")
        {
            count++;
        }

        temp = temp->next;
    }

    cout << "Total students present: " << count << endl;
}

int main()
{
    Node* head = NULL;

    int choice;
    int rollNo;
    string name;
    string attendance;

    do
    {
        cout << "\n===== University Student Attendance =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Count Total Students Present" << endl;
        cout << "6. Display Final Attendance List" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Roll Number: ";
            cin >> rollNo;

            cout << "Enter Student Name: ";
            cin >> name;

            cout << "Enter Attendance (Present/Absent): ";
            cin >> attendance;

            addStudent(head, rollNo, name, attendance);
        }

        else if (choice == 2)
        {
            cout << "Enter Roll Number to search: ";
            cin >> rollNo;

            searchStudent(head, rollNo);
        }

        else if (choice == 3)
        {
            cout << "Enter Roll Number to delete: ";
            cin >> rollNo;

            deleteStudent(head, rollNo);
        }

        else if (choice == 4)
        {
            displayStudents(head);
        }

        else if (choice == 5)
        {
            countPresent(head);
        }

        else if (choice == 6)
        {
            displayStudents(head);
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

