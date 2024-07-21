#include <iostream>
// #include <fstream>

using namespace std;

void sort(int *inputs, const int N) {
    for (int i = 1; i < N; i++) {
        const int temp = inputs[i];
        int j = i;
        for (; j > 0 && inputs[j - 1] > temp; j--) {
            inputs[j] = inputs[j - 1];
        }
        inputs[j] = temp;
    }
}

int solve(int *inputs, const int N, const int K) {
    int ret = 1000000000;
    for (int i = 0; i <= N - K; i++) {
        int temp = inputs[i + K - 1] - inputs[i];
        if (temp < ret) ret = temp;
    }
    return ret;
}

int main(int argc, char **argv) {
    // freopen("../sin.txt", "r", stdin);
    // ifstream answer("../sout.txt");

    int T, t = 1;
    scanf("%d", &T);
    int inputs[50];
    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);
        for (int j = 0; j < N; j++) {
            scanf("%d", &inputs[j]);
        }
        sort(inputs, N);
        int result = solve(inputs, N, K);

        printf("#%d %d\n", t, result);

        // int a;
        // string skip;
        // answer >> skip >> a;
        // printf("#%d ", t);
        // if (a == result) printf("success\n");
        // else printf("%d != %d\n", a, result);
        t++;
    }
    return 0;
}
