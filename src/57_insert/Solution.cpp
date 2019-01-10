#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

using namespace std;

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> l;
        vector<Interval> r;
        int start = newInterval.start;
        int end = newInterval.end;
        for (const Interval& interval : intervals) {
            if (interval.end < start) {
                l.push_back(interval);
            } else if (interval.start > end) {
                r.push_back(interval);
            } else {
                start = min(start, interval.start);
                end = max(end, interval.end);
            }
        }
        vector<Interval> ans(std::move(l)); // 调用了移动构造函数，改变了类内部成员的所有权
        ans.emplace_back(start, end);
        ans.insert(ans.end(), r.begin(), r.end());
        return ans;
    }
};
