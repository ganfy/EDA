#include <iostream>
#include <vector>
using namespace std;
 
vector<int> mat(2);
using M = vector<vector<int>>;
using namespace std;

// Fibonacci Exponencial (Recursivo)
int FibExp(int n){
  if (n == 0 || n == 1)
    return n;
  return FibExp(n-1) + FibExp(n-2);
}

// Fibonacci Lineal (Iterativo)
int FibIt(int n){
  int f[n+1];
  f[0]=0, f[1]=1;
  for (int i=2; i<=n; i++)
    f[i]=f[i-1]+f[i-2];
  return f[n];
}

M MultMat(M a, M b){
  M c(2,mat);
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      int sum=0;
      for(int s=0; s<2; s++){
        sum+=a[i][s]*b[s][j];
      }
      c[i][j]=sum;
    }
  }
  return c;
}

M FastExp(M m, int exp){
  if (exp == 2)
    return MultMat(m,m);
  if (exp==1)
    return m;
  M mitad = FastExp(m,exp/2);
  if (exp%2)
    return MultMat(MultMat(mitad,mitad),m);
  return MultMat(mitad,mitad);
}

// Fibonacci O(logn)
int FibLog(int n){
  M m = {{1,1},{1,0}};
  m = FastExp(m,n-1);
  return m[0][0]; // m* [1][0] -> f1 f0
}

int main() {
  cout<<FibExp(7)<<endl;
  cout<<FibIt(7)<<endl;
  cout<<FibLog(7);
}