#include <cstdio>
#include <iostream>
#include <deque>
#include <algorithm>

#define DIM 1685
using namespace std;
int a[3000][3000];
deque <pair <int,int> > dq;
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
int getnr(){
    int nr=0;
    char c;
    c=fgetc (fin);
    while ('0'>c || c>'9')
        c=fgetc (fin);
    while ('0'<=c && c<='9'){
        nr=nr*10+c-'0';
        c=fgetc (fin);
    }
    return nr;
}
int main()
{
    int minx,miny,maxx,maxy,i,x,y1,y2,y,x1,x2,j,apa,cx,cy,st,dr,ok;
    char c;
    minx=miny=2000000000;
    maxx=maxy=0;
    for (i=1;i<=DIM;i++){
        c=fgetc (fin);
        if (c=='x'){
            x=getnr();
            y1=getnr();
            y2=getnr();

            minx=min(minx,x);
            maxx=max(maxx,x);
            miny=min(miny,min(y1,y2));
            maxy=max(maxy,max(y1,y2));
            for (j=y1;j<=y2;j++)
                a[x][j]=1; /// clei
        }
        else {
            y=getnr();
            x1=getnr();
            x2=getnr();

            miny=min(miny,y);
            maxy=max(maxy,y);
            minx=min(minx,min(x1,x2));
            maxx=max(maxx,max(x1,x2));
            for (j=x1;j<=x2;j++)
                a[j][y]=1; /// clei
        }
    }
    cx=500;
    cy=0;
    apa=ok=0;
    while (1){
        if (ok){
            cx=500;
            cy=0;
            ok=0;
        }
        while (a[cx][cy+1]==0 && cy+1<=maxy)
            cy++;
        if (cy==maxy){ /// curge la inf
            ok=1;
            apa++;
            a[cx][cy]=-1; /// nu suntem siguri ca duce undeva
        }
        else if (cy<miny) /// nu a mai ajuns nicaieri ok
            break;
        if (!a[cx-1][cy]){
            while (!a[cx-1][cy] && a[cx][cy+1]>0) /// ducem in stanga
                cx--;
        }
        else if (!a[cx+1][cy]){
            while (!a[cx+1][cy] && a[cx][cy+1]>0) /// ducem in dreapta
                cx++;
        }
        if (a[cx][cy+1]){ /// nu mai avem support
            ok=1;
            if (a[cx][cy+1]<0 || a[cx+1][cy]<0 || a[cx-1][cy]<0){ /// nu suntem sg de vecini
                a[cx][cy]=-1;
                st=cx;
                while (a[st-1][cy]==2){ /// undo
                    a[st-1][cy]=-1;
                    st--;
                }
                dr=cx;
                while (a[dr+1][cy]==2){ /// undo
                    a[dr+1][cy]=-1;
                    dr++;
                }
            }
            else a[cx][cy]=2;
            apa++;
        }
    }
    /*for (i=minx;i<=maxx;i++){
        for (j=miny;j<=maxy;j++){
            if (a[i][j]!=-1)
                printf (" ");
            printf ("%d ",a[i][j]);
        }
        printf ("\n");
    }*/
    apa=0;
    for (i=minx;i<=maxx;i++)
        for (j=miny;j<=maxy;j++)
            apa+=(a[i][j]==2);
    fprintf (fout,"%d",apa);
    return 0;
}
