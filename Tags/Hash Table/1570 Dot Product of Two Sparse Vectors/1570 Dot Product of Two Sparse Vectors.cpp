// Date: October 2, 2022
class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                m[i]=nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int DotProd=0;
        for(auto i: this->m){
            if(vec.m.find(i.first)!= vec.m.end()){
                DotProd += this->m[i.first] * vec.m[i.first];
            }
        }
        return DotProd;
    }
private:
        unordered_map<int,int>m;
};
