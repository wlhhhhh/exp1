#include <iostream>
#include <string>

using namespace std;

//定义结点模板
struct DblNode
{
    //数据成员
    DblNode* last;
    DblNode* next;
    string data;
    int Linenumber;
    DblNode();
};

DblNode::DblNode()
{
    last = next = NULL;
    Linenumber = 0;
}

class Linklist
{
protected:
    DblNode* head;
    DblNode* tail;
    DblNode* curr;
    int currline;
public:
    Linklist();
    ~Linklist();
    bool Display();
    bool Tofirstline();
    bool Toend();
    bool Tolastline();
    bool Tonextline();
    bool Topointedline(int linenumber);
    bool Insert(int linenumber,string newline);
    bool Delete(int linenumber);
    bool ReplaceLine(string S,int linenumber);
    int Getline(int linenumber);
};

Linklist::Linklist()
{
    head=tail=curr=new DblNode();
    Linenumber=0;
    if(!head)
        cout<<"错误！"<<endl;
}

Linklist::~Linklist()
{
}

bool Linklist::Display()
{
    if(Linenumber==0)
        return false;
    DblNode* temp = head->next;
    while(temp)
    {
        cout<<temp->Linenumber<<":"<<temp->data<<endl;
        temp=temp->next;
    }
    return true;
}

bool Linklist::Tofirstline()
{
    if(Linenumber==0)
        return false;
    curr = head->next;
    return true;
}

bool Linklist::Toend()
{
    if(Linenumber==0)
        return false;
    curr = tail;
    return true;
}

bool Linklist::Tolastline()
{
    if(Linenumber==0)
        return false;
    if(curr->last==head)
        return false;
    curr = curr->last;
    return true;
}

bool Linklist::Tonextline()
{
    if(Linenumber==0)
        return false;
    if(!curr->next)
        return false;
    curr = curr->next;
    return true;
}

bool Linklist::Topointedline(int linenumber)
{
    if(Linenumber==0)
        return false;
    if(linenumber<1||linenumber>Linenumber)
        return false;
    DblNode* temp = head;
    for(int i=0;i<linenumber;i++)
        temp = temp->next;
    curr = temp;
    return true;
}

bool Linklist::Insert(int linenumber,string newline)
{
    if(Linenumber==0)
        return false;
    if(linenumber<1||linenumber>Linenumber)
        return false;
    DblNode* tmpLine,*nextLine,*newLine;
    tmpLine = Getline(linenumber-1);
    nextLine = tmpLine->next;
    newLine = new DblNode(newline,tmpLine,nextLine,linenumber-1);
    tmpLine->next = newLine;
    nextLine->last = newLine;
    return true;
}

bool Linklist::Delete(int linenumber)
{
    if(Linenumber==0)
        return false;
    if(linenumber<1||linenumber>Linenumber)
        return false;
    DblNode* tmpLine;
    tmpLine = Getline(linenumber);
    tmpLine->last->next = tmpLine->next;
    tmpLine->next->last = tmpLine->last;
    delete tmpLine;
    return true;
}

bool Linklist::ReplaceLine(string S,int linenumber)
{
    if(Linenumber==0)
        return false;
    if(linenumber<1||linenumber>Linenumber)
        return false;
    DblNode * temp = Getline(linenumber);
    temp->data = S;
}

int Linklist::Getline(int linenumber)
{
    DblNode* tmpLine = head;
    int curLine = 0;
    while(tmpLine!= NULL&&curLine<linenumber)
    {
        tmpLine = tmpLine->next;
        curLine++;
    }
    if(tmpLine!=NULL&&curLine==linenumber)
    {
        return tmpLine;
    }
    else
    {
        return -1;
    }
}
