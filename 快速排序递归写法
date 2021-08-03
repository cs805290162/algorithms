int partition(vector<int> &nums, int low, int high) {

    int left = low;
    int right = high;
    int pivot = nums[left]; /// 随意取一个值作为pivot，此处为了方便取最左

    while (left < right) {
        while (left < right && pivot <= nums[right]) { /// 先从右往左找一个比pivot小的数
            right--;
        }
        nums[left] = nums[right]; /// 找到之后把它放到左边
        while (left < right && pivot >= nums[left]) { /// 再从左往右找一个比pivot大的数
            left++;
        }
        nums[right] = nums[left]; /// 找到之后把它放到右边
    }
    /// 循环结束时left == right
    /// 直接把pivot放在这个位置
    nums[left] = pivot;

    return left;
}

/// 实际相当于二叉树的前序遍历
void quickSort(vector<int> nums, int low, int high) {

    if (low >= high) {
        return;
    }
    int pivot = partition(nums, low, high);
    pivot = partition(nums, low, high);
    quickSort(nums, low, pivot - 1);
    quickSort(nums, pivot + 1, high);
}
