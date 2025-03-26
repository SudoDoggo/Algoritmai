#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> mapas;
    int n;
    long long suma=0;
    string temp;
    string cord1;
    string cord2;
    int x;
    int prevX;
    int y;
    int prevY;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mapas.clear();
        cin>>temp;
        y=0;
        x=0;
        prevX=0;
        prevY=0;
        suma=0;
        for (int i = 0; i < temp.size(); i++)
        {
            prevX=x;
            prevY=y;
            if(temp[i]=='N')
                y+=1;
            else if(temp[i]=='S')
                y-=1;
            else if(temp[i]=='E')
                x+=1;
            else if(temp[i]=='W')
                x-=1;
            cord1=to_string(prevY)+' '+to_string(prevX)+' '+to_string(y)+' '+to_string(x);
            cord2=to_string(y)+' '+to_string(x)+' '+to_string(prevY)+' '+to_string(prevX);
            if(mapas[cord1]==1||mapas[cord2]==1)
                suma+=1;
            else if (mapas[cord1]==0||mapas[cord2]==0)
            {
                mapas[cord1]=1;
                mapas[cord2]=1;
                suma+=5;
            }
            //cout<<cord<<" "<<suma<<endl;
        }
        cout<<suma<<endl;
    }
    
    return 0;
}
