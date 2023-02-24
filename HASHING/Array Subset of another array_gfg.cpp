
string isSubset(int a1[], int a2[], int n, int m) {
    map<int,int> freq;
    for(int i=0;i<n;i++)
    {
        // if(freq.find(a1[i])==freq.end())
        //       freq[a1[i]]=1;
        //else
        freq[a1[i]]++;
    
    }
    for(int i=0;i<m;i++)
    {
        if(freq.find(a2[i])!=freq.end() and freq[a2[i]]>0)
         freq[a2[i]]--;
        else return "No"; 
    }
    return "Yes";
    
}
