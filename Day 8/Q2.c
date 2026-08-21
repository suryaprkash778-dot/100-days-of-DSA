bool isPowerOfTwo(int n) {
    if (n <= 0) return false;  // handle non-positive numbers
    while (n > 1) {
        if (n % 2 != 0) return false;  // if not divisible by 2, not a power of two
        n /= 2;
    }
    return true;
}
