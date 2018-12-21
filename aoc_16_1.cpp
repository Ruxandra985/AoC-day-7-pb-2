#include <cstdio>
#define DIM 791
#define DIM2 898
using namespace std;
FILE *fin=fopen ("a.in","r");
FILE *fout=fopen ("a.out","w");
int v[5],t[5],w[5],op;
int code[18][18],actual_code[18];
int getnr(){
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
int check (int f[]){
    //printf ("a");
    for (int i=1;i<=4;i++)
        if (f[i]!=t[i])
            return 0;

    return 1;
}
int addr(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=f[w[3]+1]+f[w[2]+1];
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][1]++;
        return 1;
    }
    return 0;
}
int addi(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=w[3]+f[w[2]+1];
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][2]++;
        return 1;
    }
    return 0;
}
int mulr(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=f[w[3]+1]*f[w[2]+1];
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][3]++;
        return 1;
    }
    return 0;
}
int muli(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=w[3]*f[w[2]+1];
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][4]++;
        return 1;
    }
    return 0;
}
int banr(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(f[w[3]+1]&f[w[2]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][5]++;
        return 1;
    }
    return 0;
}
int bani(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(w[3]&f[w[2]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][6]++;
        return 1;
    }
    return 0;
}
int borr(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(f[w[3]+1]|f[w[2]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][7]++;
        return 1;
    }
    return 0;
}
int bori(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(w[3]|f[w[2]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][8]++;
        return 1;
    }
    return 0;
}
int setr(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=f[w[2]+1];
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][9]++;
        return 1;
    }
    return 0;
}
int seti(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=w[2];
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][10]++;
        return 1;
    }
    return 0;
}
int gtir(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(w[2]>f[w[3]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][11]++;
        return 1;
    }
    return 0;
}
int gtri(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(f[w[2]+1]>w[3]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][12]++;
        return 1;
    }
    return 0;
}
int gtrr(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(f[w[2]+1]>f[w[3]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][13]++;
        return 1;
    }
    return 0;
}
int eqir(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(w[2]==f[w[3]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][14]++;
        return 1;
    }
    return 0;
}
int eqri(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(f[w[2]+1]==w[3]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][15]++;
        return 1;
    }
    return 0;
}
int eqrr(){
    int f[5];
    f[1]=v[1];
    f[2]=v[2];
    f[3]=v[3];
    f[4]=v[4];
    f[w[4]+1]=(f[w[3]+1]==f[w[2]+1]);
    if (op){
        v[1]=f[1]; v[2]=f[2]; v[3]=f[3]; v[4]=f[4];
        return 0;
    }
    if (check (f)){
        code[w[1]+1][16]++;
        return 1;
    }
    return 0;
}

int main()
{

    int i,j,sol,maxi,poz,ok=0;
    for (i=1;i<=DIM;i++){

        for (j=1;j<=4;j++)
            v[j]=getnr();
        for (j=1;j<=4;j++)
            w[j]=getnr();
        for (j=1;j<=4;j++)
            t[j]=getnr();
        sol=addr()+addi()+mulr()+muli()+banr()+bani()+borr()+bori()+setr()+seti()+gtir()+gtri()+gtrr()+eqir()+eqri()+eqrr();
        if (sol>=3){
            ok++;
        }
    }
    fprintf (fout,"%d",ok);
    int treated =0;
    int st=0;
    /*for (i=1;i<=16;i++){
        for (j=1;j<=16;j++)
            printf ("%d ",code[i][j]);
        printf ("\n");
    }*/
    /*while (treated < 16){
       // printf ("%d ",treated);
        for (i=1;i<=16;i++){
            maxi=0;
            poz=0;

            for (j=1;j<=16;j++){
                //printf ("%d ",code[i][j]);
                if (maxi<code[i][j]){
                    maxi=code[i][j];
                    poz=j;
                    st=0;
                }
                else if (maxi==code[i][j])
                    st=1;
            }
            if (st==0 && actual_code[i]==0){ /// o sg posibilitate
                for (j=1;j<=16;j++)
                    code[j][poz]=0; /// nu mai poate fi asta
                actual_code[i]=poz;
                treated++;
                //printf ("%d %d\n",i,actual_code[i]);
                //printf ("%d %d\n",i,poz);
            }
            //printf ("\n");
        }
    }
    //actual_code[1]=14;
    for (i=1;i<=16;i++)
        printf ("%d %d\n",i,actual_code[i]);
    op=1;
    v[1]=v[2]=v[3]=v[4]=0;
    for (i=1;i<=DIM2;i++){
        for (j=1;j<=4;j++)
            w[j]=getnr();
        w[1]++;
        //if (v[1]==9)
        //printf ("%d ",v[1]);
        //printf ("%d %d\n",w[1],actual_code[w[1]]);
        if (actual_code[w[1]]==1)
            addi();
        else if (actual_code[w[1]]==2)
            addr();
        else if (actual_code[w[1]]==3)
            mulr();
        else if (actual_code[w[1]]==4)
            muli();
        else if (actual_code[w[1]]==5)
            banr();
        else if (actual_code[w[1]]==6)
            bani();
        else if (actual_code[w[1]]==7)
            borr();
        else if (actual_code[w[1]]==8)
            bori();
        else if (actual_code[w[1]]==9)
            setr();
        else if (actual_code[w[1]]==10)
            seti();
        else if (actual_code[w[1]]==11)
            gtir();
        else if (actual_code[w[1]]==12)
            gtri();
        else if (actual_code[w[1]]==13)
            gtrr();
        else if (actual_code[w[1]]==14)
            eqir();
        else if (actual_code[w[1]]==15)
            eqri();
        else if (actual_code[w[1]]==16)
            eqrr();
        //printf ("%d %d %d %d\n",v[1],v[2],v[3],v[4]);

    }
    fprintf (fout,"%d",v[1]);*/
    return 0;
}
