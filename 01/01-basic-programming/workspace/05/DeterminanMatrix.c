    #include <stdio.h>
    #include <math.h>
    void subMatrix(int n,double M[n-1][n-1], double m[n][n], int I, int J)
    {
        int i, a = 0, b = 0,j;
        for (i = 0; i < n; i++)
        {
            if (i != I)
            {
                for (j = 0; j < n; j++)
                {
                    if (J != j)
                    {
                        M[a][b] = m[i][j];
                        b++;
                    }
                }
                a++;
                b=0;
            }
        }

    }
    double determinant (int n, double m[n][n])
    {
      double det = 0;
      if (n == 1)
        {
          return m[0][0];
        }
      if (n == 2)
        {
          det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
        }
      else
        {
          double M[n - 1][n - 1];
          for (int i = 0; i < n; i++)
        {
          subMatrix (n, M, m, 0, i);
          det += m[0][i] * pow (-1, i) * determinant (n - 1, M);
        }
        }
      return det;
    }

    int main (){
      int n, k = 0;
      scanf ("%d", &n);
      double Matrix[n][n];
      for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
        {
          scanf ("%lf", &Matrix[i][j]);
        }
        }
      printf ("%.2lf\n", determinant (n, Matrix));

      return 0;
    }