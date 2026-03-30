class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m*n-1;
        cout << m << " " << n << endl << endl;
        while(l<=r){
            int mid = (l+r)/2;
            int i = mid/n;
            int j = mid%n;
            cout << l << " " <<  i << " " << j << endl;
            cout <<  matrix[i][j]<< endl;
            if(target > matrix[i][j]){
                l = mid+1;
            }
            else if(target < matrix[i][j]){
                r = mid-1;
            }
            else{
                cout << "found" << endl;
                return true;
            }
        }
        return false;
    }
};
