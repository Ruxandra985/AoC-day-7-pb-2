#include <cstdio>
#include <algorithm>
#define DIMI 150
#define DIMJ 150
using namespace std;
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int cart;
struct carrt{
    int x,y,dir,in,poz;
};
carrt c[10000];
char a[1000][1000];
int f[1000];
int stari[4][3]={ {3,0,1} ,{0,1,2} , {1,2,3}, {2,3,0}};
void check (int &p,int &q){
    int i,j;
    for (i=1;i<cart;i++){
        for (j=i+1;j<=cart;j++){
            if (f[c[i].poz]+f[c[j].poz]==0 && c[i].x==c[j].x && c[i].y==c[j].y){
                f[c[i].poz]=f[c[j].poz]=1;
                p=c[i].x;
                q=c[i].y;
            }
        }
    }
}
int cmp (carrt p, carrt q){
    if (p.x!=q.x)
        return p.x<q.x;
    return p.y<q.y;
}
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,j,px,py,new_dir,p,q,lib;
    cart=0;
    for (i=1;i<=DIMI;i++){
        for (j=1;j<=DIMJ;j++){
            a[i][j]=fgetc (fin);
            //if (i==3 && j==3)
              //  printf ("%c",a[i][j]);
            if (a[i][j]==' ')
                a[i][j]=0;
            if (a[i][j]=='\n'){
                a[i][j]=0;
                break;
            }
            if (a[i][j]=='^'){
                cart++;
                c[cart].x=i;
                c[cart].y=j;
                c[cart].dir=0;
                c[cart].in=0;
                c[cart].poz=cart;
            }
            else if (a[i][j]=='>'){
                cart++;
                c[cart].x=i;
                c[cart].y=j;
                c[cart].dir=1;
                c[cart].in=0;
                c[cart].poz=cart;
            }
            else if (a[i][j]=='v'){
                cart++;
                c[cart].x=i;
                c[cart].y=j;
                c[cart].dir=2;
                c[cart].in=0;
                c[cart].poz=cart;
            }
            else if (a[i][j]=='<'){
                cart++;
                c[cart].x=i;
                c[cart].y=j;
                c[cart].dir=3;
                c[cart].in=0;
                c[cart].poz=cart;
            }
        }
        if (j>DIMJ)
            fgetc (fin);
    }
    int op=0;
    //printf ("%d ",cart);
    sort (c+1,c+cart+1,cmp);
    while (1){
        op++;
        for (i=1;i<=cart;i++){
            if (f[c[i].poz]==1)
                continue;
            //if (i==9)
              //  printf ("a");
            px=c[i].x;
            py=c[i].y;
            //if (op==14)
           // printf ("%d %d\n",px,py);
            if (a[px][py]=='+'){
                new_dir=stari[c[i].dir][c[i].in];
                c[i].dir=new_dir;
                c[i].in++;
                c[i].in%=3;
            }
            else if (a[px][py]=='/')
                if (c[i].dir==0 || c[i].dir==2)
                    c[i].dir++;
                else
                    c[i].dir--;

            else if (a[px][py]==92){
                if (c[i].dir==3 || c[i].dir==1)
                    c[i].dir=(c[i].dir+1)%4;
                else c[i].dir=(c[i].dir-1+4)%4;
            }
            c[i].x=c[i].x+di[c[i].dir];
            c[i].y=c[i].y+dj[c[i].dir];
            check(p,q);
        }
        sort (c+1,c+cart+1,cmp);
        check(p,q);
        lib=0;
        for (i=1;i<=cart;i++)
            if (f[i]==0)
                lib++;
        if (lib==1)
            break;
    }
    for (i=1;i<=cart;i++){
        if (f[c[i].poz]==0)
            fprintf (fout,"%d,%d",c[i].y-1,c[i].x-1);
    }
    return 0;
}
