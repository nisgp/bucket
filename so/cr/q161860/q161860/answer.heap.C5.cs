using C5;

namespace q161860 {
	public class MedianListPgsHeapC5 {
		private int _count;
		/// <summary>
		/// The FindMin/Max O(1)
		/// DeleteMin/Max and Add is O(log n)
		/// </summary>
		private readonly IntervalHeap<int> _leftHeap;
		private readonly IntervalHeap<int> _rightHeap;

		public MedianListPgsHeapC5(int capacity) {
			_count = 0;
			_leftHeap = new IntervalHeap<int>(capacity / 2);
			_rightHeap = new IntervalHeap<int>(capacity / 2);
		}

		public int Count => _count;

		public float InsertForMedian(int value) {
			_count++;
			if (_count == 1) {
				_leftHeap.Add(value);
				return _leftHeap.FindMax();
			}
			if (_count % 2 == 0) {
				if (value < _leftHeap.FindMax()) {
					//_count is odd and value < max of left heap
					_rightHeap.Add(_leftHeap.DeleteMax());
					_leftHeap.Add(value);
				} else {
					//_count is odd and value >= max of left heap
					_rightHeap.Add(value);
				}
				return (_leftHeap.FindMax() + _rightHeap.FindMin()) / 2.0f;
			}
			if (value < _leftHeap.FindMax()) {
				//_count is even and value < max of left heap
				_leftHeap.Add(value);
			} else {
				//_count is even and value >= max of left heap
				_leftHeap.Add(_rightHeap.DeleteMin());
				_rightHeap.Add(value);
			}
			return _leftHeap.FindMax();
		}
	}
}
