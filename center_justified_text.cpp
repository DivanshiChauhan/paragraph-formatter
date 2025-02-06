#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class ParagraphFormatter {
private:
    int maxWidth;
    int maxWords;
    vector<string> words;

public:
    ParagraphFormatter(int width, int wordLimit) : maxWidth(width), maxWords(wordLimit) {}

    void addText(const string& text) {
        stringstream ss(text);
        string word;
        int wordCount = 0;

        while (ss >> word && wordCount < maxWords) {
            words.push_back(word);
            wordCount++;
        }
    }

    void formatAndPrintParagraph() {
        vector<string> line;
        int lineLength = 0;

        for (const string& word : words) {
            if (lineLength + word.length() + (line.empty() ? 0 : 1) > maxWidth) { 
                printCentered(line, lineLength);
                line.clear();
                lineLength = 0;
            }
            line.push_back(word);
            lineLength += word.length() + (line.size() > 1 ? 1 : 0);
        }

        if (!line.empty()) {
            printCentered(line, lineLength);
        }
    }

private:
    void printCentered(const vector<string>& line, int lineLength) {
        int spacesNeeded = maxWidth - lineLength;
        int leftPadding = spacesNeeded / 2;

        cout << string(leftPadding, ' ');  

        for (size_t i = 0; i < line.size(); ++i) {
            if (i > 0) cout << " ";
            cout << line[i];
        }
        cout << endl;
    }
};

int main() {
    int maxWidth, maxWords;
    string text;

    cout << "Enter maximum width of a line: ";
    cin >> maxWidth;
    cin.ignore();

    cout << "Enter maximum number of words: ";
    cin >> maxWords;
    cin.ignore();

    cout << "Enter your paragraph:\n";
    getline(cin, text);

    ParagraphFormatter formatter(maxWidth, maxWords);
    formatter.addText(text);

    cout << "\nFormatted Paragraph:\n";
    formatter.formatAndPrintParagraph();

    return 0;
}
