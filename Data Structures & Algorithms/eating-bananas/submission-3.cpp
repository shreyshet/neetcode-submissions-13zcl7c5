class Solution {
    int countk(vector<int>& piles, int k){
        long long c = 0;
        for(int i = 0; i < piles.size(); i++){
            c += ceil(static_cast<double>(piles[i]) / k);    
        }
        return c;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.rbegin(), piles.rend());
        int pmax = 0, count = 0, pmin = INT_MAX;
        for (auto j: piles){
            count += j;
            pmax = max(pmax,j);
            pmin = min(pmin,j);
        }
        int l=1, r=pmax;
        int retk = r;

        while(l<=r){
            int k = (l+r)/2;
            int c = countk(piles,k);
            cout << c << " " << k << endl;
            if(c <= h) {retk = k; r = k-1;}
            else{ l = k+1;}

            
        }
        
        return retk;
        
    }
};
