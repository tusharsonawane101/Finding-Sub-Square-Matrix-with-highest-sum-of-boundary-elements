/////////////////////////////////////////////////////////////////////////////////
//    TKS    ////////////////////////////////////////////////////////////////////                      
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;


void print(int **badd, int sub_size, int k, int l, int num)
{
    int row_end,col_end;
    row_end = k+sub_size-1;    
    col_end = l+sub_size-1;
    
    /////////////////////////////////////////////////////////////////////////////
    //cout<<"\nlargest boundary sum : "<<num<<endl;
    //cout<<"\n k:"<<k<<" l:"<<l; // 
    //cout<<"\n r:"<<row_end<<" c:"<<col_end;
    //cout<<"\nCorrespinding Sub-matrix : \n";
    /////////////////////////////////////////////////////////////////////////////
    
    cout<<"\nSub-matrix with highest sum of boundary elements : \n";
    for(int i = k; i <=row_end; i++)
    {
        for(int j = l; j <=col_end; j++)
        {
            cout << "   " << badd[i][j];
        }
        cout << endl;
    }
}

void Calc_add(int **A, int rows, int cols, int sub_size)
{
    int add_buff,largest,start;
    int i,j,k,l;
    int r,c,row_start,col_start,row_end,col_end;
    int m,n;
    
    add_buff=0;largest=0;
    r=rows-sub_size+1;  //cutting row size to possible sub matrix origin points only
    c=cols-sub_size+1;  //cutting col size to possible sub matrix origin points only
    
    for(i=0;i<r;i++)      
    {
        for(j=0;j<c;j++)
        {
            row_start = i;          //starting index of row (sub-matrix)
            col_start = j;          //starting index of col (sub-matrix)
            row_end = row_start+sub_size-1;    //last row index (sub-matrix)
            col_end = col_start+sub_size-1;    //last col index (sub-matrix)
            
            for(m=i;m<=row_end;m++)
            {  
                for(n=j;n<=col_end;n++)                                         
                {   
                   if( (m==row_start) || (n==col_start) || (m==row_end) || (n==col_end) )  ////boundary condition
                   {
                        add_buff=add_buff+A[m][n];   ////boundary addition                              
                        
                   }        
                }        
            }
            
            //######    REMOVE BELOW COMMENT TO VIEW boundary addition and the Corresponding submatrix origin  //////////////
            //cout<<"\n sum : "<<add_buff<<"  i :"<<i<<"  j:"<<j;
            
            if(add_buff>largest)
            {
               largest=add_buff;    //largest boundary sum
               k=i;l=j;         //store origin of sub-matrix 
               cout<<"  largest occurrence."<<endl;
            }
            add_buff=0;
        }
        cout<<endl;
    }
    
    print (A,sub_size,k,l,largest);
    
}



int main()
{
    int **A, rows, cols;
    int sub_size;
    
    cout << "Input Width and Height of matrix: ";
    cin >> cols >> rows;
    cout << endl;

    A = new int* [rows]; //create rows of matrix
    for(int row = 0; row < rows; row++)
        A[row] = new int[cols]; //create columns of matrix

    cout<<"\nInput Matrix with numbers from 0 to 9: \n";
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {    
            cin >> A[i][j];
            while(A[i][j]<0||A[i][j]>9) //condition 0-9
            {
                cout<<"\nPlease Re-enter number between 0 - 9 : ";
                cin>>A[i][j];
            }
        }
    }
    
    cout<<"\nInput maximum width of square submatrix : ";
    cin>>sub_size;
    while(sub_size > rows || sub_size > cols )
    {
        cout<<"\n Sub-matrix size cannot be greater than original matrix.\n";
        cout<<"\n Please Re-enter submatrix size : ";  
        cin>>sub_size;
    }
    
    Calc_add(A,rows,cols,sub_size);
    
return 0;
}





