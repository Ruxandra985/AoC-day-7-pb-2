#include <cstdio>
#define DIM 50000
using namespace std;
int compatibil (char x,char y){
    if ((x-'a'+'A'==y) || (y-'a'+'A'==x))
        return 1;
    return 0;
}
char v[DIM+10],w[DIM+10];
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,elem;
    for (i=1;i<=DIM;i++)
        v[i]=fgetc (fin);
    elem=0;
    for (i=1;i<=DIM;i++){
        if (elem && compatibil (v[i],w[elem]))
            elem--;
        else w[++elem]=v[i];
    }
    fprintf (fout,"%d",elem);
    return 0;
}
