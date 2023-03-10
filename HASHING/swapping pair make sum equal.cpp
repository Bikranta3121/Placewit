class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        unordered_set<int> a,b;
        int sum_a=0;
        int sum_b=0;
        for(int i=0;i<n;i++)
        {
            a.insert(A[i]);
            sum_a+=A[i];
        }
        for(int i=0;i<m;i++)
        {
            b.insert(B[i]);
            sum_b+=B[i];
        }
       
        int total_sum=sum_a+sum_b;
        if(total_sum%2!=0) return -1;
        if(sum_a==sum_b) return 1;
        if(sum_a > sum_b)
        {
            int diff=sum_a-total_sum/2;
            for(int i=0;i<m;i++)
            {
                if(a.find(B[i]+diff)!=a.end())
                 return 1;
            }
        }
        else
        {
           int diff=sum_b-total_sum/2;
           for(int i=0;i<n;i++)
           {
               if(b.find(A[i]+diff)!=b.end()) return 1;
           }
        }
        return -1;
	}
 

};
