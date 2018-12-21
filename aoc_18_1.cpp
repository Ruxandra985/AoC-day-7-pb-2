#include <cstdio>
#define DIMI 50
#define DIMJ 50
using namespace std;
int di[]={-1,1,0,0,-1,-1,1,1};
int dj[]={0,0,-1,1,1,-1,1,-1};
int a[1001][100][100],b[100][100];
struct staare{
    int x,y,z;
};
staare stare[100000];
int change (int i,int j,int val,int k){
    int d,iv,jv,lib,cop,dep;
    lib=cop=dep=0;
    for (d=0;d<8;d++){
        iv=i+di[d];
        jv=j+dj[d];
        if (iv>0 && jv>0 && iv<=DIMI && jv<=DIMJ){
            if (a[k-1][iv][jv]==0)
                lib++;
            else if (a[k-1][iv][jv]==1)
                cop++;
            else dep++;
        }
    }
    if (val==0){
        if (cop>=3)
            return 1;
        return 0;
    }
    else if (val==1){
        if (dep>=3)
            return 1;
        return 0;
    }
    else {
        if (dep>=1 && cop>=1)
            return 0;
        return 1;
    }
}
int egal (int x,int y){
    int i,j;
    for (i=1;i<=DIMI;i++){
        for (j=1;j<=DIMJ;j++){
            if (a[x][i][j]!=a[y][i][j])
                return 0;
        }
    }
    return 1;
}
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int i,j,cop,dep,st=0,gol,ciclu,inc,k;
    char c;
    for (i=1;i<=DIMI;i++){
        for (j=1;j<=DIMJ;j++){
            c=fgetc (fin);
            if (c=='.')
                a[0][i][j]=0; ///gol
            else if (c=='|')
                a[0][i][j]=1; /// copac
            else a[0][i][j]=2; /// depozit
        }
        fgetc (fin);
    }
    for (k=1;k<=10;k++){
        /// build w
        for (i=1;i<=DIMI;i++){
            for (j=1;j<=DIMJ;j++){
                if (a[k-1][i][j]==0){
                    if (change(i,j,0,k))
                        b[i][j]=1;
                    else b[i][j]=0;
                }
                else if (a[k-1][i][j]==1){
                    if (change (i,j,1,k))
                        b[i][j]=2;
                    else b[i][j]=1;
                }
                else if (a[k-1][i][j]==2){
                    if (change(i,j,2,k))
                        b[i][j]=0;
                    else b[i][j]=2;
                }

            }
        }
        //printf ("\n");
        for (i=1;i<=DIMI;i++){
            for (j=1;j<=DIMJ;j++){
                a[k][i][j]=b[i][j];
                //printf ("%d ",a[i][j]);
            }
            //printf ("\n");
        }
        /*for (i=0;i<k;i++){
            if (egal(i,k)){
                //printf ("a");
                st=1;
                inc=i; /// 0..i-1
                ciclu=k-i; /// i..k
                break;
            }
        }*/
        //if (st)
          // break;
    }
    //int x=(1000000000-416)%28;
    //if (x==0)
      //x=1000000000;
    //printf ("%d ",x);
    //printf ("%d %d",inc,ciclu);
    cop=dep=0;
    for (i=1;i<=DIMI;i++){
        for (j=1;j<=DIMJ;j++){
            cop+=(a[10][i][j]==1);
            dep+=(a[10][i][j]==2);
        }
    }
    fprintf (fout,"%d",cop*dep);
    return 0;
}
