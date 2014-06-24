#include <iostream>
#include <list>
using namespace std;

struct Rect
{
    short llx;
    short lly;
    short urx;
    short ury;
    short c;
    int GetSize();
};

inline int Rect::GetSize()
{ return int(urx-llx)*int(ury-lly);}

list<Rect> rlist;

int color[2501]={0};

bool Divide(const Rect& a, const Rect& b)
{
    if ( (a.llx>=b.urx || b.llx>=a.urx) || ( a.lly>=b.ury || b.lly>=a.ury ) )
        return false;
    //x方向切割
    int interx1, interx2;
    if ( b.llx>a.llx && b.urx>a.urx )
    {
        interx1=b.llx;
        interx2=a.urx;
    }
    else if ( b.llx<a.llx && b.urx<a.urx )
    {
        interx1=a.llx;
        interx2=b.urx;
    }
    else if ( b.llx>=a.llx && b.urx<=a.urx )
    {
        interx1=b.llx;
        interx2=b.urx;
    }
    else 
    {
        interx1=a.llx;
        interx2=a.urx;
    }
    Rect newr;
    if ( a.llx<interx1 )
    {
        newr.llx=a.llx;
        newr.urx=interx1;
        newr.lly=a.lly;
        newr.ury=a.ury;
        newr.c=a.c;
        rlist.push_back(newr);
    }
    if ( interx2<a.urx )
    {
        newr.llx=interx2;
        newr.urx=a.urx;
        newr.lly=a.lly;
        newr.ury=a.ury;
        newr.c=a.c;
        rlist.push_back(newr);
    }
    //y方向切割
    int intery1, intery2;
    if ( b.lly>a.lly && b.ury>a.ury )
    {
        intery1=b.lly;
        intery2=a.ury;
    }
    else if ( b.lly<a.lly && b.ury<a.ury )
    {
        intery1=a.lly;
        intery2=b.ury;
    }
    else if ( b.lly>=a.lly && b.ury<=a.ury )
    {
        intery1=b.lly;
        intery2=b.ury;
    }
    else 
    {
        intery1=a.lly;
        intery2=a.ury;
    }
    if ( a.lly<intery1 )
    {
        newr.lly=a.lly;
        newr.ury=intery1;
        newr.llx=interx1;
        newr.urx=interx2;
        newr.c=a.c;
        rlist.push_back(newr);
    }
    if ( intery2<a.ury )
    {
        newr.lly=intery2;
        newr.ury=a.ury;
        newr.llx=interx1;
        newr.urx=interx2;
        newr.c=a.c;
        rlist.push_back(newr);
    }
    return true;
}

int main (int argc, char* argv[])
{
    Rect r;
    int n;
    while (cin>>r.urx>>r.ury>>n)
    {
        r.llx=0; r.lly=0;
        r.c=1;
        rlist.clear();
        rlist.push_back(r);
        memset(color, 0, sizeof(color));
        int i;
        short big=1;
       list<Rect>::iterator iter;
        for ( i=0; i<n; ++i )
        {
           cin>>r.llx>>r.lly>>r.urx>>r.ury>>r.c;
            if ( big<r.c )
                big=r.c;
            iter=rlist.begin();
            for ( ; ; )
            {
                if ( iter==rlist.end() )
                    break;
                if ( Divide(*iter, r) )
                    rlist.erase(iter++);
                else
                    ++iter;
            }
            rlist.push_back(r);
        }
        for ( iter=rlist.begin(); iter!=rlist.end(); ++iter )
            color[iter->c]+=iter->GetSize();

        for ( int i=1; i<=big; ++i )
            if ( color[i] )
               cout<<i<<' '<<color[i]<<'\n';
    }
    return 0;
}