#include "SortedLinkedList.h"

/***** Complete this class. *****/
SortedLinkedList::SortedLinkedList() : head(nullptr)
{

}

SortedLinkedList::~SortedLinkedList() {
    Node *next;

    //cout << endl << "Delete linked list:" << endl;

    // Loop to deallocate each node in the list.
    for (Node *ptr = head; ptr != nullptr; ptr = next)
    {
        next = ptr->next;
        delete ptr;
    }

    head = nullptr;

}

Node *SortedLinkedList::getHead() const {
    return head;
}

void SortedLinkedList::insert(Node *node)
{
    //check if list is empty. If yes then insert in first position
    if(head == nullptr)
    {
        head = node;
    }
        //Enter before first node
    else if(!(*node>*head))
    {
        node->next=head;
        head=node;
    }
    //enter anywhere else
    else
    {
        Node *tempNodeptr = head;
        Node *prevNodeptr;


        while((tempNodeptr!= nullptr)&&(*node > *tempNodeptr))
        {
            prevNodeptr=tempNodeptr;
            tempNodeptr=tempNodeptr->next;
        }
        prevNodeptr->next=node;
        node->next=tempNodeptr;
    }
}

ostream &operator<<(ostream &outs, const SortedLinkedList &list)
{
    int line = 0;      // current line
    int position = 0;  // current position in the current line

    // Loop over the nodes in the list.
    // Each time through the loop, ptr points to the next node.
    for(Node *temp=list.getHead();temp!= nullptr;temp=temp->next)
    {
        if(line!=temp->getRow())
        {
            position = 0;

            do
            {
                cout << endl;  // output a blank line
                line++;
            } while (line < temp->getRow());
        }

        if(position<=temp->getCol())
        {
           while(position< temp->getCol()){
               cout<<" ";
               position++;
           }

            cout<<*temp;
            position++;

            if(temp->getName().length()>0)
            {
                position+=temp->getName().length()+temp->getState().length()+1;
            }
        }
    }
    return outs;
}
