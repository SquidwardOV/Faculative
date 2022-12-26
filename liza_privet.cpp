void Transp(int** a,int** b,int m,int n)
{
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
            b[j][i]=a[i][j];
}
