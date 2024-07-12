#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
    node(int data, node *next)
    {
        this->data = data;
        this->next = next;
    }
};
node *vec2LL(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
//Optimal Solution
//We will use two pointer approach
//We will take two pointers fast and slow
//We will move the fast pointer n times
//Then we will move both the pointers until the fast pointer reaches the end
node* deleteMiddle(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    node* fast = head->next->next;
    node* slow = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    node* Node = slow->next;
    slow->next = slow->next->next;
    delete Node;
    return head;
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    node* head = vec2LL(arr);
    head = deleteMiddle(head);
    print(head);
    return 0;
}
