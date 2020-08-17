using System;

namespace FibonacciNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[100];
            nums[0] = 0;
            nums[1] = 1;

            Console.WriteLine("Fibonacci Numbers is generating...");
            for (int i = 2; i < 100; i++)
            {
                nums[i] = nums[i - 1] + nums[i - 2];
                Console.Write("#");
            }
            Console.WriteLine("Done");
            Console.WriteLine($"GetFibonacciNumberRecursive(nums,2) : {GetFibonacciNumberRecursive(nums,2)}");
            
            #region
            int GetFibonacciNumberRecursive(int[] nums, int idx)
            {
                if (idx == 0)
                {
                    return 0;
                }
                else if (idx == 1)
                {
                    return 1;
                }
                else
                {
                    return GetFibonacciNumberRecursive(nums, idx - 1) + GetFibonacciNumberRecursive(nums, idx - 2);
                }
            }
            #endregion
        }
    }
}
