/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
        int count=0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        while(head)
        {
            if(s.find(head->val)!=s.end())
            {
                count+=1;
                while(head and  s.find(head->val)!=s.end())
                {
                    head=head->next;
                }
                
            }
            else
            {
                head=head->next;
            }
        }
        return count;
    }
};
