https://leetcode.com/problems/trapping-rain-water/

int trap(vector<int>& height) {
        
        int size = height.size();
        if(!size) return 0;
        int maxl[size],maxr[size];
        maxl[0] = height[0];
        for(int i=1;i<size;i++){
            maxl[i] = max(maxl[i-1],height[i]);
        }
        maxr[size-1] = height[size-1];
        for(int i=size-2;i>=0;i--){
            maxr[i] = max(maxr[i+1],height[i]);
        }
        int water[size];
        for(int i=0;i<size;i++){
            water[i]=min(maxl[i],maxr[i])-height[i];
        }
        int sum =0;
        for(int i=0;i<size;i++) sum = sum + water[i];
        
        return sum;
    }
