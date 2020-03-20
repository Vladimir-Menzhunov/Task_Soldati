#include<iostream>
#include<vector>
#include<cassert>
#include <algorithm>

using namespace std;

enum state { NEW, DURING, VISITED };

void visit(int cur, const vector<vector<int>> &less, vector<int> &state, bool &resolution, vector<int> &build)
{
	if (state[cur] == DURING)
	{
		resolution = false;
		return;
	}
	if (state[cur] == VISITED)
	{
		return;
	}
	assert(state[cur] == NEW);
	state[cur] = DURING;
	for (int next : less[cur]) {
		
		visit(next, less, state, resolution, build);
		
	}
	assert(state[cur] == DURING);
	build.push_back(cur);
	state[cur] = VISITED;

}


int main()
{
	int numV;
	int numR;

	cin >> numV;
	cin >> numR;

	vector<vector<int>> less(1 + numV);

	vector<int> build;

	for (int i = 0; i < numR; i++)
	{
		int v1;
		int v2;

		cin >> v1;
		cin >> v2;

		less[v1].push_back(v2);
	}

	vector<int> state(1 + numV, NEW);

	bool resolution = true;

	for (int i = 1; i <= numV; i++)
	{
		if (state[i] == NEW)
		{
			visit(i, less, state, resolution, build);
		}
	}
	if (resolution)
	{
		cout << "YES" << endl;
		reverse(build.begin(), build.end());
		for (int num : build)
		{
			cout << num << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "NO";
	}
	return 0;
}