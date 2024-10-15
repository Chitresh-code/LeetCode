public long minimumSteps(String s) { 
    long swaps = 0, zeros = 0;
    for (int i = s.length() - 1; i >= 0; i--) 
        if (s.charAt(i) == '1') swaps += zeros;
        else zeros++;
    return swaps; 
}