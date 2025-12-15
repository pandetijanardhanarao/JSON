#include <stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10
int ConvertTODecimal(char *value,int base){
    return (int)strtol(value,NULL,base);
}
double lagrange(double x[],d  y[],int k, double x){
    double result=0.0;
    for(int i=0;i<k;i++){
        double term=y[i];
        for(int j =0;j<k;j++){
            if(i!=j){
                term*=(x-x[j])/(x[i]-x[j]);
            }
        }
        result+=term;
    }
    return result;
}
int main(){
    "{"
        "\"keys\":{\"n\":4,\"k\":3},"
        "\"1\":{\"base\":\"10\",\"value\":\"4\"},"
        "\"2\":{\"base\":\"2\",\"value\":\"111\"},"
        "\"3\":{\"base\":\"10\",\"value\":\"12\"},"
        "\"6\":{\"base\":\"4\",\"value\":\"213\"}"
        "}";
        int n=4,k=3;
        int x[MAX]={1,2,3,6};
        char *bases[MAX]={"10","2","10","4"};
        char *values[MAX]={"4","111","12","213"};
        double xd[MAX],yd[MAX];
        for (int i=0;i<n;i++){
            xd[i]=x[i];
            yd[i]=ConvertTODecimal(values[i],atoi(bases[i]));

        }
        double xp[MAX];
        for(int i=0;i<k;i++){
            xp[i]=xd[i];
            yp[i]=yd[i];
        }
        printf("Polynomial Verification:\n\n");
        for(int i=0;i<n;i++){
            double fx=lagrange(xp,yp,k,xd[i]);
            printf("f(%d)=%.0lf | Expected=%.0lf\n,x[i],fx,yd[i]");

        }
        return 0;
    

}