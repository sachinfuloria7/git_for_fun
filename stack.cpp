#include<bits/stdc++.h>
using namespace std;
bool ispar(string s)
    {
        // Your code here
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
            st.push(s[i]);
            cout<<"pushed element is "<<st.top()<<endl;
        }
            if(s[i] == ')')
            {
                if(st.top() == '(')
                st.pop();
                else
                
                {
                cout<<"breaking point is (1)"<<st.top()<<endl;
                return false;
                }
            }
            if(s[i] == '}')
            {
                if(st.top() == '{')
                st.pop();
                else
                {
                cout<<"breaking point is (1)"<<st.top()<<endl;
                return false;
            }
            }
            if(s[i] == ']')
            {
                if(st.top() == '[')
                st.pop();
                else
                {
                cout<<"breaking point is (1)"<<st.top()<<endl;

                return false;
            }
            }
            }
            if(st.size() == 0)
            return true;
            else
            return false;
    }
void 
int evaluate_postfix(string s)
{
    int res=0;
    stack<int> st;
    for(int i=0;i<s.size();i++)
    {
        int a=0,b=0;
        if(s[i] !='+'  && s[i] != '-' && s[i] != '*' && s[i] !='/')
        st.push(s[i]-48);
        else
        {
             if(s[i] == '+')
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                res =  b + a;
            
            }
              if(s[i] == '-')
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                res = b - a;
            }
              if(s[i] == '*')
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                res =  b * a;
            }
              if(s[i] == '/')
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                res = b / a;
            }
            st.push(res);
        }
}
            return res;
}
void nextLargerElement(int *a, int n)
{
    stack<int> st;
    vector<int> fa;
    if(n == 1)
    {
        fa.push_back(-1);
    }
    st.push(a[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        int temp=st.top();
        while(temp <= a[i] && st.size()>0)
        st.pop();
        if(st.size() == 0)
        fa.insert(fa.begin(),-1); ]
        
        else
        fa.insert(fa.begin(),st.top()); 
        st.push(a[i]);
    }
     fa.push_back(-1);  
     for(auto x:fa)
     cout<<x<<" ";
     cout<<endl;
}
void stock_span(int a[],int n)              
{
  stack<int> st;
    st.push(0);
    vector<int> fa(n,0);
    fa[0]=1;
    for(int i=1;i<=n-1;i++)
    {
        while(a[st.top()] <= a[i] && st.size()>0)
            st.pop();
        if(st.size() == 0)
        fa[i]=i+1;
        else
        fa[i]=(i-st.top());
        st.push(i);
    }
    for(auto x:fa)
    cout<<x<<"  ";
}
void nge_right(int a[],int n)
{
    stack<int> st;
    st.push(0);
    int fa[n];
    for(int i=1;i<n;i++)
    {
        if(a[i] > a[st.top()])
        {
            fa[st.top()]=a[i];
            st.pop();
            while(st.size()>0 && a[i] > a[st.top()])
            {
                fa[st.top()]=a[i];
                st.pop();
            }
        }
        if(i != n-1)
        {
        st.push(i);
        }
    }
    while(st.size()>0)
    {   
        fa[st.top()]=-1;
        st.pop();
    }
    fa[n-1]=-1;
    for(int x:fa)
    cout<<x<<" ";
    cout<<endl; 
}
int getMaxArea(int a[], int n)
{
     stack<int> left,right;
    int le[n],re[n];
    left.push(0);
    le[0]=0;
    for(int i=1;i<n;i++)
    {
        while(left.size() > 0  && a[i] <= a[left.top()])
        left.pop(); 
        if(left.size() == 0)
        le[i]=i;
        else
        le[i]=i-left.top()-1;
        left.push(i);
    }
    right.push(n-1);
    re[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
    while(right.size() > 0 && a[i] <= a[right.top()])
    right.pop();
    if(right.size() == 0)
    re[i]=(n-1-i);
    else
    re[i]=right.top()-i-1;
    right.push(i);
    }
    // cout<<"left"<<endl;
    // for(auto x:le)
    // cout<<x<<" ";
    // cout<<endl;
    // cout<<"right"<<endl;
    // for(auto x:re)
    // cout<<x<<" ";
    // cout<<endl;
        int  ans=0;
for(int i=0;i<n;i++)
{
    ans=max(ans,((le[i]+re[i]+1)*a[i]));
}
return ans;
}
int main()
{
 string s;
 cin>>s;
 cout<<ispar(s);
 }
 