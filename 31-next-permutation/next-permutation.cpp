class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int pvt=-1, n=arr.size();

        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                pvt = i;
                break;
            }
        }
        if(pvt == -1){
            reverse(arr.begin(),arr.end());
            return;
        }

        for (int i = n-1; i>pvt;i--){   //next larger elem
            if(arr[i]>arr[pvt]){
                swap(arr[i],arr[pvt]);
                break;
            }
        }

        int i= pvt+1, j=n-1;        //for reversing
        while(i<=j){
            swap(arr[i++],arr[j--]);
        }

    }
};