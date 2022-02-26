//
//  main.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 02/06/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "NQueens.hpp"
#include "GraphColoring.hpp"
#include "FibonacciMemoize.hpp"
#include "Sorting/MergeSort.hpp"
#include "LinkedList/LinkedList.h"
#include "ADT/Stack.h"
#include "ADT/StackLL.h"
#include "ADT/Queue.h"
#include "Trees/BinarySearchTree.h"
#include "ADT/Heap.hpp"
#include "HashTable/HashTable.hpp"
#include "Graph/BreadthFirstSearch.hpp"
#include "Graph/DepthFirstSearch.hpp"
#include "Dijkstra/DijkstraAlgorithm.hpp"
#include "BellmanFord/BellmanFord.hpp"
#include "SubstringSearch/SubstringSearch.h"
#include "Sorting/QuickSort.hpp"
#include "Sorting/InsertionSort.h"
#include "Trees/Trie.h"
#include "ADT/CircularQueue.h"

void Hanoi(int noOfDisks, char TowerSource, char TowerDestination, char TowerAux)
{
    //Base case if there is only 1 disk. Then we simply move the disk from A to C.
    if(noOfDisks == 1){
        std::cout<<"Move disk "<<noOfDisks<<" from Tower "<<TowerSource<<" to Tower "<<TowerDestination<<std::endl;
        return;
    }
    Hanoi(noOfDisks-1, TowerSource, TowerAux, TowerDestination);
    std::cout<<"Move disk "<<noOfDisks<<" from Tower "<<TowerSource<<" to Tower "<<TowerDestination<<std::endl;
    Hanoi(noOfDisks-1, TowerAux, TowerDestination, TowerSource);
}

int Factorial(int n){
    if(n==1){
        return 1;
    }
    int m = Factorial(n-1);
    return n*m;
}

bool Palindrome(std::string name)
{
    if(name.size()<=1)
    {
        return true;
    }
    else
    {
        if(name[0]==name[name.size()-1])
        {
            return Palindrome(name.substr(1,name.size()-2));
        }
        else
        {
            return  false;
        }
    }
    
}

int sumOfDigits(int num){
    if(num<10){
        return num;
    }
    int sum = num%10+sumOfDigits(num/10);
    return sum;
}

