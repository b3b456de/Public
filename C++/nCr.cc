#include <cstdio>

int nCr(double ,double);
double nCr_h(double,double,double);

int main(){
  int n, r;
  scanf("%i", &n);
  scanf("%i", &r);
  int i;
  for(i = 0; i < 1e8; ++i)
    nCr(n,r);
}

int nCr(double n, double r){
  return nCr_h(n,r,1);
}

double nCr_h(double n, double r, double i){
  if(i <= r){
    return (n+1-i) * nCr_h(n,r,i+1) / i;
  }
  else
    return 1.0;
}
