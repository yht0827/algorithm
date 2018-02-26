#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int F, S, G, U, D;

int stair[10000000];
bool visited[1000000];
queue<int> Q;

void bfs()
{
    while(!Q.empty())
    {
        int curr=Q.front();
        Q.pop();
        if(curr==G)
            return;
        if(U+curr<=F && !visited[curr+U])
        {
            stair[curr + U] = stair[curr] + 1;
            Q.push(curr + U);
            visited[curr + U] = true;
        }
        
        if (curr-D>=1 && !visited[curr-D])
        {
            stair[curr - D] = stair[curr] + 1;
            Q.push(curr - D);
            visited[curr - D] = true;
        }
    }
}
int main()
{
    cin>>F>>S>>G>>U>>D;
    memset(visited, false, sizeof(visited));
    memset(stair, 0, sizeof(stair));
    if (S == G)
    {
        printf("%d\n",0);
        return 0;
    }
    

    visited[S]=true;
    stair[S]=0;
    Q.push(S);
    
    bfs();
    if(!visited[G])
        cout<<"use the stairs"<<endl;
    else
        cout<<stair[G]<<endl;
}
