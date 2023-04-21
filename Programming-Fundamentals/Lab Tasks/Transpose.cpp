#include<iostream>
using namespace std;
int main() {
	int r=2,c=3;
int t[100][100];
   int i, j;
   int** a=new int*[r];
   for(int i=0;i<r;i++)
   a[i]=new int[c];
     for(i=0; i<r; ++i)
   for(j=0; j<c; ++j) {
      cin>>a[i][j];
   }
   cout<<"The matrix is:"<<endl;
   for(i=0; i<r; ++i) {
      for(j=0; j<c; ++j)
      cout<<a[i][j]<<" ";
      cout<<endl;
   }
   cout<<endl;
   for(i=0; i<r; ++i)
   for(j=0; j<c; ++j) {
      t[j][i] = a[i][j];
   }
   cout<<"The transpose of the matrix is:"<<endl;
   for(i=0; i<c; ++i) {
      for(j=0; j<r; ++j)
      cout<<t[i][j]<<" ";
      cout<<endl;
   }
   return 0;
}
