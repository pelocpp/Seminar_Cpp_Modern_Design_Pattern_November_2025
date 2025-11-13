// ===========================================================================
// ConceptualExampleModern.cpp // Strategy Pattern
// ===========================================================================

#include <algorithm>
#include <functional>
#include <memory>
#include <print>
#include <string>
#include <vector>

namespace StrategyConceptualExampleModern {

    /**
     * The Strategy Interface declares operations
     * common to all supported versions of some algorithm.
     *
     * The Context uses this interface to call the algorithm
     * defined by Concrete Strategies.
     *
     * In Modern C++ the Strategy Interface may be defined through a std::function type.
     */

    std::vector<double> numbers;   // Schablonen: ==> Performant
                                   // Python, JavaScript:
                                   // Interpretation von Daten zur Laufzeit
                                   // Overhead, Performanz

    // C++ Antwort auf einen Funktionszeiger
    using Strategy = std::function < std::string (const std::vector<std::string>& ) >;

    int function(int a, int b) { return 0; }

    std::string function2(const std::vector<std::string>&) { return ""; }
    
    void test()
    {
        // a la C 
        int (*pf)(int, int);  // was ist fp: Funktionszeiger // Funktionsadresse

        std::string(*pf2)(const std::vector<std::string>&);  // was ist fp: Funktionszeiger // Funktionsadresse

        pf = & function;

        pf2 = & function2;
    }


    /**
     * Concrete strategies implement the algorithm
     * based upon the std::function type definition.
     * The definition makes them interchangeable in the Context.
     */

    static std::string doAlgorithmA(const std::vector<std::string>& data)
    {
        std::string result{};

        std::for_each(
            data.begin(),
            data.end(),
            [&](const std::string& letter) {
                result += letter;
            }
        );

        std::sort(
            result.begin(),
            result.end()
        );

        return result;
    }

    static std::string doAlgorithmB(const std::vector<std::string>& data)
    {
        std::string result{};

        std::for_each(
            data.begin(),
            data.end(),
            [&](const std::string& letter) {
                result += letter;
            }
        );

        std::sort(
            result.begin(),
            result.end()
        );

        std::reverse(
            result.begin(),
            result.end()
        );

        return result;
    }

    /**
     * The Context uses the strategy interface
     */
    class Context
    {
        /**
         * The Context maintains an object implementing one of the available strategies,
         * in our case an std::function<> object.
         * The Context doesn't have any knowledge of the concrete implementation of the wrapped function.
         * It can just call this function via the std::function<> object.
         */
    private:
       // using Strategy = std::function < std::string(const std::vector<std::string>&) >;

        Strategy m_strategy;

        /**
         * Usually, the Context accepts a strategy through the constructor,
         * but also provides setter methods to change the strategy at runtime.
         */
    public:
        // c'tor(s), d'tor
        Context(Strategy&& strategy) : m_strategy{ std::move(strategy) } {}

        Context(Strategy& strategy) : m_strategy{ strategy } {}

        ~Context() {}

        /**
         * Usually, the Context allows replacing a Strategy object at runtime.
         */
        void setStrategy(Strategy&& strategy)
        {
            m_strategy = std::move(strategy);
        }

        void setStrategy(Strategy& strategy)
        {
            m_strategy = strategy;
        }

        /**
         * The Context delegates some work to the strategy object instead of
         * implementing multiple versions of the algorithm on its own.
         */
        void doSomeBusinessLogic() const
        {
            std::vector<std::string> someStrings{ "A", "E", "C", "B", "D" };

            std::println("Context: Sorting data ...");

            std::string result{ m_strategy ( someStrings ) };

            std::println("Result: {}", result);
        }
    };

    /**
     * The client code picks a concrete strategy and passes it to the Context.
     * The client should be aware of the differences between strategies
     * in order to make the right choice.
     */

    static void clientCode()
    {
        std::println("Client: Strategy is set to 'Normal Sorting':");

        Context context{ doAlgorithmA };
        context.doSomeBusinessLogic();
        std::println();

        std::println("Client: Strategy is set to 'Reverse Sorting':");
        context.setStrategy(doAlgorithmB);
        context.doSomeBusinessLogic();

        // Eine Strategie als Lambda
        auto doLambdaAlgorithm = [](const std::vector<std::string>& data)
            {
                std::string result{};

                std::for_each(
                    data.begin(),
                    data.end(),
                    [&](const std::string& letter) {
                        result += letter;
                    }
                );

                std::sort(
                    result.begin(),
                    result.end()
                );

                return result;
            };

        std::println("Client: Strategy is set to a  Lambda");
        context.setStrategy(doLambdaAlgorithm);
        context.doSomeBusinessLogic();

        // in-place // vor Ort // Modern Style
        context.setStrategy([](const std::vector<std::string>& data)
            {
                std::string result{};

                std::for_each(
                    data.begin(),
                    data.end(),
                    [&](const std::string& letter) {
                        result += letter;
                    }
                );

                std::sort(
                    result.begin(),
                    result.end()
                );

                return result;
            }
        );
        context.doSomeBusinessLogic();
    }
}

void test_conceptual_example_modern()
{
    using namespace StrategyConceptualExampleModern;

    clientCode();
}

// ===========================================================================
// End-of-File
// ===========================================================================
