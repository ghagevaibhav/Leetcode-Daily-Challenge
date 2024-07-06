class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the effective time within one cycle of passing the pillow
        int effective_time = time % (n * 2 - 2);
        
        // Calculate and return the current position of the pillow
        return n - abs(n - 1 - effective_time);
    }
};