int binarySearch(int nums[], int value, int low, int high){
    
    if(low>high){
        return -1;
    }
    
    int mid = low+(high-low)/2;
    
    if(value==nums[mid]){
        return mid;
    }
    
    if(value>nums[mid]){
        return binarySearch(nums, value, mid+1, high);
    }else{
        return binarySearch(nums, value, low, mid-1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //Hanoi(3, 'A', 'C', 'S');
    //std::cout<<Factorial(5);
    //std::cout<<Palindrome("raddars")<<"\n";
    //std::cout<<sumOfDigits(157)<<"\n";
    
    //int nums[]={1,3,4,6,7,8};
    //std::cout<<binarySearch(nums, 8, 0, 5)<<std::endl;
    
    //QueensProblem queensProblem{4};
    //queensProblem.solve();
    
    /*std::vector<std::vector<int>> adjacencyMatrix={
        {0,1,0,1,0},
        {1,0,1,1,0},
        {0,1,0,1,0},
        {1,1,1,0,1},
        {0,0,0,1,0}
    };
    GraphColoring graphColoring(adjacencyMatrix,3);
    graphColoring.solve();*/
    
    //FibonacciMemoize fibonacci;
    //std::cout<<fibonacci.FibonacciResult(60)<<"\n";
    
    /*std::vector<int> vect ={5,1,2,-9,30,300,-600,14,-9000};
    MergeSort mergeSrt;
    vect = mergeSrt.MergeSortImpl(vect);
    
    for (int i=0; i<vect.size(); i++) {
        std::cout<<vect[i]<<"->";
    }*/
    
    /*std::unique_ptr<List<int>> linkedList = std::make_unique<LinkedList<int>>();
    linkedList->push(5);
    linkedList->push(10);
    linkedList->push(15);
    linkedList->push(25);
    
    linkedList->remove(15);
    linkedList->traverseList();*/
    
    /*StackLL<std::string> stack;
    stack.push("Adam");
    stack.push("Joe");
    std::cout<<stack.size()<<"\n";
    std::cout<<stack.pop()<<"\n";
    std::cout<<stack.size()<<"\n";
    std::cout<<stack.pop()<<"\n";
    std::cout<<stack.size()<<"\n";*/
    
    /*Queue<std::string> queue;
    queue.enqueue("Ada");
    queue.enqueue("Wong");
    std::cout<<queue.size()<<"\n";
    std::cout<<queue.dequeue()<<"\n";
    std::cout<<queue.size()<<"\n";
    std::cout<<queue.dequeue()<<"\n";
    std::cout<<queue.size()<<"\n";*/
    
    /*std::unique_ptr<Tree<int>> bst = std::make_unique<BinarySearchTree<int>>();
    bst->insert(12);
    bst->insert(4);
    bst->insert(20);
    bst->insert(1);
    bst->insert(7);
    bst->insert(23);
    bst->insert(5);
    
    bst->remove(4);

    std::cout<<bst->getMinValue()<<"\n"<<bst->getMaxValue()<<"\n";
    bst->traversal();*/
    
    /*Heap heap{};
    heap.insert(8);
    heap.insert(20);
    heap.insert(300);
    heap.insert(-2);
    heap.insert(0);
    heap.insert(321);
    heap.heapSort();*/
    
    /*HashTable hashTable{};
    hashTable.put(1, 22);
    hashTable.put(11, 10);
    hashTable.put(21, 100);
    hashTable.put(1, 3);
    
    std::cout<<hashTable.get(1)<< " "<<hashTable.get(21)<< "\n";*/
    
    /*BreadthFirstSearch bfs;
    std::shared_ptr<Vertex> vertex1 = std::make_shared<Vertex>("A");
    std::shared_ptr<Vertex> vertex2 = std::make_shared<Vertex>("B");
    std::shared_ptr<Vertex> vertex3 = std::make_shared<Vertex>("C");
    std::shared_ptr<Vertex> vertex4 = std::make_shared<Vertex>("D");
    std::shared_ptr<Vertex> vertex5 = std::make_shared<Vertex>("E");
    std::shared_ptr<Vertex> vertex6 = std::make_shared<Vertex>("F");
    std::shared_ptr<Vertex> vertex7 = std::make_shared<Vertex>("G");
    std::shared_ptr<Vertex> vertex8 = std::make_shared<Vertex>("H");
    
    vertex1->addNeighbour(vertex2.get());
    vertex1->addNeighbour(vertex6.get());
    vertex1->addNeighbour(vertex7.get());
    
    vertex7->addNeighbour(vertex8.get());
    
    vertex2->addNeighbour(vertex3.get());
    vertex2->addNeighbour(vertex4.get());
    
    vertex4->addNeighbour(vertex5.get());
    
    bfs(vertex1);*/
    
    /*std::vector<std::shared_ptr<Vertex>> graph;
    graph.resize(8);
    graph[0] = std::make_shared<Vertex>("A");
    graph[1] = std::make_shared<Vertex>("B");
    graph[2] = std::make_shared<Vertex>("C");
    graph[3] = std::make_shared<Vertex>("D");
    graph[4] = std::make_shared<Vertex>("E");
    graph[5] = std::make_shared<Vertex>("F");
    graph[6] = std::make_shared<Vertex>("G");
    graph[7] = std::make_shared<Vertex>("H");
    
    graph[0]->addNeighbour(graph[1].get());
    graph[0]->addNeighbour(graph[4].get());
    graph[0]->addNeighbour(graph[5].get());
    graph[6]->addNeighbour(graph[7].get());
    graph[1]->addNeighbour(graph[2].get());
    graph[1]->addNeighbour(graph[3].get());
    graph[3]->addNeighbour(graph[4].get());
    
    DepthFirstSearch dfs(graph);
    dfs();*/
    
    /*std::vector<std::shared_ptr<DVertex>> graph;
    graph.push_back(std::make_shared<DVertex>("A"));
    graph.push_back(std::make_shared<DVertex>("B"));
    graph.push_back(std::make_shared<DVertex>("C"));
    graph.push_back(std::make_shared<DVertex>("D"));
    graph.push_back(std::make_shared<DVertex>("E"));
    graph.push_back(std::make_shared<DVertex>("F"));
    graph.push_back(std::make_shared<DVertex>("G"));
    graph.push_back(std::make_shared<DVertex>("H"));
    
    std::shared_ptr<Edge> edge01 = std::make_shared<Edge>(5, graph[0], graph[1]);
    std::shared_ptr<Edge> edge04 = std::make_shared<Edge>(9, graph[0], graph[4]);
    std::shared_ptr<Edge> edge07 = std::make_shared<Edge>(8, graph[0], graph[7]);
    std::shared_ptr<Edge> edge13 = std::make_shared<Edge>(12, graph[1], graph[3]);
    std::shared_ptr<Edge> edge14 = std::make_shared<Edge>(15, graph[1], graph[4]);
    std::shared_ptr<Edge> edge17 = std::make_shared<Edge>(4, graph[1], graph[7]);
    std::shared_ptr<Edge> edge23 = std::make_shared<Edge>(3, graph[2], graph[3]);
    std::shared_ptr<Edge> edge26 = std::make_shared<Edge>(11, graph[2], graph[6]);
    std::shared_ptr<Edge> edge36 = std::make_shared<Edge>(9, graph[3], graph[6]);
    std::shared_ptr<Edge> edge45 = std::make_shared<Edge>(4, graph[4], graph[5]);
    std::shared_ptr<Edge> edge46 = std::make_shared<Edge>(20, graph[4], graph[6]);
    std::shared_ptr<Edge> edge47 = std::make_shared<Edge>(5, graph[4], graph[7]);
    std::shared_ptr<Edge> edge52 = std::make_shared<Edge>(1, graph[5], graph[2]);
    std::shared_ptr<Edge> edge56 = std::make_shared<Edge>(13, graph[5], graph[6]);
    std::shared_ptr<Edge> edge72 = std::make_shared<Edge>(7, graph[7], graph[2]);
    std::shared_ptr<Edge> edge75 = std::make_shared<Edge>(6, graph[7], graph[5]);
    
    graph[0]->addNeighbour(edge01.get());
    graph[0]->addNeighbour(edge04.get());
    graph[0]->addNeighbour(edge07.get());
    graph[1]->addNeighbour(edge13.get());
    graph[1]->addNeighbour(edge14.get());
    graph[1]->addNeighbour(edge17.get());
    graph[2]->addNeighbour(edge23.get());
    graph[2]->addNeighbour(edge26.get());
    graph[3]->addNeighbour(edge36.get());
    graph[4]->addNeighbour(edge45.get());
    graph[4]->addNeighbour(edge46.get());
    graph[4]->addNeighbour(edge47.get());
    graph[5]->addNeighbour(edge52.get());
    graph[5]->addNeighbour(edge56.get());
    graph[7]->addNeighbour(edge72.get());
    graph[7]->addNeighbour(edge75.get());
    
    DijkstraAlgorithm sp;
    sp.computePaths(graph[0]);
    
    auto path = sp.getShortestPath(graph[6]);
    for (DVertex* vertex : path) {
        std::cout<< *vertex << ' ';
    }*/
    
    /*std::vector<BVertex> vertexList;
    vertexList.push_back(BVertex("A"));
    vertexList.push_back(BVertex("B"));
    vertexList.push_back(BVertex("C"));
    vertexList.push_back(BVertex("D"));
    vertexList.push_back(BVertex("E"));
    vertexList.push_back(BVertex("F"));
    vertexList.push_back(BVertex("G"));
    vertexList.push_back(BVertex("H"));
    
    std::vector<BEdge> edgeList;
    edgeList.push_back(BEdge(&vertexList[0], &vertexList[1], 5));
    edgeList.push_back(BEdge(&vertexList[0], &vertexList[4], 9));
    edgeList.push_back(BEdge(&vertexList[0], &vertexList[7], 8));
    edgeList.push_back(BEdge(&vertexList[1], &vertexList[3], 12));
    edgeList.push_back(BEdge(&vertexList[1], &vertexList[4], 15));
    edgeList.push_back(BEdge(&vertexList[1], &vertexList[7], 4));
    edgeList.push_back(BEdge(&vertexList[2], &vertexList[3], 3));
    edgeList.push_back(BEdge(&vertexList[2], &vertexList[6], 11));
    edgeList.push_back(BEdge(&vertexList[3], &vertexList[6], 9));
    edgeList.push_back(BEdge(&vertexList[4], &vertexList[5], 4));
    edgeList.push_back(BEdge(&vertexList[4], &vertexList[6], 20));
    edgeList.push_back(BEdge(&vertexList[4], &vertexList[7], 5));
    edgeList.push_back(BEdge(&vertexList[5], &vertexList[2], 1));
    edgeList.push_back(BEdge(&vertexList[5], &vertexList[6], 13));
    edgeList.push_back(BEdge(&vertexList[7], &vertexList[2], 7));
    edgeList.push_back(BEdge(&vertexList[7], &vertexList[5], 6));
    
    BellmanFord bellmanFordAlgo = BellmanFord(vertexList, edgeList);
    bellmanFordAlgo(0, 6);*/
    
    /*SubstringSearch substringSearch;
    char text[] = "abcabcertabcd";
    char pattern[] = "abcd";
    std::cout<<substringSearch.bruteForceSearch(pattern, text)<<std::endl;*/
    
    /*QuickSort quickSort;
    InsertionSort insertionSrt;
    std::vector<int> arr = {12,4,123,55,1,0,-9,-12,1};
    //insertionSrt.insertionSort(arr);
    quickSort.QuickSortRun(arr);
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout<<arr[i]<<"\n";
    }*/
    
    /*
    Trie* trie = new Trie();
    trie->insert("cats");
    trie->insert("cape");
    std::cout<<trie->prefixExists("ca")<<std::endl;
    std::cout<<trie->wordExists("caps")<<std::endl;
    std::cout<<trie->wordExists("cape")<<std::endl;
    std::cout<<trie->prefixExists("cap")<<std::endl;
    */
    
    CircularQueue<int> cQueue(5);
    cQueue.push(5);
    cQueue.push(7);
    cQueue.push(9);
    cQueue.push(11);
    cQueue.push(13);
    cQueue.push(15);//wont get pushed coz out of size.
    cQueue.pop();
    cQueue.push(17);
    while (!cQueue.isEmpty()) {
        std::cout<<cQueue.peekFront()<<"\n";
        cQueue.pop();
    }
    
    
    return 0;
}
