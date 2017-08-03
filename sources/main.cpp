#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

struct S {
    int a1;
    int a2;
    
    auto operator++() -> S &
    {
        ++a1;
        ++a2;
        
        return *this;
    }
    
    auto operator--() -> S &
    {
        --a1;
        --a2;
        
        return *this;
    }
};

auto operator<<( std::ostream & stream, S const & o ) -> std::ostream &
{
    return stream << '(' << o.a1 << ", " << o.a2 << ')';
}

S o;

int main()
{
    using std::literals::chrono_literals::operator""ns;
    using std::literals::chrono_literals::operator""s;
    
    std::vector<std::thread> threads;
    
    threads.emplace_back( [] {
        for( ;; ) {
            ++o;
            std::this_thread::sleep_for( 1ns );
        }
    } );
    
    threads.emplace_back( [] {
        for( ;; ) {
            --o;
            std::this_thread::sleep_for( 1ns );
        }
    } );
    
    threads.emplace_back( [] {
        for( ;; ) {
            std::cout << o << std::endl;
            std::this_thread::sleep_for( 1s );
        }
    } );
    
    
    for( auto & thread : threads ) {
        thread.join();
    }
}
