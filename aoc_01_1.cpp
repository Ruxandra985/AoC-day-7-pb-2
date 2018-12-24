#include <cstdio>
#define DIM 976
using namespace std;

int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int x,s,i;
    s=0;
    for (i=1;i<=DIM;i++){
        fscanf (fin,"%d",&x);
        s+=x;
    }
    fprintf (fout,"%d",s);
    return 0;
}
