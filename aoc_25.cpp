#include <cstdio>
#include <deque>
#define DIM 1475
using namespace std;
struct ceva {
    int x,y,z,t;
};
ceva v[DIM+10];
int f[DIM+10];
deque <ceva> q;
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
int modul (int x){
    if (x<0)
        return -x;
    return x;
}
inline int getnr(){
    int nr=0;
    int semn=1;
    char c;
    c=fgetc (fin);
    while ('0'>c || '9'<c){
        if (c=='-')
            semn=-1;
        c=fgetc (fin);
    }
    while ('0'<=c && c<='9'){
        nr=nr*10+c-'0';
        c=fgetc (fin);
    }
    return nr*semn;
}
void solve (){
    int xc,yc,zc,tc,j;
    while (!q.empty()){
        xc=q.front().x;
        yc=q.front().y;
        zc=q.front().z;
        tc=q.front().t;
        q.pop_front();
        for (j=1;j<=DIM;j++){
            if (!f[j] && modul (v[j].x-xc) + modul (v[j].y-yc) + modul (v[j].z-zc) + modul (v[j].t-tc)<=3){
                f[j]=1;
                q.push_back(v[j]);
            }
        }
    }
}
int main()
{
    int i,sol;
    for (i=1;i<=DIM;i++){
        v[i].x=getnr();
        v[i].y=getnr();
        v[i].z=getnr();
        v[i].t=getnr();
    }
    sol=0;
    for (i=1;i<=DIM;i++){
        if (!f[i]){
            q.push_back(v[i]);
            sol++;
            solve ();
        }
    }
    fprintf (fout,"%d",sol);
    return 0;
}
