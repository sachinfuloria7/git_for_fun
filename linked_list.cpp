/*
1. reverse a linked list.
2. print a linked list.
3. remove duplicates from a linked list.
4. merge two sorted linked list.
5. reverse a linked list recursively.
6. middle of a linked list.
7. find the intersection point of two linked list.
8. fold a linked list.
9. check if a linked list is a palindrome.
10. find the sum of two linked list.(store the sum as a new linked list).
11. reverse a linked list in k groups.
*/
#include<bits/stdc++.h>
using namespace std;
class ll
{
	public:
		int data;
		ll *next;
	ll (int x)	
	{
		data=x;
		next=NULL;
	}
};
ll *reverse(ll *head)
{
   ll *curr=head;
   ll *prev=NULL;
   while(curr != NULL)
   {
   	ll *next=curr->next;
   	curr->next=prev;
   	prev=curr;
	
   	curr=next;
   }
   return prev;
}
void print(ll *head)
{
	ll *temp=head;
	while(temp !=  NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL";
	cout<<endl;
}
ll *removeDuplicates(ll *root)
{
	 // your code	 goes here
	ll *newhead=new ll(root->data);
	ll* t1=newhead;
	ll *t=root;
	while(t != NULL)
	{
		
		if(t1->data != t->data)
		{
			t1->next=new ll(t->data);
			t1=t1->next;
			t=t->next;
		}
		else
		{
			t=t->next;
			
		}
	}
	return newhead;
}

ll* sortedMerge(ll* a, ll* b)  
{  
    ll *fh=NULL;
	ll *final =NULL;
	if(a->data <= b->data)
	{
		final=new ll(a->data);
		a=a->next;
	}
	else
	{
		final=new ll(b->data);
		b=b->next;
	}
	fh=final;
	while (a != NULL && b != NULL)
	{
		/* code */
		if(a->data <= b->data)
		{
			final->next=new ll(a->data); 
			//if(a->next != NULL)
			final=final->next;	
			a=a->next;
		}
		else{
			final->next=new ll(b->data);
			//if(b->next != NULL)
			final=final->next;
			b=b->next;
		}
	}
	while(a != NULL)
	{
		//final=final->next;
		final->next=new ll(a->data);
		final=final->next;
		a=a->next;
	}
	while (b!=NULL)
	{
		/* code */
		final->next=new ll(b->data);
		final=final->next;
		b=b->next;
	}
	
	return fh;
}
ll *printrec(ll *head)
{
if(head == NULL || head->next == NULL)
return head;
ll *rest_head=printrec(head->next);
ll *rest_tail=head->next;
rest_tail->next=head;
head->next=NULL;
return rest_head;
}
ll *print2(ll *curr,ll *prev)
{
	if(curr == NULL)
	{
	return prev;
	}
	ll *next=curr->next; 
	curr->next=prev;
	return print2(next,curr);
}
	//	 5 10 15 40 -1  2 3 20 -1
ll *middle(ll *head)
	{
		int count=0;
	ll *temp=head;
	while (temp != NULL)
	{
		/* code */
		count++;
		temp=temp->next;
	}
	temp=head;
	if(count %2 == 0)
	{
		for(int i=0;i<count/2;i++)
		temp=temp->next;
	}
	else
	{
		for(int i=0;i<=(count)/2;i++)
		temp=temp->next;
	}
	return temp;
	}
void delete_node(ll *head,int val)
{
	if(head == NULL)
	return head;
	ll *curr=head;
	while(curr != nullptr)
	{
		
	}

}
// int intersectPoint(ll* a, ll* b)
// {
//     // Your Code Here
//     	ll *t=a;
//         ll *t1=b;
//         int s1=0,s2=0;
//         if(a == NULL || b == NULL)
//             return NULL;
//         while(t != NULL)
//         {
//             s1++;
//             t=t->next;
//         }
// 		cout<<"size 1 is "<<s1<<endl;
//         while(t1 != NULL)
//         {
//             s2++;
//             t1=t1->next;
//         }
// 		cout<<"size 2 is "<<s2<<endl;
//         t=a;
//         t1=b;
//       if(s1 == s2)
//       {
//         while(t != NULL)
//         {
//             if(t- == t1)
//             {
// 				cout<<"breaking pont is "<<t->data<<endl;
//                 return t->data;
//             }
//             t=t->next;
//             t1=t1->next;
//       }
// 	  }
//         if(s1 > s2)
//         {
//             int d=s1-s2+1;
//             while(d--)
//             {
//                 t=t->next;
//             }
// 			cout<<t->data<<endl;
//             while(t != NULL)
//             {
//                 if(t == t1)
//                 {
// 				cout<<"breaking pont is (s1>s2) "<<t->data<<endl;
//                     return t->data;
//                 }
//                 t=t->next;
//                 t1=t1->next;
//             }
//         }
//         else if( s2 > s1)
//         {
//             int d=s2-s1;
//             while(d--)
//                 t1=t1->next;
//         while(t != NULL)
//         {
//             if(t == t1)
//             {
// 				cout<<"breaking pont is (s2>s1) "<<t->data<<endl;
//                 return t->data;
//             }
//             t=t->next;
//             t1=t1->next;
//         }
//         }
//         return -1;
//       }
// bool isPalindrome(ll *head)
// {
// 	ll *temp=head;
// 	int count=0;
// 	while(temp != NULL)
// 	{
// 		count++;
// 		temp=temp->next;
// 	}
// 	temp=head;
// 	//cout<<"no of lls are "<<count<<endl;
// 	if(count % 2 == 0)
// 	{
// 		for(int i=1;i<count/2;i++)
// 		temp=temp->next;
// 	//	cout<<" temp is "<<temp->data<<endl;
// 		ll *mid=temp;
// 		ll *prev=NULL;
// 		ll *curr=mid->next;
// 		//cout<<"curr is "<<curr->data<<endl;
// 		while(curr != NULL)
// 		{
// 			ll *nn=curr->next;
// 			curr->next=prev;
// 			prev=curr;
// 			curr=nn;
// 		}
// 	temp->next=prev;
// 	temp=head;
// 	while(prev != NULL)
// 	{
// 		if(prev->data != temp->data)
// 		{
// 		//cout<<"breaking point is "<<prev->data<<endl;
// 		return false;
// 		}
// 		prev=prev->next;
// 		temp=temp->next;
// 	}
// 	print(temp);
// 	return true;
// 	}
// 	else
// 	{
// 	print(head);
// 		for(int i=1;i<=count/2;i++)
// 		temp=temp->next;
// 		//cout<<" temp is "<<temp->data<<endl;
// 		ll *mid=temp;
// 		ll *prev=NULL;
// 		ll *curr=mid->next;
// 		while(curr != NULL)
// 		{
// 			ll *nn=curr->next;
// 			curr->next=prev;
// 			prev=curr;
// 			curr=nn;
// 		}
// 		temp->next=prev;
// 	print(head);
// 	temp=head;
// 	while(prev != NULL)
// 	{
// 		if(prev->data != temp->data)
// 		return false;
// 		prev=prev->next;
// 		temp=temp->next;
// 	}
// 	return true;
// 	}
// }
 ll* addTwoLists(ll* a, ll* b)
{
    // code here
    int fa=0,fa2=0;
    while(a != NULL)
    {
        fa=fa*10+a->data;
        a=a->next;
    }
    while(b != NULL)
    {
        fa2=fa2*10+b->data;
        b=b->next;
    }
    int res=fa+fa2;
    cout<<"sum is "<<res<<endl;
    ll *final=new ll(res%10);
    res=res/10;
    ll *fh=final;
    while(res != 0)
    {
        final->next=new ll(res%10);
        res=res/10;
        final=final->next; 
    }
    ll *prev=NULL;
    ll *curr=fh;
    while(curr != NULL)
    {
        ll *temp=curr->next; 
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
	return prev;
}
//ll* k_reverse(ll *head ,int k)
void delete(ll *node,int val)
{
	// 1 2 3 2 2 4 5 -1
	if(node == nullptr)
	node=nullptr;
	else
	{
		if(node->next == NULL)
		{
			if(node->data == val)
			{
				node=nullptr;
			//	return node;
			}
		}
		else
		{
			
			ll *temp=node;
			while(temp->next != nullptr)
			{
				
			}
		}
	}
}
int main()
{
	// 17 15 8 9 2 4 6 -1
	int data;	
	cin>>data;
	ll *head=new ll(data);
	ll *temp=head;
	 while(1)
	{ 
		cin>>data;
		if(data == -1)
			break;
		else
		{
			temp->next=new ll(data);
			temp=temp->next;
		}
	}
	// int data1;
	// cin>>data1;
	// ll *head2=new ll(data1);
	// ll *temp2=head2;
	//  while(1)
	// { 
	// 	cin>>data;
	// 	if(data == -1)
	// 		break;
	// 	else
	// 	{
	// 		temp2->next=new ll(data);
	// 		temp2=temp2->next;
	// 	}
	// }
	// print(head);
	// print(head2);
	// ll *fh=addTwoLists(head,head2);
    // print(fh);
	print(head);
	int k;
	cin>>k;
	ll *fh=k_reverse(head,k);
	print(fh);
	//print(head);
	//cout<<isPalindrome(head);
	//cout<<intersectPoint(head,head2);

}