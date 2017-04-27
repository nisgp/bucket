using System;
using System.Collections.Generic;
using System.Linq;
using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Attributes.Exporters;
using BenchmarkDotNet.Running;

namespace q161860 {
	[RPlotExporter]
	public class Benchmarks {
		private int _max = -1;
		[Params(100, 250, 500, 750, 1000, 1500, 2000, 5000, 10000, 25000, 50000)]
		public int Bound {
			set {
				_max = value;
				Random rando = new Random(123);
				_values = new int[_max];
				for (int i = 0; i < _max; i++) {
					_values[i] = rando.Next(int.MaxValue / 2);
				}
			}
			get { return _max; }
		}

		private int[] _values;

		[Benchmark]
		public float Gio() {
			return MedianList_Gio(_values, Bound).Last();
		}

		[Benchmark]
		public float Pgs() {
			return MedianList_pgs(_values, Bound).Last();
		}

		[Benchmark]
		public float Pgs_heapC5() {
			return MedianList_pgs_heapC5(_values, Bound).Last();
		}


		public IEnumerable<float> MedianList_Gio(int[] values, int count) {
			MedianListGio sortd = new MedianListGio(count);
			foreach (int value in values) {
				yield return sortd.InsertForMedian(value);
			}
		}

		public IEnumerable<float> MedianList_pgs(int[] values, int count) {
			MedianListPgs sortd = new MedianListPgs(count);
			foreach (int value in values) {
				yield return sortd.InsertForMedian(value);
			}
		}

		public IEnumerable<float> MedianList_pgs_heapC5(int[] values, int count) {
			MedianListPgsHeapC5 sortd = new MedianListPgsHeapC5(count);
			foreach (int value in values) {
				yield return sortd.InsertForMedian(value);
			}
		}
	}

	class Program {
		static void Main() {
			Benchmarks b = new Benchmarks();
			b.Bound = 1000;
			float r = b.Gio();
			float r0 = b.Pgs();
			float r1 = b.Pgs_heapC5();
			if (Math.Abs(r - r0) > Single.Epsilon || Math.Abs(r - r1) > Single.Epsilon) {
				throw new Exception("Not reproducable results");
			}
			BenchmarkRunner.Run<Benchmarks>();
			Console.ReadKey();
		}
	}
}
