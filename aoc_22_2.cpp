#include <cstdio>
#include <deque>
#define INF 2000000000

using namespace std;
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
int lt,ct,depth;
int a[5000][5000];
int d[4000][4000][3],f[4000][4000][3];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
struct incoada{
    int l,c,ut;
};
deque <incoada> dq;
int compatibil (int u,int tip){
    if (tip==0 && u!=0)
        return 1;
    else if (tip==1 && u!=1)
        return 1;
    else if (tip==2 && u!=2)
        return 1;
    return 0;
}
inline int getnr(){
    int nr=0;
    char c;
    c=fgetc (fin);
    while ('0'>c || '9'<c)
        c=fgetc (fin);
    while ('0'<=c && c<='9'){
        nr=nr*10+c-'0';
        c=fgetc (fin);
    }
    return nr;
}
int findd (int x,int y){
    if (x==0 && y==0)
        return 0;
    else if (x==ct && y==lt)
        return 0;
    else if (x==0){
        return y*48271;
    }
    else if (y==0){
        return x*16807;
    }
    else return a[y-1][x]*a[y][x-1]; /// in a sunt erosion lvl
}
void bellman_ish (){
    int ic,jc,u,iv,jv,dir,ou;
    incoada p;
    while (!dq.empty()){
        ic=dq.front().l;
        jc=dq.front().c;
        u=dq.front().ut;
        if (ic==1 && jc==1 && u==1)
            printf ("a");
        f[ic][jc][u]=0;
        dq.pop_front();
        for (dir=0;dir<4;dir++){
            iv=ic+di[dir];
            jv=jc+dj[dir];
            if (iv>=0 && jv>=0 && iv<=depth && jv<=depth){
                if (compatibil(u,a[iv][jv])){
                    if (d[iv][jv][u]>d[ic][jc][u]+1){
                        d[iv][jv][u]=d[ic][jc][u]+1;
                        if (!f[iv][jv][u]){
                            p.l=iv;
                            p.c=jv;
                            p.ut=u;
                            dq.push_back(p);
                            f[iv][jv][u]=1;
                        }
                    }
                }
            }
        }
        if (a[ic][jc]==0){
            if (u==1)
                ou=2;
            else ou=1;
        }
        else if (a[ic][jc]==1){
            if (u==0)
                ou=2;
            else ou=0;
        }
        else{
            if (u==0)
                ou=1;
            else ou=0;
        }
        if (d[ic][jc][ou]>d[ic][jc][u]+7){
            d[ic][jc][ou]=d[ic][jc][u]+7;
            if (!f[ic][jc][ou]){
                p.l=ic;
                p.c=jc;
                p.ut=ou;
                dq.push_back(p);
                f[ic][jc][ou]=1;
            }
        }
    }
}
int main()
{
    int i,j,gi;
    incoada p;
    depth=getnr();
    ct=getnr();
    lt=getnr();
    for (i=0;i<=depth;i++){
        for (j=0;j<=depth;j++){
            gi=findd(j,i);
            a[i][j]=(gi+depth)%20183;
            d[i][j][0]=d[i][j][1]=d[i][j][2]=INF;
        }
    }
    for (i=0;i<=depth;i++){
        for (j=0;j<=depth;j++)
            a[i][j]%=3;
    }
    f[0][0][1]=1;
    d[0][0][1]=0;
    p.l=0;
    p.c=0;
    p.ut=1;
    dq.push_back(p);
    bellman_ish();
    fprintf (fout,"%d",d[lt][ct][1]);
    return 0;
}
