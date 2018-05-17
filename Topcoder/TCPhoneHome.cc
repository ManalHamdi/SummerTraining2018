class TCPhoneHome {
	public:
	long long validNumbers(int digits, vector <string> specialPrefixes) {
		int n = specialPrefixes.size();
		map <string, bool> mp;
		for (int i = 0; i < n; i++)  {
			mp[specialPrefixes[i]] = true;
		}
		sort(specialPrefixes.rbegin(), specialPrefixes.rend());


		for (int i = 0; i < n; i++) {
			
			string subset = specialPrefixes[i];
			//find supersets
			for (int j = 0; j < subset.size()-1; j++) {
				string superset = subset.substr(0, j+1);
				if(mp[superset]) {
					mp[subset] = false;
					break;
				}
			}

		}
		long long result = 1;
		for (int k = 0; k < digits; k++)
			result *= 10;
		
		long long power = 1;
		for (auto pref: mp) {
			if (pref.second) {
				for (int k = 0; k < digits-pref.first.size(); k++)
					power *= 10;
				result -= power;
				power = 1;
			}
		}
		return result ;

			
		}



}