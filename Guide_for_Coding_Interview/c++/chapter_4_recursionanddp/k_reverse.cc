#include <iostream>
#include <stack>
using namespace std;

typedef struct _ListNode
{
    int       value;
    _ListNode* next;
}ListNode;

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->value = value;
    pNode->next = NULL;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode)
{
    if(pNode == NULL)
    {
        cout<< "The node is NULL"<< endl;
    }
    else
    {
        cout<< "The key in node is "<<pNode->value<<endl;
    }
}

void PrintList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        cout<<pNode->value;
        if(pNode->next != NULL)
            cout<<"->";
        pNode = pNode->next;
    }
    cout<<endl;
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

ListNode* resign1(stack<ListNode*>&stack_node, ListNode* left, ListNode* right) {
    ListNode* cur = stack_node.top();
    if (left != NULL) {
        left->next = cur;
    }
    stack_node.pop();

    ListNode* next = NULL;
    while (!stack_node.empty()) {
        next = stack_node.top();
        stack_node.pop();
        cur->next = next;
        cur = next;
    }

    cur->next = right;
    return cur;
}
ListNode* reverseKNodes1(ListNode* head, int k) {
       if (k < 2) {
           return head;
       }

       stack<ListNode*> stack_node;
       ListNode* new_head = head;
       ListNode* cur = head;
       ListNode* pre = NULL;
       ListNode* next = NULL;
       while (cur != NULL) {
           next = cur->next;
           stack_node.push(cur);
           if (stack_node.size() == k) {
               pre = resign1(stack_node, pre, next);
               new_head = new_head == head ? cur : new_head;
           }
           cur = next;
       }
       return new_head;
}

int main(int argc, char** argv) {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);
    ListNode* pNode8 = CreateListNode(8);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* output = reverseKNodes1(pNode1, k);

    PrintList(output);

    DestroyList(output);

    return 0;
}




