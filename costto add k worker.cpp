typedef pair<int, int> pii;

long long totalCost(vector<int>& costs, int k, int candidates) {
    int n = costs.size();
    priority_queue<pii, vector<pii>, greater<>> leftHeap, rightHeap;
    int i = 0, j = n - 1;

    // Fill the initial candidates
    for (int cnt = 0; cnt < candidates && i <= j; ++cnt)
        leftHeap.push({costs[i], i++});
    for (int cnt = 0; cnt < candidates && i <= j; ++cnt)
        rightHeap.push({costs[j], j--});

    long long totalCost = 0;

    while (k--) {
        pii pick;
        // Choose from valid heaps
        if (!leftHeap.empty() && !rightHeap.empty()) {
            if (leftHeap.top().first <= rightHeap.top().first) {
                pick = leftHeap.top(); leftHeap.pop();
                if (i <= j) leftHeap.push({costs[i], i++});
            } else {
                pick = rightHeap.top(); rightHeap.pop();
                if (i <= j) rightHeap.push({costs[j], j--});
            }
        } else if (!leftHeap.empty()) {
            pick = leftHeap.top(); leftHeap.pop();
            if (i <= j) leftHeap.push({costs[i], i++});
        } else {
            pick = rightHeap.top(); rightHeap.pop();
            if (i <= j) rightHeap.push({costs[j], j--});
        }
        totalCost += pick.first;
    }

    return totalCost;
}
