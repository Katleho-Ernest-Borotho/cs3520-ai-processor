#include <iostream>
#include <vector>
using namespace std;

// Compute dot product of two vectors (core workload)
float vector_dot(const vector<float>& a, const vector<float>& b) {
    float acc = 0.0f;
    for (int i = 0; i < (int)a.size(); i++) {
        acc += a[i] * b[i]; // MAC operation
    }
    return acc;
}

int main() {
    // Example: 8-element feature frame vs template
    vector<float> frame = {1,2,3,4,5,6,7,8};
    vector<float> templ = {0.5,0.4,0.3,0.2,0.1,0, -0.1, -0.2};

    float score = vector_dot(frame, templ);
    cout << "Dot product score = " << score << endl;

    return 0;
}