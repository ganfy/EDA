#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;

template<typename T, typename B>
B euclDist(vector<T> a, vector<T> b){
  double sum=0;
  for (int i = 0; i< a.size(); i++){
    sum+=pow(a[i]-b[i],2);
  }
  return sqrt(sum);
}

template<typename T>
void printVect(vector<T> v){
  for(int i=0; i<v.size(); i++)
    cout<<v[i]<<" ";
  cout<<endl;
}

template<typename T, typename B>
int64_t genVectFunct(int num, const int kSize){
  vector<T> a(kSize);
  vector<T> b(kSize);
  int64_t duration = 0;
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  
  for (int i=0; i<num; i++){
    generate(a.begin(), a.end(), [](){return rand()%1000+1;});
    generate(b.begin(), b.end(),  [](){return rand()%1000+1;});
  
    start = std::chrono::high_resolution_clock::now();
    euclDist<T,B>(a,b);
    end = std::chrono::high_resolution_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
   
  } 
  return duration;
}


int main() {

  vector<int> num = {10000, 20000, 30000, 40000, 50000};
  vector<int> size = {10, 20, 30, 40, 50};

  ofstream myfile;
  myfile.open ("tabla.csv");

  
  for (int i=0; i<5; i++){
    for (int j=0; j<5; j++){
      long int n = genVectFunct<int,double>(num[i], size[j]);
      myfile<<n<<';';
      cout<<n<<'\t';
      }
    myfile<<endl;
    cout<<endl;
  }
  myfile.close();
  
}