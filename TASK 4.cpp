#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string courseCode;
    string courseName;
    int creditHours;
    Node* next;
};

// Add course at beginning
void addAtBeginning(Node*& head, string code, string name, int credits)
{
    Node* newNode = new Node;

    newNode->courseCode = code;
    newNode->courseName = name;
    newNode->creditHours = credits;
    newNode->next = head;

    head = newNode;

    cout << "Course added at beginning." << endl;
}

// Add course at end
void addAtEnd(Node*& head, string code, string name, int credits)
{
    Node* newNode = new Node;

    newNode->courseCode = code;
    newNode->courseName = name;
    newNode->creditHours = credits;
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

    cout << "Course added at end." << endl;
}

// Search course by course code
void searchCourse(Node* head, string code)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->courseCode == code)
        {
            cout << "\nCourse found!" << endl;
            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Course not found." << endl;
}

// Delete course by course code
void deleteCourse(Node*& head, string code)
{
    if (head == NULL)
    {
        cout << "Course not found." << endl;
        return;
    }

    // If the course is the first node
    if (head->courseCode == code)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        cout << "Course deleted successfully." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->courseCode == code)
        {
            Node* deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            cout << "Course deleted successfully." << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Course not found." << endl;
}

// Display all courses
void displayCourses(Node* head)
{
    if (head == NULL)
    {
        cout << "Course list is empty." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << "Course Code: " << temp->courseCode << endl;
        cout << "Course Name: " << temp->courseName << endl;
        cout << "Credit Hours: " << temp->creditHours << endl;
        cout << "--------------------------" << endl;

        temp = temp->next;
    }
}

// Count total courses
void countCourses(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total courses: " << count << endl;
}

// Concatenate second list with first list
void concatenate(Node*& first, Node* second)
{
    if (first == NULL)
    {
        first = second;
        return;
    }

    Node* temp = first;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = second;
}

int main()
{
    Node* morning = NULL;
    Node* evening = NULL;

    int choice;
    int listChoice;
    string code;
    string name;
    int credits;

    do
    {
        cout << "\n===== University Course Management =====" << endl;
        cout << "1. Add Course at Beginning" << endl;
        cout << "2. Add Course at End" << endl;
        cout << "3. Search Course" << endl;
        cout << "4. Delete Course" << endl;
        cout << "5. Display All Courses" << endl;
        cout << "6. Count Total Courses" << endl;
        cout << "7. Concatenate Morning and Evening Lists" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n1. Morning List" << endl;
            cout << "2. Evening List" << endl;
            cout << "Select list: ";
            cin >> listChoice;

            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            cin >> name;

            cout << "Enter Credit Hours: ";
            cin >> credits;

            if (listChoice == 1)
            {
                addAtBeginning(morning, code, name, credits);
            }
            else if (listChoice == 2)
            {
                addAtBeginning(evening, code, name, credits);
            }
            else
            {
                cout << "Invalid list choice." << endl;
            }
        }

        else if (choice == 2)
        {
            cout << "\n1. Morning List" << endl;
            cout << "2. Evening List" << endl;
            cout << "Select list: ";
            cin >> listChoice;

            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            cin >> name;

            cout << "Enter Credit Hours: ";
            cin >> credits;

            if (listChoice == 1)
            {
                addAtEnd(morning, code, name, credits);
            }
            else if (listChoice == 2)
            {
                addAtEnd(evening, code, name, credits);
            }
            else
            {
                cout << "Invalid list choice." << endl;
            }
        }

        else if (choice == 3)
        {
            cout << "\n1. Morning List" << endl;
            cout << "2. Evening List" << endl;
            cout << "Select list: ";
            cin >> listChoice;

            cout << "Enter Course Code to search: ";
            cin >> code;

            if (listChoice == 1)
            {
                searchCourse(morning, code);
            }
            else if (listChoice == 2)
            {
                searchCourse(evening, code);
            }
            else
            {
                cout << "Invalid list choice." << endl;
            }
        }

        else if (choice == 4)
        {
            cout << "\n1. Morning List" << endl;
            cout << "2. Evening List" << endl;
            cout << "Select list: ";
            cin >> listChoice;

            cout << "Enter Course Code to delete: ";
            cin >> code;

            if (listChoice == 1)
            {
                deleteCourse(morning, code);
            }
            else if (listChoice == 2)
            {
                deleteCourse(evening, code);
            }
            else
            {
                cout << "Invalid list choice." << endl;
            }
        }

        else if (choice == 5)
        {
            cout << "\n===== Morning Courses =====" << endl;
            displayCourses(morning);

            cout << "\n===== Evening Courses =====" << endl;
            displayCourses(evening);
        }

        else if (choice == 6)
        {
            cout << "\nMorning Courses: ";
            countCourses(morning);

            cout << "Evening Courses: ";
            countCourses(evening);
        }

        else if (choice == 7)
        {
            concatenate(morning, evening);

            cout << "\n===== Combined Course List =====" << endl;
            displayCourses(morning);

            cout << "Morning and Evening lists have been concatenated." << endl;
        }

        else if (choice == 8)
        {
            cout << "Program ended." << endl;
        }

        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 8);

    return 0;
}
