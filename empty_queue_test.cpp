#include <bits/stdc++.h>

using namespace std;

int main(void){

	priority_queue<int> q;
	q.push(1);
	q.pop();
	printf("%lu\n", q.size());
	printf("%d\n", q.top());
	return 0;

}
