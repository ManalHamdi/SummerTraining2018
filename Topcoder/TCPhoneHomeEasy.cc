#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
class TCPhoneHome {
	public:
	long long validNumbers(int digits, vector <string> specialPrefixes) {
		int n = specialPrefixes.size();
		set <string> unprocessedPrefixes;
		for (int i = 0; i < n; i++)  {
			unprocessedPrefixes.insert(specialPrefixes[i]);
		}

		sort(specialPrefixes.rbegin(), specialPrefixes.rend());

		for (int i = 0; i < n; i++) {
			string subset = specialPrefixes[i];

			//find supersets
			for (int j = 0; j < (int)subset.size() - 1; j++) {
				string superset = subset.substr(0, j + 1);
				if(unprocessedPrefixes.count(superset)) {
					unprocessedPrefixes.erase(unprocessedPrefixes.find(superset));
					break;
				}
			}
		}
		long long result = 1;
		for (int k = 0; k < digits; k++)
			result *= 10;
		
		long long power = 1;
		for (auto pref: unprocessedPrefixes) {
				for (int k = 0; k < digits - pref.size(); k++)
					power *= 10;
				result -= power;
				power = 1;
			
		}
		return result ;
	}
};