#include "Rope/Rope.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    shared_ptr<Rope> rope(new Rope());

    // Creating initial rope
    shared_ptr<ropeNode> root(new ropeNode);
    string initialText = "HelloRopeStructure";
    rope->CreateRope(root, initialText);

    cout << "Initial rope structure: ";
    rope->Report(root);
    cout << endl;

    // Concatenating another rope
    shared_ptr<ropeNode> anotherRope(new ropeNode);
    string additionalText = "Example";
    rope->CreateRope(anotherRope, additionalText);

    shared_ptr<ropeNode> concatenatedRope = rope->Concatenate(root, anotherRope);

    cout << "After concatenation: ";
    rope->Report(concatenatedRope);
    cout << endl;

    // Deleting part of the rope
    shared_ptr<ropeNode> deletedRope = rope->Delete(concatenatedRope, 5, 5);

    cout << "After deletion: ";
    rope->Report(deletedRope);
    cout << endl;

    // Inserting into the rope
    shared_ptr<ropeNode> insertedRope = rope->Insert(deletedRope, "Insertion", 5);

    cout << "After insertion: ";
    rope->Report(insertedRope);
    cout << endl;

    return 0;
}

