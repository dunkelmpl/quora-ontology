#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Ontology {
private:
    struct Topic {
        Topic(string name) : name(name), children(0) {}

        void addChild(Topic child)
        {
            children.push_back(child);
        }

        vector<Topic> children;
    };

public:
    Ontology(string flatTree, vector<string> questions, vector<string> queries)
        : questions(questions), queries(queries)
    {
        this->loadTree(flatTree);
    }

    void loadAnswers()
    {
    }

    const vector<long>& getAnswers() const
    {
        return this->answers;
    }

protected:
    void loadTree(string flatTree)
    {
    }

private:
    vector<string> questions;
    vector<string> queries;
    vector<long> answers;
};

int main()
{
    // Num topics
    size_t N;

    cin >> N;

    string flatTree;
    cin >> flatTree;

    // Num questions
    size_t M;
    cin >> M;

    vector<string> questions(M);

    for (auto& q : questions) {
        cin >> q;
    }

    // Num queries
    size_t K;
    cin >> K;

    vector<string> queries(K);

    for (auto& q : queries) {
        cin >> q;
    }

    Ontology ontology(flatTree, questions, queries);
    ontology.loadAnswers();

    for (auto& answer : ontology.getAnswers()) {
        cout << answer << '\n';
    }

    cout.flush();

    return 0;
}