class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low = 0, mid = 0, high = n-1;

        while(mid<=high){
            if(arr[mid]==0){  //for 0s
                swap(arr[low],arr[mid]);
                mid++;
                low++;
            }else if(arr[mid]==1) { //for 1s
                mid++;
            }else{          //for 2s
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};