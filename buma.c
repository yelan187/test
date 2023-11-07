#include<stdio.h>
#include<math.h>
int f=1;
int decode(int a[] ,int n){
    int result=0;
    if(a[1]==1){
        int b[n+1];
        //负数求原码
        for (int i=2;i<=n;i++) {
            b[i]=!a[i];
        }
        b[n]++;
        for (int i=n;i>=2;i--){
            if(b[i]==2) {b[i]=0;b[i-1]++;}
        }
        for (int i=2;i<=n;i++) {
            result+=b[i]*(int)pow(2,n-i);
        }
        result=-result;
    }
    if(a[1]==0){
        for (int i=2;i<=n;i++) {
            result+=a[i]*(int)pow(2,n-i);
        }
    }
    return result;
}
void dayin(int a[],int n){
    printf("%d = ",decode(a,n));
    for (int j=1;j<=n;j++) {printf("%d",a[j]);if(j%4==0 && j!=n) printf(" ");}
    return;
}
void solve(int a[],int x,int where,int p,int n){
    if(x<0) {return;}
    //printf("%d\n",p);
    for (;p>where;p--){
        a[p]=1;x--;
        solve(a,x,p,n+1-x,n);
        if (x==0) {dayin(a,n);  if(f)  { printf("\n");}   f=1;    }
        x++;a[p]=0;
    }
    return;
}
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    int y=n-x;
    int a[n+1];
    for (int i=1;i<=n;i++) a[i]=0;
    a[1]=1;
    x--;
    solve(a,x,1,n+1-x,n);
    x++;
    for (int i=1;i<=n;i++) a[i]=0;
    //for (int i=1;i<=n;i++) printf("%d",a[i]);
    //printf("\n");
    solve(a,x,1,n+1-x,n);
    return 0;
}