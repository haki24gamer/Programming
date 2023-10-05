class simple
{
    public static void main(String[] args)
    {
        //tests for what
        int[] hey={12,13,15};
        System.out.println(what(hey));

    }
    public static int what(int[] nums)
    {
        int sum=0;
        
        for (int i = 0; i < nums.length; i++) {
            sum = sum+nums[i];
        }
        return sum;
    }
}

