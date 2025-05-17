class Solution {
public:
    bool isFreq(int fq1[], int fq2[]){
        for(int i=0;i<26;i++){
            if(fq1[i]!=fq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};

        for (int i=0 ; i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        int windSize = s1.length();

        for(int i=0; i<s2.length(); i++){
            int windIdx=0 , idx=i;
            int windFreq[26]={0};

            while(windIdx < windSize && idx < s2.length()){
                windFreq[s2[idx]-'a']++;
                windIdx++;
                idx++;
            }

            if(isFreq(freq,windFreq)){
                return true;
            }
        }
        return false;
    }
};