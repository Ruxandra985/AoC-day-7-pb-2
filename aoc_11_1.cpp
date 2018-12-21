#include <cstdio>
#include <iostream>

using namespace std;
int a[400][400];
int main()
{
    FILE *fin=fopen ("a.in","r");
    FILE *fout=fopen ("a.out","w");
    int n,i,j,rack,power,x,y,smax,xs,ys,siz;
    fscanf (fin,"%d",&n);
    for (i=1;i<=300;i++){
        for (j=1;j<=300;j++){
            x=j;
            y=i;
            rack=x+10;
            power=rack*y+n;
            power*=rack;
            //printf ("%d\n",power);
            a[i][j]=(power/100)%10-5;
        }
    }
    for (i=1;i<=300;i++)
        for (j=1;j<=300;j++)
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    //printf ("%d ",a[153][101]);
    smax=-100000;
    for (i=1;i<=300;i++){
        for (j=1;j<=300;j++){
            int l=3;
                if (i+l-1>300 || j+l-1>300)
                    continue;
                if (smax<a[i+l-1][j+l-1]-a[i+l-1][j-1]-a[i-1][j+l-1]+a[i-1][j-1]){
                    smax=a[i+l-1][j+l-1]-a[i+l-1][j-1]-a[i-1][j+l-1]+a[i-1][j-1];
                    xs=j;
                    ys=i;
                    siz=l;
                }
        }
    }
    fprintf (fout,"%d,%d",xs,ys);
    return 0;
}
