#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define oo 1e8
using namespace std;
class FoldingPaper2 {
	public:
	vector <pair <int,int> > findDiv(int n) {
		vector <pair <int, int> > div;
		for (int i = 1; i <= sqrt(n); i++) {
			if (n % i != 0)
				continue;
			div.push_back(make_pair(min(i , n/i), max(i , n/i)) );
		}
		return div;
	}

	int foldPaperSide (int side, int goal) {
		if (goal > side)
			return -1;
		if (goal == side)
			return 0;
		if (goal > ceil(side/2 + side % 2) || goal == ceil(side/2 + side % 2) )
			return 1;
		
		return 1 + foldPaperSide(ceil(side/2 + side % 2), goal);
	}
	int solve(int W, int H, int A) {
		
		//Find div of A
		
		vector <pair <int, int> > div = findDiv(A);
		
		vector <int> result;
		for (int i = 0; i < (int)div.size(); i++) {
			int a1 = foldPaperSide(min(W,H), div[i].first);
			if (a1 == -1)
				continue;
			int a2 = foldPaperSide(max(W,H), div[i].second);
			if (a2 == -1)
				continue;
			
			int inter_result = a1 + a2; 
			result.push_back(inter_result);
			
		}
		//Find min in result
		
		if (result.size() == 0)
			return -1;
		else {
			int min = oo;
			for (int i = 0; i < (int)result.size(); i++)
				if (min > result[i])
					min = result[i];
			return min;
		}
		
	}
}