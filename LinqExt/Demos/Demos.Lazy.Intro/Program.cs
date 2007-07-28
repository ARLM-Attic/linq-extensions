using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Demos.Lazy.Intro
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("[Lazy #1]");
			LazyValues1();
			Console.WriteLine("\n\n[Lazy #2]");
			LazyValues2();
			Console.WriteLine("\n\n[Lazy #3]");
			LazyValues3();
		}


		/// <summary>
		/// Demonstrates using of a lazy value. You can also debug the
		/// code to see how it is executed.
		/// </summary>
		private static void LazyValues1()
		{
			Lazy<int> lazy = new Lazy<int>(() => {
					Console.WriteLine("calculating...");
					return 42;
				});

			Console.WriteLine("starting...");
			Console.WriteLine("result = {0}", lazy.Value);
			Console.WriteLine("result (again) = {0}", lazy.Value);
		}


		/// <summary>
		/// Demonstrates using lazy values together with C# anonymous types
		/// </summary>
		private static void LazyValues2()
		{
			int a = 22, b = 20;
			var lazy = Lazy.New(() => {
					Console.WriteLine("calculating...");
					return new { Mul = a * b, Sum = a + b };
				});

			Console.WriteLine("Mul = {0}, Sum = {1}",
				lazy.Value.Mul, lazy.Value.Sum);
		}

		static Random rnd = new Random();

		/// <summary>
		/// Demonstrates how to use lazy values for emulating
		/// "lazy evaluation" when calling a method
		/// </summary>
		static void LazyValues3()
		{
			var calc1 = Lazy.New(() =>
			{
				Console.WriteLine("Calculating #1");
				return 42;
			});

			var calc2 = Lazy.New(() =>
			{
				Console.WriteLine("Calculating #2");
				return 43;
			});

			int res;
			res = ReturnRandomValue(calc1, calc2);
			Console.WriteLine("Result = {0}", res);
			res = ReturnRandomValue(calc1, calc2);
			Console.WriteLine("Result = {0}", res);
		}

		static int ReturnRandomValue(Lazy<int> a0, Lazy<int> a1)
		{
			if (rnd.Next(2) == 0)
				return a0.Value;
			else
				return a1.Value;
		}
	}
}
