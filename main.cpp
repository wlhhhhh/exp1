#include <iostream>
#include "Editor1.h"
#include "Linklist.h"
#include "string.h"

using namespace std;

int main()
{
    Editor * A= new Editor();
    cout<<"If you don't know how to operate,please tap h or H"<<endl;
    char a;
    cin >> a;
    if(a=='h'||a=='H')
        A->command_note();
    char b;
    do
    {
    cout<<"Enter the command:"<<endl;
    cin>>b;
    A->command_go(b);
    }while('b'!='q');
    return 0;
}
