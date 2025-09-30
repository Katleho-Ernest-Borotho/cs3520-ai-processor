#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

// Dictionary lookup
string translate(const string& word, unordered_map<string,string>& dict) {
    if (dict.find(word) != dict.end()) return dict[word];
    return word; // fallback
}

// Simple waveform synthesis loop (sine wave samples)
void synthesize(int samples) {
    float phase = 0;
    float freq = 440; // A4 note
    float step = 2*M_PI*freq/16000; // assume 16kHz sample rate

    for (int i = 0; i < samples; i++) {
        float val = sin(phase); // costly math op
        cout << val << " ";     
        phase += step;
    }
    cout << endl;
}

int main() {
    unordered_map<string,string> dict;
    dict["hello"] = "lumela";
    dict["money"] = "chelete";

    string word = "hello";
    string translated = translate(word, dict);
    cout << word << " -> " << translated << endl;

    cout << "Synthesized waveform: ";
    synthesize(8); // generate 8 samples

    return 0;

}
