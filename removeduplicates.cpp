#include <iostream>
using namespace std;
int main()
{
    int a[100], i, n, j, temp= 1;
    cout<<"Enter the number of elements in an array: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for (j=0; j<n; j++)
    {
        cin>>a[j];
    }
    cout<<"Your elements are:\n";
    for (j=0; j<n; j++)
    {
        cout<<a[j]<<"\t";
    }
    cout<<"\n";
    for (j=1; j<n; j++)
    {
        if (a[j-1] > a[j])
        {
            temp=0; 
            break;
        }
    }
    if (!temp)
    {
        cout<<"The array is not sorted.\n";
    }
    else
    {
        i = 0;
        for (j=1; j< n; j++)
        {
            if (a[i] !=a[j])
            {
                i++;
                a[i] =a[j];
            }
        }
        cout<<"Array after removing duplicates:\n";
        for (j=0; j<=i; j++)
        {
            cout<<a[j]<<"\t";
        }
        cout<<"\nNow the size of the array is: \n"<< i+1;
    }

    return 0;
}
