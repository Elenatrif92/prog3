
#include <iostream>
#include <vector>
using namespace std;
void segmentno_drvomax(int niza[],int index,int left,int right,vector<int>vec)
{
    if(left==right)
    {
        vec[index]=niza[left];
    }
    int middle=(left+right)/2;
    segmentno_drvomax(niza,index*2,left,middle,vec);
    segmentno_drvomax(niza,index*2+1,middle+1,right,vec);
    vec[index]=max(vec[index*2],vec[index*2+1]);
    
}
int maxx(int index,int left,int right,int a,int b,vector<int>vec)
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
    int x=maxx(index*2,left,min(middle,b),a,middle,vec);
    int y=maxx(index*2+1,max(middle+1,a),right,middle+1,b,vec);
    return max(x,y);
}
void updatemax(int index,int left,int right,int org,int val,vector<int>vec)
{
    if(right==left)
    {
        vec[index]=val;
    }
    int middle=(left+right)/2;
    if(middle<=left)
    {
        updatemax(index*2,left,middle,org,val,vec);
    }
    else
    {
        updatemax(index*2+1,middle+1,right,org,val,vec);
    }
    vec[index]=(vec[index*2],vec[index*2+1]);
}

int main()
{
    /////////

    return 0;
}