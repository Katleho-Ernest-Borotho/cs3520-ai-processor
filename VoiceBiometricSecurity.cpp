#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float dot(const vector<float>& a, const vector<float>& b) {
    float acc = 0;
    for (int i = 0; i < (int)a.size(); i++) acc += a[i] * b[i];
    return acc;
}

float norm(const vector<float>& a) {
    return sqrt(dot(a,a)); 
}

float cosine_similarity(const vector<float>& a, const vector<float>& b) {
    return dot(a,b) / (norm(a) * norm(b));
}

int main() {
    vector<float> v1 = {1,2,3,4};
    vector<float> v2 = {1,1,1,1};

    float sim = cosine_similarity(v1, v2);
    cout << "Cosine similarity = " << sim << endl;

    return 0;
}
