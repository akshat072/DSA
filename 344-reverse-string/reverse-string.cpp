class Solution {
public:
    void reverseString(vector<char>& st) {
        int str=0, end=st.size()-1;
        while(str<end){
            swap(st[str++],st[end--]);
        }       
    }
};