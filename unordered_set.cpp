struct hashFunction
	{
		size_t operator()(const vector<int>
			& myVector) const
		{
			std::hash<int> hasher;
			size_t answer = 0;

			for (int i : myVector)
			{
				answer ^= hasher(i) + 0x9e3779b9 +
					(answer << 6) + (answer >> 2);
			}
			return answer;
		}
	};
	unordered_set<vector<int>, hashFunction>st;
