#include <iostream>

using namespace std;

// Class Stack declaration
class Stack
{
public:
    //Constructor
    Stack() { values = new double[5]; };

    //Functions and variables declaration
    bool isEmpty();
    double Top();
    void Push(double);
    double Pop();
    void displayStack();

private:
    int top = -1;
    double *values;
};

//isEmpty Function
bool Stack::isEmpty()
{
    //Check if the stack is empty or not.
    return top == -1;
}

//Top Function
double Stack::Top()
{
    /*
        If the top index is -1, then there is no element inside the stack.
        Else return the top element in the stack.
    */
    if (top == -1)
    {
        cout << "There is no element inside the stack.\n";
        return -1;
    }
    else
        return values[top];
}

//Push Function
void Stack::Push(double x)
{
    /*
        If the stack is not full, then push the value x
        into the stack.
        Else print out that the stack is full.
    */
    if (top + 1 < 5)
    {
        values[top + 1] = x;
        top++;
    }
    else
    {
        cout << "The stack is full.\nCan't push anymore element into the stack.\n";
    }
}

//Pop Function
double Stack::Pop()
{
    /*
        If the stack is not empty, then pop the top element
        and return the value of it.
        Else print out that it is empty.
    */
    if (!isEmpty())
    {
        return values[top--];
    }
    else
    {
        cout << "The stack is empty.\nCan't pop the top element from the stack.\n";
        return -1;
    }
}

//displayStack Function
void Stack::displayStack()
{
    /*
        If the stack is empty, then print out Empty.
        Else print out all the elements in the stack.
    */
    if (isEmpty())
    {
        cout << "Empty\n";
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << values[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    //variable declaration
    Stack st, tmpst;
    double tmp;

    //Pushing all the elements into stack st
    cout << "(1) Pushing the elements 25, 10, 15, 20, 30 into the stack st.\n\n";
    st.Push(25);
    st.Push(10);
    st.Push(15);
    st.Push(20);
    st.Push(30);

    cout << "(2) The process of sorting elements of stack st is:\n\n";

    /*
        Algorithm which will arrange the stacks in ascending order
        which means the bottom element is the largest element
        and the top element is the smallest element in the stack.
        
        The algorithm will stop once stack st is empty.
    */

    /*
        While the stack st is not empty, the algorithm
        will first pop out the top element from stack st
        and put it into tmp variable.
   */
    while (!st.isEmpty())
    {
        tmp = st.Pop();
        cout << "\tst: Pop out " << tmp << " from the stack st.\n";

        /*
            If the stack tmpst is empty, then it will push the value in tmp
            into stack tmpst.

            If the stack tmpst is not empty, it will compare the top element
            in stack tmpst with the value in tmp.
            If the top element in stack tmpst is larger than the value in tmp,
            it will then push the top element in stack tmpst into stack st.
            This will loops until the top element is smaller or equal to the
            value in tmp or the stack tmpst is empty.
        */
        while (!tmpst.isEmpty())
        {
            cout << "\t\ttmpst: The top element of tmpst = " << tmpst.Top() << endl;
            if (tmpst.Top() > tmp)
            {
                cout << "\t\t\tSince " << tmpst.Top() << ">" << tmp << " , tmpst: Pop out " << tmpst.Top() << " from the stack tmpst.\n";
                cout << "\t\t\tst: Pushing " << tmpst.Top() << " into the stack st.\n";
                st.Push(tmpst.Pop());
            }
            else
            {
                cout << "\t\t\tSince " << tmpst.Top() << "<" << tmp << " , exiting the loop\n";
                break;
            }
        }

        //Then it will push the value in tmp into stack tmpst.
        cout << "\t\ttmpst: Pushing " << tmp << " into stack tmpst.\n\n";
        tmpst.Push(tmp);
    }

    /*
        The stack tmpst will push all its elements into
        st stack until stack tmpst is empty.
    */
    while (!tmpst.isEmpty())
    {
        st.Push(tmpst.Pop());
    }

    cout << "(3) The sorting of stack st ends.\n\n";
    cout << "(4) The sequence of elements in stack st (from bottom to top): ";

    //Displaying the stack st
    st.displayStack();

    cout << endl;
    return 1;
}