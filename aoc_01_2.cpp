#include <cstdio>
#define DIM 976
using namespace std;
int f[10000000],f2[1000000],v[1000];
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int x,s,i;
    for (i=1;i<=DIM;i++)
        fscanf (fin,"%d",&v[i]);
    s=0;
    f[0]=1;
    for (i=1;1;i++){
        if (i>DIM)
            i=1;
        s+=v[i];
        if (s>=0){
            if (f[s])
                break;
            f[s]=1;
        }
        else{
            if (f2[-s])
                break;
            f2[-s]=1;
        }
    }
    fprintf (fout,"%d",s);
    return 0;
}
