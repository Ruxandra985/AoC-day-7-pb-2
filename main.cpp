#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>
#define DIM 101
#define NRE 5

using namespace std;
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
vector <int> v[30];
int grad[30],f[30],poz[30],tata[30],e[10],a[30][30],disp[30],used[30];
pair <int,int> sol[30];
int w[300];
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
void getstep (int &x,int &y){
    char c;
    fgetc (fin);
    c=fgetc (fin);
    while ('A'>c || 'Z'<c)
        c=fgetc (fin);
    x=c-'A'+1;
    c=fgetc (fin);
    while ('A'>c || 'Z'<c)
        c=fgetc (fin);
    y=c-'A'+1;
    while (c!='\n')
        c=fgetc (fin);
}
int cmp (int x,int y){
    return x>y;
}

int main()
{

    int i,x,y,vecin,elem=0,ord,ok,mini,j,e2,p,k;
    //printf ("a");
    for (i=1;i<=DIM;i++){
        getstep(x,y);
        v[x].push_back(y);
        //printf ("%c %c\n",x-1+'A',y-1+'A');
        grad[y]++;
        f[x]=f[y]=1;
    }
    e2=0;
    ord=0;
    for (i=1;i<='Z'-'A'+1;i++){
        if (grad[i]==0 && f[i]) // i nu trb sa se afle dupa niciun alt nod NEAPARAT
            disp[++e2]=i;
        if (f[i])
            ord++;
    }

    sort (disp+1,disp+e2+1,cmp);
    e[1]=e[2]=e[3]=e[4]=e[5]=0;
    ok=0;
    i=0;
    while (i<ord){
        sort (disp+1,disp+e2+1,cmp);
        mini=1000;
        for (j=1;j<=NRE;j++)
            if (e[j]<mini && e[j]){
                mini=e[j];
            }
        if (mini==1000){ /// toate 0
            mini=0;
        }
        ok+=mini;
        p=0;
        for (j=1;j<=NRE;j++){
            if (e[j])
                e[j]-=mini;
            if (e[j]==0){
                for (k=0;k<v[poz[j]].size();k++){
                    vecin=v[poz[j]][k];
                    grad[vecin]--;
                    if (grad[vecin]==0)
                        used[++p]=vecin;
                }
                poz[j]=0;
            }
        }
        for (j=1;j<=p;j++)
            disp[++e2]=used[j];
        sort (disp+1,disp+e2+1,cmp);
        for (j=1;j<=NRE;j++)
            if (e[j]==0 && e2){
                e[j]=disp[e2]+60;
                poz[j]=disp[e2];
                e2--;
                i++;
            }

    }
    for (j=1;j<=NRE;j++) ///SCHIMBA 6
        ok+=e[j];
    fprintf (fout,"%d",ok);
    return 0;
}
