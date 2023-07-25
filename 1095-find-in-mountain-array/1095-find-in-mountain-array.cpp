/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int maxInd = 0;
        int s = 0;
        int e = n-1;
        
        while(s<e){
            int mid = s + (e-s)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        
        maxInd = s;
        s = 0;
        e = maxInd;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        s = maxInd + 1;
        e = n-1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }
};