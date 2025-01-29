
#include <iostream>
#include <vector>

using namespace std;
void segmentno_drvomin(int niza[],int index,int left,int right,vector<int>vec)
{
    if(left==right)
    {
        vec[index]=niza[left];
    }
    int middle=(left+right)/2;
    segmentno_drvomin(niza,index*2,left,middle,vec);
    segmentno_drvomin(niza,index*2+1,middle+1,right,vec);
    vec[index]=min(vec[index*2],vec[index*2+1]);
}
int minn(int index,int left,int right,int a,int b,vector<int>vec)
{
    if(a>b)
    {
        return 0;
    }
    if(a==left&&b==right)
    {
        return vec[index];
    }
    int middle=(left+right)/2;
    int x=minn(index*2,left,min(middle,b),a,middle,vec);
    int y=minn(index*2+1,max(a,middle+1),right,middle+1,b,vec);
    return min(x,y);
}
void updatemin(int index,int left,int right,int org,int val,vector<int>vec)
{
    if(right==left)
    {
        vec[index]=val;
    }
    int middle=(left+right)/2;
    if(middle<=left)
    {
        updatemin(index*2,left,middle,org,val,vec);
    }
    else
    {
        updatemin(index*2+1,middle+1,right,org,val,vec);
    }
    vec[index]=min(vec[index*2],vec[index*2+1]);
}
int main()
{
    /////////

    return 0;
}