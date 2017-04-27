using System;

namespace q161860 {
	public class MedianListGio {
		private int _count;
		private float _iters;
		private readonly int[] _values;

		public MedianListGio(int capacity) {
			_values = new int[capacity];
		}

		public int Count => _count;

		public float Iterations => _iters;

		public float IterationsPer => _iters / Math.Max(1, _count);

		public float InsertForMedian(int value) {
			Insert(value);
			float median = 0.0f;
			int middle = _count / 2;

			if (_count == 1) {
				median = _values[0];
			} else if (_count % 2 == 0) {
				median = (_values[middle] + _values[middle - 1]) / 2.0f;
			} else {
				median = _values[middle];
			}
			return median;
		}

		private void Insert(int value) {
			if (_count == 0) {
				_values[0] = value;
			} else {
				int index = FindDestinationIndex(value);
				Array.Copy(_values, index, _values, index + 1, _count - index);
				_values[index] = value;
			}
			_count++;
		}

		private int FindDestinationIndex(int value) {
			int max = _count - 1;
			int mid = 0, cmp = 0, min = 0;
			if (value <= _values[0]) {
				return 0;
			}
			if (value.CompareTo(_values[_count - 1]) >= 0) {
				return _count;
			}
			while (max > (min + 1)) {
				mid = Convert.ToInt32(Math.Min(Math.Ceiling((max - min) / 2.0f) + min, _count - 1));

				cmp = value.CompareTo(_values[mid]);
				if (cmp == 0) {
					return mid;
				}
				if (cmp > 0) {
					min = Math.Max(mid, min + 1);
				} else if (cmp < 0) {
					max = Math.Min(mid, max - 1);
				}

				_iters++;
			}

			mid = value.CompareTo(_values[min]) > 0 && value.CompareTo(_values[max]) <= 0 ? max : min;
			cmp = value.CompareTo(_values[mid]);
			var index = cmp > 0 ? mid + 1 : mid;
			return index;
		}
	}
}
