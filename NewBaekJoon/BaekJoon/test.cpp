int cnt = 0;
while (q.size()) {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < arr[cur].size(); i++) {
        int next = v[i];
        if (find(arr[cur].begin(), arr[cur].end(), next) != arr[cur].end() && !visited[next]) {
            q.push(next);
            visited[next] = 1;
            cnt++;
        };
    };
}



for (int i = 0; i < v.size(); i++) {
    int next = v.at(i);
    if (find(arr[cur].begin(), arr[cur].end(), next) != arr[cur].end() && !visited[next]) {
        q.push(next);
        visited[next] = 1;
        cnt++;
    };
};