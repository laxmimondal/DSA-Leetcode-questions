class Solution {
typedef pair<int,int> P;
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        for(auto it : hand)
        mp[it]++;

        priority_queue<P , vector<P> , greater<P>> pq;
        for(auto it : mp)
        pq.push({it.first , it.second});


        while(!pq.empty())
        {
            vector<pair<int,int>> temp;
            int prev = 1e9;
            for(int i = 1 ; i <= groupSize ; i++)
            {
                int freq = pq.top().second;
                int ele = pq.top().first;
                if(ele != prev+1 && prev != 1e9)
                return false;

                prev = ele;
                freq--;
                temp.push_back({ele,freq});
                pq.pop();
            }

            for(auto it : temp)
            {
                if(it.second > 0)
                pq.push({it.first,it.second});
            }
        }

        return true;
    }
};