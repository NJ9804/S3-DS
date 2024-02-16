#include<stdio.h>						 	 
void main()					
{								
    int n,a[50],low,high,mid,pst,key,flag=0,i;
    printf("Enter size of sorted the array\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched\n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            pst=mid;
            flag=1;
            break;
        }
        else if(a[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==1)
    {
        printf("Element found at position %d\n",pst);
    }
    else
    {
        printf("Element not found\n");
    }
}


