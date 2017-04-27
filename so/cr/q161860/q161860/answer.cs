using System;

namespace q161860 {
	public class MedianListPgs {
		private int _count;
		private float _iters;
		private readonly int[] _values;

		public MedianListPgs(int capacity) {
			_values = new int[capacity];
		}

		public int Count => _count;

		public float Iterations => _iters;

		public float IterationsPer => _iters / Math.Max(1, _count);

		public float InsertForMedian(int value) {
			Insert(value);
			int middle = _count / 2;
			return _count % 2 == 0 ? (_values[middle] + _values[middle - 1]) / 2.0f : _values[middle];
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
			int min = 0;
			int max = _count - 1;
			if (value.CompareTo(_values[0]) <= 0) {
				return 0;
			}
			if (value.CompareTo(_values[_count - 1]) >= 0) {
				return _count;
			}
			while (min < max) {
				int mid = ((max - min) >> 1) + min;
				if (value <= _values[mid]) {
					max = mid;
				} else {
					min = mid + 1;
				}
				_iters++;
			}
			return min;
		}
	}
}
