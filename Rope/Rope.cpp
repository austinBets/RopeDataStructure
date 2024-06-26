#include "Rope.h"
#include <iostream>
using namespace std;


//Public functions__________________________________________________________________________________________________________
Rope::Rope(){
    leafNodeMaxSize = 3; // maximum size that a leaf can be.
}

//Deconstructor working with shared pointers so no need.
Rope::~Rope(){

}

//CreateRope takes a root node and a sentence and converts that into a rope data structure, through recursion.
void Rope::CreateRope(shared_ptr<ropeNode> node, string sentence){
    int sentenceSize = sentence.size();
    if(sentenceSize > leafNodeMaxSize) { //Making an internal node.
        node->words = "";
        node->isLeaf = false;
        node->weight = sentenceSize/2;
        shared_ptr<ropeNode> left (new ropeNode);
        shared_ptr<ropeNode> right (new ropeNode);
        node->left = left;
        node->right = right;
        string frontHalf = sentence.substr(0,(sentenceSize)/2);
        string backHalf = sentence.substr((sentenceSize)/2,sentenceSize-1);
        CreateRope(node->left,frontHalf);
        CreateRope(node->right,backHalf);
    }
    else{ //making a leaf node.
        node->words = sentence;
        node->weight = sentence.size();
        node->isLeaf = true;
        node->left = NULL;
        node->right = NULL;
        
    }

}

//Concatenate adds two ropes together to create one large rope by combining the strings.
shared_ptr<ropeNode> Rope::Concatenate(shared_ptr<ropeNode> r1, shared_ptr<ropeNode> r2) {
    shared_ptr<ropeNode> parent (new ropeNode);
    //concatHelper(r1);
    parent->weight =StringLength(r1);
    rootweight = 0;
    parent->left = r1;
    parent->right = r2;
    parent->isLeaf = false;
    parent->words = "";
    return parent;
}

//Delete takes a rope structure a starting index and the number of characters the user wants to be removed.
//It captures all the text within the orginal node. Removes the strings that need to be removed. Then creates a new
//rope with that information removed.
shared_ptr<ropeNode> Rope::Delete(shared_ptr<ropeNode> node,int startingIndex, int numberOfCharactersRemoved){
    string fullText = FullText(node);
    fullText = fullText.erase(startingIndex,numberOfCharactersRemoved);
    shared_ptr<ropeNode> ret(new ropeNode);
    CreateRope(ret,fullText);
    return ret;

}

//Insert takes a rope data structure a sentence the user wants to insert and an index where the text will be inserted.
//it grabs the complete rope string then inserts where the user wants to then adds the index to the function.
shared_ptr<ropeNode> Rope::Insert(shared_ptr<ropeNode> node, string sentence, int index) {
    string fullText = FullText(node);
    fullText.insert(index,sentence);
    shared_ptr<ropeNode> ret(new ropeNode);
    CreateRope(ret,fullText);
    return ret;
}

//Report couts all the text within a rope
void Rope::Report(shared_ptr<ropeNode> node){
    if (node->isLeaf == true) {
        cout << node->words;
        return;
    }
    
    Report(node->left);
    Report(node->right);
}

//Helper function for both the testing software and insert and delete. it allows the user to save the complete string.
//to one variable.
string Rope::FullText(shared_ptr<ropeNode>node){
    if(node->isLeaf == true){
        return node->words;
    }
    else{
        return node->words + FullText(node->left) + FullText(node->right);
    }

}

//Private Functions_________________________________________________________________________________________________________


int Rope::StringLength(shared_ptr<ropeNode> node){
    if (node->isLeaf == true){
        return node->weight;
    }
    StringLength(node->left);
    return StringLength(node->right);
}

void Rope::concatHelper(shared_ptr<ropeNode> r1){
    if (r1->isLeaf == true){
        rootweight += r1->weight;
        return; 
    }
    else{
        concatHelper(r1->left);
        return concatHelper(r1->right);
    }
}
