#include <iostream>
#include <fstream>
#include <ctime>
#include<stdlib.h>
#include<time.h>
using namespace std;
/// Without inclusion of Exceptions.
struct link
{
    int data;
    link* prev;
    link* next;
};

class linklist
{

private :
    link* head;
    link* tail;

public :
    linklist()
    {
        head = NULL;
        tail = NULL;
    }
    link* Gettail();
    link* GetHead();
    void setdata(link* a, int b);
    int Getdata(link* a);
    void addtoTail(int);
    void addtoHead(int);
    void display();
};
void linklist::setdata(link* a, int b)
{
    a->data = b;
}

int linklist::Getdata(link* a)
{
    return a->data;
}

void linklist::addtoTail(int a)
{
    link* newlink = new link();
    if(tail == NULL)
    {
        newlink->data = a;
        newlink->prev = NULL;
        newlink->next = NULL;
        tail = head = newlink;
    }
    else
    {
        newlink->data = a;
        newlink->prev = NULL;
        newlink->next = tail;
        tail->prev = newlink;
        tail = newlink;
    }
}
link* linklist::Gettail()
{
    return tail;
}
link* linklist::GetHead()
{
    return head;
}
void linklist::addtoHead(int a)
{
    link* newlink = new link;
    if(newlink == NULL)
        cout << "Newlink is NULL" << endl;
    if(tail == NULL)
    {
        newlink->data = a;
        newlink->prev = NULL;
        newlink->next = NULL;
        tail = newlink;
        head = newlink;
    }
    else
    {
        newlink->data = a;
        newlink->prev = head;
        newlink->next = NULL;
        head->next = newlink;
        head = newlink;
    }
}

void linklist::display()
{
    link* temp;
    if(head == tail)
    {
        cout << head->data << endl;
    }
    else
    {
        //cout << endl;
        for(temp = head; temp!=NULL; temp = temp->prev)
        {
            cout  << temp->data ;
        }
    }
}

linklist* multiply(linklist* a, int p)
{
    link* temp = new link;
    link* temp1 = new link;
    temp = a->Gettail();
    int carry = 0;
    int carry1 = 0;
    int k = 1;
    while(temp!= NULL || carry != 0)
    {
        if(temp == NULL && carry!=0){
            while(carry>0)
            {
                k = carry%10;
                a->addtoHead(k);
                carry = carry/10;
            }
        }
        else
        {
            carry = ((a->Getdata(temp))*p+carry1)/10;
            a->setdata(temp,((a->Getdata(temp))*p+carry1)%10);
            carry1 = carry;
            temp = temp->next;
        }
    }
      return a;
}

linklist* numtolist(long n)
{
    linklist* kk = new linklist();
    long j = 0;
    long p = n;
    if(n == 0)
    {
        kk->addtoHead(0);
    }
    while(p>0)
    {
        j = p%10;
        kk->addtoHead(j);
        p = p/10;
    }
    return kk;
}

linklist* factorial(linklist* a, int n)
{
    linklist* temp1 = new linklist();
    temp1->addtoHead(1);
    linklist* temp0 = new linklist();
    temp0->addtoHead(0);
    linklist* fact = new linklist();
    fact->addtoHead(1);
    if(n == 0 || n == 1)
        return temp1;
    else
    {
        for(int i = 2; i<= n; i++)
        {
            fact = multiply(fact,i);
        }
    }
    return fact;
}
int pow(int a, int b){
    if(a == 0)
        return 0;
    if(a==1)
        return 1;
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    return a*pow(a,b-1);
}

int length(char* A)
{
    int i = 0;
    for( i = 0; *(A+i)!='\0';i++){}
    return i;
}
int main()
{
    int x;
    //ifstream input("input.txt");
    int t;
    cin >> t;
    //t = argv[1];
    while(t--){
    //cout << "Enter the number : " ;
    cin >> x;
    //cout << "\nThe factorial is :";
    linklist* temp1 = new linklist();
    temp1 = factorial(numtolist(x),x);
    temp1->display();
    link* temp = new link;
    temp = temp1->Gettail();
    int cnt = 0;
   /* while(temp->data == 0){
        cnt++;
        temp = temp->next;
        }
    cout << endl;*/
    //cout << "The number of end zeros is : " << cnt << endl;
   cout << endl;
    }
    return 0;
}
