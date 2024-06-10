class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count = 1;
        vector<int> occurence(1e3+1, 0);
        sort(arr.begin(), arr.end());

        if(arr.size() == 2 && arr[0] != arr[1]){
            return false;
        }
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                if(occurence[count] != 0){
                    return false;
                }
                else{
                    occurence[count] = 1;
                }
                count = 1; 
            }
        }
        
        if(occurence[count] != 0){
            return false;
        }
        occurence[count] = 1;

        return true;
    }
};
