// #503. Next Greater Element II

// #Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// # Intution: This solution efficiently computes the next greater element for each item in a circular array using a monotonic decreasing stack and reverse traversal. It iterates through the array twice (from end to start) to simulate the circular nature, using i % n to wrap around the indices. At each step, it removes elements from the stack that are less than or equal to the current value, ensuring that the stack always contains potential next greater elements in decreasing order. For the first n elements (i.e., during the actual array pass), it updates the result array with the top of the stack if the stack is not empty — this top represents the next greater element. After that, the current element is pushed to the stack so it can be considered as a next greater element for upcoming elements. 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // Monotonic decreasing stack (store values)

        for (int i = 2 * n - 1; i >= 0; --i) {
            int current = nums[i % n];

            // Maintain decreasing order
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // Only update result in the first pass
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }

            // Push current value to stack
            st.push(current);
        }

        return ans;
    }
};

