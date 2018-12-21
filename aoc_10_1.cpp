#include <cstdio>
#include <iostream>
#define DIM 365
#include <algorithm>
#define MOM 10620
using namespace std;
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
struct punct{
    int x,y;
    int mx,my;
};
int a[301][301];
punct v[DIM+10],w[DIM+10];
int getnr(){
    char c;
    int nr=0,semn=1;
    c=fgetc (fin);
    while ('0'>c || c>'9'){
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
int cmp (punct a,punct b){
    if (a.y!=b.y)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int i,minx,miny,j,maxx,maxy,pa,k;
    for (i=1;i<=DIM;i++){
        v[i].x=getnr();
        v[i].y=getnr();
        v[i].mx=getnr();
        v[i].my=getnr();
    }
    for (i=1;i<=10700;i++){
        minx=miny=2000000000;
        for (j=1;j<=DIM;j++){
            v[j].x+=v[j].mx;
            v[j].y+=v[j].my;
        }
        for (j=1;j<=DIM;j++){
            minx=min(minx,v[j].x);
            miny=min(miny,v[j].y);
        }
        maxx=maxy=0;
        //miniix=miniiy=2000000000;
        for (j=1;j<=DIM;j++){
            w[j].x=v[j].x-minx;
            w[j].y=v[j].y-miny;
            maxx=max(maxx,w[j].x);
            maxy=max(maxy,w[j].y);
        }
        //if (maxx<minx)
          //  printf ("a");
        //printf ("%d %d\n",maxx,maxy); /// 10620
        if (i==MOM-1){ //maxx-minx<210 && maxy-miny<210
            sort (w+1,w+DIM+1,cmp);
            //for (j=1;j<=DIM;j++){
              //  if (j!=1 && w[j-1].y-w[j].y>1)
                //    printf ("a");
            //}
            pa=-1;
            for (j=1;j<=DIM;j++){
                if (j!=1 && w[j-1].y!=w[j].y){
                    fprintf (fout,"\n");
                    //for (k=w[j-1].y;k<w[j].y-1;k++){
                      //  fprintf (fout,"\n");
                    //}
                    //fprintf (fout,"\n");
                    pa=-1;
                }
                for (k=pa+1;k<w[j].x;k++)
                    fprintf (fout," ");
                if (j==1 || w[j].x!=w[j-1].x)
                    fprintf (fout,"#");
                //printf ("%d %d\n",w[j].y,w[j].x);
                //a[w[j].y][w[j].x]=1;
                pa=w[j].x;
                //if (pa==maxx)
                  //  fprintf (fout,"\n");
                //fprintf (fout,"%d %d\n",w[j].x,w[j].y);
            }
            /*for (j=1;j<=DIM;j++){
                //printf ("%d %d\n",w[i].x,w[i].y);
                a[w[j].x][w[j].y]=1;
            }*/
            for (i=0;i<=200;i++){
                for (j=0;j<=200;j++){
                    if (a[i][j])
                        fprintf (fout,"#");
                    else fprintf (fout," ");
                }
                fprintf (fout,"\n");
            }
            return 0;
        }
        //printf("\n\n\n\n\n");
    }
    return 0;
}
