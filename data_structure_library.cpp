///////////////////////////////////////////////////////////
//         Generalized Data Structure Library
///////////////////////////////////////////////////////////

/*
__________________________________________________________________________________________________
| Type of Linked List  |    Name of Class for node    |    Name of Class for Functionality        |
|----------------------|------------------------------|-------------------------------------------|
|    Singly Linear     |       SinglyLLLNode          |     SinglyLLL             (Done)          |
|   Singly Circular    |       SinglyCLLNode          |     SinglyCLL             (Done)          |
|    Doubly Linear     |       DoublyLLNode           |     DoublyLLL             (Done)          |
|   Doubly Circular    |       DoublyCLLNode          |     DoublyCLL             (Done)          |
|      Stack           |       StackNode              |     Stack                 (Done)          |
|      Queue           |       QueueNode              |     Queue                 (Done)          |
|____________________ _|______________________________|___________________________________________|

*/

#include<iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////
//          Singly Linear List Using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLNode
{   
    public:
        T data;
        SinglyLLLNode<T> *next;

        SinglyLLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:
        SinglyLLLNode<T>* first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);
        void InsertLast(T);

        void DeleteFirst();
        void DeleteLast();

        void Display();
        int Count();

        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"\n\nObject of Singly Linear Linked List gets created.\n\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLNode<T>* newn = NULL;

    newn = new SinglyLLLNode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       07/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLNode<T>* newn = NULL;
    SinglyLLLNode<T>* temp = NULL;

    newn = new SinglyLLLNode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLNode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLNode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Display
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Displaying the nodes in the sequence of insertion made
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLNode<T>* temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Count
//      Input           :       Data of Node
//      Output          :       iCount
//      Description     :       Counting the number of nodes
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLNode<T>* temp = NULL;
    SinglyLLLNode<T>* newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLNode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Deletion of node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLNode<T>* temp = NULL;
    SinglyLLLNode<T>* target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}


///////////////////////////////////////////////////////////
//          Doubly Linear List Using Generic Approach
///////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>
class DoublyLLLNode
{
    public:
        T data;
        DoublyLLLNode *next;
        DoublyLLLNode *prev;

        DoublyLLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLNode<T> * first;
        int iCount;

    public:
        DoublyLLL();
        

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"\n\nObject of Doubly Linear Linked List gets created\n\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLNode<T> *newn = NULL;
    
    newn = new DoublyLLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    } 
    this->iCount++;
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       07/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLNode<T> *newn = NULL;
    DoublyLLLNode<T> *temp = NULL;
    newn = new DoublyLLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    } 
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Insertion of node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLNode<T> * newn = NULL;
    DoublyLLLNode<T> * temp = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos> this->iCount+1))
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLNode<T>(no);

        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
    
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLNode<T> * temp = NULL;
    temp = this->first;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Deletion of node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLNode<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos> this->iCount))
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp -> next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Display
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Displaying the nodes in the sequence of insertion made
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLNode<T> *temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Count
//      Input           :       Data of Node
//      Output          :       iCount
//      Description     :       Counting the number of nodes
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}



