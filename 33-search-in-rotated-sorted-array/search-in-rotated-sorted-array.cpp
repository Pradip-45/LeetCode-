class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        if (n == 1) {
            return (nums[0] == target) ? 0 : -1;
        }

        if (n == 2) {
            if (target == nums[0]) return 0;
            if (target == nums[1]) return 1;
            return -1;
        }

        int pivot = -1;

        // Find Pivot
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid == 0)
                lo = mid + 1;
            else if (mid == n - 1)
                hi = mid - 1;
            else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]) {
                pivot = mid - 1;
                break;
            }
            else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                pivot = mid;
                break;
            }
            else if (nums[mid] < nums[hi])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        // Array is not rotated
        if (pivot == -1) {
            lo = 0;
            hi = n - 1;
        }
        // Target lies in first half
        else if (target >= nums[0] && target <= nums[pivot]) {
            lo = 0;
            hi = pivot;
        }
        // Target lies in second half
        else {
            lo = pivot + 1;
            hi = n - 1;
        }

        // Normal Binary Search
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return -1;
    }
};