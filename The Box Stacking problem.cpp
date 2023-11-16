/*
The Box Stacking problem is a variation of the Longest Increasing Subsequence (LIS) problem. In this problem, you are given a set of boxes, and each box can be rotated to use any side as the base. The goal is to build the tallest stack possible by stacking boxes on top of each other, with the condition that each box must have strictly smaller width and depth than the box below it.

This problem can be solved using dynamic programming. The key steps are to generate all rotations of the boxes, sort them based on their base area (width * depth), and then apply a variation of the LIS algorithm. The time complexity of this solution is O(n²), where n is the total number of box rotations, and the space complexity is O(n).

Here's a basic implementation in C++:

1. **Include Necessary Headers:** Use `<iostream>`, `<vector>`, `<algorithm>`.
2. **Read User Input:** Get the dimensions of the boxes from the user.
3. **Algorithm Steps:**
   - Generate all rotations of each box.
   - Sort the boxes based on their base area.
   - Apply dynamic programming to find the maximum height stack.
4. **Return the Result:** The maximum height of the stack.

```cpp
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Box structure
struct Box {
    int h, w, d; // Height, width, depth
};

// Function to get all rotations of a box
vector<Box> getRotations(vector<Box>& boxes) {
    vector<Box> rotations;
    for (Box& box : boxes) {
        rotations.push_back({box.h, max(box.w, box.d), min(box.w, box.d)}); // Base: w x d
        rotations.push_back({box.w, max(box.h, box.d), min(box.h, box.d)}); // Base: h x d
        rotations.push_back({box.d, max(box.w, box.h), min(box.w, box.h)}); // Base: w x h
    }
    return rotations;
}

// Function to sort boxes based on base area
bool compare(Box a, Box b) {
    return a.w * a.d > b.w * b.d;
}

// Function to find the maximum height of the stack
int maxStackHeight(vector<Box>& boxes) {
    vector<Box> rotations = getRotations(boxes);
    sort(rotations.begin(), rotations.end(), compare);

    int n = rotations.size();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        dp[i] = rotations[i].h;
        for (int j = 0; j < i; j++) {
            if (rotations[i].w < rotations[j].w && rotations[i].d < rotations[j].d) {
                dp[i] = max(dp[i], dp[j] + rotations[i].h);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter the number of boxes: ";
    cin >> n;

    vector<Box> boxes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter height, width, and depth of box " << i + 1 << ": ";
        cin >> boxes[i].h >> boxes[i].w >> boxes[i].d;
    }

    cout << "The maximum height of the stack is: " << maxStackHeight(boxes) << endl;
    return 0;
}
/*
```

In this code:
- The `Box` structure represents a box.
- `getRotations` function generates all rotations of the input boxes.
- Boxes are sorted in decreasing order of their base area.
- The `maxStackHeight` function applies dynamic programming to find the maximum height of the stack that can be formed.
- In `main`, user input is taken for the boxes, and the maximum stack height is calculated and displayed.
*/
