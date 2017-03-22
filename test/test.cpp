#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <vector>
#include <algorithm/mergesort.hpp>
#include <algorithm/quicksort.hpp>

struct SortingTest {
  std::vector<int> in;
  std::vector<int> out;
};

std::vector<SortingTest> sorting_tests = {
  {{4, 5, 2, 1}, {1, 2, 4, 5}},
  {{1, 1, 1, 1}, {1, 1, 1, 1}},
};

class AlgorithmTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(AlgorithmTest);
  CPPUNIT_TEST(TestMergeSort);
  CPPUNIT_TEST(TestQuickSort);
  CPPUNIT_TEST_SUITE_END();
public:
  virtual void setUp() {}
  virtual void tearDown() {}
protected:
  void TestMergeSort() {
    for (int i = 0; i < sorting_tests.size(); i++) {
      SortingTest t = sorting_tests[i];
      std::vector<int> in_ = t.in;
      algorithm::mergesort(std::begin(in_), std::end(in_));
      for (int j = 0; j < in_.size(); j++) {
        CPPUNIT_ASSERT_EQUAL(in_[j], t.out[j]);
      }
    }
  }
  void TestQuickSort() {
    for (int i = 0; i < sorting_tests.size(); i++) {
      SortingTest t = sorting_tests[i];
      std::vector<int> in_ = t.in;
      algorithm::quicksort(std::begin(in_), std::end(in_));
      for (int j = 0; j < in_.size(); j++) {
        CPPUNIT_ASSERT_EQUAL(in_[j], t.out[j]);
      }
    }
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(AlgorithmTest);

auto main() -> int {
  CPPUNIT_NS::TestResult controller;
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );        
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );      
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );
  return result.wasSuccessful() ? 0 : 1;
}
