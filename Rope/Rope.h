//#include "Rope.cpp"
#ifndef Rope_H__
#define Rope_H__

#include <string>
#include <memory>
#include <vector>

using namespace std;

struct ropeNode{
    bool isLeaf;
    int weight;
    string words;
    shared_ptr<ropeNode> left;
    shared_ptr<ropeNode> right;
};

class Rope {
public:
    
    Rope(); // constructor
    
    ~Rope(); //Deconstructor
    
     //CreateInitialRope will take a string and convert that string into a rope data Structure.
    void CreateRope(shared_ptr<ropeNode> root, string sentence);

    //concate combines two ropes togther.
    shared_ptr<ropeNode> Concatenate(shared_ptr<ropeNode> r1, shared_ptr<ropeNode> r2);

    //Delete removes a certain amount of characters starting at an index that the user wants.  
    shared_ptr<ropeNode> Delete(shared_ptr<ropeNode> node,int StartingIndex, int numberOfCharactersRemoved);

    //Insert inserts a given sentence at a given index provided by the user.
    shared_ptr<ropeNode> Insert(shared_ptr<ropeNode> node, string sentence, int index);

    //Report outputs the entire string.
    void Report(shared_ptr<ropeNode> node);

    //FullText returns all the text in the rope. Allows user to save text to single variable.
    string FullText(shared_ptr<ropeNode> node);
    
    
private:
    //leaf node max size
    int leafNodeMaxSize;
    
    //helper items for concatenating.
    void concatHelper(shared_ptr<ropeNode> r1);
    int rootweight;
    int StringLength(shared_ptr<ropeNode> root);

};

#endif //Rope_H__