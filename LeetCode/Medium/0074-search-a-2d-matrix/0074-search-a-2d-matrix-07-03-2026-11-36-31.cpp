class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


        int m=matrix.size(),n=matrix[0].size();
        int left=0,right=(m*n)-1,mid;
        int row,coloum;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            row=mid/n;
            coloum=mid%n;
            if(matrix[row][coloum]==target)
            {
                return true;
            }
            else if(matrix[row][coloum]>target)
            {
                right=mid-1;
            }
            else if(matrix[row][coloum]<target)
            {
                left=mid+1;
            }

        }
        return false;


        
    }
};