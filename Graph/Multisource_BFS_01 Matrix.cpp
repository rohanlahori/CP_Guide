int multisourcebfs(queue<pair<int,int>>q,vector<vector<int>> &mark,int n,int m,vector<vector<int>> &vis1)
{
    vector<int>xx({0,1,0,-1}),yy({1,0,-1,0});
    int cnt=-1;
    while(q.size()!=0)
    {
        cnt++;
        queue<pair<int,int>>q1;
        while(q.size()!=0)
        {
            int x=q.front().first;
            int y=q.front().second;
            vis1[x][y]=1;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(x+xx[i]>=0 && y+yy[i]>=0 && x+xx[i]<n && y+yy[i]<m && vis1[x+xx[i]][y+yy[i]]==0)
                {
                    vis1[x+xx[i]][y+yy[i]]=1;
                    q1.push(make_pair(x+xx[i],y+yy[i]));
                }
            }
        }
        while(q1.size()!=0)
        {
            q.push(q1.front());
            q1.pop();
        }
    }
    return cnt;
}
