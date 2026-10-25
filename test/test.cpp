#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "AdjacencyList.h"
//#include "AdjacencyList.cpp"
//#include "main.cpp"

using namespace std;


// You must write 5 unique, meaningful tests for credit on the testing section
// of this project!
//My 5 Test cases Below


//tests all nodes pointing to same website
TEST_CASE("Case1", "[flag]") {

   AdjacencyList* testList1 = new AdjacencyList();


   testList1->insertEdge("google.com", "maps.com");
   testList1->insertEdge("facebook.com", "maps.com");
   testList1->insertEdge("ufl.edu", "maps.com");
   testList1->insertEdge("gmail.com", "maps.com");
   testList1->insertEdge("maps.com", "maps.com");



   int power_iterations = 2;
   testList1->PageRank(power_iterations);


   std::string actualOutput = testList1->PageRank(power_iterations);


   std::string expectedOutput = R"(facebook.com 0.00
gmail.com 0.00
google.com 0.00
maps.com 1.00
ufl.edu 0.00
)";




   REQUIRE(actualOutput == expectedOutput);
}

//tests 100 power iterations
TEST_CASE("Case2", "[flag]") {

   AdjacencyList* testList2 = new AdjacencyList();


   testList2->insertEdge("google.com", "apple.com");
   testList2->insertEdge("pcbuildinguf.com", "google.com");
   testList2->insertEdge("youtube.com", "instagram.com");
   testList2->insertEdge("google.com", "pcbuildinguf.com");
   testList2->insertEdge("pcbuildinguf.com", "youtube.com");
   testList2->insertEdge("instagram.com", "google.com");
   testList2->insertEdge("google.com", "ufl.edu");
   testList2->insertEdge("youtube.com", "disney.com");
   testList2->insertEdge("disney.com", "ufl.edu");


   int power_iterations = 100;
   testList2->PageRank(power_iterations);


   std::string actualOutput = testList2->PageRank(power_iterations);


   std::string expectedOutput = R"(apple.com 0.00
disney.com 0.00
google.com 0.00
instagram.com 0.00
pcbuildinguf.com 0.00
ufl.edu 0.00
youtube.com 0.00
)";



   REQUIRE(actualOutput == expectedOutput);
}

//testing one input
TEST_CASE("Case3", "[flag]") {

   AdjacencyList* testList3 = new AdjacencyList();


   testList3->insertEdge("google.com", "google.com");

   int power_iterations = 2;
   testList3->PageRank(power_iterations);

   std::string actualOutput = testList3->PageRank(power_iterations);


   std::string expectedOutput = R"(google.com 1.00
)";



   REQUIRE(actualOutput == expectedOutput);
}

//Testing one node pointing to 3 other nodes
TEST_CASE("Case4", "[flag]") {

   AdjacencyList* testList4 = new AdjacencyList();

   testList4->insertEdge("apple.com", "google.com");
   testList4->insertEdge("apple.com", "ufl.edu");
   testList4->insertEdge("apple.com", "costco.com");

   int power_iterations = 2;
   testList4->PageRank(power_iterations);


   std::string actualOutput = testList4->PageRank(power_iterations);

   std::string expectedOutput = R"(apple.com 0.00
costco.com 0.08
google.com 0.08
ufl.edu 0.08)";


   REQUIRE(actualOutput == expectedOutput);
}

//Test a Cycle graph. All pages should have an equal page rank in a cycle.
TEST_CASE("Case5", "[flag]") {

   AdjacencyList* testList5 = new AdjacencyList();


   testList5->insertEdge("apple.com", "google.com");
   testList5->insertEdge("google.com", "ufl.edu");
   testList5->insertEdge("ufl.edu", "costco.com");
   testList5->insertEdge("costco.com", "youtube.com");
   testList5->insertEdge("youtube.com", "apple.com");

   int power_iterations = 5;
   testList5->PageRank(power_iterations);


   std::string actualOutput = testList5->PageRank(power_iterations);

   std::string expectedOutput = R"(apple.com 0.20
costco.com 0.20
google.com 0.20
ufl.edu 0.20
youtube.com 0.20)";



   REQUIRE(actualOutput == expectedOutput);
}
