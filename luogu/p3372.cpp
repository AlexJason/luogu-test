#include <iostream>

using namespace std;

template <typename DataType = int, typename SizeType = size_t>
class SegmentTree {
public:
	SegmentTree(DataType *d, SizeType s) {
		width = s;
		size = s << 2;
		data = new DataType[size] - 1;
		tag = new DataType[size] - 1;
		create_node(1, 1, s, d);
	}
	void add(SizeType left, SizeType right, DataType val) {
		add(left, right, val, 1, 1, width);
	}
	DataType sum(SizeType left, SizeType right) {
		return sum(left, right, 1, 1, width);
	}
private:
	void create_node(SizeType root, SizeType ll, SizeType rr, DataType *d) {
		if (ll == rr) {
			data[root] = d[ll - 1];
			tag[root] = 0;
		}
		else {
			SizeType mid = (ll + rr) >> 1;
			create_node(root << 1, ll, mid, d);
			create_node((root << 1) | 1, mid + 1, rr, d);
			data[root] = data[root << 1] + data[(root << 1) | 1];
			tag[root] = 0;
		}
	}
	void push_down(SizeType root, SizeType ll, SizeType rr) {
		tag[root << 1] += tag[root];
		tag[(root << 1) | 1] += tag[root];
		SizeType mid = (ll + rr) >> 1;
		data[root << 1] += tag[root] * (mid - ll + 1);
		data[(root << 1) | 1] += tag[root] * (rr - mid);
		tag[root] = 0;
	}
	void add(SizeType left, SizeType right, DataType val, SizeType root, SizeType ll, SizeType rr) {
		if (left <= ll && right >= rr) {
			data[root] += val * (rr - ll + 1);
			tag[root] += val;
		}
		else {
			if (tag[root]) push_down(root, ll, rr);
			SizeType mid = (ll + rr) >> 1;
			if (left <= mid) add(left, right, val, root << 1, ll, mid);
			if (mid < right) add(left, right, val, (root << 1) | 1, mid + 1, rr);
			data[root] = data[root << 1] + data[(root << 1) | 1];
		}
	}
	DataType sum(SizeType left, SizeType right, SizeType root, SizeType ll, SizeType rr) {
		if (left <= ll && right >= rr) {
			return data[root];
		}
		else {
			if (tag[root]) push_down(root, ll, rr);
			SizeType mid = (ll + rr) >> 1;
			DataType result = 0;
			if (left <= mid) result += sum(left, right, root << 1, ll, mid);
			if (mid < right) result += sum(left, right, (root << 1) | 1, mid + 1, rr);
			return result;
		}
	}
private:
	DataType *data;
	DataType *tag;
	SizeType size;
	SizeType width;
};

int main() {
	long long n, m;
	cin >> n >> m;
	long long *d = new long long[n];
	for (long long i = 0; i < n; ++i) cin >> d[i];
	SegmentTree<long long> tree(d, n);
	while (m--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			long long x, y, k;
			cin >> x >> y >> k;
			tree.add(x, y, k);
		}
		else {
			long long x, y;
			cin >> x >> y;
			cout << tree.sum(x, y) << endl;
		}
	}
	return 0;
}

