using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Demos.Infinite.Intro
{
	class Program
	{
		/// <summary>
		/// Returns an infinite sequence of integers: 0, 1, 2, 3, ...
		/// </summary>
		static IEnumerable<int> GetNumbers()
		{
			int i = 0;
			while(true) yield return i++;
		}

		/// <summary>
		/// Generates a sequence inductively. The first elemente in the sequence is
		/// given as a first argument and the next element is generated using the function
		/// given as a second argument. When the function returns 'null' the sequence ends.
		/// </summary>
		static IEnumerable<T> Generate<T>(T initial, Func<T, T?> next) 
			where T : struct
		{
			T? val = initial;
			while (val.HasValue)
			{
				yield return val.Value;
				val = next(val.Value);
			}
		}

		static void Main(string[] args)
		{
			// Create an seq.: 0, 1, 2, 3, 4, ...
			var nums = GetNumbers();

			// Squares of even numbers: 0, 4, 16, 36, ...
			var sq = GetNumbers().Where(n => n % 2 == 0).Select(n => n * n);
			// Alternative - using LINQ query comprehension
			var sq2 = from n in GetNumbers() where n % 2 == 0 select n * n;

			Console.Write("Squares of even numbers: ");
			foreach (var n in sq.Take(20))
				Console.Write("{0}, ", n);


			// Powers of two that fit into 
			var pow = Generate(1, n => {
					if (n > Int32.MaxValue / 2)
						return null;
					else
						return (int?)(n * 2);
				});
			Console.Write("\n\nPowers of two that fit in 'int' type: ");
			foreach (var n in pow)
				Console.Write("{0}, ", n);			
		}
	}
}
