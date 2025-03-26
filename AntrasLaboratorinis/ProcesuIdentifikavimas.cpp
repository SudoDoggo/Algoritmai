#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    set<int> nextPID;
    nextPID.insert(1);
    int n;
    int cNr=1;
    map<int, int> process;
    cin>>n;
    char temp;
    int pos;
    for (int i = 0; i <n; i++)
    {
        cin>>temp;
        if(temp=='C')
        {
            if(nextPID.size()==1)
            {
                process[cNr]=*nextPID.begin();
                cout<<*nextPID.begin()<<endl;
                nextPID.insert(*nextPID.begin()+1);
                nextPID.erase(nextPID.begin());
            }
            if(nextPID.size()>1)
            {
                process[cNr]=*nextPID.begin();
                cout<<*nextPID.begin()<<endl;
                nextPID.erase(nextPID.begin());
            }
            cNr++;
        }
        else if(temp=='T')
        {
            cin>>pos;
            nextPID.insert(process[pos]);
        }
    }
    
}