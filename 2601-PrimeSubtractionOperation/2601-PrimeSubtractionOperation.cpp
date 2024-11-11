int binary_search(vector<int>& v, int x, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (v[mid] == x) {
        return mid - 1;
    } else if (v[mid] < x) {
        if (mid + 1 == v.size() or v[mid + 1] >= x) {
            return mid;
        } else {
            return binary_search(v, x, mid + 1, right);
        }
    }
    return binary_search(v, x, left, mid - 1);
}

bool primeSubOperation(vector<int>& nums) {
    vector<int> vg;
    vector<bool> vb(1000, true);
    for (int i = 2; i < vb.size(); ++i) {
        if (vb[i]) {
            vg.emplace_back(i);
            for (int k = 1; k * i <= vb.size(); ++k) {
                vb[i * k] = false;
            }
        }
    }
    int prev = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int pos = binary_search(vg, nums[i] - prev, 0, vg.size() - 1);
        if (pos < 0) {
            if (nums[i] <= prev) {
                return false;
            }
            else {
                prev = nums[i];
                continue;
            }
        }
        prev = nums[i] - vg[pos];
    }
    return true;
}