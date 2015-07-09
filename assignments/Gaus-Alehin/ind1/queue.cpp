#include "queue.h"

/*
queue::queue(QObject *parent) : QObject(parent)
{

}
*/

void queue::addPrior(MyListData x)
{   ListNode* p=new ListNode;
    p->data=x;
    p->next=NULL;
    if(first){
        ListNode* q=first;
        if (q->next){
            while(q->next)
                if(p->data.priority<q->next->data.priority)
                    q=q->next;
            p->next=q->next;
            q->next=p;
        }
        else{
            if(p->data.priority > first->data.priority){
                first->next=p;
            }
            else{
                p->next=first;
                first=p;
            }
        }

    }
    else {
        first=new ListNode;
        first->next=NULL;
        first->data=x;
    }
}
/*
ostream & operator<<(ostream & os, queue const & d)
{
    for(int i=0; i<d.count(); i++)
        os<<d.getItem(i)<<" ";
    return os;
}

istream &queue::operator>>(istream &is, queue &d)
{   int v,pr;
    is>>v>>pr;
    MyListData n;
    n.value=v;
    n.priority=pr;
    d.addPrior(n);
    return is;
}
*/

/*
queue &queue::operator<<(MyListData const &x)
{
    queue q=this;
    q.addPrior(x);
    return q;
}
queue &queue::operator>>(MyListData &x)
{
    queue q=this;
    x=q.remMostPr();
    return q;
}
*/
queue queue::operator+(queue &A)
{
    queue q=A;
    MyListData d;
    for(int i=0; i<count();i++){
        d=getItem(i);
        q.addPrior(d);
    }
    return q;
}

MyListData queue::getMostPr()
{
    if(first){
        ListNode *q=first;
        if(q->next){
            while(q->next->next)
                q=q->next;
            MyListData inf=q->next->data;
            return inf;}
        else {
            MyListData inf=q->data;
            return inf;
        }
    }
    else throw "no elements";
}

MyListData queue::remMostPr()
{
    return removeLast();
}

bool queue::is_empty()
{
    if(first==NULL)return true;
    else return false;
}




