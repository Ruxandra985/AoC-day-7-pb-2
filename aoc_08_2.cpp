#include <cstdio>
#define DIM 17655
using namespace std;
int poz,s;
int v[1000000],value[1000000];
int vec[20000][10000];
int unod=1;
void rec (int nod){
    int i,elem,fii;
    //if(nod==2)
      //  printf ("a");
    if (v[poz]==0){
        s=0;
        for (i=1;i<=v[poz+1];i++)
            s+=v[poz+1+i];
        value[nod]=s;
        poz=poz+1+v[poz+1]+1;
        return;
    }
    elem=v[poz+1];
    fii=v[poz];
    poz+=2;
    for (i=1;i<=fii;i++){
        unod++;
        vec[nod][++vec[nod][0]]=unod;
        rec(unod);
    }
    for (i=1;i<=elem;i++){
        if (v[poz+i-1]>vec[nod][0])
            continue;
        value[nod]+=value[vec[nod][v[poz+i-1]]];
        //s+=v[poz+i-1];
    }
    poz=poz+elem;
}
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,n,x;
    s=0;
    n=0;
    while (fscanf (fin,"%d",&x)==1){
        v[++n]=x;
    }
    //printf ("%d",n);
    //for (i=1;i<=DIM;i++){
      //  fscanf (fin,"%d",&v[i]);
    //}
    poz=1;
    rec(1);
    s=0;
    for (i=1;i<=n;i++){
        s+=value[i];
    }
    fprintf (fout,"%d",value[1]);
    return 0;
}
