#include <iostream>

using namespace std;

//Declare Node
struct Node
{
    int data;
    struct Node *next;
};

//Declare linkedList class
class linkedList
{
public:
    //Constructor
    linkedList()
    {
        head->next = NULL;
        list_size = 0;
    }

    //Public variable and functions declaration
    int list_size;
    void insert(int);
    void display();
    Node *getNode(int);
    void pointNull();

private:
    //Creating a head node
    Node *head = new Node();
};

//Insert function
void linkedList::insert(int value)
{
    //Create a new node
    Node *temp1 = new Node();
    temp1->data = value;
    temp1->next = NULL;

    /*
        Link the head node to the new node if the list is empty
        Else use a traversing node to traverse to the last node
        and link the last node to the new node
    */
    if (list_size == 0)
    {
        head->next = temp1;
        list_size++;
    }
    else if (list_size > 0)
    {
        Node *temp2 = head;

        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        temp2->next = temp1;
        list_size++;
    }
}

//Display the values in the list
void linkedList::display()
{
    Node *temp = head;
    temp = temp->next;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
    To get the index x element in the list which
    the head can be considered as 0-th element
*/
Node *linkedList::getNode(int x)
{
    Node *temp = head;
    int i = 1;

    while (temp != NULL)
    {
        if (i == x)
        {
            return temp->next;
        }
    }

    return head;
}

void linkedList::pointNull()
{
    head->next = NULL;
    list_size = 0;
}

int main()
{
    //Declaration of variables
    int size_L1, size_L2, numHold_L1, numHold_L2;
    linkedList L1, L2;
    Node *temp1, *temp2, *tmp_Hold1, *tmp_Hold2;

    //User input of L1 size
    cout << "Input the number of list L1 nodes: ";
    cin >> size_L1;

    //Input validation
    while (size_L1 <= 0)
    {
        cout << "\nPlease enter a number larger than 0.\n";
        cout << "Input the number of list L1 nodes: ";
        cin >> size_L1;
    }

    //User input values for L1
    cout << "Input the data elements of list L1 successively: ";
    for (int i = 0; i < size_L1; i++)
    {
        cin >> numHold_L1;
        L1.insert(numHold_L1);
    }

    //Display the values inside L1
    cout << "Nodes of List L1 are: ";
    L1.display();

    //User input of L2 size
    cout << "\nInput the number of list L2 nodes: ";
    cin >> size_L2;

    //Input validation
    while (size_L2 <= 0)
    {
        cout << "\nPlease enter a number larger than 0.\n";
        cout << "Input the number of list L2 nodes: ";
        cin >> size_L2;
    }

    //User input values for L2
    cout << "Input the data elements of list L2 successively: ";
    for (int i = 0; i < size_L2; i++)
    {
        cin >> numHold_L2;
        L2.insert(numHold_L2);
    }

    //Display the values inside L2
    cout << "Nodes of List L2 are: ";
    L2.display();

    /*
        Point temp1 to the first element in L1
        Point temp2 to the first element in L2
        Point tmp_Hold1 to the second element in L1
        Point tmp_Hold2 to the second element in L2
    */
    temp1 = L1.getNode(1);
    temp2 = L2.getNode(1);
    tmp_Hold1 = temp1->next;
    tmp_Hold2 = temp2->next;

    //Conditional statement to merge both L1 and L2
    if (size_L1 > size_L2)
    {
        while (temp2 != NULL)
        {
            temp1->next = temp2;
            temp2->next = tmp_Hold1;
            temp1 = tmp_Hold1;
            tmp_Hold1 = tmp_Hold1->next;
            temp2 = tmp_Hold2;
            if (tmp_Hold2 != NULL)
            {
                tmp_Hold2 = tmp_Hold2->next;
            }
        }
    }
    else
    {
        while (temp1 != NULL)
        {
            temp1->next = temp2;
            temp1 = tmp_Hold1;

            if (tmp_Hold1 != NULL)
            {
                temp2->next = tmp_Hold1;
                temp1 = tmp_Hold1;
                tmp_Hold1 = tmp_Hold1->next;
                temp2 = tmp_Hold2;
                tmp_Hold2 = tmp_Hold2->next;
            }
        }
    }

    //Point the head of L2 to NULL
    L2.pointNull();

    //Display the nodes which is merged into L1
    cout << "\nThe merged nodes of L1 & L2 are: ";
    L1.display();

    return 1;
}