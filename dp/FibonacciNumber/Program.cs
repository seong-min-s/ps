using System;

namespace FibonacciNumber
{
    class Program
    {
        /// <summary>
        /// 피보나치 수열
        /// n의 값으로 2 이상의 값을 넣는다고 가정해야 함.
        /// 
        /// 깊이에 대한 감각..
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            while(true)
            {
                int number;
                if (int.TryParse(Console.ReadLine(), out number) && number >= 2)
                {
                    
                    Console.WriteLine($"GetFibonacciNumberRecursive({number}) : {GetFibonacciNumberRecursive(number)}");
                }
                else
                {
                    continue;
                }
            }

            #region
            int GetFibonacciNumberRecursive(int n)
            {
                if (n == 0)
                {
                    return 0;
                }
                else if (n == 1)
                {
                    return 1;
                }
                else
                {
                    return GetFibonacciNumberRecursive(n - 1) + GetFibonacciNumberRecursive(n - 2);
                }
            }
            #endregion
        }
    }
}
