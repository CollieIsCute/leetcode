#include <iostream>
#include <list>
using namespace std;

class MedianFinder {
	list<int> l;
	list<int>::iterator mid = l.begin();
	long long list_size;

public:
	MedianFinder(): list_size(0){}

	void addNum(int num) {
		auto iter = l.begin();
		for(;iter != l.end() && (*iter < num); ++iter)
			;

		if(iter == mid)
			mid = l.insert(iter, num);
		else{
			l.insert(iter, num);
			if(*mid >= num)
				--mid;
		}

		if(++list_size >= 3 && list_size % 2)
			++mid;
	}

	double findMedian() {
		int a = *mid;
		if(list_size % 2)
			return (double)a;
		else{
			int b = *(++mid);
			--mid;
			return ((double)a + b) / 2.0;
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */