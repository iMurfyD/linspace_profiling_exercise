# linspace_profiling_exercise
How fast do various implementations of linspace work?

`linspace` is a MATLAB function which initializes and populates an array with equally spaced values on the real number line from a lower to an upper limit. It's "well" optimized, so I like to use it to test how fast the backend MATLAB implementation is against something in a compiled language. 

`linspace_bench.md` compares a naive C implmentation of `linspace` against a C++ implementation using `std::vector`, the `MATLAB 2022b` implementation, the Julia v1.9.3 `LinRange` built-in operation, which does the same thing, and a naive implementation of it in pure Julia on a 2019 Macbook Pro with a Gen. 9 intel chip. The compiler used is Apple clang version 14.0.3. To summarize this informal benchmark, the C implementation is too fast to benchmark properly using the POISIX `clock`. It probably is completing in 10's of CPU clock cycles. The MATLAB, C++, and pure Julia implementations all take ~500 μs. The pure C and Julia `LinRange` implementations are probably taking ~5 ns. 
