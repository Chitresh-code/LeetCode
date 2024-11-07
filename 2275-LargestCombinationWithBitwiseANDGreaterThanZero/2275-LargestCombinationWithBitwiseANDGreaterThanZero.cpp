for (int i = 0; i < 32; i++) {
    for (int num : candidates) {
    // Check if the i-th bit is set.
        if ((num & (1 << i)) != 0) {
                bitCount[i]++;
            }
        }
    }