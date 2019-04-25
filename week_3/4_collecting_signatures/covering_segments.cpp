#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  std::sort(std::begin(segments),std::end(segments), [](auto const&  s1, auto const& s2) 
                                                      {
                                                         if(s1.start < s2.start)
                                                            return true;
                                                          else if(s1.start == s2.start)
                                                            return s1.end < s2.end;
                                                           else 
                                                            return false;
                                                      } );
  auto it = std::begin(segments);
  Segment common_segment;
  common_segment.start = it->start;
  common_segment.end = it->end;
  std::advance(it,1);
  while(it != std::end(segments)){
    if(it->start > common_segment.end){
      points.emplace_back(common_segment.end);
      common_segment.start = it->start;
      common_segment.end = it->end;
    } else if ( it->start >= common_segment.start ){
      common_segment.start = it->start;
      if(it->end < common_segment.end){
        common_segment.end = it->end;
      }
    }
    std::advance(it,1);
  }

  points.emplace_back(common_segment.end);

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
