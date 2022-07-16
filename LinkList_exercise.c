//leetcode反转指针

//1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//反转指针
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode* n1 = NULL,*n2 = head,*n3 = n2->next;
    while(n2 != NULL)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n2->next;
    }
    return n1;
}


//2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//头插法(取原链表的结点,头插到新链表)
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* newHead = NULL;
    while(cur!=NULL)
    {
        struct ListNode* next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;
}














//链表的中间结点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head,*fast = head;
    while(fast != NULL&& fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}











//合并两个有序链表

//1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//从头开始，取两个链表中小的那个尾插到新链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    struct ListNode* head = NULL,*tail = NULL;
    //先取一个做头
    if(list1->val < list2->val)
    {
        head = tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = tail = list2;
        list2 = list2->next;
    }

    while(list1 != NULL && list2!= NULL)
    {
        if(list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if(list1)
        tail->next = list1;
    if(list2)
        tail->next = list2;
    return head;
}





//2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//从头开始，取两个链表中小的那个尾插到新链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    struct ListNode* head = NULL,*tail = NULL;
    //哨兵位
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));

    while(list1 != NULL && list2!= NULL)
    {
        if(list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if(list1)
        tail->next = list1;
    if(list2)
        tail->next = list2;
    struct ListNode* first = head->next;
    free(head);
    return first;
}



