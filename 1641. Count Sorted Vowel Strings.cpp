class Solution {

public:
     void count(int i,int j,int n,int &count_v)
     {
       if(j==n)
       {
          count_v++;
          return ; 
       }
       for(int k=i;k<5;k++)
       {
           count(k,j+1,n,count_v);
       }
       return;
     }
    int countVowelStrings(int n)
    {
       int count_v=0; 
       count(0,0,n,count_v);
       return count_v;

    }
};
