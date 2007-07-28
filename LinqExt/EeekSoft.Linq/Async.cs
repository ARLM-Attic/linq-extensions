using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.IO;

namespace EeekSoft.Asynchronous
{
	public delegate void Action();

	public class Unit
	{
		private Unit() { }
		static Unit()
		{
			Value = new Unit();
		}
		public static Unit Value { get; private set; }
	}

	public static class AsyncExtensions
	{
		public static Async<WebResponse> GetResponseAsync(this WebRequest req)
		{
			return new Async<WebResponse>(req.BeginGetResponse, req.EndGetResponse);
		}

		public static Async<int> BeginReadAsync(this Stream stream, byte[] buffer, int offset, int count)
		{
			return new Async<int>(
				(callback, st) => stream.BeginRead(buffer, offset, count, callback, st),
				stream.EndRead);
		}

		public static void Execute(this IEnumerable<IAsync> async)
		{
			AsyncExtensions.Run(async.GetEnumerator());
		}

		private static void Run(IEnumerator<IAsync> en)
		{
			if (!en.MoveNext()) return;
			en.Current.ExecuteStep
				(() => AsyncExtensions.Run(en));
		}
	}

	public static class Async
	{
		public static Async<Unit> Parallel(IEnumerable<IAsync>[] operations)
		{
			return new Async<Unit>((cont) =>
			{
				bool[] completed = new bool[operations.Length];
				for (int i = 0; i < operations.Length; i++)
					ExecuteAndSet(operations[i], completed, i, cont).Execute();
			});
		}

		private static IEnumerable<IAsync> ExecuteAndSet(IEnumerable<IAsync> op, bool[] flags, int index, Action<Unit> cont)
		{
			foreach (IAsync async in op) yield return async;
			bool allSet = true;
			lock (flags)
			{
				flags[index] = true;
				foreach (bool b in flags) if (!b) { allSet = false; break; }
			}
			if (allSet) cont(Unit.Value);
		}
	}

	public interface IAsync
	{
		void ExecuteStep(Action cont);
	}

	public class Async<T> : IAsync
	{
		Action<Action<T>> func;
		T result;
		bool completed = false;

		public Async(Action<Action<T>> function)
		{
			this.func = function;
		}

		public Async(Func<AsyncCallback, object, IAsyncResult> begin, Func<IAsyncResult, T> end)
		{
			this.func = (cont) => begin(delegate(IAsyncResult res) { cont(end(res)); }, null);
		}

		public T Result
		{
			get
			{
				if (!completed) throw new Exception("Operation not completed, did you forgot 'yield return'?");
				return result;
			}
		}

		public void ExecuteStep(Action cont)
		{
			func((res) =>
			{
				result = res;
				completed = true;
				cont();
			});
		}
	}
}
