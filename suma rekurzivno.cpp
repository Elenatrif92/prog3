#include <iostream>
#include <vector>
using namespace std;

void segmentno_drvosum(int niza[],int index,int left,int right,vector<int>v)
{
    if(left==right)
    {
        v[index]=niza[left];
    }
    int middle=(right+left)/2;
    segmentno_drvosum(niza,index*2,left,middle,v);
    segmentno_drvosum(niza,index*2+1,middle+1,right,v);
    v[index]=v[index*2]+v[index*2+1];
}


int sum(int index,int left,int right,int a,int b,vector<int>v)
{
    if(a>b)
    {
        return 0;
    }
    if(a==left&&b==right)
    {
        return v[index];
    }
    int middle=(right+left)/2;
    return sum(index*2,left,min(middle,b),a,middle,v)+sum(index*2+1,max(b,middle),right,middle+1,b,v);
}
void updatesum(int index,int left,int right,int org,int val,vector<int>v)
{
    if(right==left)
    {
        v[index]=val;
    }
    int middle=(left+right)/2;
    if(middle<=left)
    {
        updatesum(index*2,left,middle,org,val,v);
    }
    else
    {
        updatesum(index*2+1,middle+1,right,org,val,v);
    }
    v[index]=v[index*2]+v[index*2+1];
}

int main(){
    ////
}