// 1B, 2W, 3R

long long f(int n, int prev, int prevprev) {
    if(n == 1 && prevprev == 4)
        return 2;
    if(n == 1)
        return 1;
    if(prev == 1) {
        if(prevprev == 2)
            return f(n - 1, 3, prev);
        else
            return f(n - 1, 2, prev);
    }
    else if(prev == 2) {
        return f(n - 1, 1, prev) + f(n - 1, 3, prev);
    }
    else if(prev == 3) {
        return f(n - 1, 1, prev) + f(n - 1, 2, prev);
    }
    else 
        return f(n - 1, 2, prev) + f(n - 1, 3, prev);
}

long long find_Ways(int N) {
    return f(N, 5, 4);
}

