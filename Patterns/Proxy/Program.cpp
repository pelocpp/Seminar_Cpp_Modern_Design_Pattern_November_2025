// ===========================================================================
// Program.cpp // Proxy Pattern
// ================
// 
// ===========================================================


#include <vector>


// function prototypes
void test_conceptual_example();
void test_property_proxy();
void test_virtual_proxy();

void test()
{
    std::vector<int> numbers;

    // Iterieren // einen Container durchlaufen: Iterator-Konzept

    // Was ist ein Member types ???????? ZB iterator


    std::vector<int>::iterator anfang;

    anfang = numbers.begin();

  //  std::_Vector_iterator<int> xxx;
}

int main()
{
    test_conceptual_example();
    test_property_proxy();
    test_virtual_proxy();
    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