///////////////////////////////////////////////////////////
//       Singly Circular List Using Generic Approach
///////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class SinglyCLLNode
{
    public:
        T data;
        SinglyCLLNode<T>* next;

        SinglyCLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLNode<T>* first;
        SinglyCLLNode<T>* last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();        
};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"\n\nObject of Singly Circular Linked List gets created.\n\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLNode<T>* newn = NULL;
    newn = new SinglyCLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
        newn->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       07/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLNode<T>* newn = NULL;
    newn = new SinglyCLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
        newn->next = this->first;
    }
    else
    {
        this->last->next = newn;
        newn->next = this->first;
        this->last = newn;
    }
    this->iCount++;
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLNode<T>* newn = NULL;
    SinglyCLLNode<T>* temp = NULL;
    int iCnt = 0;

    if(pos<1 || pos>iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;
        newn = new SinglyCLLNode<T>(no);

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLNode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        this->last->next = this->first;
        delete temp;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLNode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next!=this->last)
        {
            temp = temp->next;
        }
        delete temp->next;
        this->last = temp;
        this->last->next= this->first;
    }
    this->iCount--;
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Deletion of node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLNode<T>* temp = NULL;
    SinglyCLLNode<T>* target = NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Display
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Displaying the nodes in the sequence of insertion made
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: Display()
{
    if(this->first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    SinglyCLLNode<T>* temp = this->first;
    
    for(int i = 0; i < iCount; i++)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout<<"\n";
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Count
//      Input           :       Data of Node
//      Output          :       iCount
//      Description     :       Counting the number of nodes
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////
//        Doubly Circular List Using Generic Approach
///////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLNode
{
    public:
        T data;
        DoublyCLLNode<T>* next;
        DoublyCLLNode<T>* prev;

        DoublyCLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLNode<T>* first;
        DoublyCLLNode<T>* last;
        int iCount;

    public:
        DoublyCLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();        
};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"\n\nObject of DoublyCLL gets created.\n\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLNode<T>* newn = NULL;
    newn = new DoublyCLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
        newn->prev = this->last;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
        newn->prev = this->last;
    }

    this->last->next = this->first;
    this->iCount++;
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       07/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLNode<T>* newn = NULL;
    newn = new DoublyCLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
        newn->prev = this->last;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
        this->first->prev = newn;
    }

    this->last->next = this->first;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       InsertAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to insert node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLNode<T>* newn = NULL;
    DoublyCLLNode<T>* temp = NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLNode<T>(no);

        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteFirst
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at first position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLNode<T>* temp = NULL;
    DoublyCLLNode<T>* target = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        target = this->first;
        this->first = this->first->next;
        this->last->next = this->first;
        this->first->prev = this->last;
        delete target;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteLast
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Use to delete node at last position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLNode<T>* temp = NULL;
    DoublyCLLNode<T>* target = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        target = this->last;
        this->last = this->last->prev;
        this->last->next = this->first;
        this->first->prev = this->last;
        delete target;
    }
    this->iCount--;
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       DeleteAtPos
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Deletion of node at a certain position
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLNode<T>* temp = NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(iCnt =1; iCnt<pos-1;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp -> next->prev = temp;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Display
//      Input           :       Data of Node
//      Output          :       Nothing
//      Description     :       Displaying the nodes in the sequence of insertion made
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    if(this->first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    DoublyCLLNode<T>* temp = this->first;
    
    for(int i = 0; i < this->iCount; i++)
    {
        cout << "| " << temp->data << " |<=> ";
        temp = temp->next;
    }
    cout<<"\n";
}
////////////////////////////////////////////////////////////////////////
//
//      Function Name   :       Count
//      Input           :       Data of Node
//      Output          :       iCount
//      Description     :       Counting the number of nodes
//      Author          :       Atharva Samadhan Khairnar
//      Date            :       06/01/2026
//
/////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////
//                      Stack Using Generic Approach
////////////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class StackNode
{
    public: 
    T data;
    StackNode<T>* next;

    StackNode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class Stack
{
    private:
        StackNode<T>* first;
        int iCount;

    public:

        Stack();

        void Push(T);
        T Pop();
        T Peep();
        void Display();
        int Count();

};

template<class T>
Stack<T> :: Stack()
{
    cout<<"\n\nStack gets created successfully...\n\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Stack<T> :: Push(T no)
{
    StackNode<T> *newn = NULL;

    newn = new StackNode<T> (no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template<class T>
T Stack<T> :: Pop()
{
    T Value = 0;
    StackNode<T> * temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Stack is Empty";
        return -1;
    }
    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

template<class T>
T Stack<T> :: Peep()
{
    T Value = 0;
    if(this->first == NULL)
    {
        cout<<"Stack is Empty";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

template<class T>
void Stack<T> :: Display()
{
    StackNode<T> * temp = this->first;
    
    if(this->first == NULL)
    {
        cout<<"Stack is Empty";
        return;
    }

    else
    {
        while(temp != NULL)
        {
            cout<<"|\t"<<temp->data<<"\t|\n";
            temp = temp->next;
        }
    }

}

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////
//                      Queue Using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class QueueNode
{
    public: 
        T data;
        QueueNode<T>* next;

        QueueNode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        QueueNode<T>* first;
        QueueNode<T>* last;
        int iCount;

    public:

        Queue();

        void enqueue(T);
        T dequeue();
        void Display();
        int Count();

};

template<class T>
Queue<T> :: Queue()
{
    cout<<"\n\nQueue gets created successfully...\n\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)
{
    QueueNode<T> *newn = NULL;
    
    newn = new QueueNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;        
    }   

    this->iCount++;
}

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    QueueNode<T> * temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Queue is Empty";
        this->last = NULL;
        return -1;
    }
    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

template<class T>
void Queue<T> :: Display()
{
    QueueNode<T> * temp = this->first;
    
    if(this->first == NULL)
    {
        cout<<"Queue is Empty";
        return;
    }

    else
    {
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-";
            temp = temp->next;
        }
        cout<<"\n";
    }

}

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////// End of Library /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLLL<int> * slllobj = new SinglyLLL<int>();

    int iRet = 0;

    slllobj->InsertFirst(51);
    slllobj->InsertFirst(21);
    slllobj->InsertFirst(11);

    slllobj->Display();

    iRet = slllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    slllobj->InsertLast(101);
    slllobj->InsertLast(111);
    slllobj->InsertLast(121);
    
    slllobj->Display();

    iRet = slllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    slllobj->DeleteFirst();
    slllobj->Display();

    iRet = slllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    slllobj->DeleteLast();

    slllobj->Display();

    iRet = slllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    slllobj->InsertAtPos(105,4);

    slllobj->Display();

    iRet = slllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    slllobj->DeleteAtPos(4);

    slllobj->Display();

    iRet = slllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";


//////////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> * dlllobj = new DoublyLLL<char>();

    dlllobj->InsertFirst('A');
    dlllobj->InsertFirst('B');
    dlllobj->InsertFirst('C');
    
    dlllobj->Display();

    cout<<"Number of elements are: "<<dlllobj->Count()<<"\n";


    dlllobj->InsertLast('X');
    dlllobj->InsertLast('Y');
    dlllobj->InsertLast('Z');
    
    dlllobj->Display();

    cout<<"Number of elements are: "<<dlllobj->Count()<<"\n";
    

    dlllobj->DeleteFirst();
    
    dlllobj->Display();

    cout<<"Number of elements are: "<<dlllobj->Count()<<"\n";


    dlllobj->DeleteLast();
    
    dlllobj->Display();

    cout<<"Number of elements are: "<<dlllobj->Count()<<"\n";
    

    dlllobj->InsertAtPos('$',4);
    
    dlllobj->Display();

    cout<<"Number of elements are: "<<dlllobj->Count()<<"\n";
   
    
    dlllobj->DeleteAtPos(4);
    
    dlllobj->Display();

    cout<<"Number of elements are: "<<dlllobj->Count()<<"\n";
 
    
////////////////////////////////////////////////////////////////
    
    SinglyCLL<double> * scllobj = new SinglyCLL<double>();

    iRet = 0;

    scllobj->InsertFirst(51.51);
    scllobj->InsertFirst(21.21);
    scllobj->InsertFirst(11.11);

    scllobj->Display();

    iRet = scllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    scllobj->InsertLast(101.101);
    scllobj->InsertLast(111.111);
    scllobj->InsertLast(121.121);
    
    scllobj->Display();

    iRet = scllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    scllobj->DeleteFirst();
    scllobj->Display();

    iRet = scllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    scllobj->DeleteLast();

    scllobj->Display();

    iRet = scllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    scllobj->InsertAtPos(105.105,4);

    scllobj->Display();

    iRet = scllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    scllobj->DeleteAtPos(4);

    scllobj->Display();

    iRet = scllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    

/////////////////////////////////////////////////////////////////////////////

    DoublyCLL<double> * dcllobj = new DoublyCLL<double>();

    dcllobj->InsertFirst(51.14599694114632);
    dcllobj->InsertFirst(21.24894941456239);
    dcllobj->InsertFirst(11.64496463258641);

    dcllobj->Display();

    iRet = dcllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    dcllobj->InsertLast(101.64919365971345);
    dcllobj->InsertLast(111.48464948493468);
    dcllobj->InsertLast(121.56616141879643);
    
    dcllobj->Display();

    iRet = dcllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    dcllobj->DeleteFirst();
    dcllobj->Display();

    iRet = dcllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    dcllobj->DeleteLast();

    dcllobj->Display();

    iRet = dcllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    dcllobj->InsertAtPos(105.314652874655,4);

    dcllobj->Display();

    iRet = dcllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    dcllobj->DeleteAtPos(4);

    dcllobj->Display();

    iRet = dcllobj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
/////////////////////////////////////////////////////////////////////////////
    Stack<char> *sobj = new Stack<char>();

    sobj->Push('a');
    sobj->Push('b');
    sobj->Push('c');
    sobj->Push('d');

    sobj->Display();
    cout<<"Number of elements in stack are: "<<sobj->Count()<<"\n";

    
    cout<<"Return Value of Peep is: "<<sobj->Peep()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are: "<<sobj->Count()<<"\n";

    
    cout<<"Poped Element is: "<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"Poped Element is: "<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are: "<<sobj->Count()<<"\n";


    sobj->Push('e');
    sobj->Display();
    cout<<"Number of elements in stack are: "<<sobj->Count()<<"\n";


/////////////////////////////////////////////////////////////////////////////
    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout<<"Number of elements in Queue are: "<<qobj->Count()<<"\n";

    
    cout<<"Removed Element is: "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are: "<<qobj->Count()<<"\n";

    cout<<"Removed Element is: "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are: "<<qobj->Count()<<"\n";


    qobj->enqueue(121.56789);
    qobj->Display();
    cout<<"Number of elements in Queue are: "<<qobj->Count()<<"\n";

/////////////////////////////////////////////////////////////////////////////

    delete scllobj;
    delete slllobj;
    delete dlllobj;
    delete dcllobj;
    delete sobj;
    delete qobj;

/////////////////////////////////////////////////////////////////////////////

    return 0;
}