/*   Swap two nibbles in a byte    [EASY]*/

 class Solution {
  public:
      int swapNibbles(int n) {
        // code here
        return (n&0x0F)<<4 | (n>>4);
    }
};
